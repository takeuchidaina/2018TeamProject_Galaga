#include <DxLib.h>
#include "UI.h"

//DEBUG
#include "Interface.h"
#define COLOR GetColor(0,255,0)

static int textImg[48];	//�e�L�X�g�̉摜
static int iconImg[12];	//�X�e�[�W�A�C�R���̉摜

static int iconX;
static int iconY;

//DEBUG
int stageNo;
int playerHP;

sTextPos textPos[] = 
{
	{ DISP_SIZE + 50,100,"HIGH SCORE" },
	{ DISP_SIZE + 50,140,"text02" },
	{ DISP_SIZE + 50,180,"text03" },

};

/*************************************************************************
�@�֐�: int UI_Init()
�@����: ����������
�@����: ����
�߂�l: ����
*************************************************************************/
int UI_Init()
{
	iconX = DISP_SIZE + 250;
	iconY = 700;

	//DEBUG
	stageNo = cInGameController::Instance()->GetNowStageNum();
	playerHP = 2;

	//�摜�̓ǂݍ���
	//LoadDivGraph("../resource/Image/UI_Text.png",48,8,6,28,28,textImg);
	LoadDivGraph("../resource/Image/Galaga_UI_icon.png", 12, 6, 2, 18, 19, iconImg);
	if (iconImg == NULL)
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "�摜���ǂݍ��߂܂���ł���");
		WaitKey();
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
	//DEBUG
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

	//DEBUG
	for (int i = 0; i < (sizeof(textPos) / sizeof*(textPos)); i++)
	{
		DrawFormatString(textPos[i].x, textPos[i].y, COLOR, "%s", textPos[i].text);
	}


		


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

	/*_DEBUG
	if (cInterface::Instance()->Get_Input(DEBUG1) == 1)
	{
	stageNo++;
	}
	if (cInterface::Instance()->Get_Input(DEBUG2) == 1)
	{
	stageNo--;
	}
	*/

	DrawFormatString(iconX - 200, iconY + 110, COLOR, "5flg:%d", fiveFlg);
	DrawFormatString(iconX - 200, iconY + 130, COLOR, "stage:%d", stageNo);
	DrawFormatString(iconX - 200, iconY + 150, COLOR, "tmp1:%d", tmp);
	DrawFormatString(iconX - 200, iconY + 170, COLOR, "tmp2:%d", tmp2);
	DrawFormatString(iconX - 200, iconY + 190, COLOR, "tmp3:%d", tmp3);
	DrawLine(iconX + IMAGEMAG, 0, iconX + IMAGEMAG, 960, GetColor(255, 255, 255));	//�A�C�R���̃X�^�[�g���C��


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