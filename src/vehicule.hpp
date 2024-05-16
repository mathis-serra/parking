#ifndef VEHICULE_HPP
#define VEHICULE_HPP

#include <vector>

class Grid;

class Vehicule {
public:
    Vehicule(int width, int height, int cellSize);
    void Draw(const Grid& grid) const;
    void shift_car(int direction);

private:
    int rows;
    int columns;
    int cellSize;
    std::vector<std::vector<int>> cells;

    void InitializeVehicles();
};

#endif 
