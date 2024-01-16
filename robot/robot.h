#include <vector>
#include <stdio.h>
#define CE_SERIAL_IMPLEMENTATION
#include "ceSerial.h"

enum RobotStatus : char
{
    OFF = 0,
    WAITING_FOR_TAKING = 1,
    DOING_REQUEST = 2,
    WAITING_FOR_RDOPPING = 3,
    DONE = 4,
};

class Robot
{
private:
    RobotStatus status = OFF;

public:
    void send(ceSerial *com, std::vector<char> path);
    void read(ceSerial *com, Robot* robot);
    RobotStatus getStatus();
};