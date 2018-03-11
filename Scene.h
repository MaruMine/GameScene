#pragma once
#include"Object.h"

enum eScene {
	TITLE,
	GAME,
	empty,
};

 class Scene {
public:
	virtual void Draw() = 0;
	virtual eScene Update() = 0;
};