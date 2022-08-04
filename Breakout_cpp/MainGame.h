#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <vector>
using namespace std;
using namespace sf;

class MainGame : public GameState
{
	bool gameHasStarted;
	unsigned hStartText;
	unsigned hBall;
	unsigned hPlayer;
public:
	MainGame(GameProxy* proxy);
	~MainGame();
	void StartGame();
	void ResetPlayerAndBall();
	void CheckBallOutBounds();
	//virtual void Draw() override;
	//virtual void Draw(RenderWindow* window) override;
	virtual void Logic() override;
	virtual void Update() override;
	virtual void CheckCollisions() override;
	virtual void Cycle() override;

};


