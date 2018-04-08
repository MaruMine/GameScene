#include"Player.h"
#include"Camera.h"

/*-------------------*/
/*private method     */
/*-------------------*/

void Player::move() {
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


	x = x + vx;
	
	//�����̕�,�V��ɂԂ������Ƃ�
	if (stage->Collision(x, y)) {
		if (vy < 0) {
			y = y / BaseSize * BaseSize + BaseSize;
		}
		if (vx < 0) {
			x = x / BaseSize * BaseSize;
		}
	}
	//�E���̕�,�V��ɂԂ������Ƃ�
	if (stage->Collision(x + width - 1, y)) {
		if (vy < 0) {
			y = y / BaseSize * BaseSize + BaseSize;
		}
		if (vx > 0) {
			x = x / BaseSize * BaseSize;
		}
	}
	//�����̕�,���ɂԂ������Ƃ�
	if (stage->Collision(x, y + height - 1)) {
		if (vy > 0) {
			vy = 0;
			jumping = false;
			y = y / BaseSize * BaseSize;
		}
		if (vx < 0 && stage->Collision(x, y)) {
			x = x / BaseSize * BaseSize + BaseSize;
		}
	}
	//�E���̕�,���ɂԂ������Ƃ�
	if (stage->Collision(x + width - 1, y + height - 1)) {
		if (vy > 0) {
			vy = 0;
			jumping = false;
			y = y / BaseSize * BaseSize;
		}
		if (vx > 0 && stage->Collision(x + width - 1, y)) {
			x = x / BaseSize * BaseSize ;
		}
	}

	//�V��ɂԂ��������ǂ����̔���
	/*if (vx == 0 && stage->Collision(x, y) || stage->Collision(x + width - 1, y)) {
		y = y / BaseSize * BaseSize + BaseSize;
		return;
	}
	//���ɒ����Ă邩�ǂ����̔���
	if (stage->Collision(x, y + height - 1) || stage->Collision(x + width - 1, y + height - 1)) {
		vy = 0;
		jumping = false;
		y = y / BaseSize * BaseSize;
	}
	//�����̕ǂɂԂ����Ă邩�̔���
	if (stage->Collision(x, y) || stage->Collision(x, y + height - 1)) {
		x = x / BaseSize * BaseSize + BaseSize;
	}

	//�E���̕ǂɂԂ����Ă邩�̔���
	if (stage->Collision(x + width - 1, y) || stage->Collision(x + width - 1, y + height - 1)) {
		x = x / BaseSize * BaseSize;
	}*/
	if (CheckHitKey(KEY_INPUT_Z) && !jumping) {
		F = -20;
		jumping = true;
	}
}

void Player::input() {
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

void Player::attack() {

}

/*-------------------*/
/*public method      */
/*-------------------*/


Player::Player(){
	jumping = false;
	vx = 0;
	vy = 0;
	F = 1;
	width = BaseSize;
	height = BaseSize;
}
void Player::Draw() {
	DrawFormatString(0, 0, 0xffffff, "VY = %d", vy);
	CameraDraw::Box(x, y, x + width, y + height, GREEN, false);
}

void Player::Update() {
	input();
	move();
	CameraDraw::setCameraTargetPosition(x, y);
}

void Player::setPos(int x,int y){
	this->x = x;
	this->y = y;
	prev_y = y;
}

