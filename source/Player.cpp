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
		if (OBJPlayer[i].onActive == false)
		{
			continue;
		}

		// �E
		if (cInterface::Instance()->Get_Input(InRIGHT) != 0)
		{
			//�t���O�̒l��1��-1�Ȃ̂Ō������ς��cx�̍X�V
			OBJPlayer[i].pos.x += SPEED;
		}

		// ��
		if (cInterface::Instance()->Get_Input(InLEFT) != 0)
		{
			//�t���O�̒l��1��-1�Ȃ̂Ō������ς��cx�̍X�V
			OBJPlayer[i].pos.x -= SPEED;
			
		}

		//cx�̍X�V
		OBJPlayer[i].cx = OBJPlayer[eLeftMachine].pos.x + (IMAGEMAG / 2);

			//�ǂƂ̓����蔻��

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
				if (OBJPlayer[j].pos.x + IMAGEMAG >= DISP_SIZE)
				{
					//��@�Ƃ��A�N�e�B�u��ԂȂ�
					if (OBJPlayer[eLeftMachine].onActive == true && OBJPlayer[eRightMachine].onActive == true)
					{
						OBJPlayer[eLeftMachine].pos.x = DISP_SIZE - IMAGEMAG * 2;
						OBJPlayer[eRightMachine].pos.x = DISP_SIZE - IMAGEMAG;
					}
					//��@�̂݃A�N�e�B�u��ԂȂ�
					else
					{
						OBJPlayer[i].pos.x = DISP_SIZE - IMAGEMAG;
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
			if (OBJPlayer[eLeftMachine].onActive == false && OBJPlayer[1].onActive == false)
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

		if (OBJPlayer[i].onActive == false)
		{
			continue;
		}

		//�\��
		DrawExtendGraph((int)OBJPlayer[i].pos.x, (int)OBJPlayer[i].pos.y, (int)OBJPlayer[i].pos.x + IMAGEMAG, (int)OBJPlayer[i].pos.y + IMAGEMAG, image[i], TRUE);

	}

//DEBUG

	//���W�̕\��
	DrawFormatString(420, 200, GetColor(255, 0, 0), "��@��x:%4.2lf", OBJPlayer[eLeftMachine].pos.x);
	DrawFormatString(420, 220, GetColor(255, 0, 0), "��@��cx:%4.2lf", OBJPlayer[eLeftMachine].cx);
	DrawFormatString(420, 240, GetColor(255, 0, 0), "��@��onActive:%d", OBJPlayer[eLeftMachine].onActive);
	

	DrawFormatString(420, 260, GetColor(255, 0, 0), "��@��x:%4.2lf", OBJPlayer[eRightMachine].pos.x);
	DrawFormatString(420, 280, GetColor(255, 0, 0), "��@��cx:%4.2lf", OBJPlayer[eRightMachine].cx);
	DrawFormatString(420, 300, GetColor(255, 0, 0), "��@��onActive:%d", OBJPlayer[eRightMachine].onActive);

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

