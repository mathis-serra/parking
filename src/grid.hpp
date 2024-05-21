#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include "raylib.h"

class Grid {
public:
    Grid(int width, int height, int cellSize);
    void Draw() const;
    int GetOffsetX() const;
    int GetOffsetY() const;
    bool IsWithinBounds(int row, int column) const; // New method to check if row and column are within grid bounds

private:
    int rows;
    int columns;
    int cellSize;
    int offsetX;
    int offsetY;
    std::vector<std::vector<int>> cells;
};

#endif
