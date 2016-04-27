// C++ File for the sprite class
#include "sprite.h"
#include <iostream>

spriteClass::spriteClass()
{
	std::cout << "Sprite Constructor!  " << std::endl;
}

// Method to move player 1's sprite (+ve value passed moves right, -ve value passed moves left)
void spriteClass::spritePlayerRight(int moveRightSpeed)
{
	xCoord = xCoord + moveRightSpeed;
}

void spriteClass::spriteMovement(bool movingRight, bool movingLeft, bool movingUp, bool p2MoveRight, bool p2MoveLeft, SDL_Renderer *ren, SDL_Texture *tex, SDL_Texture *tex2, SDL_Texture *tex3, SDL_Texture *tex4, SDL_Texture *tex5, SDL_Texture *enemyTex, SDL_Texture *player2Tex)
{


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

		// 2nd Floor (Left)
		texture_rect2.x = 150;
		texture_rect2.y = 350;
		texture_rect2.w = 350;
		texture_rect2.h = 40;

		sprite_rect2.x = 0;
		sprite_rect2.y = 10;
		sprite_rect2.w = 70;
		sprite_rect2.h = 70;

		SDL_RenderCopy(ren, tex2, &sprite_rect2, &texture_rect2);

		// 2nd Floor (Left Step 1)
		texture_rect2.x = 500;
		texture_rect2.y = 310;
		texture_rect2.w = 150;
		texture_rect2.h = 40;

		sprite_rect2.x = 0;
		sprite_rect2.y = 10;
		sprite_rect2.w = 70;
		sprite_rect2.h = 70;

		SDL_RenderCopy(ren, tex2, &sprite_rect2, &texture_rect2);

		// 2nd Floor (Left Step 2)
		texture_rect2.x = 650;
		texture_rect2.y = 270;
		texture_rect2.w = 150;
		texture_rect2.h = 40;

		sprite_rect2.x = 0;
		sprite_rect2.y = 10;
		sprite_rect2.w = 70;
		sprite_rect2.h = 70;

		SDL_RenderCopy(ren, tex2, &sprite_rect2, &texture_rect2);

		// 2nd Floor (Left Step 3)
		texture_rect2.x = 800;
		texture_rect2.y = 230;
		texture_rect2.w = 150;
		texture_rect2.h = 40;

		sprite_rect2.x = 0;
		sprite_rect2.y = 10;
		sprite_rect2.w = 70;
		sprite_rect2.h = 70;

		SDL_RenderCopy(ren, tex2, &sprite_rect2, &texture_rect2);

		// 3rd Floor
		texture_rect2.x = 200;
		texture_rect2.y = 200;
		texture_rect2.w = 200;
		texture_rect2.h = 40;

		sprite_rect2.x = 0;
		sprite_rect2.y = 10;
		sprite_rect2.w = 70;
		sprite_rect2.h = 70;

		SDL_RenderCopy(ren, tex2, &sprite_rect2, &texture_rect2);


	}


	// Code relating to the ladders

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
		SDL_Rect texture_rect3a;
		texture_rect3a.x = 600;
		texture_rect3a.y = 430;
		texture_rect3a.w = 40;
		texture_rect3a.h = 250;

		sprite_rect3.x = 0;
		sprite_rect3.y = 10;
		sprite_rect3.w = 70;
		sprite_rect3.h = 70;

		SDL_RenderCopy(ren, tex3, &sprite_rect3, &texture_rect3a);


		// Ladder 3 (Left, Tall)
		SDL_Rect texture_rect3b;
		texture_rect3b.x = 400;
		texture_rect3b.y = 80;
		texture_rect3b.w = 40;
		texture_rect3b.h = 600;

		sprite_rect3.x = 0;
		sprite_rect3.y = 10;
		sprite_rect3.w = 70;
		sprite_rect3.h = 70;

		SDL_RenderCopy(ren, tex3, &sprite_rect3, &texture_rect3b);



	// Code relating to the eggs
	
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

		// Egg 2
		SDL_Rect texture_rectEgg2;
		texture_rectEgg2.x = 1120;
		texture_rectEgg2.y = 630;
		texture_rectEgg2.w = 50;
		texture_rectEgg2.h = 50;

		SDL_RenderCopy(ren, tex4, &sprite_rect4, &texture_rectEgg2);
	


	// Code relating to enemies
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
			spriteFrame2 = 0;
			break;
		}

		SDL_Rect texture_rectEnemy;
		texture_rectEnemy.x = xCoordE1;
		texture_rectEnemy.y = yCoordE1;
		texture_rectEnemy.w = 72;
		texture_rectEnemy.h = 97;


		SDL_Rect sprite_rectEnemy;
		sprite_rectEnemy.x = spriteX;
		sprite_rectEnemy.y = spriteY;
		sprite_rectEnemy.w = 72;
		sprite_rectEnemy.h = 97;

		if (movingRight == true && movingLeft == false)
		{
			// Collision Detection for when the player hits the right wall, followed by left wall detection
			if (xCoord + 72 < 1280)
			{
				SDL_RenderCopy(ren, enemyTex, &sprite_rectEnemy, &texture_rectEnemy);
				spriteFrame2++;
			}
			else
			{
				movingRight = false;
				xCoord = 1280 - 72;
				spriteFrame2 = 1;
				SDL_RenderCopy(ren, enemyTex, &sprite_rectEnemy, &texture_rectEnemy);
			}

		}
		else if (movingLeft == true && movingRight == false)
		{
			if (xCoord > 0)
			{
				SDL_RenderCopy(ren, enemyTex, &sprite_rectEnemy, &texture_rectEnemy);
				spriteFrame2++;
				movingLeft = false;
			}
			else
			{
				movingLeft = false;
				xCoord = 0.1;
				spriteFrame2 = 1;
				SDL_RenderCopy(ren, enemyTex, &sprite_rectEnemy, &texture_rectEnemy);
			}
		}
		else
		{
			// When the player is stood still, display this one sprite
			spriteFrame = 1;
			SDL_RenderCopy(ren, enemyTex, &sprite_rectEnemy, &texture_rectEnemy);
		}
	}


	//Draw the texture (player sprite)
	
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

		if (movingRight == true && movingLeft == false)
		{
			if (xCoord + 72 < 1280)
			{
				SDL_RenderCopy(ren, tex, &sprite_rect, &texture_rect);
				spriteFrame++;
			}
			else
			{
				movingRight = false;
				xCoord = 1280 - 72;
				spriteFrame = 1;
				SDL_RenderCopy(ren, tex, &sprite_rect, &texture_rect);
			}

		}
		else if (movingLeft == true && movingRight == false)
		{
			if (xCoord > 0)
			{
				SDL_RenderCopy(ren, tex, &sprite_rect, &texture_rect);
				spriteFrame++;
				movingLeft = false;
			}
			else
			{
				movingLeft = false;
				xCoord = 0.1;
				spriteFrame = 1;
				SDL_RenderCopy(ren, tex, &sprite_rect, &texture_rect);
			}
		}
		else
		{
			spriteFrame = 1;
			SDL_RenderCopy(ren, tex, &sprite_rect, &texture_rect);
		}

		if (texture_rect.x == texture_rectEgg2.x && texture_rect.y + 45 == texture_rectEgg2.y)
		{
			std::cout << "Score!" << std::endl;
		}
	

		if (texture_rect.x >= texture_rect3.x && texture_rect.x <= texture_rect3.x + 40 && texture_rect.y > texture_rect3.y - 25 && movingUp == true)
		{
			yCoord = yCoord - 5;
		}
		else if (texture_rect.x >= texture_rect3a.x && texture_rect.x <= texture_rect3a.x + 40 && texture_rect.y > texture_rect3a.y - 25 && movingUp == true)
		{
			yCoord = yCoord - 5;
		}
		else if (texture_rect.x >= texture_rect3b.x && texture_rect.x <= texture_rect3b.x + 40 && texture_rect.y > texture_rect3b.y && movingUp == true)
		{
			yCoord = yCoord - 5;
		}


	// Code relating to drawing player 2's sprite
	{
		switch (spriteFrameP2)
		{
		case 0:
			spriteX = 0;
			spriteY = 0;
			break;

		case 1:
			spriteX = 71;
			spriteY = 0;
			break;

		case 2:
			spriteX = 142;
			spriteY = 0;
			break;

		case 3:
			spriteX = 0;
			spriteY = 95;
			break;

		case 4:
			spriteX = 71;
			spriteY = 95;
			break;

		case 5:
			spriteX = 142;
			spriteY = 95;
			break;

		case 6:
			spriteX = 213;
			spriteY = 0;
			break;

		case 7:
			spriteX = 284;
			spriteY = 0;
			break;

		case 8:
			spriteX = 213;
			spriteY = 95;
			break;

		case 9:
			spriteX = 355;
			spriteY = 0;
			break;

		case 10:
			spriteX = 284;
			spriteY = 95;
			spriteFrameP2 = 0;
			break;
		}

		SDL_Rect texture_rectP2;
		texture_rectP2.x = xCoordP2;
		texture_rectP2.y = yCoordP2;
		texture_rectP2.w = 72;
		texture_rectP2.h = 97;


		SDL_Rect sprite_rectP2;
		sprite_rectP2.x = spriteX;
		sprite_rectP2.y = spriteY;
		sprite_rectP2.w = 72;
		sprite_rectP2.h = 97;

		if (p2MoveRight == true && p2MoveLeft == false)
		{
			if (xCoordP2 + 72 < 1280)
			{
				SDL_RenderCopy(ren, player2Tex, &sprite_rectP2, &texture_rectP2);
				spriteFrameP2++;
			}
			else
			{
				p2MoveRight = false;
				xCoordP2 = 1280 - 72;
				spriteFrameP2 = 1;
				SDL_RenderCopy(ren, player2Tex, &sprite_rectP2, &texture_rectP2);
			}

		}
		else if (p2MoveLeft == true && p2MoveRight == false)
		{
			if (xCoordP2 > 0)
			{
				SDL_RenderCopy(ren, player2Tex, &sprite_rectP2, &texture_rectP2);
				spriteFrameP2++;
				p2MoveLeft = false;
			}
			else
			{
				p2MoveLeft = false;
				xCoordP2 = 0.1;
				spriteFrameP2 = 1;
				SDL_RenderCopy(ren, player2Tex, &sprite_rectP2, &texture_rectP2);
			}
		}
		else
		{
			spriteFrameP2 = 1;
			SDL_RenderCopy(ren, player2Tex, &sprite_rectP2, &texture_rectP2);
		}


	}


}

void spriteClass::playerWallCollision()
{

}

// Method to move player 2's sprite (+ve value passed moves right, -ve value passed moves left)
void spriteClass::spritePlayer2Move(int moveRightSpeedP2)
{
	xCoordP2 = xCoordP2 + moveRightSpeedP2;
}

spriteClass::~spriteClass()
{
	std::cout << "Sprite Destructor!" << std::endl;
}