#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SafeCell.h"

class Graphics {
protected:
	sf::RenderWindow* window;
	sf::Event event = {};
	sf::Font font;
public:
	Graphics(int size, std::string name);
	void OpenWindow(SafeCell* cell[10][10]);
	void drawCell(float, int, int, int);
	void drawMines(float, bool, int, int);
	void drawNumber(int, int, int);
	void reveal(SafeCell* cell[10][10]);
};