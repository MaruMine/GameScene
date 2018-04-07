#include"SceneManager.h"

/*--------------*/
/*Private Method*/
/*--------------*/

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

SceneManager::SceneManager() {
	scene = new Title(this);
}

SceneManager::~SceneManager() {
	delete scene;
}

void SceneManager::changeScene(Scene *nextScene) {
	delete scene;
	scene = nextScene;
}

void SceneManager::Draw() {
	DispState();
	scene->Draw();
}

void SceneManager::Update() {
	scene->Update();
}

void SceneManager::Finalize() {
	delete scene;
}