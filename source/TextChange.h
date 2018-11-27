#pragma once

#ifndef _TEXTCONVERSION_INCLUDE_
#define _TEXTCONVERSION_INCLUDE_

#include "Singleton.h"

class cTextChange : public cSingleton<cTextChange>
{
private:

	int textImg[48];
	int hue;			//色相[0～360]
	int saturation;		//彩度[-255～]
	int bright;			//輝度[-255～255]
	cTextChange();  //privateなのでnewが使えない
	friend cSingleton< cTextChange >;


public:

	int DrawTextImage(int, int, const char *,int);
};

typedef enum
{
	eRed,		//赤色
	eYellow,	//黄色
	eLBlue,		//水色
	eWhite,		//白色
}eColor;

#endif
