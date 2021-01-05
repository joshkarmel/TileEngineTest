#pragma once

#include "actor.h"

class Menu : Actor
{
public:
	Menu(int index);
	~Menu();
	void toggleMenu(bool pIsPause);

	void initAnims();
private:
	enum selection
	{
		PLAYER,
		MONSTER,
		DEX,
		SAVE,
		OPTION
	};
	
	selection markerSel;
	

	const Vec2 HiddenPos = { -128, -128 };
	const Vec2 VisPos = { 320, 16 };
};