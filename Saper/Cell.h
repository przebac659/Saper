#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Cell {
protected:
    int seen;
    int x;      //coordinate X
    int y;      //coordinate Y
    int number; //number of neighbouring cells with mines
public:
    friend class Graphics;
    friend class SafeCell;
    Cell();
    virtual ~Cell();
    virtual void calculateNumber(Cell* ptr[10][10]) = 0;
};