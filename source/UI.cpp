#include <DxLib.h>
#include "UI.h"
#include "Player.h"

int UIsize;			//画面サイズ
int textImg[48];	//テキストの画像
int iconImg[12];	//ステージアイコンの画像

int UI_Init()
{
	UIsize = 0;

	//画像の読み込み
	LoadDivGraph("../resource/Image/UI_Text.png",48,8,6,28,28,textImg);
	LoadDivGraph("../resource/Image/Galaga_UI_icon.png", 12, 6, 2, 18, 19, iconImg);


	return 0;
}

int UI_Update()
{
	//UIsize = (1280 / 4 * 3) - 50;

	return 0;
}

int UI_Draw()
{
	
	DrawBox(DISP_SIZE,0,DISP_SIZE + UI_SIZE,960,GetColor(125,125,125),TRUE);
	DrawGraph(100, 100, textImg[3],TRUE);
	DrawExtendGraph(200, 100,200+IMAGEMAG,100+IMAGEMAG, iconImg[3], TRUE);
	return 0;
}

int UI_End()
{

	return 0;
}