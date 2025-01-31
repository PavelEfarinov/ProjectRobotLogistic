/*******************************************************************************************
*
*   raylib [textures] example - blend modes
*
*   NOTE: Images are loaded in CPU memory (RAM); textures are loaded in GPU memory (VRAM)
*
*   This example has been created using raylib 3.5 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Example contributed by Karlo Licudine (@accidentalrebel) and reviewed by Ramon Santamaria (@raysan5)
*
*   Copyright (c) 2020 Karlo Licudine (@accidentalrebel)
*
********************************************************************************************/

#include "raylib.h"

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - blend modes");

    // NOTE: Textures MUST be loaded after Window initialization (OpenGL context is required)
    Image bgImage = rl_LoadImage("resources/cyberpunk_street_background.png");     // Loaded in CPU memory (RAM)
    Texture2D bgTexture = LoadTextureFromImage(bgImage);          // Image converted to texture, GPU memory (VRAM)

    Image fgImage = rl_LoadImage("resources/cyberpunk_street_foreground.png");     // Loaded in CPU memory (RAM)
    Texture2D fgTexture = LoadTextureFromImage(fgImage);          // Image converted to texture, GPU memory (VRAM)

    // Once image has been converted to texture and uploaded to VRAM, it can be unloaded from RAM
    UnloadImage(bgImage);
    UnloadImage(fgImage);

    const int blendCountMax = 4;
    BlendMode blendMode = 0;

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyPressed(KEY_SPACE))
        {
            if (blendMode >= (blendCountMax - 1)) blendMode = 0;
            else blendMode++;
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            rl_DrawTexture(bgTexture, screenWidth/2 - bgTexture.width/2, screenHeight/2 - bgTexture.height/2, WHITE);

            // Apply the blend mode and then draw the foreground texture
            BeginBlendMode(blendMode);
                rl_DrawTexture(fgTexture, screenWidth/2 - fgTexture.width/2, screenHeight/2 - fgTexture.height/2, WHITE);
            EndBlendMode();

            // Draw the texts
            rl_DrawText("Press SPACE to change blend modes.", 310, 350, 10, GRAY);

            switch (blendMode)
            {
                case BLEND_ALPHA: rl_DrawText("Current: BLEND_ALPHA", (screenWidth / 2) - 60, 370, 10, GRAY); break;
                case BLEND_ADDITIVE: rl_DrawText("Current: BLEND_ADDITIVE", (screenWidth / 2) - 60, 370, 10, GRAY); break;
                case BLEND_MULTIPLIED: rl_DrawText("Current: BLEND_MULTIPLIED", (screenWidth / 2) - 60, 370, 10, GRAY); break;
                case BLEND_ADD_COLORS: rl_DrawText("Current: BLEND_ADD_COLORS", (screenWidth / 2) - 60, 370, 10, GRAY); break;
                default: break;
            }

            rl_DrawText("(c) Cyberpunk Street Environment by Luis Zuno (@ansimuz)", screenWidth - 330, screenHeight - 20, 10, GRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(fgTexture); // Unload foreground texture
    UnloadTexture(bgTexture); // Unload background texture

    rl_CloseWindow();            // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
