#include"Stage.h"
#include"Object.h"

Stage::Stage() {
	width = nStageWidth;
	for (int i = 0; i < nHeight ; i++) {
		for (int j = 0; j < width; j++) {
			if (i == 0 || j == 0 || i == nHeight - 1 || j == nStageWidth - 1) {
				Terrain[i][j] = 1;
			}
			else {
				Terrain[i][j] = 0;
			}
		}
	}
	for (int j = 10; j < 20; j++) {
		Terrain[10][j] = 1;
	}
}

bool Stage::Collision(int x,int y) {
	if (x < 0 || y < 0 || x / BaseSize > nStageWidth || y / BaseSize > nStageHeight) {
		return false;
	}

	if (Terrain[y / BaseSize][x / BaseSize] == 1) {
		return true;
	}

	return false;
}

void Stage::Draw() {
	for (int i = 0; i < nHeight; i++) {
		for (int j = 0; j < width; j++) {
			if (Terrain[i][j] == 1) {
				int temp_x = BaseSize * j + 1;
				int temp_y = BaseSize * i + 1;
				//DrawBox(temp_x, temp_y, temp_x + BaseSize - 1, temp_y + BaseSize - 1, LBLUE, false);
				DrawBox(j * BaseSize, i * BaseSize, (j + 1)*BaseSize , (i + 1)*BaseSize ,LBLUE,false);
			}
		}
	}
}

void Stage::Update() {

}