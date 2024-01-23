#include <string>
#include <vector>
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include "extras/raygui.h"
#include "../../robot/request.cpp"
#include "../classes/button.cpp"
#include "../classes/radiobutton.cpp"
#include "../classes/radiobuttoncontrol.cpp"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1920;
    const int screenHeight = 1035;

    InitWindow(screenWidth, screenHeight, "RoboLogist");

    bool OrderMenu = false;
    bool Sent = false;
    int from, to;
    std::vector<Request> Queue;
    Color selectedColor = GREEN;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //---------------------------------------------------------------------------------------

    Texture2D logo = LoadTexture("../Robot_App/textures/logo.png");
    Texture2D doRequest = LoadTexture("../Robot_App/textures/doRequest.png");
    Texture2D toMenu = LoadTexture("../Robot_App/textures/toMenu.png");
    Texture2D send = LoadTexture("../Robot_App/textures/send.png");
    Texture2D fromTo = LoadTexture("../Robot_App/textures/fromTo.png");
    Texture2D queue = LoadTexture("../Robot_App/textures/queue.png");

    RadioButton A({675, 325}, {350, 75}, RED, "A");
    RadioButton B({675, 425}, {350, 75}, RED, "B");
    RadioButton C({675, 525}, {350, 75}, RED, "C");
    RadioButton D({675, 625}, {350, 75}, RED, "D");
    RadioButtonControl AB;
    AB.buttons.push_back(&A);
    AB.buttons.push_back(&B);
    AB.buttons.push_back(&C);
    AB.buttons.push_back(&D);

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        int from;
        int to;

        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
        {
            if (CheckCollisionPointRec(GetMousePosition(), {960, 450, 128 * 5, 32 * 5}) && !OrderMenu)
            {
                OrderMenu = true;
            }
            else if (OrderMenu)
            {
                AB.Update();
                if (CheckCollisionPointRec(GetMousePosition(), {1550, 900, (float)toMenu.width * 3, (float)toMenu.height * 3}))
                {
                    OrderMenu = false;
                }
            }
            // else if (CheckCollisionPointRec(GetMousePosition(), {675, 325, 350, 75})) {
            // p
            // from = 0;
            //}
            // else if (CheckCollisionPointCircle(GetMousePosition(), ))
        }

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(WHITE);
        DrawRectangleV({0, 100}, {500, 935}, {255, 0, 0, 255});
        DrawRectangleV({0, 0}, {screenWidth, 100}, {200, 0, 0, 255});
        DrawRectangle(1550, 900, (float)toMenu.width * 3, (float)toMenu.height * 3, BLUE);
        DrawTextureEx(logo, {18, 18}, 0, 2, WHITE);
        DrawTextureEx(queue, {100, 125}, 0, 5, WHITE);
        if (!OrderMenu && !Sent)
        {
            DrawTextureEx(doRequest, {960, 450}, 0, 5, WHITE);
            // DrawRectangleV({960, 350}, {500, 200}, {255, 0, 0, 255});
            // DrawText("Order", 1150, 410, 50, WHITE);
        }
        else
        {
            Sent = false;
            DrawTextureEx(toMenu, {1550, 900}, 0, 3, WHITE);
            DrawText("From", 750, 250, 60, RED);
            DrawTextureEx(fromTo, {920, 125}, 0, 3, WHITE);
            DrawTextureEx(send, {1425, 900}, 0, 3, WHITE);
            AB.Draw();
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}