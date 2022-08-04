#pragma once
#include "GameText.h"


class StartText : public GameText
{
	bool isShown;

public:

	StartText(const Vector2f& Position);
	~StartText();
	void Show();
	void Hide();
	void Draw(sf::RenderWindow* window) override;
	void Update() override;
};
