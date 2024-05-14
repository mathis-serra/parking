#ifndef VEHICLE_HPP
#define VEHICLE_HPP

#include<vector>
#include "raylib.h"

class Vehicle
{
public:
    Vehicle(int width, int height, int cellSize);
    void Draw();
    void shift_car();


private:
    int rows;
    int columns;
    int cellSize;
    std::vector<std::vector<int>> cells;
};

#endif
