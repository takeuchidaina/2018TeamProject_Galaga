#include <DxLib.h>
#include "TextChange.h"
//#define GREEN 1,120,0,0
//#define RED 1,360,0,0
//#define YELLOW 1,60,0,0

//�R���X�g���N�^
cTextChange::cTextChange()
{
	//�e�L�X�g�̉摜�̓ǂݍ���
	LoadDivGraph("../resource/Image/UI_Text.png", 48, 8, 6, 28, 28, textImg);
	//LoadDivGraph("../Image/UI_Text.png", 48, 8, 6, 28, 28, textImg);
	//for (int i = 0; i < 48; i++)
	//{
	//	GraphFilter(textImg[i], DX_GRAPH_FILTER_HSB, YELLOW);// 1, 120, 0, 0);
	//}

	eColor color;
	
}

/*************************************************************************
�@�֐�: int cTextChange::_Update()
  ����: �����񂩂�摜�̗v�f���ւ̕ϊ�
  ����: (int,int,*text)
�߂�l: ����
*************************************************************************/
int cTextChange::DrawTextImage(int x,int y,const char *text)
{


	//�摜�̎Z�o����
	for (int i= 0;i<strlen(text);i++)
	{

			//������0�`9�Ȃ�
			if (text[i] >= '0' && text[i] <= '9')
			{
				DrawGraph(x+(i*30), y, textImg[text[i] - '0'], TRUE);
			}
			//������A�`Z�Ȃ�
			else if (text[i] >= 'A' && text[i] <= 'Z')
			{
				DrawGraph(x+(i*30), y, textImg[text[i] - 'A'+10], TRUE);
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