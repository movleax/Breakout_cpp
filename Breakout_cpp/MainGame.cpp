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
#include "StartGameCommand.h"
#include "ScoreText.h"
#include "LivesText.h"
#include "StartText.h"

MainGame::MainGame(GameProxy* proxy)
	: GameState(proxy)
{

	/* initialize random seed: */
	srand(time(NULL));

	/*Wall* wall = new Wall(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Green);
	AddGameObject(wall);*/

	Player* player = new Player(Vector2f(250,600));
	//Wall* ptr_Wall = new Wall(Vector2f(200, 200), rand() % 200 + 100, rand() % 200 + 100, Color::Green);
	//Brick* brick = new Brick(Vector2f(rand() % 500 + 1, rand() % 200 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Red);
	/*Paddle* paddle = new Paddle(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Magenta);
	paddle->SetSpeed(.2);
	paddle->SetVelocity(Vector2f(1,0));*/
	PlayerProxy* ptrPlayerProxy = new PlayerProxy(player);
	Ball* ball = new Ball(Vector2f(250, 400), 10, Color::Cyan, ptrPlayerProxy);
	ball->SetSpeed(8);
	ball->SetVelocity(Vector2f(-.25, -.75));

	ScoreText* scoreText = new ScoreText(Vector2f(25,20), ptrPlayerProxy);
	LivesText* livesText = new LivesText(Vector2f(600, 20), ptrPlayerProxy);
	StartText* startText = new StartText(Vector2f(170, 300));
	startText->Show();


	Input* input = new Input();
	MoveLeftCommand* moveLeftCmd = new MoveLeftCommand(player);
	MoveRightCommand* moveRightCmd = new MoveRightCommand(player);
	StopCommand* stopCmd = new StopCommand(player);
	StartGameCommand* startGameCmd = new StartGameCommand(this);
	input->AddCommand(moveLeftCmd);
	input->AddCommand(moveRightCmd);
	input->AddCommand(stopCmd);
	input->AddCommand(startGameCmd);

	//AddGameObject(brick);
	hPlayer = AddGameObject(player);
	hBall = AddGameObject(ball);

	//AddGameObject(ptr_Wall);

	
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				AddGameObject(new Brick(Vector2f(45+j*60,150+i*35), 50, 25, Color::Red));
			}
		}
	

	/*AddGameObject(new Brick(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Red));
	AddGameObject(new Brick(Vector2f(rand() % 500 + 1, rand() % 500 + 1), rand() % 100 + 10, rand() % 100 + 10, Color::Red));
	*/
	AddGameObject(new Wall(Vector2f(0, 100), 10, 600, Color::Green));
	AddGameObject(new Wall(Vector2f(790, 100), 10, 600, Color::Green));
	AddGameObject(new Wall(Vector2f(0, 100), 800, 10, Color::Green));
	//AddGameObject(new Wall(Vector2f(0,690), 800, 10, Color::Green));

	AddGameObject(scoreText);
	AddGameObject(livesText);
	hStartText = AddGameObject(startText);

	
	this->AddInputHandler(input);
}
MainGame::~MainGame()
{

}
void MainGame::StartGame()
{
	gameHasStarted = true;
	StartText* startText = dynamic_cast<StartText*> (gameObjCollection[hStartText]);
	startText->Hide();

	// Make Start Game text toggle off here
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
	if (!gameHasStarted) return;
	GameState::Update();
}
void MainGame::CheckCollisions() 
{
	GameState::CheckCollisions();
	CheckBallOutBounds();
}
void MainGame::CheckBallOutBounds()
{
	Ball* tempBall = dynamic_cast<Ball*>(gameObjCollection[hBall]);
	Player* tempPlayer = dynamic_cast<Player*>(gameObjCollection[hPlayer]);
	Vector2u bounds = gameProxy->GetWindowDimensions();

	if (tempBall->GetPosition().y > bounds.y)
	{
		//remove life
		tempPlayer->DecrementLife();
		//restart game
		Vector2f PlayerPosition = tempPlayer->GetCenter();
		//PlayerPosition.x = tempPlayer->GetCenter();
		PlayerPosition.y -= 150;
		tempBall->UpdatePosition(PlayerPosition);
		tempBall->SetVelocity(Vector2f(0, 1));
		//tempBall->SetSpeed(22);
		gameHasStarted = false;
		// Make Start Game text toggle on here
		StartText* startText = dynamic_cast<StartText*> (gameObjCollection[hStartText]);
		startText->Show();
	}
}

void MainGame::Cycle() 
{

}