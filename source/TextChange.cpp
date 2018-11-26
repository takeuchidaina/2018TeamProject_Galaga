#include <DxLib.h>
#include "TextChange.h"

//�R���X�g���N�^
cTextChange::cTextChange()
{
	//�e�L�X�g�̉摜�̓ǂݍ���
	LoadDivGraph("../resource/Image/UI_Text.png", 48, 8, 6, 28, 28, textImg);

	imgEle[40] = { 0 };
	cnt = 0;
}

/*************************************************************************
�@�֐�: int cTextChange::_Update()
  ����: �����񂩂�摜�̗v�f���ւ̕ϊ�
  ����: (int,int,*text)
�߂�l: ����
*************************************************************************/
int cTextChange::DrawTextImage(int x,int y,const char *text)
{
	
	//DEBUG
	//char text[] = "HIGHSCORE";
	cnt = 0;

	//�摜�̎Z�o����
	for (int i= 0;i<strlen(text);i++)
	{
		int tmp = text[i];

			//������0�`9�Ȃ�
			if (text[i] >= '0' && text[i] <= '9')
			{
				DrawGraph(x+(i*30), y, textImg[tmp - '0'], TRUE);
			}
			//������A�`Z�Ȃ�
			else if (text[i] >= 'A' && text[i] <= 'Z')
			{
				DrawGraph(x+(i*30), y, textImg[tmp - 'A'+10], TRUE);
				// +10����̂�0�`9�̔ԍ����܂߂Ȃ��悤�ɂ��邽��
			}
			//�������L���Ȃ�
			else
			{
				//�L��
				//switch case
			}

	}
	return 0;
}