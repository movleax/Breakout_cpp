#pragma once

#include <SFML/Audio.hpp>
#include "SoundBufferCollection.h"
#include <string>

using namespace std;
using namespace sf;

class SoundPlayer
{
	static SoundBufferCollection* soundBufferCollection;
	static Sound sound;
	SoundPlayer();
public:

	static void AttachSoundCollection(SoundBufferCollection* SoundBufferCollection);
	static void PlaySound(string Key);
};