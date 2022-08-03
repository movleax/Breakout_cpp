#pragma once

#include "GameObject.h"
#include <unordered_map>

class GameObjectCollection
{
	std::unordered_map<unsigned, GameObject*> gameObjects;
	unsigned currentHandle;
public:
	GameObjectCollection();
	~GameObjectCollection();
	unsigned AddGameObject(GameObject* gameObj);
	std::unordered_map<unsigned, GameObject*>::iterator RemoveGameObject(std::unordered_map<unsigned, GameObject*>::iterator it);

	std::unordered_map<unsigned, GameObject*>::iterator begin();
	std::unordered_map<unsigned, GameObject*>::iterator end();

	GameObject* operator [](unsigned);
};