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



public:
	spriteClass();

	void spriteMovement(bool movingRight, bool movingLeft, SDL_Renderer *ren, SDL_Texture *tex, SDL_Texture *tex2, SDL_Texture *tex3, SDL_Texture *tex4);

	~spriteClass();


};