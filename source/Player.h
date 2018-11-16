#pragma once

#ifndef _PLAYER_INCLUDE_
#define _PLAYER_INCLUDE_

#include "Struct.h"
#include "UI.h"
#include "Singleton.h"

#define SPEED 3			//プレイヤーのスピード
#define MAXMACHINE 2	//プレイヤーは二機まで(三機にならない)
#define NULL 0			//エラー時に使用

class cPlayer : public cSingleton<cPlayer>
{
	cPlayer();	//コンストラクタ
	~cPlayer();	//デストラクタ
	friend cSingleton< cPlayer >;

private:

	int image[2];	  //画像

protected:

public:


	void Update();	//計算処理
	void Draw();		//描写処理
	void Double();   //二機の処理
	void Break(int,int);    //死亡処理
	sOBJPos GetPlayer(int num) 	//構造体の受け渡し　　num 0:左  1:右
	{
		sOBJPos *p = NULL;
		return ((num == 0 || num == 1) ? player[num]:*p);
		//エラー時NULL
		//for文で受け取ってください
	}

	sOBJPos player[2];
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
	eDoubleMachine,			//両方の機体

}eMachineNum;

#endif