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

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (cells[i][j] == 1) {
                DrawRectangle(offsetX + j * cellSize, offsetY + i * cellSize, cellSize, cellSize, BLUE);
            } else if (cells[i][j] == 2) {
                DrawRectangle(offsetX + j * cellSize, offsetY + i * cellSize, cellSize, cellSize, YELLOW);
            }

            if (i == selectedRow && j == selectedColumn) {
                DrawRectangleLines(offsetX + j * cellSize, offsetY + i * cellSize, cellSize, cellSize, RED);
            }
        }
    }
}

bool Vehicule::hasNeighbourOfSameColor(int row, int column) const {
    if (cells[row][column] == 1 || cells[row][column] == 2) {
        if (column > 0 && cells[row][column - 1] == cells[row][column]) return true;
        if (column < columns - 1 && cells[row][column + 1] == cells[row][column]) return true;
        if (row > 0 && cells[row - 1][column] == cells[row][column]) return true;
        if (row < rows - 1 && cells[row + 1][column] == cells[row][column]) return true;
    }
    return false;
}
void Vehicule::shift_car(int direction) {
    if (selectedRow == -1 || selectedColumn == -1) return;

    int nextRow = selectedRow;
    int nextColumn = selectedColumn;

    int carType = cells[selectedRow][selectedColumn];
    bool canMove = false;

    switch (direction) {
        case 'g': // Left
            if (isHorizontal && selectedColumn > 0 && cells[selectedRow][selectedColumn - 1] == 0) {
                nextColumn = selectedColumn - 1;
                canMove = true;
            }
            break;
        case 'd': // Right
            if (isHorizontal && selectedColumn < columns - 2 && cells[selectedRow][selectedColumn + 2] == 0) {
                nextColumn = selectedColumn + 1;
                canMove = true;
            }
            break;
        case 'h': // Up
            if (!isHorizontal && selectedRow > 0 && cells[selectedRow - 1][selectedColumn] == 0) {
                nextRow = selectedRow - 1;
                canMove = true;
            }
            break;
        case 'b': // Down
            if (!isHorizontal && selectedRow < rows - 2 && cells[selectedRow + 2][selectedColumn] == 0) {
                nextRow = selectedRow + 1;
                canMove = true;
            }
            break;
    }

    if (canMove) {
        // Check if the next position is within the grid bounds
        if (nextRow >= 0 && nextRow < rows && nextColumn >= 0 && nextColumn < columns) {
            cells[selectedRow][selectedColumn] = 0;
            if (isHorizontal) {
                cells[selectedRow][selectedColumn + 1] = 0;
                cells[nextRow][nextColumn] = carType;
                cells[nextRow][nextColumn + 1] = carType;
            } else {
                cells[selectedRow + 1][selectedColumn] = 0;
                cells[nextRow][nextColumn] = carType;
                cells[nextRow + 1][nextColumn] = carType;
            }
            selectedRow = nextRow;
            selectedColumn = nextColumn;
        }
    }
}


void Vehicule::select_car(int x, int y) {
    int row = y / cellSize;
    int column = x / cellSize;

    if (row >= 0 && row < rows && column >= 0 && column < columns) {
        if (cells[row][column] == 2) {
            if (column > 0 && cells[row][column - 1] == 2) {
                isHorizontal = true;
            } else if (row > 0 && cells[row - 1][column] == 2) {
                isHorizontal = false;
            }
        } else if (cells[row][column] == 1) {
            if (column > 0 && cells[row][column - 1] == 1) {
                isHorizontal = true;
            } else if (row > 0 && cells[row - 1][column] == 1) {
                isHorizontal = false;
            }
        }

        if (hasNeighbourOfSameColor(row, column)) {
            selectedRow = row;
            selectedColumn = column;
            printf("Selected vehicle at (%d, %d)\n", selectedRow, selectedColumn);
        } else {
            selectedRow = -1;
            selectedColumn = -1;
            printf("No vehicle selected\n");
        }
    }
}

void Vehicule::selectNeighbourBlocks(int row, int column, int color) {
    selectedBlocks.clear();
    selectedBlocks.push_back(std::make_pair(row, column));

    if (column > 0 && cells[row][column - 1] == color) {
        selectNeighbourBlocks(row, column - 1, color);
    }
    if (column < columns - 1 && cells[row][column + 1] == color) {
        selectNeighbourBlocks(row, column + 1, color);
    }
    if (row > 0 && cells[row - 1][column] == color) {
        selectNeighbourBlocks(row - 1, column, color);
    }
    if (row < rows - 1 && cells[row + 1][column] == color) {
        selectNeighbourBlocks(row + 1, column, color);
    }
}
