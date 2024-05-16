#include "raylib.h"
#include "vehicule.hpp"
#include "grid.hpp"
#include <cstdio> 

int main()
{
    const int screenWidth = 700;
    const int screenHeight = 600;
    const int cellSize = 80;
    bool displayGrid = false;

    InitWindow(screenWidth, screenHeight, "Parking");
    SetTargetFPS(60);

    Grid grid(screenWidth, screenHeight, cellSize);
    Vehicule vehicule(screenWidth, screenHeight, cellSize);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            displayGrid = !displayGrid;
        }

        if (displayGrid)
        {
            
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                Vector2 mousePosition = GetMousePosition();
                vehicule.select_car(mousePosition.x - grid.GetOffsetX(), mousePosition.y - grid.GetOffsetY());
            }

            if (IsKeyDown(KEY_LEFT))
            {
                vehicule.shift_car('g'); 
            }
            else if (IsKeyDown(KEY_RIGHT))
            {
                vehicule.shift_car('d'); 
            }
            else if (IsKeyDown(KEY_UP))
            {
                vehicule.shift_car('h');
            }
            else if (IsKeyDown(KEY_DOWN))
            {
                vehicule.shift_car('b'); 
            }
        }

        BeginDrawing();
        ClearBackground(WHITE);

        if (displayGrid)
        {
            grid.Draw();
            vehicule.Draw(grid); 
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
