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
	cTextChange();  //private�Ȃ̂�new���g���Ȃ�
	friend cSingleton< cTextChange >;


public:

	int DrawTextImage(int, int, const char *,int);
};

typedef enum
{
	eRed,		//�ԐF
	eYellow,	//���F
	eLBlue,		//���F
	eWhite,		//���F
}eColor;

#endif
