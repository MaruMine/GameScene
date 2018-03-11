#pragma once
//StageConfig
#define nStageWidth 100
#define nStageHeight 15
#define DeadLine 500

class Stage {
	int Terrain[nStageHeight][nStageWidth];
	int width, height;
public:
	Stage();
	bool Collision(int x,int y);
	void Draw();
	void Update();
};