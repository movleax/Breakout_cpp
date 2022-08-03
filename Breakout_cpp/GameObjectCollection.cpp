#include "GameObjectCollection.h"

GameObjectCollection::GameObjectCollection()
{
	currentHandle = 0;
}

GameObjectCollection::~GameObjectCollection()
{
	std::unordered_map<unsigned, GameObject*>::iterator it = gameObjects.begin();

	while (it != gameObjects.end())
	{
		it = RemoveGameObject(it);
		it++;
	}
}


unsigned GameObjectCollection::AddGameObject(GameObject* gameObj)
{
	for (unsigned i=0; gameObjects.find(currentHandle) != gameObjects.end() && i < UINT_MAX - 1; i++)
	{
		currentHandle = (currentHandle+1) % UINT_MAX;
	}

	unsigned returnHandle = currentHandle;

	gameObjects[currentHandle] = gameObj;

	currentHandle = (currentHandle + 1) % UINT_MAX;

	return returnHandle;
}

std::unordered_map<unsigned, GameObject*>::iterator GameObjectCollection::RemoveGameObject(std::unordered_map<unsigned, GameObject*>::iterator it)
{
	delete it->second;
	return gameObjects.erase(it);
}


std::unordered_map<unsigned, GameObject*>::iterator GameObjectCollection::begin()
{
	return gameObjects.begin();
}

std::unordered_map<unsigned, GameObject*>::iterator GameObjectCollection::end()
{
	return gameObjects.end();
}

GameObject* GameObjectCollection::operator [](unsigned objKey)
{
	return gameObjects[objKey];
}
