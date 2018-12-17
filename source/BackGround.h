#pragma once
#ifndef _BACKGROUND_INCLUDE_
#define _BACKGROUND_INCLUDE_

#include<time.h>
#include "Singleton.h"
#include "UI.h"
#include "InGameMgr.h"

#define MAXSTAR 200
#define TRUE 1


typedef struct {

	int x, y, r;
	int speed;
	int blinkFlg;
	double blinkCnt, blinkNum;
	int color;

} sStar;

class cBackGround : public cSingleton<cBackGround>
{
	cBackGround();
	friend cSingleton< cBackGround >;
private:
	sStar starArray[MAXSTAR];
	int image;

	void Init(int);			//‰Šú‰»ˆ—

public:
	void Update();			//ŒvZˆ—
	void Draw();			//•`Êˆ—

};
#endif