#pragma once

#ifndef _PLAYER_INCLUDE_
#define _PLAYER_INCLUDE_

#include "Interface.h"

class cPlayer {
private:
	int x;
	int y;
	int isLRflg;


protected:

public:
	cPlayer();	//コンストラクタ
	~cPlayer();	//デストラクタ
	int Update();	//計算処理
	int Draw();		//描写処理
	int Double();   //二機の処理
	int Break();    //死亡処理

	cInterface Interface;

};

/*
struct tPlayer
{
int x, y;
int image[9];
int isLRflg;

};
*/
#endif