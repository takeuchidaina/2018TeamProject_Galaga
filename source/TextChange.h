#pragma once

#ifndef _TEXTCHANGE_INCLUDE_
#define _TEXTCHANGE_INCLUDE_

#include "Singleton.h"

#define IMAGE_NUM 41
#define MAG16 16
#define MAG32 32
#define MAG48 48

class cTextChange : public cSingleton<cTextChange>
{
	cTextChange();
	~cTextChange();
	friend cSingleton< cTextChange >;

private:

	//�摜
	int textImgRD[IMAGE_NUM];	//�摜�n���h�� ��
	int textImgLB[IMAGE_NUM];	//�摜�n���h�� ��
	int textImgYL[IMAGE_NUM];	//�摜�n���h�� ��
	int textImgWH[IMAGE_NUM];	//�摜�n���h�� ��
	int imgColor[IMAGE_NUM];	//�摜�n���h������p  
	//�摜��40�����X�y�[�X���~�����̂ŁA41�̓X�y�[�X�p

	//�{���֌W
	int magX;			//�摜�{���p��x
	int magY;			//�摜�{���p��y
	int spacing;		//�����Ԋu

public:

	/*************************************************************************
	 �@�֐�: int DrawTextImage
	 �@����: �����̍��W�Ɏw��̐F�Ɣ{���ŕ�����\�����܂��A�A���t�@�x�b�g�̑啶���ƋL���ł��B
	       �@�Ή��L�� : [.] [%] [-] [@]���R�s�[���C�g
	 �@����: (int x, int y, char *������, eColor, eMag)
			  eColor��eMag�͉��L�L�q
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
	eNone,		//�_�œ��ň����Ɏg�p(�F�͔����w�肳���)
}eColor;

//�����T�C�Y(�{��)
typedef enum
{
	eMag16,		//16x16
	eMag32,		//32x32
	eMag48,		//48x48
}eMag;

#endif
