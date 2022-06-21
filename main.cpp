#include "raylib.h"
#include "star_generator.hpp"

int main()
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    const auto stars_background = generate_stars_background<screenWidth, screenHeight>(); 
    InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input");

    Vector2 ballPosition = { screenWidth/2, screenHeight/2 };

    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);

            DrawText("move the ball with arrow keys", 10, 10, 20, DARKGRAY);

            for(const auto &star : stars_background){
                DrawTriangle(star.v1, star.v2, star.v3, star.color);
            }
            DrawCircleV(ballPosition, 50, MAROON);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
