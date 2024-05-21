#include "grid.hpp"

Grid::Grid(int width, int height, int cellSize)
    : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {
    int gridSize = 6; // Suppose the grid size is 6x6
    offsetX = (GetScreenWidth() - gridSize * cellSize) / 2;
    offsetY = (GetScreenHeight() - gridSize * cellSize) / 2;
}

void Grid::Draw() const {
    const int gridSize = 6; 
    const char letters[] = {'A', 'B', 'C', 'D', 'E', 'F'};

    // Draw letters on the left side
    for (int row = 0; row < gridSize; row++) {
        DrawText(TextFormat("%c", letters[row]), offsetX - 40, offsetY + row * cellSize + cellSize / 2 - 10, 20, BLACK);
    }

    // Draw numbers on the top
    for (int column = 0; column < gridSize; column++) {
        DrawText(TextFormat("%d", column + 1), offsetX + column * cellSize + cellSize / 2 - 5, offsetY - 30, 20, BLACK);
    }

    

    // Draw the grid
    for (int row = 0; row < gridSize; row++) {
        for (int column = 0; column < gridSize; column++) {
            Color color = LIGHTGRAY; // Default cell color
            DrawRectangle(offsetX + column * cellSize, offsetY + row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}

bool Grid::IsWithinBounds(int row, int column) const {
    return (row >= 0 && row < rows && column >= 0 && column < columns);
}

int Grid::GetOffsetX() const {
    return offsetX;
}

int Grid::GetOffsetY() const {
    return offsetY;
}
