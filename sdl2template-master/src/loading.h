// Header file for the loading screen class
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


class loadingClass
{
	private:


	public:
		loadingClass();

		void loadScreen(SDL_Renderer *ren, SDL_Surface *loadingScreenSurface, SDL_Texture *loadingScreenTexture);

		~loadingClass();
};