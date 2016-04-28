// Header file for the sprite class
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <cstdlib>
#include "audio.h"


class spriteClass
{
private:
	int spriteFrame = 0;
	int spriteFrame2 = 0;
	int spriteFrameP2 = 0;
	int spriteX = 0;
	int spriteY = 0;
	int yCoord = 585;
	int xCoord = 450;
	int yCoordE1 = 405;
	int xCoordE1 = 150;
	int yCoordP2 = 585;
	int xCoordP2 = 550;
	int p1ScoreValue = 0;
	int p2ScoreValue = 0;
	bool enemyRight = true;
	bool egg1Done = false;
	bool egg2Done = false;
	bool egg3Done = false;
	bool egg4Done = false;

	Audio soundFX;


public:
	spriteClass();

	void spriteMovement(bool movingRight, bool movingLeft, bool movingUp, bool movingDown, bool p2MoveRight, bool p2MoveLeft, bool p2MoveUp, bool p2MoveDown, SDL_Renderer *ren, SDL_Texture *tex, SDL_Texture *tex2, SDL_Texture *tex3, SDL_Texture *tex4, SDL_Texture *tex5, SDL_Texture *enemyTex, SDL_Texture *player2Tex, Mix_Chunk *playSFX);

	void spritePlayerRight(int moveRightSpeed);

	void spritePlayer2Move(int moveRightSpeedP2);

	int player1ScoreChange();

	int player2ScoreChange();

	~spriteClass();


};