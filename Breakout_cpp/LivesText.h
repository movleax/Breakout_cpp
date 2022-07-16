#pragma once
#include "GameText.h"
#include "PlayerProxy.h"

class LivesText : public GameText
{
	PlayerProxy* playerProxy;
public:
	
	LivesText(const Vector2f& Position, PlayerProxy* PlayerProxy);
	~LivesText();
	void Update() override;
};

