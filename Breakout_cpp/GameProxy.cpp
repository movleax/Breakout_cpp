#include "GameProxy.h"
#include "GameState.h"
#include "Game.h"

GameProxy::GameProxy(const Game* game)
{

}
void GameProxy::LoadGameState(GameState* gameState)
{
	game->LoadGameState(gameState);
}