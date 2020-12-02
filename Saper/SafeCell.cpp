#include "SafeCell.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>

SafeCell::SafeCell() {
    mine = 0;
    seen = 0;
    x = 0;
    y = 0;
    number = 0;
    clickedOnMine = 0;
}

SafeCell::SafeCell(float i, float j) {
    mine = 0;
    seen = 0;
    x = i;
    y = j;
    number = 0;
    clickedOnMine = 0;
}
SafeCell::~SafeCell() {

}

void SafeCell::setMine() {
    mine = 1;
}

void SafeCell::drawCell(sf::RenderWindow& window, float size) {
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

void SafeCell::drawMines(sf::RenderWindow& window, float size) {
    if (mine == 1) {
        sf::RectangleShape R(sf::Vector2f(size, size));
        R.setFillColor(sf::Color::Blue);
        R.setPosition(x + 15, y + 15);
        window.draw(R);
    }
    }

void SafeCell::calculateNumber(SafeCell* ptr[10][10]) {

    for (unsigned int i = std::max(0, x / 60 - 1); i < std::min(10, x / 60 + 2); ++i) {
        for (unsigned int j = std::max(0, y / 60 - 1); j < std::min(10, y / 60 + 2); ++j) {
            if (i == x && j == y)
                continue;
            SafeCell* neighbouring_cell = ptr[i][j];
            if (neighbouring_cell->mine) ++number;
        }
    }
}

void SafeCell::drawNumber(sf::RenderWindow& window, sf::Font& font) {
    sf::Text text;
    text.setFont(font);
    text.setString(std::to_string(number));
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::White);
    text.setPosition(x + 15, y + 15);
    if (number>0)
    window.draw(text);
}

void SafeCell::GameOver(sf::Event& event, sf::RenderWindow& window, sf::Font& font) {
    sf::Text text;
    text.setFont(font);
    text.setString("Game over");
    text.setCharacterSize(100);
    text.setFillColor(sf::Color::Red);
    text.setPosition(7, 230);
    if (clickedOnMine == 1)
    {
        window.draw(text);
    }
    

}

void SafeCell::reveal(sf::Event& event, SafeCell* ptr[10][10], sf::Sound& sound) {
    if (event.type == sf::Event::MouseButtonPressed)
    {
        if (event.mouseButton.button == sf::Mouse::Left && x + 50 > event.mouseButton.x && event.mouseButton.x > x && y + 50 > event.mouseButton.y && event.mouseButton.y > y && mine == 1 && seen == 0)
        {
            seen = 1;
            clickedOnMine = 1;
            sound.play();
        }
        if (event.mouseButton.button == sf::Mouse::Left && x+50>event.mouseButton.x && event.mouseButton.x>x && y+50>event.mouseButton.y && event.mouseButton.y>y && seen == 0 && number > 0)
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

void SafeCell::revealZeros(SafeCell* ptr[10][10]) {
    for (unsigned int i = std::max(0, x / 60 - 1); i < std::min(10, x / 60 + 2); ++i) {
        for (unsigned int j = std::max(0, y / 60 - 1); j < std::min(10, y / 60 + 2); ++j) {
            SafeCell* neighbouring_cell = ptr[i][j];
            neighbouring_cell->seen = 1;
        }
    }
} 