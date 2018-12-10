#include <DxLib.h>
#include "TextChange.h"

//�R���X�g���N�^
cTextChange::cTextChange()
{
	//�e�L�X�g�̉摜�̓ǂݍ���
	//LoadDivGraph("../resource/Image/AC_Classic.png", 40, 8, 5, 16, 16, textImg);
	LoadDivGraph("../resource/Image/AC_Classic_Red.png", 40, 8, 5, 16, 16, textImgRD);
	LoadDivGraph("../resource/Image/AC_Classic_LBlue.png", 40, 8, 5, 16, 16, textImgLB);
	LoadDivGraph("../resource/Image/AC_Classic_Yellow.png", 40, 8, 5, 16, 16, textImgYL);
	LoadDivGraph("../resource/Image/AC_Classic_White.png", 40, 8, 5, 16, 16, textImgWH);
	imgColor[48] = { 0 };
	//hue = 0;			//�F��[0�`360]
	//saturation = 0;		//�ʓx[-255�`100]
	//bright = 0;			//�P�x[-255�`255]
	magX = 0;			//�摜���g�傷��ۂ�x
	magY = 0;			//�摜���g�傷��ۂ�y
	
}

//�f�X�g���N�^
cTextChange::~cTextChange() 
{
	for (int i = 0; i < 48; i++) 
	{
		DeleteGraph(textImgRD[i]);
		DeleteGraph(textImgLB[i]);
		DeleteGraph(textImgYL[i]);
		DeleteGraph(textImgWH[i]);
		DeleteGraph(imgColor[i]);
	}
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
		//ImgColor�ɐԐF����
		memcpy(imgColor, textImgRD, sizeof(textImgRD));

		//hue = 360;
		//saturation = 0;
		//bright = 0;
		break;

	case eYellow:
		//ImgColor�ɉ��F����
		memcpy(imgColor, textImgYL, sizeof(textImgYL));

		//hue = 60;
		//saturation = 0;
		//bright = 0;
		break;

	case eLBlue:
		//ImgColor�ɐ��F����
		memcpy(imgColor, textImgLB, sizeof(textImgLB));

		//hue = 187;
		//saturation = 0;
		//bright = 0;
		break;

	case eWhite:
		//ImgColor�ɔ��F����
		memcpy(imgColor, textImgWH, sizeof(textImgWH));

		//hue = 0;
		//saturation = 90;
		//bright = 10;
		break;

	default:
		//eNone

		//ImgColor�ɔ��F����
		memcpy(imgColor, textImgWH, sizeof(textImgWH));

		break;
	}

	//�{���̐ݒ�
	switch (mag)
	{
	case eMag16:
		magX = x + 16;
		magY = y + 16;
		mag = 16;  //�����Ԋu�̒����K�v
		break;

	case eMag32:
		magX = x + 32;
		magY = y + 32;
		mag = 32;  //�����Ԋu�̒����K�v
		break;

	case eMag48:
		magX = x + 48;
		magY = y + 48;
		mag = 32;
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
				//GraphFilter(textImg[text[j]-'0'], DX_GRAPH_FILTER_HSB, 1, hue, saturation, bright);
				//�`��
				DrawExtendGraph(x+(j*mag), y,magX+(j*mag),magY, imgColor[text[j] - '0'], TRUE);
			}
			//������A�`Z�Ȃ�
			else if (text[j] >= 'A' && text[j] <= 'Z')
			{
				//�F���ω�
				//GraphFilter(textImg[text[j] - 'A'+10], DX_GRAPH_FILTER_HSB, 1, hue, saturation, bright);
				//�`��(+10����̂�0�`9�̔ԍ����܂߂Ȃ��悤�ɂ��邽��)
				DrawExtendGraph(x+(j*mag), y, magX + (j * mag), magY, imgColor[text[j] - 'A'+10], TRUE);
			}
			//�������X�y�[�X�Ȃ�
			else if(text[j] == ' ')
			{
				//�L��
				DrawExtendGraph(x + (j*mag), y, magX + (j * mag), magY, imgColor[38], TRUE);
			}

	}
	
	return 0;
}