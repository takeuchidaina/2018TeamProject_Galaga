#include <DxLib.h>
#include "Player.h"
//#include "Keyboard.h"
#include "Interface.h"
#define SPEED 5

//Templateクラスの実装

//コンストラクタ
cPlayer::cPlayer()
{

	x = 100;
	y = 400;
	isLRflg = 0;

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
	x += (SPEED * isLRflg);

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
	DrawBox(x, y, x + 64, y + 64, GetColor(255, 255, 255), TRUE);

	//DEBUG
	DrawFormatString(200, 420, GetColor(255, 0, 0), "flg:%d", isLRflg);
	DrawFormatString(200, 440, GetColor(255, 0, 0), "x:%d", x);
	DrawFormatString(200, 460, GetColor(255, 0, 0), "y:%d", y);

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
説明: 死亡処理
      引数で死亡かトラクタービームか判断
引数: あり
戻り値: 無し
*************************************************************************/
int cPlayer::Break()
{

	return 0;
}

