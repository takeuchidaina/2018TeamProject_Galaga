#include <DxLib.h>
#include "Player.h"
#include "Interface.h"
#include "InGameMgr.h"
#include "InGameController.h"

//�R���X�g���N�^
cPlayer::cPlayer()
{


	//�摜�̓ǂݍ��݂ƕ���
	LoadDivGraph("../resource/Image/Galaga_OBJ_dualFighter.png", 2, 2, 1, 16, 16, image);
	if (image == NULL)   //error
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "�摜���ǂݍ��߂܂���ł���");
		WaitKey();
	}
	Init();

}

void cPlayer::Init() {
	//�����̋@��
	player[eLeftMachine].pos.x = 450.0;
	player[eLeftMachine].pos.y = 850.0;
	player[eLeftMachine].r = IMAGEMAG / 2;
	player[eLeftMachine].cx = player[eLeftMachine].pos.x + (IMAGEMAG / 2);
	player[eLeftMachine].cy = player[eLeftMachine].pos.y + (IMAGEMAG / 2);
	player[eLeftMachine].onActive = TRUE;
	//�E���̋@��
	player[eRightMachine].pos.x = player[eLeftMachine].pos.x + IMAGEMAG;
	player[eRightMachine].pos.y = player[eLeftMachine].pos.y;
	player[eRightMachine].r = IMAGEMAG / 2;
	player[eRightMachine].cx = player[eRightMachine].pos.x + (IMAGEMAG / 2);
	player[eRightMachine].cy = player[eRightMachine].pos.y + (IMAGEMAG / 2);

	player[eRightMachine].onActive = FALSE;
	//��@���̃t���O  0:��@ 1:��@
	isDoubleFlg = FALSE;

	//Player��HP
	playerHP = 2;   //(��ɏo�Ă���@�̂��܂܂Ȃ�)

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
  ����: �e�v�Z�����̌Ăяo��
  ����: ����
�߂�l: ����
*************************************************************************/
void cPlayer::Update()
{
	//�ړ��ƕǂƂ̓����蔻��
	cPlayer::Instance()->Move();
			
}

/*************************************************************************
  �֐�: void cPlayer::Move()
  ����: �ړ������ƕǂ̓����蔻��
  ����: ����
�߂�l: ����
*************************************************************************/
void cPlayer::Move()
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
			player[i].pos.x += SPEED;
		}

		// ��
		if (cInterface::Instance()->Get_Input(InLEFT) != 0)
		{
			player[i].pos.x -= SPEED;
		}

		//cx�̍X�V
		player[i].cx = player[i].pos.x + (IMAGEMAG / 2);

		//�ǂƂ̓����蔻��
		for (int j = 0; j < MAXMACHINE; j++)
		{

			//����
			if (player[j].pos.x <= 0)
			{
				//��@�Ƃ��A�N�e�B�u��ԂȂ�
				if (isDoubleFlg == TRUE)
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

#ifdef PLAYER_BREAK_DEBUG
	//�L�[
	if (cInterface::Instance()->Get_Input(DEBUG1) == 1)
	{
		cPlayer::Double();		// ��@�ɂȂ�
	}
	else if (cInterface::Instance()->Get_Input(DEBUG2) == 1)
	{
		cPlayer::Break(eDeath, eLeftMachine);	// �����j��
	}
	else if (cInterface::Instance()->Get_Input(DEBUG3) == 1)
	{
		cPlayer::Break(eDeath, eRightMachine);	// �E���j��
	}
#endif

	//DEBUG�Ɏg�p����ꍇ��Interface.h��enum��DEBUG1,2,3��
	//Interface.cpp��Update��enum��z��̗v�f���Ɏg�p���A�O��ނ̃L�[�{�[�h��Ή������Ă��������B

}

/*************************************************************************
  �֐�: void cPlayer::Draw()
  ����: �`�揈��
  ����: ����
�߂�l: ����
*************************************************************************/
void cPlayer::Draw()
{
	//�@�̂̕`��
	if(player[0].onActive == TRUE)
	{
		DrawExtendGraph((int)player[0].pos.x, (int)player[0].pos.y, (int)player[0].pos.x + IMAGEMAG, (int)player[0].pos.y + IMAGEMAG, image[0], TRUE);
	}
	if(player[1].onActive == TRUE)
	{
		DrawExtendGraph((int)player[1].pos.x, (int)player[1].pos.y, (int)player[1].pos.x + IMAGEMAG, (int)player[1].pos.y + IMAGEMAG, image[1], TRUE);
	}
#ifdef PLAYER_POS_DEBUG

	//���W�̕\��
	DrawFormatString(DISP_SIZE - 300, 500, P_COLOR, "��@��x:%4.2lf", player[eLeftMachine].pos.x);
	DrawFormatString(DISP_SIZE - 300, 520, P_COLOR, "��@��cx:%4.2lf", player[eLeftMachine].cx);
	DrawFormatString(DISP_SIZE - 300, 540, P_COLOR, "��@��onActive:%d", player[eLeftMachine].onActive);
	DrawFormatString(DISP_SIZE - 300, 560, P_COLOR, "��@��x:%4.2lf", player[eRightMachine].pos.x);
	DrawFormatString(DISP_SIZE - 300, 580, P_COLOR, "��@��cx:%4.2lf", player[eRightMachine].cx);
	DrawFormatString(DISP_SIZE - 300, 600, P_COLOR, "��@��onActive:%d", player[eRightMachine].onActive);
	DrawFormatString(DISP_SIZE - 300, 620, P_COLOR, "HP:%d", playerHP);

#endif



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
	int activeMachine;	// ��ɏo�Ă���@��
	int newMachine;		// �V�����@��

	isDoubleFlg = TRUE;
	playerHP--;
	cUI::Instance()->UI_SetPlayerHP(playerHP);

	//�ǂ̋@�̂��A�N�e�B�u��Ԃ����f
	if (player[eLeftMachine].onActive == TRUE)
	{
		newMachine = eRightMachine;
		activeMachine = eLeftMachine;
	}
	else
	{
		newMachine = eLeftMachine;
		activeMachine = eRightMachine;
	}

	//�A�N�e�B�u�ȋ@�̂̉E���ɍ��W���X�V���A�N�e�B�u��Ԃ�
	player[newMachine].pos.x = player[activeMachine].pos.x + IMAGEMAG;
	player[newMachine].cx = player[activeMachine].pos.x + (IMAGEMAG / 2);
	player[newMachine].onActive = TRUE;

	//��h�b�g�������̉���(��)
	//�����蔻��Ŕ����ɂȂ�ƍl����
	if (newMachine == eLeftMachine)
	{
		player[newMachine].pos.x -= 6;
		player[newMachine].cx -= (6/2);
	}


}

/*************************************************************************
  �֐�: void cPlayer::Break()
  ����: ���S���� (�����Ŏ��S���g���N�^�[�r�[�����𔻒f)
  ����: int judgeBreak   eDeath       : ��@�����Ȃ���ԂłŌ��j���ꂽ��
					�@ �@eTractorBeam : �g���N�^�[�r�[���ŝ���ꂽ��

		int machineNum�@ eLeftMachine   : ���̋@��
						 eRightMachine  : �E�̋@��
						 eNoneMachine   : �@�̖���
			
�߂�l: ����
*************************************************************************/
void cPlayer::Break(int judgeBreak ,int machineNum)
{
	//�@�̂��j�󂳂ꂽ��
	if (judgeBreak == eDeath)
	{
		//�v���C���[��HP������
		playerHP--;
		cUI::Instance()->UI_SetPlayerHP(playerHP);

		//���j���ꂽ�����A�N�e�B�u��
		if (machineNum == eLeftMachine)
		{
			player[eLeftMachine].onActive = FALSE;
		}
		else
		{
			player[eRightMachine].onActive = FALSE;
		}

		isDoubleFlg = FALSE;

		//��@�Ƃ����j���ꂽ��
		if (player[eLeftMachine].onActive == FALSE && player[eRightMachine].onActive == FALSE)
		{
			//�C���Q�[���R���g���[���[��HP���Ǘ����ĕ������Q�[���I�[�o�[
			//�����Ƃ��ā@0 �ʏ펀�S 1�g���N�^�[�Ƃ��܂��� by��
			cInGameController::Instance()->PlayerDeath(0);
		}

	}
	//�g���N�^�[�r�[���ɝ���ꂽ��
	else if(judgeBreak == eTractorBeam)
	{
		//�V�[���̕ύX
		//�g���N�^�[�r�[��

		//�v���C���[��HP������
		playerHP--;
		cUI::Instance()->UI_SetPlayerHP(playerHP);

		//���j���ꂽ�����A�N�e�B�u��
		if (machineNum == eLeftMachine)
		{
			player[eLeftMachine].onActive = FALSE;
		}
		else
		{
			player[eRightMachine].onActive = FALSE;
		}

		isDoubleFlg = FALSE;

		//��@�Ƃ����j���ꂽ��
		if (player[eLeftMachine].onActive == FALSE && player[eRightMachine].onActive == FALSE)
		{
			//�C���Q�[���R���g���[���[��HP���Ǘ����ĕ������Q�[���I�[�o�[
			//�����Ƃ��ā@0 �ʏ펀�S 1�g���N�^�[�Ƃ��܂��� by��
			cInGameController::Instance()->PlayerDeath(1);
		}
	

	}

}
/*************************************************************************
�֐�: int cPlayer::GetPlayerHP()
����: �v���C���[��HP(����܂߂�c�@)���󂯓n��
����: ����
�߂�l: playerHP
*************************************************************************/
int cPlayer::GetPlayerHP()
{
	return playerHP;
}

/*************************************************************************
�@�֐�: void PlayerRevive();
  ����: �v���C���[�̕���
  ����: ����
�߂�l: ����
*************************************************************************/
void cPlayer::PlayerRevive()
{
	player[eLeftMachine].pos.x = 450.0;
	player[eLeftMachine].pos.y = 850.0;
	player[eLeftMachine].cx = player[eLeftMachine].pos.x + (IMAGEMAG / 2);
	player[eLeftMachine].cy = player[eLeftMachine].pos.y + (IMAGEMAG / 2);
	player[eLeftMachine].onActive = TRUE;
}

