#include "SoundPlayer.h"

// Initialize SoundBufferCollection and Sound.
SoundBufferCollection* SoundPlayer::soundBufferCollection = 0;
Sound SoundPlayer::sound;

SoundPlayer::SoundPlayer()
{
	// do nothing
}

void SoundPlayer::AttachSoundCollection(SoundBufferCollection* SoundBufferCollection)
{
	if (soundBufferCollection != NULL)
	{
		delete soundBufferCollection;
	}

	soundBufferCollection = SoundBufferCollection;
}

void SoundPlayer::PlaySound(string Key)
{
	SoundBuffer* soundBuffer = (*soundBufferCollection)[Key];

	if (soundBuffer == NULL)
	{
		return;
	}

	sound.setBuffer(*soundBuffer);
	sound.play();
}