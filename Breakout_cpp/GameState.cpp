#include "GameProxy.h"
#include "GameState.h"


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
/*
void GameState::AddInputHandler(Input* input)
{

}*/
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

}
void GameState::Update()
{

}
void GameState::CheckCollisions()
{

}
void GameState::Cycle()
{

}