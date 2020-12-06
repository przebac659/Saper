#pragma once

#include "Cell.h"
#include "SafeCell.h"
#include "CellWithMine.h"
#include "Graphics.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <random>

using namespace sf;
using namespace std;

class Game {
protected:
    Graphics* graphics;
    SafeCell* ptr[10][10];
    random_device rd;


public:
    void StartGame() {

        graphics = new Graphics(590, "Sweeper!");

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ptr[i][j] = new SafeCell(60 * i, 60 * j);
            }
        }

           // non-deterministic generator
        mt19937 gen(rd());
        discrete_distribution<> d({ 65, 35 });

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (d(gen) == 1)
                    ptr[i][j]->setMine();
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ptr[i][j]->calculateNumber(ptr);
            }
        }

        graphics->OpenWindow(ptr);

    }


};