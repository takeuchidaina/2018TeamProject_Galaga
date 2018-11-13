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
	DrawGraph(100, 100, textImg[5], TRUE);
}