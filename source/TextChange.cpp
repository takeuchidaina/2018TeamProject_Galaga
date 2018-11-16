#include <DxLib.h>
#include "TextChange.h"

//コンストラクタ
cTextChange::cTextChange()
{
	//テキストの画像の読み込み
	LoadDivGraph("../resource/Image/UI_Text.png", 48, 8, 6, 28, 28, textImg);


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
	char text[256] = "1H";

	//画像の算出処理
	for (int i= 0;i<strlen(text);i++)
	{
		int tmp = text[i];

		//文字列の中身が0～9なら
		if (text[i] >= '0' && text[i] <= '9')
		{
			DrawGraph(100, 100, textImg[tmp - '0'], TRUE);
		}
		else if (text[i] >= 'A' && text[i] <= 'Z')
		{
			DrawGraph(120, 100, textImg[tmp - 'A'+10], TRUE);
			// +10するのは0～9の番号を含めないようにするため
		}
		else
		{
			//記号
			//switch case
		}
	}

	return 0;
}

/*************************************************************************
 関数: int cTextChange::_Update()
 説明: デバッグ用？もしくは表示もするかも(?)
 引数: 
 戻り値: 無し
 *************************************************************************/
void cTextChange::Draw()
{

	//DEBUG
	//DrawGraph(100, 100, textImg[5], TRUE);
}