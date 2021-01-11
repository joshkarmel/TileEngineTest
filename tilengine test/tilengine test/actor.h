#pragma once
#include "auxillary.h"
#include <map>



class Actor
{
public:
	Actor(float posX, float posY, float pSpeed, int pIndex);
	~Actor();

	virtual void initAnims() = 0;

	void initSprite();
	void setPosition(const float pX, const float pY);
	void loadSprite(std::string str);

	int getIndex();
	int getX();
	int getY();
	float getSpeed();
protected:

	int index;
	float x, y;
	float speed;

	Rect hitbox;
	TLN_Spriteset spriteset;
	Aux aux;
	
	
};