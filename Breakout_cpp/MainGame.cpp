#include "MainGame.h"
#include "GameProxy.h"

#include <stdlib.h>
#include <time.h>

MainGame::MainGame(const GameProxy* proxy)
	: GameState(proxy)
{

	/* initialize random seed: */
	srand(time(NULL));


	//Shape* blah = new CircleShape(10.f);

	shapes.push_back(new CircleShape(rand() % 100 + 10));
	shapes.push_back(new CircleShape(rand() % 100 + 10));
	shapes.push_back(new CircleShape(rand() % 100 + 10));
	shapes.push_back(new CircleShape(rand() % 100 + 10));
	shapes.push_back(new CircleShape(rand() % 100 + 10));
	shapes.push_back(new CircleShape(rand() % 100 + 10));
	shapes.push_back(new CircleShape(rand() % 100 + 10));
	shapes.push_back(new CircleShape(rand() % 100 + 10));


	vector<Shape*>::iterator it;
	for (it = shapes.begin(); it != shapes.end(); it++)
	{
		(*it)->setPosition(Vector2f(rand() % 500 + 1, rand() % 500 + 1));
		(*it)->setFillColor(sf::Color::Green);
	}
}
MainGame::~MainGame()
{

}
void MainGame::StartGame()
{

}
void MainGame::ResetPlayerAndBall()
{

}

void MainGame::Draw() 
{
	throw exception();
}

void MainGame::Draw(RenderWindow* window)
{
	vector<Shape*>::iterator it;

	for (it = shapes.begin(); it != shapes.end(); it++)
	{
		window->draw(**it);
	}
}

void MainGame::Logic() 
{

}
void MainGame::Update() 
{
	//vector<Shape*>::iterator it;

	//for (it = shapes.begin(); it != shapes.end(); it++)
	//{
	//	(*it)->Update();
	//}
}
void MainGame::CheckCollisions() 
{

}
void MainGame::Cycle() 
{

}