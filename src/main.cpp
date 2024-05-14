#include "raylib.h"
#include "grid.hpp"

int main()
{
    const int screenWidth = 700;
    const int screenHeight = 600;
    const int cellSize = 80;
    bool displayGrid = false;

    InitWindow(screenWidth, screenHeight, "Parking");
    SetTargetFPS(60);

    Grid grid(screenWidth, screenHeight, cellSize);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            displayGrid = !displayGrid;
        }
        
        BeginDrawing();
        ClearBackground(WHITE);

        if (displayGrid)
        {
            grid.Draw();
        }
        else
        {
            int centerX = screenWidth / 2;
            int centerY = screenHeight / 2;

            DrawText("Press ENTER to PLAY Parking", centerX - MeasureText("Press ENTER to PLAY Parking", 40) / 2, centerY - 60, 40, BLACK);
            DrawText("Play with directional arrows", centerX - MeasureText("Play with directional arrows", 30) / 2, centerY + 20, 30, BLACK);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
