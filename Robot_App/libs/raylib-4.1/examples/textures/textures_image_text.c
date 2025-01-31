/*******************************************************************************************
*
*   raylib [texture] example - Image text drawing using TTF generated font
*
*   This example has been created using raylib 1.8 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2017 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [texture] example - image text drawing");

    Image parrots = rl_LoadImage("resources/parrots.png"); // Load image in CPU memory (RAM)

    // TTF Font loading with custom generation parameters
    Font font = LoadFontEx("resources/KAISG.ttf", 64, 0, 0);

    // Draw over image using custom font
    Imagerl_rl_DrawTextEx(&parrots, font, "[Parrots font drawing]", (Vector2){ 20.0f, 20.0f }, (float)font.baseSize, 0.0f, RED);

    Texture2D texture = LoadTextureFromImage(parrots);  // Image converted to texture, uploaded to GPU memory (VRAM)
    UnloadImage(parrots);   // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM

    Vector2 position = { (float)(screenWidth/2 - texture.width/2), (float)(screenHeight/2 - texture.height/2 - 20) };

    bool showFont = false;

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_SPACE)) showFont = true;
        else showFont = false;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            if (!showFont)
            {
                // Draw texture with text already drawn inside
                rl_DrawTextureV(texture, position, WHITE);

                // Draw text directly using sprite font
                rl_rl_DrawTextEx(font, "[Parrots font drawing]", (Vector2){ position.x + 20,
                           position.y + 20 + 280 }, (float)font.baseSize, 0.0f, WHITE);
            }
            else rl_DrawTexture(font.texture, screenWidth/2 - font.texture.width/2, 50, BLACK);

            rl_DrawText("PRESS SPACE to SHOW FONT ATLAS USED", 290, 420, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(texture);     // Texture unloading

    UnloadFont(font);           // Unload custom font

    rl_CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}