#include "GameProxy.h"
#include "GameState.h"
#include "Moveable.h"


GameState::GameState(const GameProxy* proxy)
{

}
GameState::~GameState()
{

}
void GameState::AddGameObject(GameObject* gameObj)
{
	gameObjects.push_back(gameObj);
}

void GameState::AddInputHandler(Input* input)
{
	this->input = input;
}
void GameState::HandleDeactivatedObjects()
{

}
//void GameState::Draw()
//{
//
//}
void GameState::Draw(RenderWindow* window)
{
	std::vector<GameObject*>::iterator it;

	for (it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		(*it)->Draw(window);
	}
}
void GameState::Logic()
{
	input->HandleInput();
	Update();

}
void GameState::Update()
{
	std::vector<GameObject*>::iterator it;

	for (it = gameObjects.begin(); it != gameObjects.end(); it++)
	{
		Moveable* moveobj =  dynamic_cast<Moveable*> (*it);
		if (moveobj != NULL) 
		{
			moveobj->Update();
		}
	}
}
void GameState::CheckCollisions()
{

}
void GameState::Cycle()
{

}