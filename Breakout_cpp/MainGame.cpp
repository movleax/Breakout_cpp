#include "MainGame.h"
#include "GameProxy.h"

#include <stdlib.h>
#include <time.h>

#include "Brick.h"
#include "Wall.h"
//#include "Paddle.h"
#include "Player.h"
#include "Ball.h"
#include "MoveLeftCommand.h"
#include "MoveRightCommand.h"
#include "StopCommand.h"
#include "GameText.h"

MainGame::MainGame(const GameProxy* proxy)
	: GameState(proxy)
{

	/* initialize random seed: */
	srand(time(NULL));

	/*Wall* wall = new Wall(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Green);
	AddGameObject(wall);*/

	Player* player = new Player(Vector2f(250,400));
	//Wall* ptr_Wall = new Wall(Vector2f(200, 200), rand() % 200 + 100, rand() % 200 + 100, Color::Green);
	Brick* brick = new Brick(Vector2f(rand() % 500 + 1, rand() % 200 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Red);
	/*Paddle* paddle = new Paddle(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Magenta);
	paddle->SetSpeed(.2);
	paddle->SetVelocity(Vector2f(1,0));*/
	PlayerProxy* ptrPlayerProxy = new PlayerProxy(player);
	Ball* ball = new Ball(Vector2f(250, 300), 10, Color::Cyan, ptrPlayerProxy);
	ball->SetSpeed(.2);
	ball->SetVelocity(Vector2f(-.25, -.75));

	GameText* ingameText = new GameText(Vector2f(25,25), "here we go", "arial.ttf", false, 55, sf::Color::Magenta);

	Input* input = new Input();
	MoveLeftCommand* moveLeftCmd = new MoveLeftCommand(player);
	MoveRightCommand* moveRightCmd = new MoveRightCommand(player);
	StopCommand* stopCmd = new StopCommand(player);
	input->AddCommand(moveLeftCmd);
	input->AddCommand(moveRightCmd);
	input->AddCommand(stopCmd);

	AddGameObject(brick);
	AddGameObject(player);
	AddGameObject(ball);
	//AddGameObject(ptr_Wall);

	/*AddGameObject(new Brick(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Red));
	AddGameObject(new Brick(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Red));
	*/
	AddGameObject(new Wall(Vector2f(0, 0), 10, 600, Color::Green));
	AddGameObject(new Wall(Vector2f(790, 0), 10, 600, Color::Green));
	AddGameObject(new Wall(Vector2f(0, 0), 800, 10, Color::Green));
	AddGameObject(new Wall(Vector2f(0,590), 800, 10, Color::Green));

	AddGameObject(ingameText);


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
}
void MainGame::CheckCollisions() 
{
	GameState::CheckCollisions();
}
void MainGame::Cycle() 
{

}