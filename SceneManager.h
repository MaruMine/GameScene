#pragma once
#include"Scene.h"
#include"Title.h"
#include"Game.h"


class SceneManager {
	Scene *scene;
	eScene currentScene;
	eScene nextScene;

	void ChangeScene() {
		switch (currentScene) {
		case TITLE:
			if (CheckHitKey(KEY_INPUT_RETURN)) {
				nextScene = GAME;
			}
			break;
		case GAME:
			if (CheckHitKey(KEY_INPUT_SPACE)) {
				nextScene = TITLE;
			}
			break;
		default:
			nextScene = empty;
			break;
		}

		if (nextScene != empty) {
			delete scene;

			switch (nextScene) {
			case TITLE:
				currentScene = TITLE;
				scene = new Title();
				break;
			case GAME:
				currentScene = GAME;
				scene = new Game();
				break;
			default:
				break;
			}
		}
	}

	void DispState() {
		switch (currentScene) {
		case TITLE:
			DrawString(0, 0, "Title", GREEN);
			break;
		case GAME:
			DrawString(0, 0, "GAME", GREEN);
			break;
		default:
			break;
		}
	}

public:
	SceneManager() {
		currentScene = TITLE;
		scene = new Title();
	}
	void Draw() {
		DispState();
		scene->Draw();
	}
	void Update() {

		//Scene Change
		ChangeScene();
		//Scene Update
		scene->Update();
	}

	void Finalize() {
		delete scene;
	}
	
};