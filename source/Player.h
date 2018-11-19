#pragma once

#ifndef _PLAYER_INCLUDE_
#define _PLAYER_INCLUDE_

#include "Struct.h"
#include "UI.h"
#include "Singleton.h"

#define SPEED 6			//プレイヤーのスピード
#define MAXMACHINE 2	//プレイヤーは二機まで(三機にならない)
#define NULL 0			//エラー時に使用

//DEBUG
#define P_COLOR GetColor(255,0,0)

      //    #include "takeuchi_debug_define.h"


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
	int GetPlayerHP();		//HPを渡す
	sOBJPos GetPlayer(int num) 	//構造体の受け渡し　　num 0:左  1:右
	{
		sOBJPos *p = NULL;
		return ((num == 0 || num == 1) ? player[num]:*p);
		//エラー時NULL
		//for文で受け取ってください
	}

	sOBJPos player[2];  //配列なのは一機か二機かで変わる為
	int isDoubleFlg;    // 0:一機 1:二機
	int playerHP;       //HP(場に出ている機体を含まない)


};

//死亡かトラクタービームか判断
typedef enum
{
	eDeath,				//撃破
	eTractorBeam,		//トラクタービーム

}ePlayerBreak;

//左の機体か右の機体か、また両方を指定しているのか
typedef enum
{
	eLeftMachine,		//左の機体
	eRightMachine,		//右の機体
	eNoneMachine,		//機体無し

}eMachineNum;

#endif