#include "robot.cpp"
#include<iostream>

int main()
{
    ceSerial com("\\\\.\\COM4", 9600, 8, 'N', 1);
    Robot logist;

   // printf("Opening port %s.\n", com.GetPort().c_str());
    
    
    for(int i = 0; i < 10; i++)
    {
        logist.send({0, 1, 2, 7, 8, 9});//&com, 
        Sleep(2000);
    }
    std::cout<< "finish";
    com.Close();
}