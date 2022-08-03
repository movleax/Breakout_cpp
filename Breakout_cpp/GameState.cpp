#include "GameProxy.h"
#include "GameState.h"
#include "Moveable.h"
#include "Utility_Collisions.h"
#include <unordered_map>

using namespace std;

GameState::GameState(const GameProxy* proxy)
{

}
GameState::~GameState()
{

}
unsigned GameState::AddGameObject(GameObject* gameObj)
{
	return gameObjCollection.AddGameObject(gameObj);
}

void GameState::AddInputHandler(Input* input)
{
	this->input = input;
}
void GameState::HandleDeactivatedObjects()
{
	unordered_map<unsigned, GameObject*>::iterator it = gameObjCollection.begin();

	while (it != gameObjCollection.end())
	{
		if (!it->second->GetIsActive()) 
		{
			it = gameObjCollection.RemoveGameObject(it);
		}
		else
		{
			it++;
		}
	}
}
//void GameState::Draw()
//{
//
//}
void GameState::Draw(RenderWindow* window)
{
	unordered_map<unsigned, GameObject*>::iterator it;

	for (it = gameObjCollection.begin(); it != gameObjCollection.end(); it++)
	{
		it->second->Draw(window);
	}
}
void GameState::Logic()
{
	input->HandleInput();
	Update();
	CheckCollisions();
	HandleDeactivatedObjects();
}
void GameState::Update()
{
	unordered_map<unsigned, GameObject*>::iterator it;

	for (it = gameObjCollection.begin(); it != gameObjCollection.end(); it++)
	{
		/*Moveable* moveobj =  dynamic_cast<Moveable*> (*it);
		if (moveobj != NULL) 
		{
			moveobj->Update();
		}*/

		it->second->Update();
	}
}
void GameState::CheckCollisions()
{
	unordered_map<unsigned, GameObject*>::iterator it_A;
	unordered_map<unsigned, GameObject*>::iterator it_B;

	for (it_A = gameObjCollection.begin(); it_A != gameObjCollection.end(); it_A++)
	{
		Collidable* obj_A = dynamic_cast<Collidable*> (it_A->second);
		
		if (obj_A == NULL)
		{
			continue;
		}

		for ((it_B = it_A)++; it_B != gameObjCollection.end(); it_B++)
		{
			Collidable* obj_B = dynamic_cast<Collidable*> (it_B->second);

			if (obj_B == NULL || obj_A == obj_B)
			{
				continue;
			}

			Shape* A = obj_A->GetShapeObject();
			Shape* B = obj_B->GetShapeObject();

			if (intersects(A, B)) 
			{
				obj_A->HandleCollision(obj_B);
				obj_B->HandleCollision(obj_A);
			}
		}
	}
}
void GameState::Cycle()
{

}