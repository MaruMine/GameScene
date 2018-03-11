#include"Game.h"
/*--------------*/
/*Private Method*/
/*--------------*/


/*-------------*/
/*Public Method*/
/*-------------*/

Game::Game() {
	player = new Player();
	stage = new Stage();

	player->setPos(320, 32);
	player->entryStage(stage);
}

Game::~Game() {
	delete player;
	delete stage;
}

void Game::Draw() {
	stage->Draw();
	player->Draw();
}

eScene Game::Update() {

	player->Update();

	return empty;
}