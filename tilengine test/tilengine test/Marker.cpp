#include "Marker.h"

Marker::Marker(int index)
	:
	Actor(-128, -128, 0 , index)
{
	loadSprite("menu_box_tileset");
	initSprite();
	initAnims();
	TLN_SetSpritePosition(index, HiddenPos.x, HiddenPos.y);
}

Marker::~Marker()
{
}

void Marker::toggleVis(bool pIsPause)
{
	switch (pIsPause)
	{
	case true:
		setPosition(VisPos.x, VisPos.y);
		break;
	case false:
		setPosition(HiddenPos.x, HiddenPos.y);
		break;
	}
}

void Marker::moveMarker(bool pUp)
{
	moveDir = pUp;
	isMarkerMoving = true;

	if (moveDir && markerPos >= 0) {
		markerPos--;
	}
	else if(!moveDir && markerPos < 5)
	{
		markerPos++;
	}

	switch (markerPos) {
		case 0:
			setPosition(menuPos0.x, menuPos0.y);
			break;
		case 1:
			setPosition(menuPos1.x, menuPos1.y);
			break;
		case 2:
			setPosition(menuPos2.x, menuPos2.y);
			break;
		case 3:
			setPosition(menuPos3.x, menuPos3.y);
			break;
		case 4:
			setPosition(menuPos4.x, menuPos4.y);
			break;
		case 5:
			setPosition(menuPos5.x, menuPos5.y);
		default:
			break;
	}
}

void Marker::move() 
{
	if (moveDir && markerPos >= 0)
	{
		setPosition(x, y - 1);
	}
	else if (!moveDir && markerPos < 5)
	{
		setPosition(x, y + 1);
	}
}

void Marker::initAnims()
{
	Default = TLN_CreateSpriteSequence(NULL, spriteset, "Default", aux.DELAY);
}

int Marker::getPixY() {
	return y;
}

bool Marker::isMoving() {
	return isMarkerMoving;
}
