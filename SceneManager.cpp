#include"SceneManager.h"

void SceneManager::ChangeScene2(eScene nextScene) {
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

void SceneManager::Update2() {
	nextScene =  scene->Update2();
	ChangeScene2(nextScene);
}