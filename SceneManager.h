#pragma once
#include"Scene.h"
#include"Title.h"
#include"Game.h"


class SceneManager {
	Scene *scene;
	eScene currentScene;
	eScene nextScene;

	void ChangeScene(eScene nextScene);
	void DispState();

public:
	SceneManager() {
		currentScene = TITLE;
		scene = new Title();
	}
	void Draw();
	void Update();
	void Finalize();
	
};