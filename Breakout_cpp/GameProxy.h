#pragma once

#include <SFML/Graphics.hpp>

class Game;
class GameState;

using namespace sf;

class GameProxy
{
	Game* game;

public:
	GameProxy(Game* game);
	void LoadGameState(GameState* gameState);
	sf::RenderWindow& GetWindowRef();
};

