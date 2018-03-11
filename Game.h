#pragma once
#include"Scene.h"
#include"Player.h"
#include"Stage.h"

#define MAX_nObject 20

class Game : public Scene {
	Object *player;
	Stage *stage;
public:
	Game();
	~Game();
	void Draw();
	eScene Update();
};