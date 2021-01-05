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
	if (pUp == true && markerPos > 0)
	{
		markerPos--;
		setPosition(x, y - 16);
	}
	if (pUp == false && markerPos < 5)
	{
		markerPos++;
		setPosition(x, y + 16);
	}
}

void Marker::initAnims()
{
	Default = TLN_CreateSpriteSequence(NULL, spriteset, "Default", aux.DELAY);
}
