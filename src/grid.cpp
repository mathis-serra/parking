#include "grid.hpp"

Grid::Grid(int width, int height, int cellSize)
    : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {
            this->cellSize = cellSize;
    }

void Grid::Draw()
{
    const int gridSize = 6; 
    const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    
    const int gridWidth = gridSize * cellSize;
    const int gridHeight = gridSize * cellSize;

    const int offsetX = (GetScreenWidth() - gridWidth) / 2;
    const int offsetY = (GetScreenHeight() - gridHeight) / 2;

    // Dessiner les lettres sur le côté gauche
    for (int row = 0; row < gridSize; row++)
    {
        DrawText(TextFormat("%c", letters[row]), offsetX - 40, offsetY + row * cellSize + cellSize / 2 - 10, 20, BLACK);
    }

    // Dessiner les nombres en haut
    for (int column = 0; column < gridSize; column++)
    {
        DrawText(TextFormat("%d", column + 1), offsetX + column * cellSize + cellSize / 2 - 5, offsetY - 30, 20, BLACK);
    }

    // Dessiner la grille
    for (int row = 0; row < gridSize; row++)
    {
        for (int column = 0; column < gridSize; column++)
        {
            Color color = LIGHTGRAY; // Couleur de la cellule par défaut
            DrawRectangle(offsetX + column * cellSize, offsetY + row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}
