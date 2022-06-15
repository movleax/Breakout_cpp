#include "Game.h"


Game::Game()
	: window(VideoMode(800, 600), "SFML works!")
{
	// define a starting game state to load
	// _gameState = new MainGame(...);
}
Game::~Game()
{

}
void Game::LoadGameState(GameState* gameState)
{

}
void Game::CheckStateChange(GameState* gameState)
{

}
void Game::Draw() 
{
	// Call _gameState->Draw()
}
void Game::Logic() 
{
	// Call _gameState->Logic()
}
void Game::Update() 
{
	Logic();
	CheckCollisions();
}
void Game::CheckCollisions() 
{
	// Call _gameState->CheckCollisions()
}
void Game::Cycle() 
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