#include "Map.h"

Map::Map(std::string pName)
	:
	tilemapName(pName)
{
	loadTilemap(tilemapName);
}

Map::~Map()
{
	TLN_DeleteTilemap(background);
}

void Map::loadTilemap(std::string str)
{
	TLN_SetLoadPath("assets/smw/level");

	background = TLN_LoadTilemap(aux.stringToCharArray(str), NULL);
	
	//TLN_SetLayerTilemap(LAYER_FOREGROUND, foreground);
	TLN_SetLayerTilemap(LAYER_BACKGROUND, background);
	//TLN_SetLayerPosition(LAYER_FOREGROUND, 0, 48);
	TLN_SetLayerPosition(LAYER_BACKGROUND, 0, 80);
}
