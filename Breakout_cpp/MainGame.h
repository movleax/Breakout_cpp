#pragma once

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include <vector>
using namespace std;
using namespace sf;

class MainGame : public GameState
{
	bool gameHasStarted;
	//vector<Shape*> shapes; // temporary for testing
public:
	MainGame(const GameProxy* proxy);
	~MainGame();
	void StartGame();
	void ResetPlayerAndBall();
	//virtual void Draw() override;
	//virtual void Draw(RenderWindow* window) override;
	virtual void Logic() override;
	virtual void Update() override;
	virtual void CheckCollisions() override;
	virtual void Cycle() override;
};


