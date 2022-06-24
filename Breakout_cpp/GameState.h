#pragma once

#include "iGame.h"
#include <SFML/Graphics.hpp>
#include "GameObject.h"

using namespace sf;

class GameProxy;

class GameState : public iGame
{
protected:
	GameProxy* gameProxy;
	/*Input* input;*/
	std::vector<GameObject*> gameObjects;
public:
	GameState(const GameProxy* proxy);
	virtual ~GameState();
	void AddGameObject(GameObject* gameObj);
	/*
	void AddInputHandler(Input* input)
	{

	}*/
	void HandleDeactivatedObjects();
	//virtual void Draw() override;
	virtual void Draw(RenderWindow* window);
	virtual void Logic() override;
	virtual void Update() override;
	virtual void CheckCollisions() override;
	virtual void Cycle() override;
};