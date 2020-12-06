#include "Graphics.h"
#include "SafeCell.h"

Graphics::Graphics(int size, std::string name)  {
    window = new sf::RenderWindow(sf::VideoMode(size, size), name);
    font.loadFromFile("Steinberg.ttf");
}

void Graphics::OpenWindow(SafeCell* cell[10][10]) {
    while (window->isOpen())
    {
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        window->clear();

        reveal(cell);

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                drawNumber(cell[i][j]->number, cell[i][j]->x, cell[i][j]->y);
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                drawMines(20, cell[i][j]->mine, cell[i][j]->x, cell[i][j]->y);
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                drawCell(50, cell[i][j]->seen, cell[i][j]->x, cell[i][j]->y);
            }
        }

        window->display();
    }

    
}

void Graphics::drawCell(float size, int seen, int x, int y) {
    if (seen == 0) {
        sf::RectangleShape R(sf::Vector2f(size, size));
        R.setFillColor(sf::Color::Green);
        R.setPosition(x, y);
        window->draw(R);
    }
    if (seen == 2) {
        sf::RectangleShape R(sf::Vector2f(size, size));
        R.setFillColor(sf::Color::Red);
        R.setPosition(x, y);
        window->draw(R);
    }
}

void Graphics::drawMines(float size, bool mine, int x, int y) {
    if (mine == 1) {
        sf::RectangleShape R(sf::Vector2f(size, size));
        R.setFillColor(sf::Color::Blue);
        R.setPosition(x + 15, y + 15);
        window->draw(R);
    }
}

void Graphics::drawNumber(int number, int x, int y) {
    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(number));
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(x + 15, y + 15);
    if (number > 0)
        window->draw(text);
}

void Graphics::reveal(SafeCell* cell[10][10]) {
    if (event.type == sf::Event::MouseButtonPressed)
    {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (event.mouseButton.button == sf::Mouse::Left && cell[i][j]->x + 50 > event.mouseButton.x && event.mouseButton.x > cell[i][j]->x && cell[i][j]->y + 50 > event.mouseButton.y && event.mouseButton.y > cell[i][j]->y && cell[i][j]->seen == 0)
                {
                    cell[i][j]->seen = 1;
                }
                else if (event.mouseButton.button == sf::Mouse::Right && cell[i][j]->x + 50 > event.mouseButton.x && event.mouseButton.x > cell[i][j]->x && cell[i][j]->y + 50 > event.mouseButton.y && event.mouseButton.y > cell[i][j]->y && cell[i][j]->seen == 0)
                {
                    cell[i][j]->seen = 2;
                }
            }
        }  
    }
}

