#pragma once
#include"Scene.h"
#include"DxLib.h"

class SceneManager;

class Title : public Scene {
	SceneManager *owner_;
public:
	Title(SceneManager *scmgr);
	Title();

	void Draw();
	void Update();
};