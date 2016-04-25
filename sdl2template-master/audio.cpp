// C++ File for the audio class
#include "audio.h"
#include <SDL_mixer.h>

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

//Mix_Music gMusic, Mix_Chunk gScratch, Mix_Chunk gLow, Mix_Chunk gMedium, Mix_Chunk gHigh

Audio::Audio()
{
	std::cout << "Audio Constructor!" << std::endl;

	// Instantiate the audio shizzle

	gMusic = Mix_LoadMUS("./assets/musicSFX/beat.wav");
	if (!gMusic)
	{
		printf("Gone done goofed on gMusic");
		//ERROR
	}

	gHigh = Mix_LoadWAV("./assets/musicSFX/high.wav");
	if (!gHigh)
	{
		printf("Loading the High wav has failed");
		//ERROR
	}

	//playSound(gHigh);

}

void Audio::playSound(Mix_Chunk *playedSound)
{
	Mix_PlayChannel(-1, playedSound, -1);
	printf("Hey, it worked!");
}


Audio::~Audio()
{
	std::cout << "Audio Destructor!" << std::endl;
}