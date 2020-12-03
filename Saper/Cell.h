#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Cell {
protected:
    int seen;
    int x;
    int y;
public:
    Cell();
    ~Cell();
    void drawCell(sf::RenderWindow&, float);
    void reveal(sf::Event&, Cell* ptr[10][10], sf::Sound&);
};