#pragma once
#include"Scene.h"
#include"Title.h"
#include"Game.h"


class SceneManager {
	Scene *scene;
	eScene currentScene;
	eScene nextScene;
	void DispState();
public:
	SceneManager();
	~SceneManager();

	void changeScene(Scene *nextScene);
	void Draw();
	void Update();
	void Finalize();
	
};