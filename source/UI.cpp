#include <DxLib.h>
#include "UI.h"
#include "Player.h"

int UIsize;		//âÊñ ÉTÉCÉY
int textImg[48];
int iconImg[12];

int UI_Init()
{
	UIsize = 0;

	//âÊëúÇÃì«Ç›çûÇ›
	LoadDivGraph("../resource/Image/UI_Text.png",48,8,6,28,28,textImg);
	LoadDivGraph("../resource/Image/Galaga_UI_icon.png", 12, 6, 2, 16, 16, iconImg);


	return 0;
}

int UI_Update()
{
	UIsize = (1280 / 4 * 3) - 50;

	return 0;
}

int UI_Draw()
{
	
	DrawBox(UIsize,0,UIsize + (1280-UIsize),960,GetColor(125,125,125),TRUE);
	DrawGraph(100, 100, textImg[3],TRUE);
	DrawExtendGraph(200, 100,200+IMAGEMAG,100+IMAGEMAG, iconImg[3], TRUE);
	return 0;
}

int UI_End()
{

	return 0;
}