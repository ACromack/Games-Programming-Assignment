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


	//gHigh = Mix_LoadWAV("./assets/musicSFX/high.wav");
	//if (!gHigh)
	//{
	//	printf("Loadig the High wav has failed");
	//	//ERROR
	//}
}

//void playSound(Mix_Chunk soundUsed);


Audio::~Audio()
{
	std::cout << "Audio Destructor!" << std::endl;
}