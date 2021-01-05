#pragma once

#include "player.h"
#include "Menu.h"
#include <stdio.h>
#include <SDL.h>
#include <windows.h>
#include "marker.h"
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

	enum
	{
		LAYER_FOREGROUND,
		LAYER_BACKGROUND,
		MAX_LAYER
	};
	
	TLN_Spriteset spriteset;
	TLN_Tilemap foreground, background;
	int spriteIndex = 0;

	Aux aux;

	SDL_Event event;

	bool isPause = false;
};

