#include <DxLib.h>
#include "TextChange.h"
#include "UI.h"

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
  引数: 
戻り値: 
*************************************************************************/
int cTextChange::Update()
{

	//DEBUG
	char text[] = "HIGHSCORE";
	cnt = 0;

	//画像の算出処理
	for (int i= 0;i<strlen(text);i++)
	{
		int tmp = text[i];

			//文字が0～9なら
			if (text[i] >= '0' && text[i] <= '9')
			{
				//DrawGraph(100, 100, textImg[tmp - '0'], TRUE);
				imgEle[cnt] = (tmp - '0');
				cnt++;
			}
			//文字がA～Zなら
			else if (text[i] >= 'A' && text[i] <= 'Z')
			{
				//DrawGraph(120, 100, textImg[tmp - 'A'+10], TRUE);
				imgEle[cnt] = (tmp - 'A'+10);
				cnt++;
				// +10するのは0～9の番号を含めないようにするため
			}
			//文字が記号なら
			else
			{
				//記号
				//switch case
			}

	}
	//cnt = 1;
	return 0;
}

/*************************************************************************
 関数: void cTextChange::_Update()
 説明: デバッグ用？もしくは表示もするかも(?)
 引数: 
 戻り値: 無し
 *************************************************************************/
void cTextChange::Draw()
{

	//DEBUG	
	for (int i = 0;i<cnt; i++)
	{
		DrawGraph(DISP_SIZE + 50 +(i*30), 100, textImg[imgEle[i]], TRUE);
		
	}
	DrawFormatString(150, 150, GetColor(0, 255, 122), "cnt:%d", cnt);
	//DrawGraph(100 , 100, textImg[imgEle[0]], TRUE);
	//DrawGraph(120 , 100, textImg[imgEle[1]], TRUE);
}

/*_DEBUG.memo
	カウントは2なのでfor文は2回しか回っていないはずなのに
	横に伸びていく

	iをkにしてもダメ
	iをfor文の中で定義しなくても関係なし

	for文じゃないなら二文字だけ出力可能

*/