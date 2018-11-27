#include <DxLib.h>
#include "TextChange.h"

//�R���X�g���N�^
cTextChange::cTextChange()
{
	//�e�L�X�g�̉摜�̓ǂݍ���
	LoadDivGraph("../resource/Image/UI_Text_Color.png", 48, 8, 6, 28, 28, textImg);

	hue = 0;			//�F��[0�`360]
	saturation = 0;		//�ʓx[-255�`]
	bright = 0;			//�P�x[-255�`255]
	
}

/*************************************************************************
�@�֐�: int cTextChange::_Update()
  ����: �����񂩂�摜�̗v�f���ւ̕ϊ�
  ����: (int,int,*text)
�߂�l: ����
*************************************************************************/
int cTextChange::DrawTextImage(int x,int y,const char *text,int color)
{
	
	//�F�̐ݒ�
	switch (color)
	{
	case eRed:
		hue = 360;
		saturation = 0;
		bright = 0;
		break;

	case eYellow:
		hue = 60;
		saturation = 0;
		bright = 0;
		break;

	case eLBlue:
		hue = 187;
		saturation = 0;
		bright = 0;
		break;

	case eWhite:
		hue = 0;
		saturation = 90;
		bright = 10;
		break;

	default:
		//eNone
		break;
	}

	//�摜�̎Z�o�E�F���ω��E�`��
	for (int j= 0;j<strlen(text);j++)
	{
			//������0�`9�Ȃ�
			if (text[j] >= '0' && text[j] <= '9')
			{
				//�F���ω�
				GraphFilter(textImg[text[j]-'0'], DX_GRAPH_FILTER_HSB, 1, hue, saturation, bright);
				//�`��
				DrawGraph(x+(j*30), y, textImg[text[j] - '0'], TRUE);
			}
			//������A�`Z�Ȃ�
			else if (text[j] >= 'A' && text[j] <= 'Z')
			{
				//�F���ω�
				GraphFilter(textImg[text[j] - 'A'+10], DX_GRAPH_FILTER_HSB, 1, hue, saturation, bright);
				//�`��(+10����̂�0�`9�̔ԍ����܂߂Ȃ��悤�ɂ��邽��)
				DrawGraph(x+(j*30), y, textImg[text[j] - 'A'+10], TRUE);
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