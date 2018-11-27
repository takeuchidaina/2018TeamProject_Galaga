#pragma once

#ifndef _TEXTCONVERSION_INCLUDE_
#define _TEXTCONVERSION_INCLUDE_

#include "Singleton.h"

class cTextChange : public cSingleton<cTextChange>
{
private:

	int textImg[48];
	int hue;			//F[0`360]
	int saturation;		//Κx[-255`]
	int bright;			//Px[-255`255]
	cTextChange();  //privateΘΜΕnewͺg¦Θ’
	friend cSingleton< cTextChange >;


public:

	int DrawTextImage(int, int, const char *,int);
};

typedef enum
{
	eRed,		//ΤF
	eYellow,	//©F
	eLBlue,		//F
	eWhite,		//F
}eColor;

#endif
