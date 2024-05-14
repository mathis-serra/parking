#include "grid.hpp"

Grid::Grid(int width, int height, int cellSize)
    : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {}

void Grid::Draw()
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            Color color = cells[row][column] ? BLACK : WHITE;
            DrawRectangle(column * cellSize, row * cellSize, cellSize - 1, cellSize - 1, color);
        }
    }
}
