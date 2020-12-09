#include "CellWithMine.h"

CellWithMine::CellWithMine() {
    seen = 0;
    x = 0;
    y = 0;
}

CellWithMine::CellWithMine(int i, int j) {
    seen = 0;
    x = i;
    y = j;
}

CellWithMine::~CellWithMine() {

}

void CellWithMine::calculateNumber(Cell* ptr[10][10]) {
    number = 10;
}
