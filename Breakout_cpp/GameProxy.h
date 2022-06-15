#pragma once

#include "GameState.h"
#include "Game.h"

class Game;
class GameState;

class GameProxy
{
	Game* game;

public:
	GameProxy(const Game* game)
	{

	}
	void LoadGameState(GameState* gameState)
	{
		//game->LoadGameState(gameState);
	}
};

