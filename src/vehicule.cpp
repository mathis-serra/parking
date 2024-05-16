#include "vehicule.hpp"
#include "grid.hpp"

Vehicule::Vehicule(int width, int height, int cellSize)
    : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {
    InitializeVehicles();
}

void Vehicule::InitializeVehicles() {
    cells[0][0] = 2; 
    cells[0][1] = 2;
    cells[1][1] = 1; 
    cells[1][2] = 1;
    cells[2][2] = 1;
    cells[2][3] = 1;
}

void Vehicule::Draw(const Grid& grid) const {
    int offsetX = grid.GetOffsetX();
    int offsetY = grid.GetOffsetY();

    // Dessiner les véhicules
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (cells[i][j] == 1) { // Autre véhicule (carré bleu)
                DrawRectangle(offsetX + j * cellSize, offsetY + i * cellSize, cellSize, cellSize, BLUE);
            } else if (cells[i][j] == 2) { // Véhicule principal (deux carrés jaunes)
                DrawRectangle(offsetX + j * cellSize, offsetY + i * cellSize, cellSize, cellSize, YELLOW);
            }
        }
    }
}

void Vehicule::shift_car(int direction) {
    int row = -1, column = -1; // Initialiser avec des valeurs par défaut

    // Trouver la position de la voiture principale
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (cells[i][j] == 2) { // Voiture principale trouvée
                row = i;
                column = j;
                break; // Sortir de la boucle une fois que la voiture principale est trouvée
            }
        }
        if (row != -1 && column != -1) {
            break; // Sortir de la boucle externe une fois que la voiture principale est trouvée
        }
    }

    if (row == -1 || column == -1) {
        // Afficher un message d'erreur ou gérer le cas où la voiture principale n'est pas trouvée
        return;
    }

    // Maintenant, vous pouvez procéder à votre logique de déplacement en toute sécurité
    switch (direction) {
        case 'g': // Gauche
            if (column > 0 && cells[row][column - 1] == 0) {
                cells[row][column] = 0; // Effacer l'ancienne position
                cells[row][column - 1] = 2; // Mettre à jour la nouvelle position
            }
            break;
        case 'd': // Droite
            if (column < columns - 1 && cells[row][column + 1] == 0) {
                cells[row][column] = 0;
                cells[row][column + 1] = 2;
            }
            break;
        case 'h': // Haut
            if (row > 0 && cells[row - 1][column] == 0) {
                cells[row][column] = 0;
                cells[row - 1][column] = 2;
            }
            break;
        case 'b': // Bas
            if (row < rows - 1 && cells[row + 1][column] == 0) {
                cells[row][column] = 0;
                cells[row + 1][column] = 2;
            }
            break;
        default:
            break;
    }
}
