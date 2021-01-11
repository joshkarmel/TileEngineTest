#pragma once
#include "auxillary.h"
class Map
{
public:
	Map(std::string pName);
	~Map();

	void loadTilemap(std::string str);
private:
	TLN_Tilemap background;
	std::string tilemapName;

	enum
	{
		LAYER_FOREGROUND,
		LAYER_BACKGROUND,
		MAX_LAYER
	};
};

