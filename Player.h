#pragma once
#include"Object.h"

#define SPEED_MAX 4
#define START_POS_Y 13 * 32

class Player : public Object {
	int vx, vy;
	int prev_y,F;
	bool jumping;
//private ä÷êî
	void move();
	void input();
	void attack();
public:
	Player();
	void Draw();
	void Update();
	void setPos(int x,int y);
};