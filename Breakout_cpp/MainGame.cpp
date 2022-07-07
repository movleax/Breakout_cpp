#include "MainGame.h"
#include "GameProxy.h"

#include <stdlib.h>
#include <time.h>

#include "Brick.h"
#include "Wall.h"
#include "Paddle.h"
#include "Ball.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"

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
	Brick* brick = new Brick(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Red);
	Paddle* paddle = new Paddle(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Magenta);
	Ball* ball = new Ball(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, Color::Cyan);
	paddle->SetSpeed(.2);
	paddle->SetVelocity(Vector2f(1,0));
	ball->SetSpeed(.2);
	ball->SetVelocity(Vector2f(1, 0));



	AddGameObject(ptr_Wall);
	AddGameObject(brick);
	AddGameObject(paddle);
	AddGameObject(ball);

	AddGameObject(new Brick(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Red));
	AddGameObject(new Brick(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Red));
	AddGameObject(new Wall(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Green));
	AddGameObject(new Wall(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Green));
	AddGameObject(new Wall(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Green));
	AddGameObject(new Wall(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Green));
	AddGameObject(new Wall(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Green));


	Input* input = new Input();
	MoveLeftCommand* moveLeftCmd = new MoveLeftCommand(ptr_Wall);
	MoveRightCommand* moveRightCmd = new MoveRightCommand(brick);
	input->AddCommand(moveLeftCmd);
	input->AddCommand(moveRightCmd);

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
	GameState::Update();
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