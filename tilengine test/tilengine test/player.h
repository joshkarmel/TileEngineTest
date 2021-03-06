#pragma once
#include "actor.h"

class Player : public Actor
{
public:
	Player(float posX, float posY, float pSpeed, int pIndex);
	~Player();

	void initAnims();
	void setAnim(animStates animKey);
	void setWalk(bool pIsWalking);
	bool getWalk();
	void setDir(charDir pDir);
	void move(charDir pDir);
	void setIdle();
	void checkAnimState();

	charDir getDir();
private:
	TLN_Sequence WalkingDown;
	TLN_Sequence IdleDown;

	TLN_Sequence WalkingLeft;
	TLN_Sequence IdleLeft;

	TLN_Sequence WalkingRight;
	TLN_Sequence IdleRight;

	TLN_Sequence WalkingUp;
	TLN_Sequence IdleUp;

	bool isWalking;

	charDir Direction;
};