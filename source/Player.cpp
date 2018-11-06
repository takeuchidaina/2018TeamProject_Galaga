#include <DxLib.h>
#include "Player.h"
#include "Interface.h"
#include "InGameMgr.h"



//�R���X�g���N�^
cPlayer::cPlayer()
{

	player[0].x = 100;
	player[0].y = 400;
	isLRflg = 0;	
	isDoubleFlg = 0;
	
	LoadDivGraph("../resource/Image/Galaga_OBJ_dualFighter.png", 2, 2, 1, 16, 16, image);
	if (image == NULL)
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "�摜���ǂݍ��߂܂���ł���");
		WaitKey();
	}

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

//#ifndef _DEBUG

	if (Interface.Get_Input(InDEBUG) != 0)
	{
		isDoubleFlg = true;
	}

//#endif 


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
  �֐�: int cPlayer::Double()
  ����: ��@�̏���
  ����: ����
�߂�l: ����
*************************************************************************/
int cPlayer::Double()
{
	//�摜�̕\�����ς��
	isDoubleFlg = true;

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

