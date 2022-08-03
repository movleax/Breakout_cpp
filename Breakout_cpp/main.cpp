#include "Game.h"
#include "MainGame.h"
#include "GameProxy.h"

int main()
{
    Game game;
    GameProxy* gameProxy = new GameProxy(&game);
    MainGame* mainGame = new MainGame(gameProxy);

    game.LoadGameState(mainGame);
    game.Cycle();

    return 0;
}