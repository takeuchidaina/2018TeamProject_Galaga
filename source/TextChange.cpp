#include <DxLib.h>
#include "TextChange.h"

cTextChange::cTextChange()
{
	//テキストの画像の読み込み
	LoadDivGraph("../resource/Image/UI_Text.png", 48, 8, 6, 28, 28, textImg);
}

int cTextChange::Update()
{
	//DEBUG
	DrawGraph(100, 100, textImg[5], TRUE);

	return 0;
}