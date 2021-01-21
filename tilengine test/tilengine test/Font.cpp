#include "Font.h"

Font::Font(std::string pTextString)
	:
	textString(pTextString)
{
	//textString = "A";
	createLine(pTextString);
}

Font::~Font()
{
}

void Font::createLine(std::string pLine)
{
	letters.clear();
	textString = pLine;
	
	int tempCount = pLine.length();
	

	for (int i = 0; i < tempCount; i++)
	{
		stringX = 16 * (i + 1);
		letters.push_back(Letter(stringX, 0, i + 10, aux.getLetterAtLoc(textString, i)));
		letters[i].setPosition(stringX, stringY);
		letters[i].createSequence(aux.getLetterAtLoc(textString, i));
	}

	
}
