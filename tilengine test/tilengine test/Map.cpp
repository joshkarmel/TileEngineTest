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
	char* writable = new char[str.size() + 1];
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0'; 
	
	background = TLN_LoadTilemap(writable, NULL);
	
	delete[] writable;

	//TLN_SetLayerTilemap(LAYER_FOREGROUND, foreground);
	TLN_SetLayerTilemap(LAYER_BACKGROUND, background);
	//TLN_SetLayerPosition(LAYER_FOREGROUND, 0, 48);
	TLN_SetLayerPosition(LAYER_BACKGROUND, 0, 80);
}
