#include "game.h"
#include <iostream>
void Game::init()
{
	/* basic setup */
	TLN_Init(WIDTH, HEIGHT, MAX_LAYER, 1, 0);
	TLN_SetBGColor(0, 96, 184);
	TLN_SetLoadPath("assets/smw");
	foreground = TLN_LoadTilemap("test.tmx", NULL);
	//background = TLN_LoadTilemap("smw_background.tmx", NULL);
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



	Player cuckie(0, 0, .275f, spriteIndex);
	spriteIndex++;

	/* main loop */
	TLN_CreateWindow(NULL, 0);
	TLN_DisableCRTEffect();
	bool keyflag = false;

		while (TLN_ProcessWindow())
			
		{
			
			TLN_DrawFrame(0);

			if (!cuckie.getWalk()) {
				if (TLN_GetInput(INPUT_LEFT))
				{
					cuckie.setWalk(true);
					cuckie.setDir(CHLEFT, false);
					cuckie.move(cuckie.getDir(), cuckie.getSpeed(), false);

				}
				else if (TLN_GetInput(INPUT_RIGHT))
				{
					cuckie.setWalk(true);
					cuckie.setDir(CHRIGHT, false);
					cuckie.move(cuckie.getDir(), cuckie.getSpeed(), false);
				}
				else if (TLN_GetInput(INPUT_UP))
				{
					cuckie.setWalk(true);
					cuckie.setDir(CHUP, false);
					cuckie.move(cuckie.getDir(), cuckie.getSpeed(), false);
				}
				else if (TLN_GetInput(INPUT_DOWN))
				{
					cuckie.setWalk(true);
					cuckie.setDir(CHDOWN, false);
					cuckie.move(cuckie.getDir(), cuckie.getSpeed(), false);
				}
				else
				{
				}
				cuckie.checkAnimState();
			}

			if (cuckie.getWalk()) {
				int xOffset = cuckie.getX() % aux.GRIDSIZE;
				int yOffset = cuckie.getY() % aux.GRIDSIZE;
				if (cuckie.getX() % aux.GRIDSIZE != 0 || cuckie.getY() % aux.GRIDSIZE != 0) {
					cuckie.move(cuckie.getDir(), cuckie.getSpeed(), false);
				}
				else {
					cuckie.setWalk(false);
				}
			}
			
		}

}


