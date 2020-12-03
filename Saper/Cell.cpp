#include "Cell.h"

Cell::Cell() {}

Cell::~Cell() {}

void Cell::drawCell(sf::RenderWindow& window, float size) {

}

void Cell::reveal(sf::Event& event, Cell* ptr[10][10], sf::Sound& sound) {
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left && x + 50 > event.mouseButton.x && event.mouseButton.x > x && y + 50 > event.mouseButton.y && event.mouseButton.y > y && /*mine == 1 &&*/ seen == 0)
        {
            seen = 1;
            sound.play();
        }
        if (event.mouseButton.button == sf::Mouse::Left && x + 50 > event.mouseButton.x && event.mouseButton.x > x && y + 50 > event.mouseButton.y && event.mouseButton.y > y && seen == 0 /*&& number > 0*/)
        {
            seen = 1;
            sound.play();
        }
        if (event.mouseButton.button == sf::Mouse::Right && x + 50 > event.mouseButton.x && event.mouseButton.x > x && y + 50 > event.mouseButton.y && event.mouseButton.y > y && seen == 0)
        {
            seen = 2;
            sound.play();
        }
        if (event.mouseButton.button == sf::Mouse::Left && x + 50 > event.mouseButton.x && event.mouseButton.x > x && y + 50 > event.mouseButton.y && event.mouseButton.y > y && seen == 0 /*&& number == 0*/)
        {
            sound.play();
            for (unsigned int i = std::max(0, x / 60 - 1); i < std::min(10, x / 60 + 2); ++i) {
                for (unsigned int j = std::max(0, y / 60 - 1); j < std::min(10, y / 60 + 2); ++j) {
                    Cell* neighbouring_cell = ptr[i][j];
                    neighbouring_cell->seen = 1;
                    //if (neighbouring_cell->number == 0) neighbouring_cell->revealZeros(ptr);
                }
            }
        }
    }
}

