#pragma once
#include "Tilengine.h"
#include <string>
#include "auxillary.h"
#include <map>
#include <iostream>

typedef struct
{
	int x1, y1, x2, y2;
}
Rect;

class Actor
{
public:
	Actor(float posX, float posY, float sp, int pIndex);
	Actor();
	~Actor();

	void initSprite();
	//virtual void move(const float pX, const float pY);
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