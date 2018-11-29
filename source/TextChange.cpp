#include <DxLib.h>
#include "TextChange.h"

//�R���X�g���N�^
cTextChange::cTextChange()
{
	//�e�L�X�g�̉摜�̓ǂݍ���
	//LoadDivGraph("../resource/Image/UI_Text_Color.png", 48, 8, 6, 28, 28, textImg);
	LoadDivGraph("../Image/GogoFiveAI.png", 48, 8, 6, 16, 16, textImg);
	hue = 0;			//�F��[0�`360]
	saturation = 0;		//�ʓx[-255�`100]
	bright = 0;			//�P�x[-255�`255]
	magX = 0;			//�摜���g�傷��ۂ�x
	magY = 0;			//�摜���g�傷��ۂ�y
	
}

/*************************************************************************
�֐�: int DrawTextImage
����: �����̍��W�Ɏw��̐F�Ɣ{���ŕ�����\�����܂�
����: (int x, int y, char *������, int �F, int �{��)
	   �F�Ɣ{����enum
�߂�l: ����
*************************************************************************/
int cTextChange::DrawTextImage(int x,int y,const char *text,int color,int mag)
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

	//�{���̐ݒ�
	switch (mag)
	{
	case eMag16:
		magX = x + 16;
		magY = y + 16;
		mag = 16;
		break;

	case eMag32:
		magX = x + 32;
		magY = y + 32;
		mag = 32;
		break;

	case eMag48:
		magX = x + 48;
		magY = y + 48;
		mag = 48;
		break;

	default:
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
				DrawExtendGraph(x+(j*mag), y,magX+(j*mag),magY, textImg[text[j] - '0'], TRUE);
			}
			//������A�`Z�Ȃ�
			else if (text[j] >= 'A' && text[j] <= 'Z')
			{
				//�F���ω�
				GraphFilter(textImg[text[j] - 'A'+10], DX_GRAPH_FILTER_HSB, 1, hue, saturation, bright);
				//�`��(+10����̂�0�`9�̔ԍ����܂߂Ȃ��悤�ɂ��邽��)
				DrawExtendGraph(x+(j*mag), y, magX + (j * mag), magY, textImg[text[j] - 'A'+10], TRUE);
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