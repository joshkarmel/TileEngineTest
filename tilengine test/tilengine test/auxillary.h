#pragma once
#include <string>
#include <vector>
#include "Tilengine.h"
#include <iostream>

#define WIDTH	400 //25
#define HEIGHT	240 //15

#define MIN_SCALE	 50
#define MAX_SCALE	200

enum animStates
{
	IDLE_DOWN,
	IDLE_LEFT,
	IDLE_RIGHT,
	IDLE_UP,
	WALKING_DOWN,
	WALKING_LEFT,
	WALKING_RIGHT,
	WALKING_UP
};

enum charDir
{
	CHLEFT,
	CHRIGHT,
	CHUP,
	CHDOWN
};

typedef struct
{
	int x, y;
}
Vec2;

typedef struct
{
	int x1, y1, x2, y2;
}
Rect;

class Aux
{
public:

	animStates charDirtoAnim(charDir pDir)
	{
		switch (pDir)
		{
		case CHLEFT:
			return WALKING_LEFT;
			break;
		case CHRIGHT:
			return WALKING_RIGHT;
			break;
		case CHUP:
			return WALKING_UP;
			break;
		case CHDOWN:
			return WALKING_DOWN;
			break;
		default:
			break;
		}
	}
	char* stringToCharArray(std::string pString)
	{
		char* writable = new char[pString.size() + 1];
		std::copy(pString.begin(), pString.end(), writable);
		writable[pString.size()] = '\0';

		return writable;
		delete[] writable;
	}
	char getLetterAtLoc(std::string pString, uint8_t pLoc)
	{
		char temp = pString[pLoc];
		return temp;
	}
	static int lerp(int x, int x0, int x1, int fx0, int fx1)
	{
		return (fx0)+((fx1)-(fx0)) * ((x)-(x0)) / ((x1)-(x0));
	}


	const int GRIDSIZE = 16;
	const int DELAY = 12;

	const int NSTACK = 99;

};

