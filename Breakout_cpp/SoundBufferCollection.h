#pragma once

//#include "GameObject.h"
#include <string>
#include <unordered_map>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;

class SoundBufferCollection
{
	unordered_map<string, SoundBuffer*> sounds;
public:
	SoundBufferCollection();
	~SoundBufferCollection();
	void AddSound(string FileName);
	unordered_map<string, SoundBuffer*>::iterator RemoveSound(unordered_map<string, SoundBuffer*>::iterator it);

	unordered_map<string, SoundBuffer*>::iterator begin();
	unordered_map<string, SoundBuffer*>::iterator end();

	SoundBuffer* operator [](string);
};
