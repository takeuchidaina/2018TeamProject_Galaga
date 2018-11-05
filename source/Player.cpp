#include <DxLib.h>
#include "Player.h"
#include "Interface.h"
#include "InGameMgr.h"

#define SPEED 3

//�R���X�g���N�^
cPlayer::cPlayer()
{
	
	player[0].x = 100;
	player[0].y = 400;
	isLRflg = 0;	
	/*
	LoadDivGraph("resource/Image/Galaga_OBJ_myMachine.png", 12, 4, 3, 19, 19, image);
	if (image == NULL)
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "�摜���ǂݍ��߂܂���ł���");
		WaitKey();
	}
	*/

}

//�f�X�g���N�^
cPlayer::~cPlayer()
{

}

/*************************************************************************
  �֐�: int cPlayer::Update()
  ����: �ړ�����
  ����: ����
�߂�l: ����
*************************************************************************/
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
	player[0].x += (SPEED * isLRflg);

	return 0;
}

/*************************************************************************
  �֐�: int cPlayer::Draw()
  ����: �`�揈��
  ����: ����
�߂�l: ����
*************************************************************************/
int cPlayer::Draw()
{
	//�l�p(�v���C���[�̑���)
	DrawBox(player[0].x, player[0].y, player[0].x + 18, player[0].y + 18, GetColor(255, 255, 255), TRUE);
	//�摜���\������Ȃ�
	//DrawGraph(x,y,image[1],TRUE);

	//DEBUG
	DrawFormatString(200, 420, GetColor(255, 0, 0), "flg:%d", isLRflg);
	DrawFormatString(200, 440, GetColor(255, 0, 0), "x:%d", player[0].x);
	DrawFormatString(200, 460, GetColor(255, 0, 0), "y:%d", player[0].y);

	return 0;
}

/*************************************************************************
  �֐�: int cPlayer::Double()
  ����: ��@�̏���
  ����: ����
�߂�l: ����
*************************************************************************/
int cPlayer::Double()
{


	return 0;
}

/*************************************************************************
  �֐�: int cPlayer::Break()
  ����: ���S���� (�����Ŏ��S���g���N�^�[�r�[�����𔻒f)
  ����: int
�߂�l: ����
*************************************************************************/
int cPlayer::Break(int judgeBreak)
{
	if (judgeBreak == eDeath)
	{
		//���S����
	}

	if (judgeBreak == eTractorBeam)
	{
		//�g���N�^�[�r�[���ɝ����鏈��
	}

	return 0;
}

