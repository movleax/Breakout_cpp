#include "MainGame.h"
#include "GameProxy.h"

#include <stdlib.h>
#include <time.h>

#include "Wall.h"
#include "MoveLeftCommand.h"

MainGame::MainGame(const GameProxy* proxy)
	: GameState(proxy)
{

	/* initialize random seed: */
	srand(time(NULL));


	//Shape* blah = new CircleShape(10.f);

	/*shapes.push_back(new CircleShape(rand() % 100 + 10));
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
	}*/

	/*Wall* wall = new Wall(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Green);
	AddGameObject(wall);*/

	Wall* ptr_Wall = new Wall(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Green);

	AddGameObject(ptr_Wall);
	AddGameObject(new Wall(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Green));
	AddGameObject(new Wall(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Green));
	AddGameObject(new Wall(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Green));
	AddGameObject(new Wall(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Green));
	AddGameObject(new Wall(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Green));

	Input* input = new Input();
	MoveLeftCommand* moveLeftCmd = new MoveLeftCommand(ptr_Wall);
	input->AddCommand(moveLeftCmd);

	this->AddInputHandler(input);
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

//void MainGame::Draw() 
//{
//	throw exception();
//}

//void MainGame::Draw(RenderWindow* window)
//{
//	/*vector<Shape*>::iterator it;
//
//	for (it = shapes.begin(); it != shapes.end(); it++)
//	{
//		window->draw(**it);
//	}*/
//}

void MainGame::Logic() 
{
	GameState::Logic();
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