#pragma once
#include "Player.h"



class PlayerProxy
{
	Player* player;

public:
	PlayerProxy(Player* ptrPlayer);
	~PlayerProxy();
	void DecrementLife();
	unsigned GetLives();
	unsigned GetScore();
	void AddToScore(unsigned points);
	
};