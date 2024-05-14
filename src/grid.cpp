
#include "raylib.h"
#include"grid.hpp"

void Grid::Draw()
{
    for (int row = 0; row < rows; row++)
    {
        for(int column = 0 ; column < columns; column++ )
        {
            Color color = cells[row][column] ? Color{0, 0, 0, 255} : Color{255, 255, 255, 255};
            DrawRectangle(column * cellSize, row * cellSize, cellSize -1, cellSize -1, color);
        }
    }


}