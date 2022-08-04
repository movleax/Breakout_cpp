#pragma once

#include "GameObject.h"

class Command
{
protected:
	void* obj;
public:
	Command(void* obj);
	virtual ~Command();
	virtual void Execute() = 0;
	virtual bool CheckCondition() = 0;
};
