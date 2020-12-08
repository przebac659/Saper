#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdexcept>
#include "SafeCell.h"

class Graphics {
protected:
	sf::RenderWindow* window;
	sf::Event event = {};
	sf::Font font;
public:
	Graphics(int size, std::string name);
	void OpenWindow(Cell* cell[10][10]);
	void drawCell(float, int, int, int);
	void drawMines(float, Cell* cell, int, int);
	void drawNumber(int, int, int);
	void reveal(Cell* cell[10][10]);
};