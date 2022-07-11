#include "GameProxy.h"
#include "GameState.h"
#include "Moveable.h"
#include "Utility_Collisions.h"

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
	CheckCollisions();
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
	std::vector<GameObject*>::iterator it_A;
	std::vector<GameObject*>::iterator it_B;

	for (it_A = gameObjects.begin(); it_A != gameObjects.end(); it_A++)
	{
		Collidable* obj_A = dynamic_cast<Collidable*> (*it_A);
		
		if (obj_A == NULL)
		{
			continue;
		}

		for (it_B = gameObjects.begin(); it_B != gameObjects.end(); it_B++)
		{
			Collidable* obj_B = dynamic_cast<Collidable*> (*it_B);

			if (obj_B == NULL || obj_A == obj_B)
			{
				continue;
			}

			Shape* A = obj_A->GetShapeObject();
			Shape* B = obj_B->GetShapeObject();

			if (intersects(A, B)) 
			{
				obj_A->HandleCollision(obj_B);
			}
		}
	}
}
void GameState::Cycle()
{

}