#include <DxLib.h>
#include "TextChange.h"

//�R���X�g���N�^
cTextChange::cTextChange()
{
	//�e�L�X�g�̉摜�̓ǂݍ���
	LoadDivGraph("../resource/Image/AC_Classic_Red.png", 40, 8, 5, 16, 16, textImgRD);
	LoadDivGraph("../resource/Image/AC_Classic_LBlue.png", 40, 8, 5, 16, 16, textImgLB);
	LoadDivGraph("../resource/Image/AC_Classic_Yellow.png", 40, 8, 5, 16, 16, textImgYL);
	LoadDivGraph("../resource/Image/AC_Classic_White.png", 40, 8, 5, 16, 16, textImgWH);

	//�ϐ��̏�����
	imgColor[41] = { 0 };
	magX = 0;
	magY = 0;
	spacing = 32;
	
}

//�f�X�g���N�^
cTextChange::~cTextChange() 
{
	for (int i = 0; i < 41; i++) 
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
		break;
	case eYellow:
		//ImgColor�ɉ��F����
		memcpy(imgColor, textImgYL, sizeof(textImgYL));
		break;
	case eLBlue:
		//ImgColor�ɐ��F����
		memcpy(imgColor, textImgLB, sizeof(textImgLB));
		break;
	case eWhite:
		//ImgColor�ɔ��F����
		memcpy(imgColor, textImgWH, sizeof(textImgWH));
		break;
	default:	//eNone
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
		spacing = 8;
		break;
	case eMag32:
		magX = x + 32;
		magY = y + 32;
		spacing = 16;
		break;
	case eMag48:
		magX = x + 48;
		magY = y + 48;
		spacing = 32;
		break;
	default:	//eMag48
		magX = x + 48;
		magY = y + 48;
		spacing = 32;
		break;
	}

	//�摜�̎Z�o�E�F���ω��E�`��
	for (int j= 0;j<strlen(text);j++)
	{
			//������0�`9�Ȃ�
			if (text[j] >= '0' && text[j] <= '9')
			{
				DrawExtendGraph(x+(j*spacing), y,magX+(j*spacing),magY, imgColor[text[j] - '0'], TRUE);
			}
			//������A�`Z�Ȃ�
			else if (text[j] >= 'A' && text[j] <= 'Z')
			{
				//+10����̂�0�`9�̔ԍ����܂߂Ȃ��悤�ɂ��邽��
				DrawExtendGraph(x+(j*spacing), y, magX + (j * spacing), magY, imgColor[text[j] - 'A'+10], TRUE);
			}
			//�L��
			else
			{
				switch (text[j]) 
				{
				case '.':  //�h�b�g
					DrawExtendGraph(x + (j*spacing), y, magX + (j * spacing), magY, imgColor[36], TRUE);
					break;
				case '%':  // % 
					DrawExtendGraph(x + (j*spacing), y, magX + (j * spacing), magY, imgColor[37], TRUE);
					break;
				case '-':  // �X�y�[�X
					DrawExtendGraph(x + (j*spacing), y, magX + (j * spacing), magY, imgColor[38], TRUE);
					break;
				case '@' :  // �R�s�[���C�g�̑���
					DrawExtendGraph(x + (j*spacing), y, magX + (j * spacing), magY, imgColor[39], TRUE);
					break;
				default :  //�X�y�[�X
					DrawExtendGraph(x + (j*spacing), y, magX + (j * spacing), magY, imgColor[40], TRUE);
					break;

				}
			}
	}
	
	return 0;
}