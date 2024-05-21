#ifndef VEHICULE_HPP
#define VEHICULE_HPP

#include <vector>
#include "raylib.h"
#include "grid.hpp"
#include <cstdio> 


class Vehicule {
public:
    Vehicule(int width, int height, int cellSize);
    void InitializeVehicles();
    void Draw(const Grid& grid) const;
    void shift_car(int direction);
    void select_car(int x, int y);
    bool hasNeighbourOfSameColor(int row, int column) const;
    void selectNeighbourBlocks(int row, int column, int color);
    int getSelectedRow() const { return selectedRow; }
    int getSelectedColumn() const { return selectedColumn; }
    int getSelectedCarType() const { return cells[selectedRow][selectedColumn]; }
    std::vector<std::pair<int, int>> selectedBlocks; 

private:
    int rows;
    int columns;
    int cellSize;
    std::vector<std::vector<int>> cells;
    int selectedRow;
    int selectedColumn;
    bool isHorizontal;
};

#endif
