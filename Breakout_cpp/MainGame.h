#pragma once

#include "GameState.h"

class MainGame : public GameState
{
	bool gameHasStarted;
public:
	MainGame(const GameProxy* proxy);
	~MainGame();
	void StartGame();
	void ResetPlayerAndBall();
};


