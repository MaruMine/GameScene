#pragma once
#include"Object.h"

#define SPEED_MAX 4

class Player : public Object {
	int vx, vy;
	int prev_y,F;
	bool jumping;
public:
	Player();
	void Input();
	void Draw();
	void Update();
	void setPos(int x,int y);
};