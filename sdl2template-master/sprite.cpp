// C++ File for the sprite class
#include "sprite.h"
#include <iostream>

spriteClass::spriteClass()
{
	std::cout << "Sprite Constructor!  " << std::endl;

	//Draw the texture

	switch (spriteFrame)
	{
	case 0:
		spriteX = 0;
		spriteY = 0;
		break;

	case 1:
		spriteX = 73;
		spriteY = 0;
		break;

	case 2:
		spriteX = 146;
		spriteY = 0;
		break;

	case 3:
		spriteX = 0;
		spriteY = 98;
		break;

	case 4:
		spriteX = 73;
		spriteY = 98;
		break;

	case 5:
		spriteX = 146;
		spriteY = 98;
		break;

	case 6:
		spriteX = 219;
		spriteY = 0;
		break;

	case 7:
		spriteX = 292;
		spriteY = 0;
		break;

	case 8:
		spriteX = 219;
		spriteY = 98;
		break;

	case 9:
		spriteX = 365;
		spriteY = 0;
		break;

	case 10:
		spriteX = 292;
		spriteY = 98;
		spriteFrame = 0;
		break;
	}

	SDL_Rect texture_rect;
	texture_rect.x = xCoord;
	texture_rect.y = yCoord;
	texture_rect.w = 72;
	texture_rect.h = 97;


	SDL_Rect sprite_rect;
	sprite_rect.x = spriteX;
	sprite_rect.y = spriteY;
	sprite_rect.w = 72;
	sprite_rect.h = 97;

	//SDL_RenderCopy(ren, tex, &sprite_rect, &texture_rect);

	spriteFrame++;


}

spriteClass::~spriteClass()
{
	std::cout << "Sprite Destructor!" << std::endl;
}