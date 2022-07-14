#pragma once
#include "GameObject.h"
#include <string.h>

using namespace std;

class GameText : public GameObject
{
	sf::Font font;
protected:
	sf::Text* text;
public:
	GameText(const Vector2f& Position, string Text, string fontFileName, bool Bold, unsigned Size, sf::Color color);
	~GameText();
	Vector2f GetCenter();
	void Draw(sf::RenderWindow* window);
};

