#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

    class Cell
    {
    private:
        bool mine;
        int seen;
        int x;
        int y;
        int number;
        bool clickedOnMine;
    public:
        Cell();
        Cell(float, float);
        ~Cell();
        void drawCell(sf::RenderWindow&, float);
        void drawMines(sf::RenderWindow&, float);
        void calculateNumber(Cell* ptr[10][10]);
        void drawNumber(sf::RenderWindow&, sf::Font&);
        bool ReturnMine();
        void setMine();
        void reveal(sf::Event&, Cell* ptr[10][10], sf::Sound&);
        void revealZeros(Cell* ptr[10][10]);
        void _revealZeros(Cell* ptr[10][10]);
        void GameOver(sf::Event&, sf::RenderWindow&, sf::Font&);
    };