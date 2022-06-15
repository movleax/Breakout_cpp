#pragma once

class Game;
class GameState;

class GameProxy
{
	Game* game;

public:
	GameProxy(const Game* game);
	void LoadGameState(GameState* gameState);
};

