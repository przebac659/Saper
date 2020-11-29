#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Cell.h"
#include <random> 

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(590, 590), "Antsweeper");

   Music music;
    if (!music.openFromFile("Music.wav"))
        return -1; // error
    music.play();

    SoundBuffer buffer;
    if (!buffer.loadFromFile("sound.wav"))
        return -1;
    Sound sound;
    sound.setBuffer(buffer);

    Cell* ptr[10][10];

    Font font;
    font.loadFromFile("Steinberg.ttf");
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            ptr[i][j] = new Cell(60*i, 60*j);
        }
    }

    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());
    discrete_distribution<> d({ 80, 20 });

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

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ptr[i][j]->reveal(event, ptr, sound);
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ptr[i][j]->drawNumber(window, font);
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ptr[i][j]->drawMines(window, 20);
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ptr[i][j]->drawCell(window, 50);
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ptr[i][j]->GameOver(event, window, font);
            }
        }

        window.display();
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            delete ptr[i][j];
        }
    }

    return 0;
}