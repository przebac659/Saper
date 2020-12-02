#pragma once

class Cell {
protected:
    int seen;
    int x;
    int y;
public:
    Cell();
    Cell(float, float);
    ~Cell();
    void drawCell(sf::RenderWindow&, float);
    void reveal(sf::Event&, Cell* ptr[10][10], sf::Sound&);
    void revealZeros(Cell* ptr[10][10]);
};