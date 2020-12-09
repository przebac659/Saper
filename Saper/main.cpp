#include "Cell.h"
#include "SafeCell.h"
#include "Game.h"

int main()
{
    Game* game;
    game = new Game();
    game->StartGame();
    delete game;
    return 0;
}
