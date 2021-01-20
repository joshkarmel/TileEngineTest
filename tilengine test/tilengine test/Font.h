#pragma once
#include "letter.h"
class Font
{
public:
	Font(std::string pTextString);
	~Font();

	void createLine(std::string pLine);
private:
	
	std::string textString;
	Aux aux;
	std::vector<Letter> letters;

	int stringX = 16;
	int stringY = 16;

};

