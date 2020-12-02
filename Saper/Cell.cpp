#include "Cell.h"

void Cell::drawCell(sf::RenderWindow& window, float size) {
    if (seen == 0) {
        sf::RectangleShape R(sf::Vector2f(size, size));
        R.setFillColor(sf::Color::Green);
        R.setPosition(x, y);
        window.draw(R);
    }
    if (seen == 2) {
        sf::RectangleShape R(sf::Vector2f(size, size));
        R.setFillColor(sf::Color::Red);
        R.setPosition(x, y);
        window.draw(R);
    }
}

void Cell::reveal(sf::Event& event, SafeCell* ptr[10][10], sf::Sound& sound) {
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left && x + 50 > event.mouseButton.x && event.mouseButton.x > x && y + 50 > event.mouseButton.y && event.mouseButton.y > y && mine == 1 && seen == 0)
        {
            seen = 1;
            clickedOnMine = 1;
            sound.play();
        }
        if (event.mouseButton.button == sf::Mouse::Left && x + 50 > event.mouseButton.x && event.mouseButton.x > x && y + 50 > event.mouseButton.y && event.mouseButton.y > y && seen == 0 && number > 0)
        {
            seen = 1;
            sound.play();
        }
        if (event.mouseButton.button == sf::Mouse::Right && x + 50 > event.mouseButton.x && event.mouseButton.x > x && y + 50 > event.mouseButton.y && event.mouseButton.y > y && seen == 0)
        {
            seen = 2;
            sound.play();
        }
        if (event.mouseButton.button == sf::Mouse::Left && x + 50 > event.mouseButton.x && event.mouseButton.x > x && y + 50 > event.mouseButton.y && event.mouseButton.y > y && seen == 0 && number == 0)
        {
            sound.play();
            for (unsigned int i = std::max(0, x / 60 - 1); i < std::min(10, x / 60 + 2); ++i) {
                for (unsigned int j = std::max(0, y / 60 - 1); j < std::min(10, y / 60 + 2); ++j) {
                    SafeCell* neighbouring_cell = ptr[i][j];
                    neighbouring_cell->seen = 1;
                    if (neighbouring_cell->number == 0) neighbouring_cell->revealZeros(ptr);
                }
            }
        }
    }
}