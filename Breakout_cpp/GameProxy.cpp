#include "GameProxy.h"
#include "GameState.h"
#include "Game.h"

GameProxy::GameProxy(Game* game)
{
	this->game = game;
}
void GameProxy::LoadGameState(GameState* gameState)
{
	game->LoadGameState(gameState);
}

sf::RenderWindow& GameProxy::GetWindowRef()
{
	return game->GetWindowRef();
}

Vector2u GameProxy::GetWindowDimensions()
{
	return game->GetWindowDimensions();
}