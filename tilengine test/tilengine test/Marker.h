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
	void move();
	int getPixY();
	bool isMoving();

	bool isMarkerMoving = false;
	int markerPos = 0;

private:

	Vec2 HiddenPos{ -128, -128 };
	Vec2 VisPos{ 320,16 };
	TLN_Sequence Default;
	bool moveDir = false;//t=up, f=down
};

