#pragma once
#include"Scene.h"
#include"Object_Header.h"

#define MAX_nObject 20

class SceneManager;

class Game : public Scene {
	Object *player;
	Stage *stage;
	Object *enemy;
	SceneManager *owner_;
public:
	Game(SceneManager *scmgr);
	Game();
	~Game();
	void Draw();
	void Update();
};