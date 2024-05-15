#ifndef GRID_HPP
#define GRID_HPP

#include<vector>
#include "raylib.h"

class Grid
{
public:
    Grid(int width, int height, int cellSize);
    void Draw();

private:
    int rows;
    int columns;
    int cellSize;
    std::vector<std::vector<int>> cells;
};

#endif
