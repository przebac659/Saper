#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Cell.h"
#include "SafeCell.h"
#include <random> 
#include "Game.h"

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(590, 590), "name");
    Game game;
    game.StartGame(window);
    return 0;
}
