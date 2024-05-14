#include "raylib.h"
#include "grid.hpp"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int cellSize = 50;

    InitWindow(screenWidth, screenHeight, "Parking");
    SetTargetFPS(60);

    Grid grid(screenWidth, screenHeight, cellSize);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        grid.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}