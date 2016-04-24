// C++ File for the sprite class
#include "sprite.h"
#include <iostream>

spriteClass::spriteClass()
{
	std::cout << "Sprite Constructor!  " << testValue << std::endl;
}

spriteClass::~spriteClass()
{
	std::cout << "Sprite Destructor!" << std::endl;
}