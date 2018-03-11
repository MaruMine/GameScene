#include"Player.h"

Player::Player(){
	jumping = false;
	vx = 0;
	vy = 0;
	F = 1;
	width = BaseSize;
	height = BaseSize;
	color = LBLUE;
}
void Player::Draw() {
	DrawBox(x, y, x + width, y + height, GREEN, false);
	SetFontSize(16);
	DrawFormatString(0, 0, WHITE, "VY = %d", vy);
	DrawFormatString(0, 16, WHITE, "prev_y = %d,y = %d", prev_y, y);
}

void Player::Update() {
	Input();

	//Vertical
	vy = (y - prev_y) + F;
	if (vy > BaseSize - 1) {
		vy = BaseSize - 1;
	}
	if (vy < -BaseSize + 1) {
		vy = -BaseSize + 1;
	}

	prev_y = y;
	y = y + vy;
	F = 1;
	
	if (stage->Collision(x, y) || stage->Collision(x + width - 1, y)) {
		y = y / BaseSize * BaseSize + BaseSize;
	}

	if (stage->Collision(x, y + height - 1) || stage->Collision(x + width - 1,y + height -1)) {
		vy = 0;
		jumping = false;
		y = y / BaseSize * BaseSize;
	}

	

	//Horizontal
	x = x + vx;
	//LEFT
	if (stage->Collision(x, y) || stage->Collision(x,y + height - 1) ) {
		x = x / BaseSize * BaseSize + BaseSize;
	}
	if (stage->Collision(x + width -1, y) || stage->Collision(x + width - 1,y + height -1)) {
		x = x / BaseSize * BaseSize;
	}

	if (CheckHitKey(KEY_INPUT_Z) && !jumping) {
		F = -20;
		jumping = true;
	}
}

void Player::setPos(int x,int y){
	this->x = x;
	this->y = y;
	prev_y = y;
}

void Player::Input() {
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		vx = SPEED_MAX;
	}
	else if (CheckHitKey(KEY_INPUT_LEFT)) {
		vx = -SPEED_MAX;
	}
	else {
		vx = 0;
	}
}