#ifndef GRID_HPP
#define GRID_HPP

#include<vector>
#include "raylib.h"

class Grid
{
public:
    Grid(int width, int height, int cellSize);
    void Draw();

    int GetRows() const { return rows; }
    int GetColumns() const { return columns; }

private:
    int rows;
    int columns;
    int cellSize;
    std::vector<std::vector<int>> cells;
};

#endif
