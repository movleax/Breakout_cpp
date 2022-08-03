#pragma once

#include <SFML/Graphics.hpp>
#include "iGame.h"
#include "GameState.h"

using namespace sf;

class Game : public iGame
{
	GameState* _gameState;
	RenderWindow window;

public:
	Game();
	~Game();
	void LoadGameState(GameState* gameState);
	void CheckStateChange(GameState* gameState);
	void Draw();
	void Logic() override;
	void Update() override;
	void CheckCollisions() override;
	void Cycle() override;
	sf::RenderWindow& GetWindowRef();
	Vector2u GetWindowDimensions();
};


