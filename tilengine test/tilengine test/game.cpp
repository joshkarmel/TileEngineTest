#include "game.h"
#include <iostream>
void Game::init()
{
	/* basic setup */
	TLN_Init(WIDTH, HEIGHT, 2, 50, 0);
	TLN_SetBGColor(0, 96, 184);
	TLN_SetLoadPath("assets/smw");
	//foreground = TLN_LoadTilemap("test2.tmx", NULL);

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
	
	TLN_Deinit();
}


void Game::gameLoop()
{

	Player cuckie(16, 16, 1.0f, spriteIndex);
	spriteIndex++;
	Menu menu(spriteIndex);
	spriteIndex++;
	Marker mMarker(spriteIndex);
	spriteIndex++;


	Map oMap("test2.tmx");

	/* main loop */
	TLN_CreateWindow(NULL, 0);
	TLN_DisableCRTEffect();

		while (TLN_ProcessWindow())
		{
			//NOT PAUSED
			if (!isPause)
			{
					if (TLN_GetInput(INPUT_LEFT) && leftPressOld == false && lockInput == false)
					{
						lockInput = true;
						cuckie.setDir(CHLEFT);
						leftPress = true;
						
					}
					else if (!TLN_GetInput(INPUT_LEFT) && leftPressOld == true)
					{
						leftPress = false;
					}
					leftPressOld = leftPress;
					if (leftPress)
					{
						if (!cuckie.getWalk())
						{
							cuckie.setWalk(true);
							cuckie.move(CHLEFT);
							cuckie.setAnim(WALKING_LEFT);
						}
					}

					if (TLN_GetInput(INPUT_RIGHT) && rightPressOld == false && lockInput == false)
					{
						lockInput = true;
						cuckie.setDir(CHRIGHT);
						rightPress = true;
					}
					else if (!TLN_GetInput(INPUT_RIGHT) && rightPressOld == true)
					{
						rightPress = false;
					}
					rightPressOld = rightPress;
					if (rightPress)
					{
						if (!cuckie.getWalk())
						{
							cuckie.setWalk(true);
							cuckie.move(CHRIGHT);
							cuckie.setAnim(WALKING_RIGHT);
						}
					}


					if (TLN_GetInput(INPUT_UP) && upPressOld == false && lockInput == false)
					{
						lockInput = true;
						cuckie.setDir(CHUP);
						upPress = true;
					}
					else if (!TLN_GetInput(INPUT_UP) && upPressOld == true)
					{
						upPress = false;
					}
					upPressOld = upPress;
					if (upPress)
					{
						if (!cuckie.getWalk())
						{
							cuckie.setWalk(true);
							cuckie.move(CHUP);
						}
					}


					if (TLN_GetInput(INPUT_DOWN) && downPressOld == false && lockInput == false)
					{
						lockInput = true;
						cuckie.setDir(CHDOWN);
						downPress = true;
					}
					else if (!TLN_GetInput(INPUT_DOWN) && downPressOld == true)
					{
						downPress = false;
						cuckie.checkAnimState();
					}
					downPressOld = downPress;
					if (downPress)
					{
						if (!cuckie.getWalk())
						{
							cuckie.setWalk(true);
							cuckie.move(CHDOWN);
						}
					}
					
					std::cout << lockInput;

				//OFFSET CODE
				if (cuckie.getWalk()) {
					if (cuckie.getX() % aux.GRIDSIZE != 0 || cuckie.getY() % aux.GRIDSIZE != 0) {
						cuckie.move(cuckie.getDir());
					}
					else {
						cuckie.setWalk(false);
						if (!leftPress && !rightPress && !upPress && !downPress)
						{
							lockInput = false;
							cuckie.checkAnimState();
						}
						
					}
				}
				
			}//IS PAUSED
			else if (isPause)
			{
			
					if (TLN_GetInput(INPUT_UP) && upPressOld == false)
					{
						mMarker.moveMarker(true);
						upPress = true;
					}
					else if (!TLN_GetInput(INPUT_UP) && upPressOld == true)
					{
						upPress = false;
					}
					upPressOld = upPress;


					if (TLN_GetInput(INPUT_DOWN) && downPressOld == false)
					{
						mMarker.moveMarker(false);
						downPress = true;
					}
					else if (!TLN_GetInput(INPUT_DOWN) && downPressOld == true)
					{
						downPress = false;
					}
					downPressOld = downPress;
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
					lockInput = false;

					upPress = false;
					downPress = false;
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


