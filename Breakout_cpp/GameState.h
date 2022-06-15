#pragma once

#include "GameProxy.h"
#include "iGame.h"


class GameState : public iGame
{
protected:
	GameProxy* gameProxy;
	/*Input* input;
	std::vector<GameObjects*> gameObjects;*/
public:
	/*GameState(const GameProxy* proxy)
	{

	}*/
	virtual ~GameState()
	{

	}
	/*void AddGameObject(GameObject* gameObj)
	{

	}
	void AddInputHandler(Input* input)
	{

	}*/
	void HandleDeactivatedObjects()
	{

	}
	void Draw() override
	{

	}
	void Logic() override
	{

	}
	void Update() override
	{

	}
	void CheckCollisions() override
	{

	}
	void Cycle() override
	{

	}
};