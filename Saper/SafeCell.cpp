#include "SafeCell.h"

SafeCell::SafeCell() {
    seen = 0;
    x = 0;
    y = 0;
    number = 0;
}

SafeCell::SafeCell(int i, int j) {
    seen = 0;
    x = i;
    y = j;
    number = 0;
}
SafeCell::~SafeCell() {

}

void SafeCell::calculateNumber(Cell* ptr[10][10]) {             //Calculates neighbors with the mine with respect to the boundaries of the board

    for (unsigned int i = std::max(0, x / 60 - 1); i < std::min(10, x / 60 + 2); ++i) {             //60 because 50 is the size of one cell and 10 is the empty space between cells
        for (unsigned int j = std::max(0, y / 60 - 1); j < std::min(10, y / 60 + 2); ++j) {
            if (i == x && j == y)
                continue;
            Cell* neighbouring_cell = ptr[i][j];
            if (dynamic_cast<SafeCell*>(neighbouring_cell)==nullptr) ++number;
        }
    }
}