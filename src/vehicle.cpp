#include "vehicle.hpp"
#include<cstdlib>


Vehicle::Vehicle(int width, int height, int cellSize)
    : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {
            this->cellSize = cellSize;
    }

void Draw_cars() {
    int maxSquares = 3;
    int gridSize = 6;
    int cellSize = cellSize;

    for (int i = 0; i < maxSquares; i++)
    {
        int row = rand() % gridSize;
        int column = rand() % gridSize;
        int size = (rand() % 3 + 1) * cellSize; 
        Color color = (BLUE); 
        DrawRectangle(column * cellSize + cellSize, row * cellSize + cellSize, size, size, color);
    }
}

void Draw_playeur(){
    return;
}


