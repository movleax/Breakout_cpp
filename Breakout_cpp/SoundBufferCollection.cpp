#include "SoundBufferCollection.h"

SoundBufferCollection::SoundBufferCollection()
{
	
}

SoundBufferCollection::~SoundBufferCollection()
{
	unordered_map<string, SoundBuffer*>::iterator it = sounds.begin();

	while (it != sounds.end())
	{
		it = RemoveSound(it);
		it++;
	}
}


void SoundBufferCollection::AddSound(string FileName)
{
	sf::SoundBuffer* buffer = new SoundBuffer();
	if (!buffer->loadFromFile(FileName))
		return;


	if (sounds.find(FileName) == sounds.end())
	{
		return;
	}

	sounds[FileName] = buffer;
}

unordered_map<string, SoundBuffer*>::iterator SoundBufferCollection::RemoveSound(unordered_map<string, SoundBuffer*>::iterator it)
{
	delete it->second;
	return sounds.erase(it);
}


std::unordered_map<string, SoundBuffer*>::iterator SoundBufferCollection::begin()
{
	return sounds.begin();
}

std::unordered_map<string, SoundBuffer*>::iterator SoundBufferCollection::end()
{
	return sounds.end();
}

SoundBuffer* SoundBufferCollection::operator [](string Key)
{
	if (sounds.find(Key) == sounds.end())
	{
		return NULL;
	}

	return sounds[Key];
}
