#pragma once
#include"DxLib.h"
#include"Stage.h"

//Object Config
#define BaseSize 32
#define nWidth 20
#define nHeight 15

//Color Pattern
#define WHITE GetColor(255,255,255)
#define RED GetColor(255,0,0)
#define BLUE GetColor(0,0,255)
#define GREEN GetColor(0,255,0)
#define LBLUE GetColor(0,255,255)

class Object {
protected:
	int x, y;
	int width, height;
	int color;
	Stage *stage;
public:
	virtual void Draw() {
		DrawBox(x, y, x + width, y + height, color, false);
	}
	virtual void Update() = 0;
	virtual void setPos(int x, int y) {
		this->x = x;
		this->y = y;
	}
	virtual void entryStage(Stage *s) {
		this->stage = s;
	}
};