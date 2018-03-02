#pragma once
#include"Object.h"

#define SPEED_MAX 5

class Player : public Object {
protected:
	int vx, vy;
public:
	Player() {
		vx = 1;
		x = 320, y = 240;
		width = BaseSize;
		height = BaseSize;
		color = LBLUE;
	}
	void Draw() {
		DrawBox(x, y, x + width, y + height, LBLUE, false);
	}

	void Update() {
		x = x + vx;
	}
};