#include "Graphics.h"
#include "SafeCell.h"

/*void Graphics::LoadWindow(int size, std::string name) {
	window = new sf::RenderWindow(sf::VideoMode(size, size), name);
    font.loadFromFile("Steinberg.ttf");
}*/

void Graphics::OpenWindow(SafeCell* cell[10][10], sf::RenderWindow& window) {
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ptr[i][j]->reveal(cell[i][j]->x, cell[i][j]->y, cell, cell[i][j]->seen, cell[i][j]->mine, cell[i][j]->number, window);
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ptr[i][j]->drawNumber(cell[i][j]->number, cell[i][j]->x, cell[i][j]->y, window);
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ptr[i][j]->drawMines(20, cell[i][j]->mine, cell[i][j]->x, cell[i][j]->y, window);
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                ptr[i][j]->drawCell(50, cell[i][j]->seen, cell[i][j]->x, cell[i][j]->y, window);
            }
        }

        window.display();
    }

    
}

void Graphics::drawCell(float size, bool seen, int x, int y, sf::RenderWindow& window) {
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

void Graphics::drawMines(float size, bool mine, int x, int y, sf::RenderWindow& window) {
    if (mine == 1) {
        sf::RectangleShape R(sf::Vector2f(size, size));
        R.setFillColor(sf::Color::Blue);
        R.setPosition(x + 15, y + 15);
        window.draw(R);
    }
}

void Graphics::drawNumber(int number, int x, int y, sf::RenderWindow& window) {
    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(number));
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(x + 15, y + 15);
    if (number > 0)
        window.draw(text);
}

void Graphics::reveal(int x, int y, SafeCell* cell[10][10], int seen, bool mine, int number, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left && x + 50 > event.mouseButton.x && event.mouseButton.x > x && y + 50 > event.mouseButton.y && event.mouseButton.y > y && mine == 1 && seen == 0)
        {
            seen = 1;
        }
        if (event.mouseButton.button == sf::Mouse::Left && x + 50 > event.mouseButton.x && event.mouseButton.x > x && y + 50 > event.mouseButton.y && event.mouseButton.y > y && seen == 0 && number > 0)
        {
            seen = 1;
        }
        if (event.mouseButton.button == sf::Mouse::Right && x + 50 > event.mouseButton.x && event.mouseButton.x > x && y + 50 > event.mouseButton.y && event.mouseButton.y > y && seen == 0)
        {
            seen = 2;
        }
        if (event.mouseButton.button == sf::Mouse::Left && x + 50 > event.mouseButton.x && event.mouseButton.x > x && y + 50 > event.mouseButton.y && event.mouseButton.y > y && seen == 0 && number == 0)
        {
            for (unsigned int i = std::max(0, x / 60 - 1); i < std::min(10, x / 60 + 2); ++i) {
                for (unsigned int j = std::max(0, y / 60 - 1); j < std::min(10, y / 60 + 2); ++j) {
                    SafeCell* neighbouring_cell = cell[i][j];
                    neighbouring_cell->seen = 1;
                    if (neighbouring_cell->number == 0) neighbouring_cell->revealZeros(cell);
                }
            }
        }
    }
}

