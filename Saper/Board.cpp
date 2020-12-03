#include "Board.h"
#include <SFML/Graphics.hpp>

Board::Board() {


}



Board::Board(int v) {
	for (int i = 0; i < v; i++) {
		pointer.push_back(new int);
	}
}

void Board::draw() {


}