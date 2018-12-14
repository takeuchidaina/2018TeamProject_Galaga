#pragma once

#ifndef _TEXTCHANGE_INCLUDE_
#define _TEXTCHANGE_INCLUDE_

#include "Singleton.h"

class cTextChange : public cSingleton<cTextChange>
{
	cTextChange();
	~cTextChange();
	friend cSingleton< cTextChange >;

private:

	int textImgRD[40];	//�摜�n���h�� ��
	int textImgLB[40];	//�摜�n���h�� ��
	int textImgYL[40];	//�摜�n���h�� ��
	int textImgWH[40];	//�摜�n���h�� ��
	int imgColor[40];//�摜�n���h������p
	int magX;			//�摜�{���p��x
	int magY;			//�摜�{���p��y

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
