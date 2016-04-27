// Header file for the audio class
#pragma once

#include <SDL_mixer.h>

class Audio
{
	private :
		// Music that will be played
		Mix_Music *gMusic = NULL;

		//SFX that will be used
		Mix_Chunk *gScratch = NULL;
		Mix_Chunk *gHigh = NULL;
		Mix_Chunk *gMedium = NULL;
		Mix_Chunk *gLow = NULL;

		
	public: 
		Audio();

		void playSound(Mix_Chunk *playedSound);

		void playMusic(Mix_Music *playedMusic);

		~Audio();


};