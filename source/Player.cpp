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