#include <DxLib.h>
#include "Player.h"
#include "Interface.h"
#include "InGameMgr.h"



//�R���X�g���N�^
cPlayer::cPlayer()
{

	//�����̋@��
	OBJPlayer[0].pos.x = 640.0;
	OBJPlayer[0].pos.y = 850.0;
	OBJPlayer[0].cx = OBJPlayer[0].pos.x + (IMAGEMAG / 2);
	OBJPlayer[0].cy = OBJPlayer[0].pos.y + (IMAGEMAG / 2);
	OBJPlayer[0].onActive = true;
	//�E���̋@��
	OBJPlayer[1].pos.x = OBJPlayer[0].pos.x + IMAGEMAG;
	OBJPlayer[1].pos.y = 850.0;
	OBJPlayer[1].cx = OBJPlayer[1].pos.x + (IMAGEMAG / 2);
	OBJPlayer[1].cy = OBJPlayer[1].pos.y + (IMAGEMAG / 2);
	OBJPlayer[1].onActive = false;

	//�t���O
	isLRflg = false;      // 0:�ړ��Ȃ�  1:�E  -1:��

	//UI�̔�����
	UIsize = (1280 / 4 * 3) - 50;
	
	//�摜�̓ǂݍ��݂ƕ���
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
	//�ǂݍ��񂾉摜�̍폜
	DeleteGraph(image[0]);
	DeleteGraph(image[1]);
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
	// ��
	else if (Interface.Get_Input(InLEFT) != 0)
	{
		isLRflg = -1;
	}
	// �ړ��Ȃ�
	else
	{
		isLRflg = 0;
	}

	//�ړ��̌v�Z
	for (int i = 0; i < MAXMACHINE; i++)
	{
		//�A�N�e�B�u��Ԃł͂Ȃ��Ȃ玟��
		if (OBJPlayer[i].onActive == false)
		{
			continue;
		}

		//�t���O�̒l��1��-1�Ȃ̂Ō������ς��
		OBJPlayer[i].pos.x += (SPEED * isLRflg);
		OBJPlayer[i].cx = OBJPlayer[0].pos.x + (IMAGEMAG / 2);

		//�ǂ̐ݒ�
		if (OBJPlayer[i].pos.x <= 0)
		{
			OBJPlayer[i].pos.x = 0;
		}
		if (OBJPlayer[i].pos.x + IMAGEMAG >= UIsize)
		{
			//��@�Ƃ��A�N�e�B�u��ԂȂ�
			if (OBJPlayer[0].onActive == true && OBJPlayer[1].onActive == true)
			{
				OBJPlayer[0].pos.x = UIsize - IMAGEMAG*2;
				OBJPlayer[1].pos.x = UIsize - IMAGEMAG;
			}
			OBJPlayer[i].pos.x = UIsize - IMAGEMAG;
		}
	}


//DEBUG
	//�L�[
	if (Interface.Get_Input(InDEBUG1) != 0)
	{
		cPlayer::Double();		// I �����������@�ɂȂ�
	}

	else if (Interface.Get_Input(InDEBUG2) != 0)
	{
		cPlayer::Break(eDoubleDeath,eLeftMachine);	// O �����������@�ڂ�����
	}
	else if (Interface.Get_Input(InDEBUG3) != 0)
	{
		cPlayer::Break(eDoubleDeath,eRightMachine);	// P �����������@�ڂ�����
	}

	//�������j���ꂽ��
	if (OBJPlayer[0].onActive == false && OBJPlayer[1].onActive == false)
	{
		cPlayer::Break(eDeath, eDouble);
	}

	

	

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

	for (int i = 0; i < MAXMACHINE; i++)
	{

		if (OBJPlayer[i].onActive == false)
		{
			continue;
		}

		//�\��
		DrawExtendGraph(OBJPlayer[i].pos.x, OBJPlayer[i].pos.y, OBJPlayer[i].pos.x + IMAGEMAG, OBJPlayer[i].pos.y + IMAGEMAG, image[i], TRUE);

	}

//DEBUG
	//UI�̘g�g�݂̔���
	DrawLine(UIsize,0,UIsize,960,GetColor(255,255,255));

	//���W�̕\��
	DrawFormatString(920, 200, GetColor(255, 0, 0), "��@��x:%4.2lf", OBJPlayer[0].pos.x);
	DrawFormatString(920, 220, GetColor(255, 0, 0), "��@��cx:%4.2lf", OBJPlayer[0].cx);
	DrawFormatString(920, 240, GetColor(255, 0, 0), "��@��onActive:%d", OBJPlayer[0].onActive);
	

	DrawFormatString(920, 260, GetColor(255, 0, 0), "��@��x:%4.2lf", OBJPlayer[1].pos.x);
	DrawFormatString(920, 280, GetColor(255, 0, 0), "��@��cx:%4.2lf", OBJPlayer[1].cx);
	DrawFormatString(920, 300, GetColor(255, 0, 0), "��@��onActive:%d", OBJPlayer[1].onActive);






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
	//��@�ڂ̍��W���X�V����Ԃ��A�N�e�B�u��
	OBJPlayer[1].pos.x = OBJPlayer[0].pos.x + IMAGEMAG;
	OBJPlayer[1].cx = OBJPlayer[1].pos.x + (IMAGEMAG / 2);
	OBJPlayer[1].cy = OBJPlayer[1].pos.y + (IMAGEMAG / 2);
	OBJPlayer[1].onActive = true;

	//���_:���ڂ̓�@�̎��ɍ��W���������W�ɂȂ�̂Ŕz��𑝂₵�ĎO�@�ڂ̏������Ȃ��Ƃ����Ȃ���������Ȃ��B
	//��₱�����Ȃ邩�瑼�̕��@��T��
	//���̊֐�������ăv���C���[�̈�@�ڂ𐶐�����������Ă����������H

	return 0;
}

/*************************************************************************
  �֐�: int cPlayer::Break()
  ����: ���S���� (�����Ŏ��S���g���N�^�[�r�[�����𔻒f)
  ����: int
�߂�l: ����
*************************************************************************/
int cPlayer::Break(int judgeBreak ,int machineNum)
{
	//��@�̏�ԂŕЕ������񂾂�
	if (judgeBreak == eDoubleDeath)
	{
		//���j���ꂽ�����A�N�e�B�u��
		if (machineNum == eLeftMachine)
		{
			OBJPlayer[0].onActive = false;
		}
		else
		{
			OBJPlayer[1].onActive = false;
		}

	}
	//��@�̏�ԂŎ��񂾂�
	else if (judgeBreak == eDeath)
	{
		//�c�@�ɂ���āA�}�V�[���̐������͏I������

		//DEBUG
		DrawFormatString(600, 500, GetColor(255, 0, 0), "GAME OVER");
	}
	//�g���N�^�[�r�[���ɝ���ꂽ��
	else if(judgeBreak == eTractorBeam)
	{
		////////////////////////////////
	}

	return 0;
}

