#pragma once
#include "GameText.h"
#include "PlayerProxy.h"

class ScoreText : public GameText
{
	PlayerProxy* playerProxy;
public:
	ScoreText(const Vector2f& Position, PlayerProxy* PlayerProxy);
	~ScoreText();
	void Update() override;
};

