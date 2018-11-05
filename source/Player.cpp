#include <DxLib.h>
#include "Player.h"
#include "Interface.h"
#include "InGameMgr.h"

#define SPEED 3

//コンストラクタ
cPlayer::cPlayer()
{
	
	player[0].x = 100;
	player[0].y = 400;
	isLRflg = 0;	
	/*
	LoadDivGraph("resource/Image/Galaga_OBJ_myMachine.png", 12, 4, 3, 19, 19, image);
	if (image == NULL)
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "画像が読み込めませんでした");
		WaitKey();
	}
	*/

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
	//四角(プレイヤーの代わり)
	DrawBox(player[0].x, player[0].y, player[0].x + 18, player[0].y + 18, GetColor(255, 255, 255), TRUE);
	//画像が表示されない
	//DrawGraph(x,y,image[1],TRUE);

	//DEBUG
	DrawFormatString(200, 420, GetColor(255, 0, 0), "flg:%d", isLRflg);
	DrawFormatString(200, 440, GetColor(255, 0, 0), "x:%d", player[0].x);
	DrawFormatString(200, 460, GetColor(255, 0, 0), "y:%d", player[0].y);

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

