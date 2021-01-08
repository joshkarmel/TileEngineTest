#include "game.h"
#include <iostream>
void Game::init()
{
	/* basic setup */
	TLN_Init(WIDTH, HEIGHT, MAX_LAYER, 50, 0);
	TLN_SetBGColor(0, 96, 184);
	TLN_SetLoadPath("assets/smw");
	foreground = TLN_LoadTilemap("test2.tmx", NULL);

	TLN_DefineInputKey(PLAYER1, INPUT_BUTTON5, SDLK_p);
}

bool Game::inputtest()
{
	if (TLN_GetInput(INPUT_LEFT))
	{
		return true;
	}
	else
	{
		return false;
	}
}

Game::Game()
{
	init();
}

Game::~Game()
{
	/* deinit */
	TLN_DeleteTilemap(foreground);
	TLN_DeleteTilemap(background);
	TLN_Deinit();
}


void Game::gameLoop()
{
	/* load resources */
	TLN_SetLayerTilemap(LAYER_FOREGROUND, foreground);
	TLN_SetLayerTilemap(LAYER_BACKGROUND, background);
	TLN_SetLayerPosition(LAYER_FOREGROUND, 0, 48);
	TLN_SetLayerPosition(LAYER_BACKGROUND, 0, 80);

	Player cuckie(0, 0, 0.5f, spriteIndex);
	spriteIndex++;
	Menu menu(spriteIndex);
	spriteIndex++;
	Marker mMarker(spriteIndex);
	spriteIndex++;
	bool downstate = false;
	bool downstateold = false;

	/* main loop */
	TLN_CreateWindow(NULL, 0);
	TLN_DisableCRTEffect();

		while (TLN_ProcessWindow())
		{
			//NOT PAUSED
			if (!isPause)
			{
				if (!cuckie.getWalk())
				{
					
					if (TLN_GetInput(INPUT_LEFT) && leftPressOld == false )
					{
						cuckie.setWalk(true);
						cuckie.setDir(CHLEFT, false);
						cuckie.move(cuckie.getDir(), cuckie.getSpeed(), false);
						leftPress = true;
						
					}
					else if (!TLN_GetInput(INPUT_LEFT) && leftPressOld == true)
					{
						leftPress = false;
					}
					leftPressOld = leftPress;


					if (TLN_GetInput(INPUT_RIGHT) && rightPressOld == false)
					{
						cuckie.setWalk(true);
						cuckie.setDir(CHRIGHT, false);
						cuckie.move(cuckie.getDir(), cuckie.getSpeed(), false);
						rightPress = true;
					}
					else if (!TLN_GetInput(INPUT_RIGHT) && rightPressOld == true)
					{
						rightPress = false;
					}
					rightPressOld = rightPress;

					if (TLN_GetInput(INPUT_UP) && upPressOld == false)
					{
						cuckie.setWalk(true);
						cuckie.setDir(CHUP, false);
						cuckie.move(cuckie.getDir(), cuckie.getSpeed(), false);
						upPress = true;
					}
					else if (!TLN_GetInput(INPUT_UP) && upPressOld == true)
					{
						upPress = false;
					}
					upPressOld = upPress;

					if (TLN_GetInput(INPUT_DOWN) && downPressOld == false)
					{
						cuckie.setWalk(true);
						cuckie.setDir(CHDOWN, false);
						cuckie.move(cuckie.getDir(), cuckie.getSpeed(), false);
						upPress = true;
					}
					else if (!TLN_GetInput(INPUT_DOWN) && downPressOld == true)
					{
						downPress = false;
					}
					downPressOld = downPress;

					cuckie.checkAnimState();
				}

				//OFFSET CODE
				if (cuckie.getWalk()) {
					if (cuckie.getX() % aux.GRIDSIZE != 0 || cuckie.getY() % aux.GRIDSIZE != 0) {
						cuckie.move(cuckie.getDir(), cuckie.getSpeed(), false);
					}
					else {
						cuckie.setWalk(false);
					}
				}
			}//IS PAUSED
			else if (isPause)
			{
					if (TLN_GetInput(INPUT_UP))
					{
						mMarker.moveMarker(true);
					}
					else if (TLN_GetInput(INPUT_DOWN))
					{
						mMarker.moveMarker(false);
					}
			}

			if (TLN_GetInput(INPUT_BUTTON5))
			{
				if (isPause == false)
				{
					isPause = true;
					cuckie.setWalk(false);
					cuckie.checkAnimState();
					menu.toggleMenu(isPause);
					mMarker.toggleVis(isPause);
				}
			}
			if (TLN_GetInput(INPUT_B))
			{
				if (isPause == true)
				{
					isPause = false;
					cuckie.setWalk(true);
					cuckie.checkAnimState();
					menu.toggleMenu(isPause);
					mMarker.toggleVis(isPause);
				}
			}
			TLN_DrawFrame(0);
		}

}


