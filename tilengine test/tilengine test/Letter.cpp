#include "Letter.h"

Letter::Letter(float posX, float posY, int pIndex, char pLetter)
	:
	Actor(posX, posY, 0, pIndex),
	letter(pLetter)
{
	loadSprite("font_tileset");
	initSprite();
	initAnims();
	setLetterAnim();
	//TLN_SetSpritePosition(index, 16, 16);
}

Letter::~Letter()
{
}

void Letter::initAnims()
{
	
	letterSprite = TLN_CreateSpriteSequence(NULL, spriteset, "LetterA", aux.DELAY);
	//letterSprite[0] = temp;
}

void Letter::setLetterAnim()
{
	
	TLN_SetSpriteAnimation(index, letterSprite, 0);
}
