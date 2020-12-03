#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "SafeCell.h"

class Graphics {
protected:
	//sf::RenderWindow* window;
	sf::Event event;
	Graphics* ptr[10][10];
	sf::Font font;
public:
	//void LoadWindow(int, std::string);
	void OpenWindow(SafeCell* cell[10][10], sf::RenderWindow& window);
	void drawCell(float, bool, int, int, sf::RenderWindow& window);
	void drawMines(float, bool, int, int, sf::RenderWindow& window);
	void drawNumber(int, int, int, sf::RenderWindow& window);
	void reveal(int, int, SafeCell* cell[10][10], int, bool, int, sf::RenderWindow& window);
};