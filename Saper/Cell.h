#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Cell {
protected:
    int seen;
    int x;
    int y;
    int number;
public:
    friend class Graphics;
    friend class SafeCell;
    Cell();
    ~Cell();
    virtual void calculateNumber(Cell* ptr[10][10]) = 0;
    //void setMine();
    //virtual void GameOver(sf::Event&, sf::RenderWindow&, sf::Font&) = 0;
};