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
	_gameState = gameState;
}
void Game::CheckStateChange(GameState* gameState)
{

}
void Game::Draw() 
{
	// Call _gameState->Draw()
	_gameState->Draw(&window);
}
void Game::Logic() 
{
	_gameState->Logic();
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
			if (event.type == sf::Event::KeyPressed) {
				int nop = 0;
			}
		}

		Update();

		window.clear();
		Draw();
		window.display();
	}
}

RenderWindow& Game::GetWindowRef()
{
	return window;
}