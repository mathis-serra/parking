#include "raylib.h"
#include "vehicule.hpp"
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
    Vehicule vehicule(screenWidth, screenHeight, cellSize);

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            displayGrid = !displayGrid;
        }

        if (displayGrid)
        {
            if (IsKeyDown(KEY_LEFT))
            {
                vehicule.shift_car('g'); // Déplacer la voiture principale vers la gauche
            }
            else if (IsKeyDown(KEY_RIGHT))
            {
                vehicule.shift_car('d'); // Déplacer la voiture principale vers la droite
            }
            else if (IsKeyDown(KEY_UP))
            {
                vehicule.shift_car('h'); // Déplacer la voiture principale vers le haut
            }
            else if (IsKeyDown(KEY_DOWN))
            {
                vehicule.shift_car('b'); // Déplacer la voiture principale vers le bas
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
