#include "Game.h"
#include "MainGame.h"
#include "GameProxy.h"

int main()
{
    Game game;
    game.LoadGameState(new MainGame(new GameProxy(&game)));
    game.Cycle();

    return 0;
}