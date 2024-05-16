#include "grid.hpp"

Grid::Grid(int width, int height, int cellSize)
    : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {
    int gridSize = 6; // Supposons que la grille est de taille 6x6
    offsetX = (GetScreenWidth() - gridSize * cellSize) / 2;
    offsetY = (GetScreenHeight() - gridSize * cellSize) / 2;
}

void Grid::Draw() const {
    const int gridSize = 6; 
    const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    // Dessiner les lettres sur le côté gauche
    for (int row = 0; row < gridSize; row++) {
        DrawText(TextFormat("%c", letters[row]), offsetX - 40, offsetY + row * cellSize + cellSize / 2 - 10, 20, BLACK);
    }

    // Dessiner les nombres en haut
    for (int column = 0; column < gridSize; column++) {
        DrawText(TextFormat("%d", column + 1), offsetX + column * cellSize + cellSize / 2 - 5, offsetY - 30, 20, BLACK);
    }

    // Dessiner la grille
    for (int row = 0; row < gridSize; row++) {
        for (int column = 0; column < gridSize; column++) {
            Color color = LIGHTGRAY; // Couleur de la cellule par défaut
            DrawRectangle(offsetX + column * cellSize, offsetY + row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}
