#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Cell.h"

    class SafeCell :public Cell
    {
    private:
        bool mine;
        //int seen;
        //int x;
        //int y;
        int number;
        bool clickedOnMine;
    public:
        SafeCell();
        SafeCell(float, float);
        ~SafeCell();
        void drawCell(sf::RenderWindow&, float);
        void drawMines(sf::RenderWindow&, float);
        void calculateNumber(SafeCell* ptr[10][10]);
        void drawNumber(sf::RenderWindow&, sf::Font&);
        void setMine();
        void reveal(sf::Event&, SafeCell* ptr[10][10], sf::Sound&);
        void revealZeros(SafeCell* ptr[10][10]);
        void GameOver(sf::Event&, sf::RenderWindow&, sf::Font&);
    };