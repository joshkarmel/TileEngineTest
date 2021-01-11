#include "player.h"

Player::Player(float posX, float posY, float pSpeed, int pIndex)
	:
	Actor(posX, posY, pSpeed, pIndex),
	isWalking(false),
	Direction(CHDOWN)
{
	loadSprite("character_tileset_test");
	initSprite();
	initAnims();
}

Player::~Player()
{
}

void Player::initAnims()
{
	WalkingDown = TLN_CreateSpriteSequence(NULL, spriteset, "WalkingDown", aux.DELAY);
	IdleDown = TLN_CreateSpriteSequence(NULL, spriteset, "IdleDown", aux.DELAY);
	WalkingUp = TLN_CreateSpriteSequence(NULL, spriteset, "WalkingUp", aux.DELAY);
	IdleUp = TLN_CreateSpriteSequence(NULL, spriteset, "IdleUp", aux.DELAY);
	WalkingLeft = TLN_CreateSpriteSequence(NULL, spriteset, "WalkingLeft", aux.DELAY);
	IdleLeft = TLN_CreateSpriteSequence(NULL, spriteset, "IdleLeft", aux.DELAY);
	WalkingRight = TLN_CreateSpriteSequence(NULL, spriteset, "WalkingRight", aux.DELAY);
	IdleRight = TLN_CreateSpriteSequence(NULL, spriteset, "IdleRight", aux.DELAY);

	TLN_SetSpriteAnimation(0, IdleDown, 0);
}

void Player::setAnim(animStates animKey)
{
	switch (animKey)
	{
	case IDLE_DOWN:
		TLN_SetSpriteAnimation(0, IdleDown, 0);
		break;
	case IDLE_LEFT:
		TLN_SetSpriteAnimation(0, IdleLeft, 0);
		break;
	case IDLE_RIGHT:
		TLN_SetSpriteAnimation(0, IdleRight, 0);
		break;
	case IDLE_UP:
		TLN_SetSpriteAnimation(0, IdleUp, 0);
		break;
	case WALKING_DOWN:
		TLN_SetSpriteAnimation(0, WalkingDown, 0);
		break;
	case WALKING_LEFT:
		TLN_SetSpriteAnimation(0, WalkingLeft, 0);
		break;
	case WALKING_RIGHT:
		TLN_SetSpriteAnimation(0, WalkingRight, 0);
		break;
	case WALKING_UP:
		TLN_SetSpriteAnimation(0, WalkingUp, 0);
		break;
	default:
		TLN_SetSpriteAnimation(0, IdleDown, 0);
		break;
	}
}

void Player::setWalk(bool pIsWalking)
{
	isWalking = pIsWalking;
}

bool Player::getWalk()
{
	return isWalking;
}

void Player::setDir(charDir pDir)
{
	Direction = pDir;
}

void Player::move(charDir pDir)
{
	Direction = pDir;

	switch (Direction)
	{
	case CHLEFT:

		x -= speed;
		break;
	case CHRIGHT:

		x += speed;
		break;
	case CHUP:
		
		y -= speed;
		break;
	case CHDOWN:
		
		y += speed;
		break;
	default:
		std::cout << "cplayer move default";
		break;
	}
	
	TLN_SetSpritePosition(index, x, y);
}

void Player::setIdle()
{
	setAnim(aux.charDirtoAnim(Direction));
}

charDir Player::getDir()
{
	return Direction;
}

void Player::checkAnimState() 
{
	if (!isWalking) {
		switch (Direction)
		{
		case CHLEFT:
			setAnim(IDLE_LEFT);
			break;
		case CHRIGHT:
			setAnim(IDLE_RIGHT);
			break;
		case CHDOWN:
			setAnim(IDLE_DOWN);
			break;
		case CHUP:
			setAnim(IDLE_UP);
			break;
		default:
			setAnim(IDLE_DOWN);
			break;
		}
	}
	else {
		setAnim(aux.charDirtoAnim(Direction));
	}
}