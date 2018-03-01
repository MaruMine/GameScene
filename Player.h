#pragma once
#include"Object.h"

class Player : public Object {
protected:
public:
	Player() {
		x = 320, y = 240;
		width = 32;
		height = width;
		color = LBLUE;
	}
	void Draw() {
		DrawBox(x, y, x + 24, y + 16, LBLUE, false);
	}

	void Update() {

	}
};