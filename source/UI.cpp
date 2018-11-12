#include <DxLib.h>
#include "UI.h"

int UIsize;			//��ʃT�C�Y
int textImg[48];	//�e�L�X�g�̉摜
int iconImg[12];	//�X�e�[�W�A�C�R���̉摜

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
	UIsize = 0;

	//�摜�̓ǂݍ���
	//LoadDivGraph("../resource/Image/UI_Text.png",48,8,6,28,28,textImg);
	LoadDivGraph("../resource/Image/Galaga_UI_icon.png", 12, 6, 2, 18, 19, iconImg);

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
	//�X�e�[�W�����v�Z
	//�ǂ̃A�C�R���ɂ��邩

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

	for(int i=0;i < (sizeof(textPos) / sizeof*(textPos));i++)
	{
		DrawFormatString(textPos[i].x, textPos[i].y, GetColor(0,255,0),"%s", textPos[i].text);
	}

	//DEBUG
	DrawExtendGraph(200, 100,200+IMAGEMAG,100+IMAGEMAG, iconImg[3], TRUE);

	for (int j = 0; j < 2; j++)  //3�̓v���C���[�̎c�@
	{
		DrawExtendGraph(DISP_SIZE + 50 +(IMAGEMAG*j),900, DISP_SIZE + 50 + (IMAGEMAG*j+1)+IMAGEMAG, 900+IMAGEMAG,iconImg[6],TRUE);
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