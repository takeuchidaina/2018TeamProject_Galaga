#include <DxLib.h>
#include "Title.h"

//コンストラクタ
cTitle::cTitle()
{
	//画像の読み込みと分割
	LoadDivGraph("../resource/Image/Galaga_OBJ_dualFighter.png", 2, 2, 1, 16, 16, TitleHandle);
	if (TitleHandle == NULL)   //error
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "画像が読み込めませんでした");
		WaitKey();
	}
	TitleIcon = LoadGraph("../resource/Image/Galaga_Title_ult.png");
}

//デストラクタ
cTitle::~cTitle()
{
	//読み込んだ画像の削除
	DeleteGraph(TitleHandle[0]);
	DeleteGraph(TitleHandle[1]);
	DeleteGraph(TitleIcon);
}

int cTitle::Draw()
{
	//タイトルロゴ
	DrawExtendGraph(125, 50, 125 + 666, 50 + 376, TitleIcon, TRUE);

	for (int i = 0; i < 5;i++) 
	{
		//左にあるプレイヤーの画像 
		if (i > 0 && i < 4) {
			DrawExtendGraph(TTextPos[i].x - 50, TTextPos[i].y, TTextPos[i].x - 50 + IMAGEMAG, TTextPos[i].y + IMAGEMAG, TitleHandle[0], TRUE);
		}
		//文字
		cTextChange::Instance()->DrawTextImage(TTextPos[i].x, TTextPos[i].y, TTextPos[i].text,
			TTextPos[i].color, TTextPos[i].mag);
	}


	
	return 0;
}