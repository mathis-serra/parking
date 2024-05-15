#include "raylib.h"
#include "vehicule.hpp"

int main()
{
    const int screenWidth = 700;
    const int screenHeight = 600;
    const int cellSize = 80;
    bool displayGrid = false;

    InitWindow(screenWidth, screenHeight, "Parking");
    SetTargetFPS(60);

    Vehicule parking(screenWidth, screenHeight, cellSize);

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
                parking.shift_car('g'); // Déplacer la voiture principale vers la gauche
            }
            else if (IsKeyDown(KEY_RIGHT))
            {
                parking.shift_car('d'); // Déplacer la voiture principale vers la droite
            }
            else if (IsKeyDown(KEY_UP))
            {
                parking.shift_car('h'); // Déplacer la voiture principale vers le haut
            }
            else if (IsKeyDown(KEY_DOWN))
            {
                parking.shift_car('b'); // Déplacer la voiture principale vers le bas
            }
        }

        BeginDrawing();
        ClearBackground(WHITE);

        if (displayGrid)
        {
            parking.Draw();
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
