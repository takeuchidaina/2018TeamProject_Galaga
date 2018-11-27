#pragma once

#ifndef _TEXTCONVERSION_INCLUDE_
#define _TEXTCONVERSION_INCLUDE_

#include "Singleton.h"

class cTextChange : public cSingleton<cTextChange>
{
private:

	int textImg[48];
	int hue;			//�F��[0�`360]
	int saturation;		//�ʓx[-255�`]
	int bright;			//�P�x[-255�`255]
	int magX;			//�摜�{���p��x
	int magY;			//�摜�{���p��y
	int mag;			//�摜�{��
	cTextChange();  //private�Ȃ̂�new���g���Ȃ�
	friend cSingleton< cTextChange >;


public:

	int DrawTextImage(int, int, const char *,int,int);
};

typedef enum
{
	eRed,		//�ԐF
	eYellow,	//���F
	eLBlue,		//���F
	eWhite,		//���F
	eNone,		//����(�F�͂��邪�v���O�����̌����ڏ�)
}eColor;

typedef enum
{
	eMag16,
	eMag32,
	eMag48,

}eMagnification;

#endif
