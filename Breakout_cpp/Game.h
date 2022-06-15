#pragma once

#include <SFML/Graphics.hpp>
#include "iGame.h"
#include "GameState.h"

using namespace sf;

class Game : public iGame
{
	GameState* _gameState;
	sf::RenderWindow window;
	
public:
	Game()
		: window(VideoMode(800, 600), "SFML works!")
	{
		// define a starting game state to load
		// _gameState = new MainGame(...);
	}
	~Game()
	{

	}
	void LoadGameState(GameState* gameState)
	{

	}
	void CheckStateChange(GameState* gameState)
	{

	}
	void Draw() override
	{
		// Call _gameState->Draw()
	}
	void Logic() override
	{
		// Call _gameState->Logic()
	}
	void Update() override
	{
		Logic();
		CheckCollisions();
	}
	void CheckCollisions() override
	{
		// Call _gameState->CheckCollisions()
	}
	void Cycle() override
	{
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			Update();

			window.clear();
			Draw();
			window.display();
		}
	}
};


