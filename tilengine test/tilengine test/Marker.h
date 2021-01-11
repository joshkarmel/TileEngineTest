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

	const Vec2 menuPos0 = { 320, 16 };
	const Vec2 menuPos1 = { 320, 32 };
	const Vec2 menuPos2 = { 320, 48 };
	const Vec2 menuPos3 = { 320, 64 };
	const Vec2 menuPos4 = { 320, 80 };
	const Vec2 menuPos5 = { 320, 96 };
};

