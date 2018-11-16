#include <DxLib.h>
#include "Player.h"
#include "Interface.h"
#include "InGameMgr.h"



//�R���X�g���N�^
cPlayer::cPlayer()
{

	//�����̋@��
	player[eLeftMachine].pos.x = 640.0;
	player[eLeftMachine].pos.y = 850.0;
	player[eLeftMachine].cx = player[eLeftMachine].pos.x + (IMAGEMAG / 2);
	player[eLeftMachine].cy = player[eLeftMachine].pos.y + (IMAGEMAG / 2);
	player[eLeftMachine].onActive = TRUE;
	//�E���̋@��
	player[eRightMachine].pos.x = player[eLeftMachine].pos.x + IMAGEMAG;
	player[eRightMachine].pos.y = 850.0;
	player[eRightMachine].cx = player[eRightMachine].pos.x + (IMAGEMAG / 2);
	player[eRightMachine].cy = player[eRightMachine].pos.y + (IMAGEMAG / 2);
	player[eRightMachine].onActive = FALSE;

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
	//�ړ��̌v�Z
	for (int i = 0; i < MAXMACHINE; i++)
	{
		//�A�N�e�B�u��Ԃł͂Ȃ��Ȃ玟��
		if (player[i].onActive == FALSE)
		{
			continue;
		}

		// �E
		if (cInterface::Instance()->Get_Input(InRIGHT) != 0)
		{
			//�t���O�̒l��1��-1�Ȃ̂Ō������ς��cx�̍X�V
			player[i].pos.x += SPEED;
		}

		// ��
		if (cInterface::Instance()->Get_Input(InLEFT) != 0)
		{
			//�t���O�̒l��1��-1�Ȃ̂Ō������ς��cx�̍X�V
			player[i].pos.x -= SPEED;
			
		}

		//cx�̍X�V
		player[i].cx = player[eLeftMachine].pos.x + (IMAGEMAG / 2);

			//�ǂƂ̓����蔻��

			for (int j = 0; j < MAXMACHINE; j++)
			{

				//����
				if (player[j].pos.x <= 0)
				{
					//��@�Ƃ��A�N�e�B�u��ԂȂ�
					if (player[eLeftMachine].onActive == TRUE && player[eRightMachine].onActive == TRUE)
					{
						player[eLeftMachine].pos.x = 0;
						player[eRightMachine].pos.x = 0 + IMAGEMAG;
					}
					//��@�̂݃A�N�e�B�u��ԂȂ�
					else
					{
						player[i].pos.x = 0;
					}

				}
				//�E��
				if (player[j].pos.x + IMAGEMAG >= DISP_SIZE)
				{
					//��@�Ƃ��A�N�e�B�u��ԂȂ�
					if (player[eLeftMachine].onActive == TRUE && player[eRightMachine].onActive == TRUE)
					{
						player[eLeftMachine].pos.x = DISP_SIZE - IMAGEMAG * 2;
						player[eRightMachine].pos.x = DISP_SIZE - IMAGEMAG;
					}
					//��@�̂݃A�N�e�B�u��ԂȂ�
					else
					{
						player[i].pos.x = DISP_SIZE - IMAGEMAG;
					}

				}

			}
	}

		//DEBUG
			/*
			//�L�[
			if (cInterface::Instance()->Get_Input(DEBUG1) != 0)
			{
				cPlayer::Double();		// ��@�ɂȂ�
			}
			else if (cInterface::Instance()->Get_Input(DEBUG2) != 0)
			{
				cPlayer::Break(eDoubleDeath,eLeftMachine);	// ��@�ڂ�����
			}
			else if (cInterface::Instance()->Get_Input(DEBUG3) != 0)
			{
				cPlayer::Break(eDoubleDeath,eRightMachine);	// ��@�ڂ�����
			}

			//�������j���ꂽ��
			if (player[eLeftMachine].onActive == FALSE && player[1].onActive == FALSE)
			{
				cPlayer::Break(eDeath, eDoubleMachine);  //GAMEOVER
			}

			//DEBUG�Ɏg�p����ꍇ��Interface.h��enum��DEBUG1,2,3��
			//Interface.cpp��Update��enum��z��̗v�f���Ɏg�p���A�O��ނ̃L�[�{�[�h��Ή������Ă��������B
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

		if (player[i].onActive == FALSE)
		{
			continue;
		}

		//�\��
		DrawExtendGraph((int)player[i].pos.x, (int)player[i].pos.y, (int)player[i].pos.x + IMAGEMAG, (int)player[i].pos.y + IMAGEMAG, image[i], TRUE);

	}

//DEBUG

	//���W�̕\��
	DrawFormatString(DISP_SIZE - 300, 500, GetColor(255, 0, 0), "��@��x:%4.2lf", player[eLeftMachine].pos.x);
	DrawFormatString(DISP_SIZE - 300, 520, GetColor(255, 0, 0), "��@��cx:%4.2lf", player[eLeftMachine].cx);
	DrawFormatString(DISP_SIZE - 300, 540, GetColor(255, 0, 0), "��@��onActive:%d", player[eLeftMachine].onActive);
	DrawFormatString(DISP_SIZE - 300, 560, GetColor(255, 0, 0), "��@��x:%4.2lf", player[eRightMachine].pos.x);
	DrawFormatString(DISP_SIZE - 300, 580, GetColor(255, 0, 0), "��@��cx:%4.2lf", player[eRightMachine].cx);
	DrawFormatString(DISP_SIZE - 300, 600, GetColor(255, 0, 0), "��@��onActive:%d", player[eRightMachine].onActive);

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
	player[eRightMachine].pos.x = player[0].pos.x + IMAGEMAG;
	player[eRightMachine].cx = player[eRightMachine].pos.x + (IMAGEMAG / 2);
	player[eRightMachine].onActive = TRUE;

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
						 eNoneMachine   : �@�̖���
			
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
			player[eLeftMachine].onActive = FALSE;
		}
		else
		{
			player[eRightMachine].onActive = FALSE;
		}

	}
	//��@�̏�ԂŎ��񂾂�
	else if (judgeBreak == eDeath && machineNum == eNoneMachine)
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

