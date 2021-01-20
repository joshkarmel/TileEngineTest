#include "actor.h"

Actor::Actor(float posX, float posY, float pSpeed, int pIndex)
	:
	x(posX),
	y(posY),
	index(pIndex),
	speed(pSpeed)
{
	
}

Actor::~Actor()
{
}

void Actor::initSprite()
{	
	TLN_SetSpriteSet(index, spriteset);
	TLN_SetSpritePicture(0, 0);
	TLN_SetSpritePosition(index, x, y);
}

void Actor::setPosition(const float pX, const float pY)
{
	x = pX;
	y = pY;
	TLN_SetSpritePosition(index, x, y);
}

void Actor::loadSprite(std::string str)
{
	spriteset = TLN_LoadSpriteset(aux.stringToCharArray(str));
}

int Actor::getIndex()
{
	return index;
}

int Actor::getX() 
{
	return x;
}

int Actor::getY() 
{
	return y;
}


float Actor::getSpeed() 
{
	return speed;
}
