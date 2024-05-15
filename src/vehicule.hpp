#ifndef VEHICULE_HPP
#define VEHICULE_HPP

#include <vector>
#include "raylib.h"

class Vehicule
{
public:
    Vehicule(int width, int height, int cellSize);
    void Draw();
    void shift_car(int direction);

private:
    int rows;
    int columns;
    int cellSize;
    std::vector<std::vector<int>> cells;

    void InitializeVehicles(); // Déclaration de la fonction InitializeVehicles
};

#endif
