#pragma once

class  iGame
{
public:
	virtual void Draw() = 0;
	virtual void Logic() = 0;
	virtual void Update() = 0;
	virtual void CheckCollisions() = 0;
	virtual void Cycle() = 0;
};
