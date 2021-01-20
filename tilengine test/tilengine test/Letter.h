#pragma once
#include "actor.h"
class Letter : public Actor
{
public:
	Letter(float posX, float posY, int pIndex, char pLetter);
	~Letter();

	void initAnims();
	void setLetterAnim();
private:
	char letter;

	TLN_Sequence letterSprite;

	
};

