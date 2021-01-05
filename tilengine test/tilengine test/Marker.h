#pragma once
#include "actor.h"
class Marker : public Actor
{
public:
	Marker(int index);
	~Marker();

	void toggleVis(bool pIsPause);
	void moveMarker(bool pUp);
	void initAnims();
private:

	Vec2 HiddenPos{ -128, -128 };
	Vec2 VisPos{ 300,20 };
	int8_t markerPos = 0;
	TLN_Sequence Default;
	

};

