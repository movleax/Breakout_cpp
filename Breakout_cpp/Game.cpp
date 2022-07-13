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
	// Declare and load a font
	sf::Font font;
	font.loadFromFile("arial.ttf");
	// Create a text
	sf::Text text("hello", font);
	text.setCharacterSize(30);
	//text.setStyle(sf::Text::Bold);
	text.setFillColor(sf::Color::Red);

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
		window.draw(text);
		window.display();
	}
}

RenderWindow& Game::GetWindowRef()
{
	return window;
}