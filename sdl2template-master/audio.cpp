// C++ File for the audio class
#include "audio.h"
#include <SDL_mixer.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Audio Class Constructor
Audio::Audio()
{
	std::cout << "Audio Constructor!" << std::endl;

	// Instantiate the audio shizzle

	//gMusic = Mix_LoadMUS("./assets/musicSFX/beat.wav");
	//if (!gMusic)
	//{
	//	printf("Gone done goofed on gMusic");
	//	//ERROR
	//}

	//gHigh = Mix_LoadWAV("./assets/musicSFX/high.wav");
	//if (!gHigh)
	//{
	//	printf("Loading the High wav has failed");
	//	//ERROR
	//}

	//playSound(gHigh);

}

// Audio Class 'playSound' function :: plays a sound effect upon call
void Audio::playSound(Mix_Chunk *playedSound)
{
	Mix_PlayChannel(-1, playedSound, 0);
	printf("Hey, it worked!");
}

// Audio Class 'playMusic' function :: plays music upon call
void Audio::playMusic(Mix_Music *playedMusic)
{
	// Music only plays when there is no music already playing
	if (Mix_PlayingMusic() == 0)
	{
		Mix_PlayMusic(playedMusic, -1);
	}

}

// Audio Class Destructor
Audio::~Audio()
{
	std::cout << "Audio Destructor!" << std::endl;
}