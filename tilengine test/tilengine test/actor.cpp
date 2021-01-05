#include "actor.h"

Actor::Actor(float posX, float posY, float sp, int pIndex)
	:
	x(posX),
	y(posY),
	index(pIndex),
	speed(sp)
{
	
}

Actor::Actor()
{
}

Actor::~Actor()
{
}

void Actor::initSprite()
{
	
	TLN_SetSpriteSet(0, spriteset);
	TLN_SetSpritePicture(0, 0);
	TLN_SetSpritePosition(0, x, y);

	
}

/*void Actor::move(const float pX, const float pY)
{
	x = x + pX;
	y += pY;
	TLN_SetSpritePosition(index, x, y);
}*/

void Actor::setPosition(const float pX, const float pY)
{
	
}

void Actor::loadSprite(std::string str)
{
	char* writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0'; // don't forget the terminating 0

	spriteset = TLN_LoadSpriteset(writable);
	delete[] writable;
}

int Actor::getIndex()
{
	return index;
}

int Actor::getX() {
	return x;
}

int Actor::getY() {
	return y;
}


float Actor::getSpeed() {
	return speed;
}

