#include"Title.h"
#include"SceneManager.h"
Title::Title() {

}

Title::Title(SceneManager *scmgr) : owner_(scmgr) {

}




/*----------------*/
/*ï`âÊä÷òAÇÃèàóù  */
/*----------------*/

void drawBlock(int x,int y) {
	if (y == 0 || x == 0 || y == nHeight - 1 || x == nWidth - 1) {
		int temp_x = BaseSize * x + 1;
		int temp_y = BaseSize * y + 1;
		DrawBox(temp_x, temp_y, temp_x + BaseSize - 1, temp_y + BaseSize - 1, GREEN, false);
	}
}

void drawBlocks(int y) {
	for (int i = 0; i < nWidth; i++) {
		drawBlock(i, y);
	}
}

void Title::Draw() {
	for (int i = 0; i < nHeight; i++) {
		drawBlocks(i);
	}
}


/*---------------*/
/*çXêV           */
/*               */
void Title::Update() {
	if (CheckHitKey(KEY_INPUT_RETURN)) {
		owner_->changeScene(new Game(owner_));
	}
}