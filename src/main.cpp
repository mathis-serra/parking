#include "raylib.h"
#include "grid.hpp"

int main()
{
    const int screenWidth = 700;
    const int screenHeight = 600;
    const int cellSize = 80;

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
