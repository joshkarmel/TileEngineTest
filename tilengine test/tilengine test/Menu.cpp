#include "Menu.h"

Menu::Menu(int index)
	:
	Actor(-128,-128, 0, index)
{
	loadSprite("menu_tileset");
	initSprite();
	initAnims();

	TLN_SetSpritePosition(index, x, y);
}

Menu::~Menu()
{
}

void Menu::toggleMenu(bool pIsPause)
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


void Menu::initAnims()
{
	
}
