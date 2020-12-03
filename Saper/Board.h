#pragma once
#include "Cell.h"
#include <vector>

class Board : public Cell {
private:
	std::vector<int*> pointer;
public:
	Board();
	Board(int);
	void draw();
};