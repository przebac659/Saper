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
    Game game;
    game.StartGame();
    return 0;
}
