#include <DxLib.h>
#include "UI.h"

int UIsize;			//画面サイズ
int textImg[48];	//テキストの画像
int iconImg[12];	//ステージアイコンの画像

sTextPos textPos[] = 
{
	{ DISP_SIZE + 50,100,"HIGH SCORE" },
	{ DISP_SIZE + 50,140,"text02" },
	{ DISP_SIZE + 50,180,"text03" },

};

/*************************************************************************
　関数: int UI_Init()
　説明: 初期化処理
　引数: 無し
戻り値: 無し
*************************************************************************/
int UI_Init()
{
	UIsize = 0;

	//画像の読み込み
	//LoadDivGraph("../resource/Image/UI_Text.png",48,8,6,28,28,textImg);
	LoadDivGraph("../resource/Image/Galaga_UI_icon.png", 12, 6, 2, 18, 19, iconImg);

	return 0;
}

/*************************************************************************
　関数: int UI_Update()
  説明: 計算処理
  引数: 無し
戻り値: 無し
*************************************************************************/
int UI_Update()
{
	//文字を割り出すやつ
	//他のcppで作るようにする
	//文字を投げたら文字が返ってくるような
	//シングルトン?で作れとのこと

	return 0;
}

/*************************************************************************
　関数: int UI_Draw()
  説明: 描画処理
  引数: 無し
戻り値: 無し
*************************************************************************/
int UI_Draw()
{
	//UIを表示する灰色の部分の描画
	DrawBox(DISP_SIZE,0,DISP_SIZE + UI_SIZE,960,GetColor(125,125,125),TRUE);

	for(int i=0;i < (sizeof(textPos) / sizeof*(textPos));i++)
	{
		DrawFormatString(textPos[i].x, textPos[i].y, GetColor(0,255,0),"%s", textPos[i].text);
	}

	//DEBUG
	//DrawGraph(100, 100, textImg[3],TRUE);
	DrawExtendGraph(200, 100,200+IMAGEMAG,100+IMAGEMAG, iconImg[3], TRUE);

	return 0;
}

/*************************************************************************
　関数: int UI_End()
  説明: 終了処理
  引数: 無し
戻り値: 無し
*************************************************************************/
int UI_End()
{
	//終了
	return 0;
}