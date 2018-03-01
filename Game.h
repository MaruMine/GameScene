#pragma once
#include"Scene.h"

class Game : public Scene {
public:
	void Draw() {
		for (int i = 0; i < nHeight; i++) {
			for (int j = 0; j < nWidth; j++) {
				if (i == 0 || j == 0 || i == nHeight - 1 || j == nWidth - 1) {
					int temp_x = BaseSize * j + 1;
					int temp_y = BaseSize * i + 1;
					DrawBox(temp_x, temp_y, temp_x + BaseSize - 1, temp_y + BaseSize - 1, LBLUE, false);
				}
			}
		}
	}
	void Update() {

	}
};