#include <DxLib.h>
#include "Player.h"
#include "Interface.h"
#include "InGameMgr.h"



//�R���X�g���N�^
cPlayer::cPlayer()
{

	//�����̋@��
	OBJPlayer[eLeftMachine].pos.x = 640.0;
	OBJPlayer[eLeftMachine].pos.y = 850.0;
	OBJPlayer[eLeftMachine].cx = OBJPlayer[eLeftMachine].pos.x + (IMAGEMAG / 2);
	OBJPlayer[eLeftMachine].cy = OBJPlayer[eLeftMachine].pos.y + (IMAGEMAG / 2);
	OBJPlayer[eLeftMachine].onActive = true;
	//�E���̋@��
	OBJPlayer[eRightMachine].pos.x = OBJPlayer[eLeftMachine].pos.x + IMAGEMAG;
	OBJPlayer[eRightMachine].pos.y = 850.0;
	OBJPlayer[eRightMachine].cx = OBJPlayer[eRightMachine].pos.x + (IMAGEMAG / 2);
	OBJPlayer[eRightMachine].cy = OBJPlayer[eRightMachine].pos.y + (IMAGEMAG / 2);
	OBJPlayer[eRightMachine].onActive = false;

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
	DeleteGraph(image[eLeftMachine]);
	DeleteGraph(image[eRightMachine]);
}

/*************************************************************************
  �֐�: void cPlayer::Update()
  ����: �ړ������ƕǂ̓����蔻��
  ����: ����
�߂�l: ����
*************************************************************************/
void cPlayer::Update()
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

		//�t���O�̒l��1��-1�Ȃ̂Ō������ς��cx�̍X�V
		OBJPlayer[i].pos.x += (SPEED * isLRflg);
		OBJPlayer[i].cx = OBJPlayer[eLeftMachine].pos.x + (IMAGEMAG / 2);

	//�ǂ̐ݒ�

		for (int j = 0; j < MAXMACHINE; j++)
		{

			//����
			if (OBJPlayer[j].pos.x <= 0)
			{
				//��@�Ƃ��A�N�e�B�u��ԂȂ�
				if (OBJPlayer[eLeftMachine].onActive == true && OBJPlayer[eRightMachine].onActive == true)
				{
					OBJPlayer[eLeftMachine].pos.x = 0;
					OBJPlayer[eRightMachine].pos.x = 0 + IMAGEMAG;
				}
				//��@�̂݃A�N�e�B�u��ԂȂ�
				else
				{
					OBJPlayer[i].pos.x = 0;
				}

			}
			//�E��
			if (OBJPlayer[j].pos.x + IMAGEMAG >= UIsize)
			{
				//��@�Ƃ��A�N�e�B�u��ԂȂ�
				if (OBJPlayer[eLeftMachine].onActive == true && OBJPlayer[eRightMachine].onActive == true)
				{
					OBJPlayer[eLeftMachine].pos.x = UIsize - IMAGEMAG * 2;
					OBJPlayer[eRightMachine].pos.x = UIsize - IMAGEMAG;
				}
				//��@�̂݃A�N�e�B�u��ԂȂ�
				else
				{
					OBJPlayer[i].pos.x = UIsize - IMAGEMAG;
				}

			}

		}
	}


//DEBUG
	/*
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
	if (OBJPlayer[eLeftMachine].onActive == false && OBJPlayer[1].onActive == false)
	{
		cPlayer::Break(eDeath, eDoubleMachine);
	}

	//DEBUG�Ɏg�p����ꍇ��Interface.h��enum��InDEBUG1,2,3��
	//Interface.cpp��Update��enum��z��̗v�f���Ɏg�p���AI��O��P��Ή������Ă��������B

	*/

}

/*************************************************************************
  �֐�: void cPlayer::Draw()
  ����: �`�揈��
  ����: ����
�߂�l: ����
*************************************************************************/
void cPlayer::Draw()
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
	DrawFormatString(920, 200, GetColor(255, 0, 0), "��@��x:%4.2lf", OBJPlayer[eLeftMachine].pos.x);
	DrawFormatString(920, 220, GetColor(255, 0, 0), "��@��cx:%4.2lf", OBJPlayer[eLeftMachine].cx);
	DrawFormatString(920, 240, GetColor(255, 0, 0), "��@��onActive:%d", OBJPlayer[eLeftMachine].onActive);
	

	DrawFormatString(920, 260, GetColor(255, 0, 0), "��@��x:%4.2lf", OBJPlayer[eRightMachine].pos.x);
	DrawFormatString(920, 280, GetColor(255, 0, 0), "��@��cx:%4.2lf", OBJPlayer[eRightMachine].cx);
	DrawFormatString(920, 300, GetColor(255, 0, 0), "��@��onActive:%d", OBJPlayer[eRightMachine].onActive);

}

/*************************************************************************
  �֐�: void cPlayer::Double()
  ����: �Ă΂ꂽ�ꍇ�̂ݏ��������
		��@�ڂ̋@�̂�x��cx���X�V����A�N�e�B�u��ԂɂȂ�
  ����: ����
�߂�l: ����
*************************************************************************/
void cPlayer::Double()
{
	//��@�ڂ̍��W���X�V����Ԃ��A�N�e�B�u��
	OBJPlayer[eRightMachine].pos.x = OBJPlayer[0].pos.x + IMAGEMAG;
	OBJPlayer[eRightMachine].cx = OBJPlayer[eRightMachine].pos.x + (IMAGEMAG / 2);
	OBJPlayer[eRightMachine].onActive = true;

	//���_:���ڂ̓�@�̎��ɍ��W���������W�ɂȂ�̂Ŕz��𑝂₵�ĎO�@�ڂ̏������Ȃ��Ƃ����Ȃ���������Ȃ��B
	//��₱�����Ȃ邩�瑼�̕��@��T��
	//���̊֐�������ăv���C���[�̈�@�ڂ𐶐�����������Ă����������H

}

/*************************************************************************
  �֐�: void cPlayer::Break()
  ����: ���S���� (�����Ŏ��S���g���N�^�[�r�[�����𔻒f)
  ����: int judgeBreak �@eDoubleDeath : ��@�����ԂŕЕ������j���ꂽ��
					�@�@ eDeath       : ��@�����Ȃ���ԂłŌ��j���ꂽ��
					�@ �@eTractorBeam : �g���N�^�[�r�[���ŝ���ꂽ��

		int machineNum�@ eLeftMachine   : ���̋@��
						 eRightMachine  : �E�̋@��
						 eDoubleMachine : �����̋@��
			
�߂�l: ����
*************************************************************************/
void cPlayer::Break(int judgeBreak ,int machineNum)
{
	//��@�̏�ԂŕЕ������񂾂�
	if (judgeBreak == eDoubleDeath)
	{
		//���j���ꂽ�����A�N�e�B�u��
		if (machineNum == eLeftMachine)
		{
			OBJPlayer[eLeftMachine].onActive = false;
		}
		else
		{
			OBJPlayer[eRightMachine].onActive = false;
		}

	}
	//��@�̏�ԂŎ��񂾂�
	else if (judgeBreak == eDeath && machineNum == eDoubleMachine)
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

}

