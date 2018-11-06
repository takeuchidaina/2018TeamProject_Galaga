#pragma once

#ifndef _PLAYER_INCLUDE_
#define _PLAYER_INCLUDE_

#include "Interface.h"
#include "Struct.h"

#define SPEED 3
#define IMAGEMAG 32 //画像倍率

class cPlayer {
private:

	int isLRflg;
	int isDoubleFlg;
	int image[2];


protected:

public:
	cPlayer();	//コンストラクタ
	~cPlayer();	//デストラクタ
	int Update();	//計算処理
	int Draw();		//描写処理
	int Double();   //二機の処理
	int Break(int);    //死亡処理

	cInterface Interface;
	sPos player[2];
	//sOBJPos OBJPlayer[2];
	//配列なのは一機か二機かで変わる為

};


//死亡かトラクタービームか判断
typedef enum
{
	eDeath,
	eTractorBeam,

}ePlayerBreak;

/*
struct tPlayer
{
int x, y;
int image[9];
int isLRflg;

};
*/
#endif