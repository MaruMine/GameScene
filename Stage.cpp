#include"Stage.h"
#include"Camera.h"
#include"Object.h"
#include<cassert>

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
	//座標が地形の範囲外にあれば衝突判定をせずにfalseを返す
	bool out_of_range = x <= 0 || y <= 0 || x / BaseSize >= nStageWidth || y / BaseSize >= nStageHeight;
	//assert(!out_of_range);

	if (out_of_range) {
		return false;
	}

	return Terrain[y / BaseSize][x / BaseSize] == 1;
}

void Stage::Draw() {
	for (int i = 0; i < nHeight; i++) {
		for (int j = 0; j < width; j++) {
			if (Terrain[i][j] == 1) {
				int temp_x = BaseSize * j + 1;
				int temp_y = BaseSize * i + 1;
				CameraDraw::Box(j * BaseSize, i * BaseSize, (j + 1)*BaseSize , (i + 1)*BaseSize ,LBLUE,false);
			}
		}
	}
}

void Stage::Update() {

}