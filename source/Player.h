#pragma once

#ifndef _PLAYER_INCLUDE_
#define _PLAYER_INCLUDE_

#include "Interface.h"
#include "Struct.h"

#define SPEED 3			//プレイヤーのスピード
#define IMAGEMAG 48		//画像倍率
#define MAXMACHINE 2	//プレイヤーは二機まで(三機にならない)

class cPlayer {
private:

	int isLRflg;   // 0:移動なし -1:左 1:右
	int image[2];
	int UIsize;

protected:

public:
	cPlayer();	//コンストラクタ
	~cPlayer();	//デストラクタ

	int Update();	//計算処理
	int Draw();		//描写処理
	int Double();   //二機の処理
	int Break(int,int);    //死亡処理

	cInterface Interface;
	sOBJPos OBJPlayer[2];
	//配列なのは一機か二機かで変わる為

};


//死亡かトラクタービームか判断
typedef enum
{
	eDoubleDeath,		//二機の状態で片方が撃破
	eDeath,				//一機の状態で撃破
	eTractorBeam,		//トラクタービーム

}ePlayerBreak;

//左の機体か右の機体か、また両方を指定しているのか
typedef enum
{
	eLeftMachine,		//左の機体
	eRightMachine,		//右の機体
	eDouble,			//両方の機体

}eMachineNum;

#endif