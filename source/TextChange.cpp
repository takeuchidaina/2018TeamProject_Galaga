#include <DxLib.h>
#include "TextChange.h"

//コンストラクタ
cTextChange::cTextChange()
{
	//テキストの画像の読み込み
	LoadDivGraph("../resource/Image/UI_Text.png", 48, 8, 6, 28, 28, textImg);

	imgEle[40] = { 0 };
	cnt = 0;
}

/*************************************************************************
　関数: int cTextChange::_Update()
  説明: 文字列から画像の要素数への変換
  引数: (int,int,*text)
戻り値: 無し
*************************************************************************/
int cTextChange::DrawTextImage(int x,int y,const char *text)
{
	
	//DEBUG
	//char text[] = "HIGHSCORE";
	cnt = 0;

	//画像の算出処理
	for (int i= 0;i<strlen(text);i++)
	{
		int tmp = text[i];

			//文字が0～9なら
			if (text[i] >= '0' && text[i] <= '9')
			{
				DrawGraph(x+(i*30), y, textImg[tmp - '0'], TRUE);
			}
			//文字がA～Zなら
			else if (text[i] >= 'A' && text[i] <= 'Z')
			{
				DrawGraph(x+(i*30), y, textImg[tmp - 'A'+10], TRUE);
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