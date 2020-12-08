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
    Cell* ptr[10][10];
    random_device rd;


public:

    Game() {
        try {
            graphics = new Graphics(590, "Sweeper!");
        }
        catch (const std::logic_error& e) {
            std::cerr << "An error occured: " << e.what() << std::endl;
        }

        mt19937 gen(rd());
        discrete_distribution<> d({ 25, 75 });

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (d(gen) == 1) ptr[i][j] = new SafeCell(60 * i, 60 * j);
                else ptr[i][j] = new CellWithMine(60 * i, 60 * j);
            }
        }
    }

    void StartGame() {


        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ptr[i][j]->calculateNumber(ptr);
            }
        }

        graphics->OpenWindow(ptr);

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                delete ptr[i][j];
            }
        }

        delete graphics;

    }
};