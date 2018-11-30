#include <DxLib.h>
#include "UI.h"

//�R���X�g���N�^
cUI::cUI()
{

	iconX = DISP_SIZE + 250;
	iconY = 700;

	stageNo = cInGameController::Instance()->GetNowStageNum();
	playerHP = cPlayer::Instance()->GetPlayerHP();

	blinkCnt = 0;  
	blinkFlg = FALSE;

	//�摜�̓ǂݍ���
	LoadDivGraph("../resource/Image/Galaga_UI_icon1616.png", 12, 6, 2, 16, 16, iconImg);
	if (iconImg == NULL)
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "�摜���ǂݍ��߂܂���ł���");
		WaitKey();
	}
}

//�f�X�g���N�^
cUI::~cUI()
{
	for (int i = 0; i < 12; i++)
	{
		DeleteGraph(iconImg[i]);
	}
}

/*************************************************************************
�@�֐�: int UI_Draw()
  ����: �g�g�݁E�c�@�E�X�e�[�W�A�C�R���̕\���ƕ����f�[�^�̑��M
  ����: ����
�߂�l: ����
*************************************************************************/
int cUI::UI_Draw()
{

	int i, j;

	//UI��\������D�F�̕����̕`��
	DrawBox(DISP_SIZE, 0, DISP_SIZE + UI_SIZE, 960, GetColor(80, 80, 80), TRUE);

	//�e�L�X�g�ނ̕\��
	/*
	for (i = 0; i<sizeof(textPos) / sizeof(textPos[0]); i++);
	{
		cTextChange::Instance()->DrawTextImage(textPos[i].x, textPos[i].y, textPos[i].text);
		//i�ł͂Ȃ�������v�f���ɂ��Əo�͂����
	}
	*/
	cTextChange::Instance()->DrawTextImage(textPos[0].x, textPos[0].y, textPos[0].text,textPos[0].color,eMag48);
	cTextChange::Instance()->DrawTextImage(textPos[1].x, textPos[1].y, textPos[1].text, textPos[1].color, eMag48);

	// 1UP�̓_��
	blinkCnt++;
	if (blinkCnt >= 20)
	{
		blinkCnt = 0;
		blinkFlg = !blinkFlg;
	}

	if (blinkFlg)
	{
		cTextChange::Instance()->DrawTextImage(textPos[2].x, textPos[2].y, textPos[2].text, textPos[2].color, eMag48);
	}
	else
	{
		cTextChange::Instance()->DrawTextImage(textPos[3].x, textPos[3].y, textPos[3].text, textPos[3].color, eMag48);
	}

	//�v���C���[�̎c�@
	for (j = 0; j < playerHP; j++)
	{
		DrawExtendGraph(DISP_SIZE + 50 + (IMAGEMAG*j), 900, DISP_SIZE + 50 + (IMAGEMAG*j + 1) + IMAGEMAG, 900 + IMAGEMAG, iconImg[6], TRUE);
	}

	//�X�e�[�W�A�C�R���̕\��
	UI_StgSelectIcon(stageNo);

#ifdef UI_POS_DEBUG

	for (int i = 0; i < (sizeof(textPos) / sizeof*(textPos)); i++)
	{
		//DrawFormatString(textPos[i].x, textPos[i].y, UI_COLOR, "%s", textPos[i].text);
	}

#endif

	return 0;
}

/*************************************************************************
 �֐�: int UI_SelectIcon()
 ����: �X�e�[�W���̃A�C�R�����ǂ��\�����邩
 ����: �X�e�[�W�ԍ�
 �߂�l: ����
 *************************************************************************/
int cUI::UI_StgSelectIcon(int stageNo)
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
void cUI::UI_SetPlayerHP(int HP)
{
	playerHP = HP;
}
