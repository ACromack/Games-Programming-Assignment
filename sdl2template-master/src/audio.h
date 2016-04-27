// Header file for the audio class
#pragma once

#include <SDL_mixer.h>

class Audio
{
	private :

		
	public: 
		Audio();

		void playSound(Mix_Chunk *playedSound);

		void playMusic(Mix_Music *playedMusic);

		~Audio();


};