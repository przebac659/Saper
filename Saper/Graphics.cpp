#include "Graphics.h"
#include "SafeCell.h"

Graphics::Graphics(int size, std::string name)  {
    window = new sf::RenderWindow(sf::VideoMode(size, size), name);
    if (!font.loadFromFile("Steinberg.ttf"))
    {
        throw std::logic_error("Font not loaded.");     //exceptions
    }
    gameOver = false;
}

void Graphics::OpenWindow(Cell* cell[10][10]) {
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
                drawNumber(cell[i][j]->number, cell[i][j]->x, cell[i][j]->y);       //draws number of the mines in neighbouring cell
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                drawMines(20, cell[i][j], cell[i][j]->x, cell[i][j]->y);
            }
        }

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                drawCell(50, cell[i][j]->seen, cell[i][j]->x, cell[i][j]->y);
            }
        }

        GameOver();

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

void Graphics::drawMines(float size, Cell* cell, int x, int y) {
    if (dynamic_cast<SafeCell*>(cell) == nullptr) {         //RTTI
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
    if (10 > number && number > 0)
        window->draw(text);
}

void Graphics::reveal(Cell* cell[10][10]) {
    if (event.type == sf::Event::MouseButtonPressed)
    {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (event.mouseButton.button == sf::Mouse::Left && cell[i][j]->x + 50 > event.mouseButton.x && event.mouseButton.x > cell[i][j]->x && cell[i][j]->y + 50 > event.mouseButton.y && event.mouseButton.y > cell[i][j]->y && cell[i][j]->number>0 && cell[i][j]->number < 10)
                {
                    cell[i][j]->seen = 1;
                }
                else if (event.mouseButton.button == sf::Mouse::Left && cell[i][j]->x + 50 > event.mouseButton.x && event.mouseButton.x > cell[i][j]->x && cell[i][j]->y + 50 > event.mouseButton.y && event.mouseButton.y > cell[i][j]->y && cell[i][j]->number == 10)
                {
                    for (int a = 0; a < 10; a++) {
                        for (int b = 0; b < 10; b++) {
                            cell[a][b]->seen = 1;
                        }
                    }
                    gameOver = true;
                }
                else if (event.mouseButton.button == sf::Mouse::Right && cell[i][j]->x + 50 > event.mouseButton.x && event.mouseButton.x > cell[i][j]->x && cell[i][j]->y + 50 > event.mouseButton.y && event.mouseButton.y > cell[i][j]->y && cell[i][j]->seen == 0)
                {
                    cell[i][j]->seen = 2;
                }
                else if (event.mouseButton.button == sf::Mouse::Left && cell[i][j]->x + 50 > event.mouseButton.x && event.mouseButton.x > cell[i][j]->x && cell[i][j]->y + 50 > event.mouseButton.y && event.mouseButton.y > cell[i][j]->y && cell[i][j]->number==0)
                {
                    for (unsigned int a = std::max(0, cell[i][j]->x / 60 - 1); a < std::min(10, cell[i][j]->x / 60 + 2); ++a) {
                        for (unsigned int b = std::max(0, cell[i][j]->y / 60 - 1); b < std::min(10, cell[i][j]->y / 60 + 2); ++b) {
                            Cell* neighbouring_cell = cell[a][b];
                            neighbouring_cell->seen = 1;
                        }
                    }
                }
            }
        }  
    }
}

void Graphics::GameOver() { //displays "Game Over"
    sf::Text text;
    text.setFont(font);
    text.setString("Game over");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Red);
    text.setPosition(7, 230);
    if (gameOver==true) window->draw(text);
}