#pragma once
#include "Cell.h"
#include <iostream>

class CellWithMine :public Cell {
public:
	CellWithMine();
	CellWithMine(int, int);
	~CellWithMine();
	void calculateNumber(Cell* ptr[10][10]);
};