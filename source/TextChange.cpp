#include <DxLib.h>
#include "TextChange.h"
//#define GREEN 1,120,0,0
//#define RED 1,360,0,0
//#define YELLOW 1,60,0,0

//コンストラクタ
cTextChange::cTextChange()
{
	//テキストの画像の読み込み
	LoadDivGraph("../resource/Image/UI_Text.png", 48, 8, 6, 28, 28, textImg);
	//LoadDivGraph("../Image/UI_Text.png", 48, 8, 6, 28, 28, textImg);
	//for (int i = 0; i < 48; i++)
	//{
	//	GraphFilter(textImg[i], DX_GRAPH_FILTER_HSB, YELLOW);// 1, 120, 0, 0);
	//}

	eColor color;
	
}

/*************************************************************************
　関数: int cTextChange::_Update()
  説明: 文字列から画像の要素数への変換
  引数: (int,int,*text)
戻り値: 無し
*************************************************************************/
int cTextChange::DrawTextImage(int x,int y,const char *text)
{


	//画像の算出処理
	for (int i= 0;i<strlen(text);i++)
	{

			//文字が0～9なら
			if (text[i] >= '0' && text[i] <= '9')
			{
				DrawGraph(x+(i*30), y, textImg[text[i] - '0'], TRUE);
			}
			//文字がA～Zなら
			else if (text[i] >= 'A' && text[i] <= 'Z')
			{
				DrawGraph(x+(i*30), y, textImg[text[i] - 'A'+10], TRUE);
				// +10するのは0～9の番号を含めないようにするため
			}
			//文字が記号なら
			else
			{
				//記号
				//switch case
			}

	}
	return 0;
}