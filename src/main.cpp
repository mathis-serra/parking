#include "raylib.h"

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;
    const int cellSize = 50;

    InitWindow(screenWidth, screenHeight, "Parking");
    SetTargetFPS(60);

    
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        EndDrawing();
    }



    return 0;
}