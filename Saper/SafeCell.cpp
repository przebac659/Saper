#include "SafeCell.h"

SafeCell::SafeCell() {
    seen = 0;
    x = 0;
    y = 0;
    number = 0;
}

SafeCell::SafeCell(int i, int j) {
    seen = 0;
    x = i;
    y = j;
    number = 0;
}
SafeCell::~SafeCell() {

}

//void SafeCell::setMine() {
//    mine = 1;
//}

void SafeCell::calculateNumber(Cell* ptr[10][10]) {

    for (unsigned int i = std::max(0, x / 60 - 1); i < std::min(10, x / 60 + 2); ++i) {
        for (unsigned int j = std::max(0, y / 60 - 1); j < std::min(10, y / 60 + 2); ++j) {
            if (i == x && j == y)
                continue;
            Cell* neighbouring_cell = ptr[i][j];
            if (dynamic_cast<SafeCell*>(neighbouring_cell)==nullptr) ++number;
        }
    }
}

/*void SafeCell::GameOver(sf::Event& event, sf::RenderWindow& window, sf::Font& font) {
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
    

}*/