#include"Game.h"
#include"SceneManager.h"
/*--------------*/
/*Private Method*/
/*--------------*/


/*-------------*/
/*Public Method*/
/*-------------*/

Game::Game(){
	player = new Player();
	stage = new Stage();
	enemy = new Hopper();

	player->setPos(320, START_POS_Y);
	player->entryStage(stage);
	enemy->entryStage(stage);
}

Game::Game(SceneManager *scmgr) : owner_(scmgr) {
	player = new Player();
	stage = new Stage();
	enemy = new Hopper();

	player->setPos(320, START_POS_Y);
	player->entryStage(stage);
	enemy->entryStage(stage);
}

Game::~Game() {
	delete player;
	delete stage;
}

void Game::Draw() {
	enemy->Draw();
	stage->Draw();
	player->Draw();
}

void Game::Update() {
	enemy->Update();
	player->Update();
}