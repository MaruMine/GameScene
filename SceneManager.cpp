#include"SceneManager.h"

/*--------------*/
/*Private Method*/
/*--------------*/

void SceneManager::ChangeScene(eScene nextScene) {
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

void SceneManager::DispState() {
	const char *state = "";
	switch (currentScene) {
	case TITLE:
		state = "Title";
		//DrawString(0, 0, "Title", GREEN);
		break;
	case GAME:
		state = "Game Mode";
		//DrawString(0, 0, "GAME", GREEN);
		break;
	default:
		break;
	}
	DrawString(BaseSize, BaseSize, state, GREEN);
}

/*-------------*/
/*Public Method*/
/*-------------*/
void SceneManager::Draw() {
	DispState();
	scene->Draw();
}

void SceneManager::Update() {
	nextScene =  scene->Update();
	ChangeScene(nextScene);
}

void SceneManager::Finalize() {
	delete scene;
}