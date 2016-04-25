// Header file for the sprite class
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>


class spriteClass
{
private:
	int spriteFrame = 0;
	int spriteX = 0;
	int spriteY = 0;
	int yCoord = 150;
	int xCoord = 150;

	SDL_Renderer *ren;
	SDL_Texture *tex;


public:
	spriteClass();


	~spriteClass();


};