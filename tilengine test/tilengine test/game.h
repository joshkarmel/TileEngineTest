#pragma once

#include "player.h"
#include "Menu.h"
#include <stdio.h>
#include <SDL.h>
#include <windows.h>
#include "marker.h"
#include "Map.h"
#undef main


class Game
{
public:
	Game();
	~Game();
	
	void gameLoop();
	void init();

private:
	float fgscale;
	float bgscale;
	int bgypos;
	int maxy;
	int scale;
	
	TLN_Spriteset spriteset;
	TLN_Tilemap foreground, background;
	int spriteIndex = 0;

	Aux aux;

	bool isPause = false;

	//input flags
	bool leftPress = false;
	bool leftPressOld = false;

	bool rightPress = false;
	bool rightPressOld = false;

	bool upPress = false;
	bool upPressOld = false;

	bool downPress = false;
	bool downPressOld = false;

	bool lockInput = false;
	bool markerLock = false;
};

