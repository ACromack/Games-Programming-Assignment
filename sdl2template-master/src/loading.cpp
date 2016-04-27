// C++ File for the loading screen class
#include "loading.h"
#include <iostream>

loadingClass::loadingClass()
{
	std::cout << "Loading Screen Constructor!  " << std::endl;
}

void loadingClass::loadScreen(SDL_Renderer *ren, SDL_Surface *loadingScreenSurface, SDL_Texture *loadingScreenTexture)
{
	loadingScreenTexture = SDL_CreateTextureFromSurface(ren, loadingScreenSurface);
	SDL_Rect loadMessage_rect;
	loadMessage_rect.x = 0;
	loadMessage_rect.y = 0;
	loadMessage_rect.w = 800;
	loadMessage_rect.h = 200;

	SDL_RenderCopy(ren, loadingScreenTexture, NULL, &loadMessage_rect);
}

loadingClass::~loadingClass()
{
	std::cout << "Loading Screen Destructor!  " << std::endl;
}
