#pragma once

#include "GameObject.h"

class Command
{
protected:
	GameObject* gameObj;
public:
	Command(GameObject* gameObj);
	virtual ~Command();
	virtual void Execute() = 0;
	virtual bool CheckCondition() = 0;
};
