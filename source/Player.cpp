#include <DxLib.h>
#include "Player.h"
//#include "Keyboard.h"
#include "Interface.h"
#define SPEED 5

//Template�N���X�̎���

//�R���X�g���N�^
cPlayer::cPlayer()
{

	x = 100;
	y = 400;
	isLRflg = 0;

}

//�f�X�g���N�^
cPlayer::~cPlayer()
{

}


int cPlayer::Update()
{

	Interface.Update();

	// �E
	if (Interface.Get_Input(InRIGHT) != 0)
	{
		isLRflg = 1;
	}
	//�@��
	else if (Interface.Get_Input(InLEFT) != 0)
	{
		isLRflg = -1;
	}
	else
	{
		isLRflg = 0;
	}

	//�t���O�̒l��1��-1�Ȃ̂Ō������ς��
	x += (SPEED * isLRflg);

	return 0;
}

int cPlayer::Draw()
{
	//�l�p(�v���C���[�̑���)
	DrawBox(x, y, x + 64, y + 64, GetColor(255, 255, 255), TRUE);

	//DEBUG
	DrawFormatString(200, 420, GetColor(255, 0, 0), "flg:%d", isLRflg);
	DrawFormatString(200, 440, GetColor(255, 0, 0), "x:%d", x);
	DrawFormatString(200, 460, GetColor(255, 0, 0), "y:%d", y);

	return 0;
}