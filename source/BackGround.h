#pragma once
#ifndef _BACKGROUND_INCLUDE_
#define _BACKGROUND_INCLUDE_

#include<time.h>
#include "Singleton.h"
#include "UI.h"
#include "InGameMgr.h"

#define MAXSTAR 50
#define TRUE 1
#define FALSE -1

typedef struct {

	double x, y;
	double speed;
	int blinkFlg;
	double blinkCnt, blinkNum;

} sStar;

class cBackGround : public cSingleton<cBackGround>
{
	cBackGround();
	friend cSingleton< cBackGround >;
private:
	sStar starArray[MAXSTAR];
	int image;

public:
	void Init(int);	//����������
	void Update();	//�v�Z����
	void Draw();	//�`�ʏ���
	int Rand(int,int);		//�����_���֐�

};
#endif