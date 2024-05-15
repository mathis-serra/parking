#include "vehicule.hpp"
#include <vector>
#include <cstdlib>
#include "raylib.h"

Vehicule::Vehicule(int width, int height, int cellSize)
    : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)) {
}

void Vehicule::Draw() {
    // Dessiner la grille
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            DrawRectangle(j * cellSize, i * cellSize, cellSize, cellSize, LIGHTGRAY);
            DrawRectangleLines(j * cellSize, i * cellSize, cellSize, cellSize, DARKGRAY);
        }
    }

    // Dessiner les voitures
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (cells[i][j] == 1) { // Si une voiture est présente à cette position
                // Dessiner une voiture
                DrawRectangle(j * cellSize, i * cellSize, cellSize, cellSize, BLUE);
                DrawRectangle(j * cellSize + cellSize / 3, i * cellSize, cellSize / 3, cellSize, BLUE);
            } else if (cells[i][j] == 2) { // Si c'est la voiture principale
                // Dessiner la voiture principale en jaune
                DrawRectangle(j * cellSize, i * cellSize, cellSize, cellSize, YELLOW);
                DrawRectangle(j * cellSize + cellSize / 3, i * cellSize, cellSize / 3, cellSize, YELLOW);
            }
        }
    }
}
void Vehicule::shift_car(int direction) {
    // Code pour déplacer la voiture principale
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


