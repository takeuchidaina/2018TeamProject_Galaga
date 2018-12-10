#pragma once

#ifndef _TEXTCHANGE_INCLUDE_
#define _TEXTCHANGE_INCLUDE_

#include "Singleton.h"

class cTextChange : public cSingleton<cTextChange>
{
	cTextChange();
	friend cSingleton< cTextChange >;

private:

	int textImgRD[48];	//�摜�n���h�� ��
	int textImgLB[48];	//�摜�n���h�� ��
	int textImgYL[48];	//�摜�n���h�� ��
	int textImgWH[48];	//�摜�n���h�� ��
	int ImgColor[48];//�摜�n���h������p
	//int hue;			//�F��[0�`360]
	//int saturation;		//�ʓx[-255�`]
	//int bright;			//�P�x[-255�`255]
	int magX;			//�摜�{���p��x
	int magY;			//�摜�{���p��y
	int mag;			//�摜�{��

public:

	/*************************************************************************
	 �֐�: int DrawTextImage
	 ����: �����̍��W�Ɏw��̐F�Ɣ{���ŕ�����\�����܂��A�A���t�@�x�b�g�̑啶���݂̂ł��B
	 ����: (int x, int y, char *������, int �F, int �{��)
			�F�Ɣ{����enum(���L�ɋL�q)
	 �߂�l: ����
	 *************************************************************************/
	int DrawTextImage(int, int, const char *,int,int);
};

//�F
typedef enum
{
	eRed,		//�ԐF
	eYellow,	//���F
	eLBlue,		//���F
	eWhite,		//���F
	eNone,		//����(�F�͂��邪�v���O�����̌����ڏ�)
}eColor;

//�����T�C�Y(�{��)
typedef enum
{
	eMag16,		//16x16
	eMag32,		//32x32
	eMag48,		//48x48

}eMagnification;

#endif
