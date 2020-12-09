#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Cell.h"

    class SafeCell : public Cell
    {
    public:
        friend class Graphics;
        SafeCell();
        SafeCell(int, int);
        ~SafeCell();
        virtual void calculateNumber(Cell* ptr[10][10]);
    };