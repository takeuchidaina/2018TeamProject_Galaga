#include "DxLib.h"
#include "Score.h"
#include "TextChange.h"

cScore::cScore() {
	score = 0;
}

void cScore::Draw() {
	//後でフォント付きに変える
	//cTextChange::Instance()->DrawTextImage (1000, 200, "HIGH", eRed, eMag16);
	DrawFormatString(960, 200, GetColor(255, 0, 0), "HIGH");
	DrawFormatString(980, 220, GetColor(255, 0, 0), "SCORE");
	DrawFormatString(960, 240, GetColor(255, 255, 255), "%d",40000);

	DrawFormatString(960, 280, GetColor(255, 0, 0), "1UP");
	DrawFormatString(960, 300, GetColor(255, 255, 255), "%d", score);

}