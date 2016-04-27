// C++ File for the sprite class
#include "sprite.h"
#include <iostream>

spriteClass::spriteClass()
{
	std::cout << "Sprite Constructor!  " << std::endl;
}


void spriteClass::spriteMovement(bool movingRight, bool movingLeft, SDL_Renderer *ren, SDL_Texture *tex, SDL_Texture *tex2, SDL_Texture *tex3, SDL_Texture *tex4)
{
	//Draw the texture (player sprite)
	{
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

		if (movingRight == true)
		{
			SDL_RenderCopy(ren, tex, &sprite_rect, &texture_rect);
		}
		else if (movingLeft == true)
		{
			SDL_RenderCopy(ren, tex, &sprite_rect, &texture_rect);
		}

		spriteFrame++;
	}


	// Code relating to the floor sprites
	{
		// Bottom Floor
		SDL_Rect texture_rect2;
		texture_rect2.x = 0;
		texture_rect2.y = 680;
		texture_rect2.w = 1280;
		texture_rect2.h = 40;

		SDL_Rect sprite_rect2;
		sprite_rect2.x = 0;
		sprite_rect2.y = 10;
		sprite_rect2.w = 70;
		sprite_rect2.h = 70;

		SDL_RenderCopy(ren, tex2, &sprite_rect2, &texture_rect2);


		// 1st Floor
		texture_rect2.x = 100;
		texture_rect2.y = 500;
		texture_rect2.w = 1080;
		texture_rect2.h = 40;

		sprite_rect2.x = 0;
		sprite_rect2.y = 10;
		sprite_rect2.w = 70;
		sprite_rect2.h = 70;

		SDL_RenderCopy(ren, tex2, &sprite_rect2, &texture_rect2);


		// 2nd Floor
		texture_rect2.x = 850;
		texture_rect2.y = 350;
		texture_rect2.w = 250;
		texture_rect2.h = 40;

		sprite_rect2.x = 0;
		sprite_rect2.y = 10;
		sprite_rect2.w = 70;
		sprite_rect2.h = 70;

		SDL_RenderCopy(ren, tex2, &sprite_rect2, &texture_rect2);

	}


	// Code relating to the ladders
	{
		// Ladder 1 (Right)
		SDL_Rect texture_rect3;
		texture_rect3.x = 950;
		texture_rect3.y = 430;
		texture_rect3.w = 40;
		texture_rect3.h = 250;

		SDL_Rect sprite_rect3;
		sprite_rect3.x = 0;
		sprite_rect3.y = 10;
		sprite_rect3.w = 70;
		sprite_rect3.h = 70;

		SDL_RenderCopy(ren, tex3, &sprite_rect3, &texture_rect3);


		// Ladder 2 (Middle)
		texture_rect3.x = 600;
		texture_rect3.y = 430;
		texture_rect3.w = 40;
		texture_rect3.h = 250;

		sprite_rect3.x = 0;
		sprite_rect3.y = 10;
		sprite_rect3.w = 70;
		sprite_rect3.h = 70;

		SDL_RenderCopy(ren, tex3, &sprite_rect3, &texture_rect3);


		// Ladder 3 (Left, Tall)
		texture_rect3.x = 400;
		texture_rect3.y = 180;
		texture_rect3.w = 40;
		texture_rect3.h = 500;

		sprite_rect3.x = 0;
		sprite_rect3.y = 10;
		sprite_rect3.w = 70;
		sprite_rect3.h = 70;

		SDL_RenderCopy(ren, tex3, &sprite_rect3, &texture_rect3);

	}


	// Code relating to the eggs
	{
		// Egg 1
		SDL_Rect texture_rect4;
		texture_rect4.x = 1120;
		texture_rect4.y = 450;
		texture_rect4.w = 50;
		texture_rect4.h = 50;

		SDL_Rect sprite_rect4;
		sprite_rect4.x = 0;
		sprite_rect4.y = 10;
		sprite_rect4.w = 70;
		sprite_rect4.h = 70;

		SDL_RenderCopy(ren, tex4, &sprite_rect4, &texture_rect4);
	}
}


spriteClass::~spriteClass()
{
	std::cout << "Sprite Destructor!" << std::endl;
}