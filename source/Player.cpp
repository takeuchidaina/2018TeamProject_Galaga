#include <DxLib.h>
#include "Player.h"
#include "Interface.h"
#include "InGameMgr.h"



//コンストラクタ
cPlayer::cPlayer()
{

	player[0].x = 100;
	player[0].y = 400;
	isLRflg = 0;	
	isDoubleFlg = 0;
	
	LoadDivGraph("../resource/Image/Galaga_OBJ_dualFighter.png", 2, 2, 1, 16, 16, image);
	if (image == NULL)
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "画像が読み込めませんでした");
		WaitKey();
	}

}

//デストラクタ
cPlayer::~cPlayer()
{

}

/*************************************************************************
  関数: int cPlayer::Update()
  説明: 移動処理
  引数: 無し
戻り値: 無し
*************************************************************************/
int cPlayer::Update()
{

	Interface.Update();

	// 右
	if (Interface.Get_Input(InRIGHT) != 0)
	{
		isLRflg = 1;
	}
	//　左
	else if (Interface.Get_Input(InLEFT) != 0)
	{
		isLRflg = -1;
	}
	else
	{
		isLRflg = 0;
	}

//#ifndef _DEBUG

	if (Interface.Get_Input(InDEBUG) != 0)
	{
		isDoubleFlg = true;
	}

//#endif 


	//フラグの値が1か-1なので向きが変わる
	player[0].x += (SPEED * isLRflg);

	return 0;
}

/*************************************************************************
  関数: int cPlayer::Draw()
  説明: 描画処理
  引数: 無し
戻り値: 無し
*************************************************************************/
int cPlayer::Draw()
{

	if (isDoubleFlg == 0)
	{
		DrawExtendGraph(player[0].x, player[0].y, player[0].x+32, player[0].y+32, image[0], TRUE);
	}
	else
	{
		DrawExtendGraph(player[0].x, player[0].y, player[0].x + IMAGEMAG, player[0].y + IMAGEMAG, image[0], TRUE);
		DrawExtendGraph(player[0].x + IMAGEMAG , player[0].y, player[0].x + IMAGEMAG*2, player[0].y + IMAGEMAG, image[0], TRUE);
	}

#ifndef _DEBUG

	DrawFormatString(200, 420, GetColor(255, 0, 0), "flg:%d", isLRflg);
	DrawFormatString(200, 440, GetColor(255, 0, 0), "x:%4.2lf", player[0].x);
	DrawFormatString(200, 460, GetColor(255, 0, 0), "y:%4.2lf", player[0].y);

#endif 



	return 0;
}

/*************************************************************************
  関数: int cPlayer::Double()
  説明: 二機の処理
  引数: 無し
戻り値: 無し
*************************************************************************/
int cPlayer::Double()
{
	//画像の表示が変わる
	isDoubleFlg = true;

	return 0;
}

/*************************************************************************
  関数: int cPlayer::Break()
  説明: 死亡処理 (引数で死亡かトラクタービームかを判断)
  引数: int
戻り値: 無し
*************************************************************************/
int cPlayer::Break(int judgeBreak)
{
	if (judgeBreak == eDeath)
	{
		//死亡処理
	}

	if (judgeBreak == eTractorBeam)
	{
		//トラクタービームに攫われる処理
	}

	return 0;
}

