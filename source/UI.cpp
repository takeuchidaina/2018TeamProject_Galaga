#include <DxLib.h>
#include "UI.h"

static int textImg[48];	//�e�L�X�g�̉摜
static int iconImg[12];	//�X�e�[�W�A�C�R���̉摜

static int iconX;
static int iconY;

int stageNo;
int playerHP;

sTextPos textPos[3] = 
{
	{ DISP_SIZE + 150, 100,"HIGH" },
	{ DISP_SIZE +  50, 130,"SCORE" },
	{ DISP_SIZE + 150, 200,"1UP" },

};

/*************************************************************************
�@�֐�: int UI_Init()
�@����: ����������
�@����: ����
�߂�l: -1 �摜�ǂݍ��ݎ��̃G���[
*************************************************************************/
int UI_Init()
{
	iconX = DISP_SIZE + 250;
	iconY = 700;

	stageNo = cInGameController::Instance()->GetNowStageNum();
	playerHP = cPlayer::Instance()->GetPlayerHP();

	//�摜�̓ǂݍ���
	//LoadDivGraph("../resource/Image/UI_Text.png",48,8,6,28,28,textImg);
	LoadDivGraph("../resource/Image/Galaga_UI_icon1616.png", 12, 6, 2, 16, 16, iconImg);
	if (iconImg == NULL)
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "�摜���ǂݍ��߂܂���ł���");
		WaitKey();
		return -1;
	}

	return 0;
}

/*************************************************************************
�@�֐�: int UI_Update()
  ����: �v�Z����
  ����: ����
�߂�l: ����
*************************************************************************/
int UI_Update()
{
	UI_StgSelectIcon(stageNo);

	return 0;
}

/*************************************************************************
�@�֐�: int UI_Draw()
  ����: �`�揈��
  ����: ����
�߂�l: ����
*************************************************************************/
int UI_Draw()
{
	//UI��\������D�F�̕����̕`��
	DrawBox(DISP_SIZE,0,DISP_SIZE + UI_SIZE,960,GetColor(125,125,125),TRUE);

	//�v���C���[�̎c�@
	for (int j = 0; j < playerHP; j++)  //3�̓v���C���[�̎c�@
	{
		DrawExtendGraph(DISP_SIZE + 50 + (IMAGEMAG*j), 900, DISP_SIZE + 50 + (IMAGEMAG*j + 1) + IMAGEMAG, 900 + IMAGEMAG, iconImg[6], TRUE);
	}

	//�X�e�[�W�A�C�R���̕\��
	UI_StgSelectIcon(stageNo);

#ifdef UI_POS_DEBUG

	for (int i = 0; i < (sizeof(textPos) / sizeof*(textPos)); i++)
	{
		DrawFormatString(textPos[i].x, textPos[i].y, UI_COLOR, "%s", textPos[i].text);
	}

#endif

	return 0;
}

/*************************************************************************
�@�֐�: int UI_End()
  ����: �I������
  ����: ����
�߂�l: ����
*************************************************************************/
int UI_End()
{
	//�I��
	return 0;
}

/*************************************************************************
�@�֐�: int UI_SelectIcon()
 ����: �X�e�[�W���̃A�C�R�����ǂ��\�����邩
 ����: �X�e�[�W�ԍ�
 �߂�l: ����
 *************************************************************************/
int UI_StgSelectIcon(int stageNo)
{
	//�X�e�[�W�A�C�R��
	int tmp;
	int tmp2;
	int tmp3;
	int fiveFlg;

	tmp = stageNo % 5;
	tmp2 = stageNo / 5;
	tmp3 = stageNo / 10;

	/* tmp���̉��

	�y tmp �z
	5�Ŋ����ďo���]��
	1�`4��\���A�C�R���̕\������for���Ɏg�p
	���̑��A�C�R���̍��W�̌v�Z�Ɏg�p


	�y tmp2 �z
	5�Ŋ����ė]���؂�̂Ă��l
	5�̃A�C�R�����K�v���K�v����Ȃ����𔻒f����ۂɎg�p

	�y tmp3 �z
	10�Ŋ����ė]���؂�̂Ă��l
	10���̃X�e�[�W�A�C�R���̗v�f���Ɏg�p


	*/

	fiveFlg = FALSE;

#ifdef UI_ICON_DEBUG

	if (cInterface::Instance()->Get_Input(DEBUG1) == 1)
	{
	stageNo++;
	}
	if (cInterface::Instance()->Get_Input(DEBUG2) == 1)
	{
	stageNo--;
	}
	DrawFormatString(iconX - 200, iconY + 110, UI_COLOR, "5flg:%d", fiveFlg);
	DrawFormatString(iconX - 200, iconY + 130, UI_COLOR, "stage:%d", stageNo);
	DrawFormatString(iconX - 200, iconY + 150, UI_COLOR, "tmp1:%d", tmp);
	DrawFormatString(iconX - 200, iconY + 170, UI_COLOR, "tmp2:%d", tmp2);
	DrawFormatString(iconX - 200, iconY + 190, UI_COLOR, "tmp3:%d", tmp3);

#endif
	




	//�X�e�[�W��5�Ŋ���؂�Ȃ��Ȃ�
	if (stageNo % 5 != 0)
	{

		for (int i = 0; i < tmp; i++)
		{
			DrawExtendGraph(iconX - (ICONMAG * i),
							iconY,
							iconX + IMAGEMAG + (ICONMAG / 2) - (ICONMAG * i),
							iconY + IMAGEMAG + ICONMAG,
							iconImg[0], TRUE);
		}
	}
	//�X�e�[�W5�E15�E25�E�E�E
	if (tmp2 % 2 != 0)		//10��20��������tmp2�������Ȃ̂�%2�Ŋ����0�ɂȂ�׏���������Ȃ�
	{
		//1�`4�̃A�C�R��������Ȃ�(tmp��1�`4)
		if (stageNo % 5 != 0)	
		{
			// X���W����A�C�R���̐��ɉ����Ă����
			DrawExtendGraph(iconX - (ICONMAG * tmp + 1),
							iconY,
							(iconX + 64) - (ICONMAG * tmp + 1),
							iconY + IMAGEMAG + ICONMAG,
							iconImg[1], TRUE);
		}
		//1�`4�̃A�C�R�����Ȃ��Ȃ�(tmp��0)
		else
		{
			// X���W�ɕ\��
			DrawExtendGraph(iconX,
							iconY,
							iconX + IMAGEMAG + (ICONMAG / 2),
							iconY + IMAGEMAG + ICONMAG,
							iconImg[1], TRUE);
		}

		fiveFlg = TRUE;  // 5�̃A�C�R����\�����Ă���
	}
	//�X�e�[�W10�E20�E30�E�E�E
	if (stageNo >= 10)
	{
		// 5�̃A�C�R��������Ȃ�
		if (fiveFlg == TRUE)
		{
			DrawExtendGraph(iconX - (ICONMAG * (tmp + 1)),
							iconY,
							iconX + IMAGEMAG + (ICONMAG / 2) - (ICONMAG * (tmp + 1)),
							iconY + IMAGEMAG + ICONMAG,
							iconImg[tmp3 + 1], TRUE);
		}
		// 5�̃A�C�R�����Ȃ��Ȃ�
		else
		{
			DrawExtendGraph(iconX - (ICONMAG * tmp),
							iconY,
							iconX + IMAGEMAG + (ICONMAG / 2) - (ICONMAG * tmp),
							iconY + IMAGEMAG + ICONMAG,
							iconImg[tmp3 + 1], TRUE);
		}
	}

	return 0;
}

/*************************************************************************
   �֐�: void UI_SetPlayerHP()
   ����: �v���C���[�̎c�@�̍X�V
   ����: int (�v���C���[��HP)
 �߂�l: ����
 *************************************************************************/
void UI_SetPlayerHP(int HP)
{
	playerHP = HP;
}
/*************************************************************************
�֐�: int GetTextPos()
����: �\����textPos�̎󂯓n��
����: ����
�߂�l: textPos
*************************************************************************/
sTextPos GetTextPos()
{
	int i;
	for( i=0;i<sizeof(textPos) / sizeof(textPos[0]);i++);
	{
		return textPos[i];
	}
}
