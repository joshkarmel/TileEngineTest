#include "Font.h"

Font::Font(std::string pTextString)
	:
	textString(pTextString)
{
	//textString = "A";
	createLine("AAA");
}

Font::~Font()
{
}

void Font::createLine(std::string pLine)
{
	letters.clear();
	
	int tempCount = pLine.length();
	std::cout << tempCount;

	for (int i = 0; i < tempCount; i++)
	{
		letters.push_back(Letter(16 * i, 0, i + 10, 'A'));
		letters[i].setPosition(stringX + 16, stringY);

		std::cout << letters.size();
	}

	
}
