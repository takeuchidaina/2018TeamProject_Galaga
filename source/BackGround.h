#pragma once
#ifndef _BACKGROUND_INCLUDE_
#define _BACKGROUND_INCLUDE_

#include<time.h>
#include "Singleton.h"
#include "UI.h"
#include "InGameMgr.h"

#define MAXSTAR 200		//星の数
#define TRUE 1


typedef struct {

	int x, y, r;				//座標・半径
	int speed;					//移動速度
	int blinkFlg;				//点滅用フラグ
	double blinkCnt, blinkNum;	//点滅用カウント
	int color;					//色

} sStar;

class cBackGround : public cSingleton<cBackGround>
{
	cBackGround();
	friend cSingleton< cBackGround >;
private:
	sStar starArray[MAXSTAR];	//星の配列

	void Init(int);			//初期化処理

	int sceneFlg;			//scene情報
	int eTractor;

public:
	void Update();			//計算処理
	void Draw();			//描写処理

	/************************************************************
	関数：void TractingUpdate
	説明：トラクター中の星の動き
	引数：なし
	戻り値：なし
	************************************************************/
	void TractingUpdate();

	/************************************************************
	関数：void PauseUpdate
	説明：星の動き停止
	引数：なし
	戻り値：なし
	************************************************************/
	void PauseUpdate();

};
#endif