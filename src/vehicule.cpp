#include "vehicule.hpp"
#include "grid.hpp"


Vehicule::Vehicule(int width, int height, int cellSize)
    : rows(height / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)), selectedRow(-1), selectedColumn(-1), isHorizontal(true) {
    InitializeVehicles();
}

void Vehicule::InitializeVehicles() {
    cells[0][0] = 2; 
    cells[0][1] = 2;

    cells[1][1] = 1; 
    cells[1][2] = 1;

    cells[1][4] = 1;
    cells[2][4] = 1;
    
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

            // Indicateur de sélection
            if ((i == selectedRow && j == selectedColumn) || (isHorizontal && i == selectedRow && (j == selectedColumn - 1 || j == selectedColumn + 1)) || (!isHorizontal && j == selectedColumn && (i == selectedRow - 1 || i == selectedRow + 1))) {
                DrawRectangleLines(offsetX + j * cellSize, offsetY + i * cellSize, cellSize, cellSize, RED);
            }
        }
    }
}

bool Vehicule::hasNeighbourOfSameColor(int row, int column) const {
    // Vérifie si la case a un voisin de la même couleur
    if (cells[row][column] == 1 || cells[row][column] == 2) {
        // Vérifie les voisins horizontaux
        if (column > 0 && cells[row][column - 1] == cells[row][column]) return true;
        if (column < columns - 1 && cells[row][column + 1] == cells[row][column]) return true;
        // Vérifie les voisins verticaux
        if (row > 0 && cells[row - 1][column] == cells[row][column]) return true;
        if (row < rows - 1 && cells[row + 1][column] == cells[row][column]) return true;
    }
    return false;
}

void Vehicule::shift_car(int direction) {
    if (selectedRow == -1 || selectedColumn == -1) return;

    int nextRow = selectedRow;
    int nextColumn = selectedColumn;

    // Effacer l'ancienne position de la voiture
    cells[selectedRow][selectedColumn] = 0;
    if (isHorizontal) {
        cells[selectedRow][selectedColumn + 1] = 0; // Effacer la case à droite
    } else {
        cells[selectedRow + 1][selectedColumn] = 0; // Effacer la case en bas
    }

    // Déplacer le véhicule d'une seule case dans la direction spécifiée
    switch (direction) {
        case 'g': // Gauche
            if (isHorizontal && selectedColumn > 0 && cells[selectedRow][selectedColumn - 1] == 0) {
                nextColumn = selectedColumn - 1;
            }
            break;
        case 'd': // Droite
            if (isHorizontal && selectedColumn < columns - 2 && cells[selectedRow][selectedColumn + 2] == 0) {
                nextColumn = selectedColumn + 1;
            }
            break;
        case 'h': // Haut
            if (!isHorizontal && selectedRow > 0 && cells[selectedRow - 1][selectedColumn] == 0) {
                nextRow = selectedRow - 1;
            }
            break;
        case 'b': // Bas
            if (!isHorizontal && selectedRow < rows - 2 && cells[selectedRow + 2][selectedColumn] == 0) {
                nextRow = selectedRow + 1;
            }
            break;
        default:
            break;
    }

    // Limiter le déplacement à l'intérieur de la grille
    if (nextRow >= 0 && nextRow < rows && nextColumn >= 0 && nextColumn < columns) {
        // Vérifier si la case de destination est vide
        if (cells[nextRow][nextColumn] == 0) {
            // Mettre à jour la nouvelle position du véhicule
            cells[nextRow][nextColumn] = 2;
            if (isHorizontal) {
                cells[nextRow][nextColumn + 1] = 2;
            } else {
                cells[nextRow + 1][nextColumn] = 2;
            }
            selectedRow = nextRow;
            selectedColumn = nextColumn;
        } else {
            // Restaurer la position précédente si la case de destination n'est pas vide
            cells[selectedRow][selectedColumn] = 2;
            if (isHorizontal) {
                cells[selectedRow][selectedColumn + 1] = 2;
            } else {
                cells[selectedRow + 1][selectedColumn] = 2;
            }
        }
    }
}



void Vehicule::select_car(int x, int y) {
    int row = y / cellSize;
    int column = x / cellSize;

    // Vérifier si les coordonnées sont à l'intérieur de la grille
    if (row >= 0 && row < rows && column >= 0 && column < columns) {
        // Vérifier si la case sélectionnée contient une partie de la voiture
        if (cells[row][column] == 2) {
            // Vérifier si la voiture est horizontale
            if (column > 0 && cells[row][column - 1] == 2) {
                isHorizontal = true;
                selectNeighbourBlocks(row, column, 2); // Sélectionner les blocs jaunes adjacents
            }
            // Vérifier si la voiture est verticale
            else if (row > 0 && cells[row - 1][column] == 2) {
                isHorizontal = false;
                selectNeighbourBlocks(row, column, 2); // Sélectionner les blocs jaunes adjacents
            }
        }
        else if (cells[row][column] == 1) {
            // Vérifier si la voiture est horizontale
            if (column > 0 && cells[row][column - 1] == 1) {
                isHorizontal = true;
                selectNeighbourBlocks(row, column, 1); // Sélectionner les blocs bleus adjacents
            }
            // Vérifier si la voiture est verticale
            else if (row > 0 && cells[row - 1][column] == 1) {
                isHorizontal = false;
                selectNeighbourBlocks(row, column, 1); // Sélectionner les blocs bleus adjacents
            }
        }

        // Vérifier si la voiture sélectionnée a un voisin de la même couleur
        if (hasNeighbourOfSameColor(row, column)) {
            selectedRow = row;
            selectedColumn = column;
            printf("Selected vehicle at (%d, %d)\n", selectedRow, selectedColumn); // Message de débogage
        } else {
            selectedRow = -1;
            selectedColumn = -1;
            printf("No vehicle selected\n"); // Message de débogage
        }
    }
}


void Vehicule::selectNeighbourBlocks(int row, int column, int color) {
    // Marquer le bloc initial comme sélectionné
    selectedBlocks.clear();
    selectedBlocks.push_back(std::make_pair(row, column));

    // Parcourir les voisins horizontaux
    if (column > 0 && cells[row][column - 1] == color) {
        selectNeighbourBlocks(row, column - 1, color);
    }
    if (column < columns - 1 && cells[row][column + 1] == color) {
        selectNeighbourBlocks(row, column + 1, color);
    }

    // Parcourir les voisins verticaux
    if (row > 0 && cells[row - 1][column] == color) {
        selectNeighbourBlocks(row - 1, column, color);
    }
    if (row < rows - 1 && cells[row + 1][column] == color) {
        selectNeighbourBlocks(row + 1, column, color);
    }
}



