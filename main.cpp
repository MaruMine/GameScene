#include<DxLib.h>
#include"SceneManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

	ChangeWindowMode(true);

	if (DxLib_Init() != 0 || SetDrawScreen(DX_SCREEN_BACK) != 0) {
		return -1;
	}
	SceneManager sceneMgr;

	while (ProcessMessage() == 0 && ClearDrawScreen() == 0 &&  CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		sceneMgr.Draw();
		sceneMgr.Update2();

		ScreenFlip();
	}

	sceneMgr.Finalize();

	DxLib_End();

	return 0;
}