#pragma once

#ifndef _EFFECTMGR_INCLUDE_
#define _EFFECTMGR_INCLUDE_
#define BLOWUPNUM 10
#define PLAYER 0
#define ENEMY 1

#include "Singleton.h"
#include "Winbox.h"
#include "Effect.h"


/*
//テンプレート例 クラスもテンプレート化可能
template <typename TYPE>
void Swap(TYPE& a, TYPE& b) {
	TYPE tmp;
	tmp = a;
	a = b;
	b = tmp;
}
*/


class cEffectMgr :public cSingleton<cEffectMgr> {
	cEffectMgr();
	~cEffectMgr();
	friend cSingleton<cEffectMgr>;
private:
	cEffect *BlowupArray;
	int BlowupCnt;
	//Player
	int PBlowupGrHandle[8];
	int PcheckGr;
	int PblowupOrders[6] = {0,0,1,1,2,2};
	//Enemy
	int EBlowupGrHandle[40];
	int EcheckGr;
	int EblowupOrders[6] = {0,0,1,1,2,2};
	
protected:

public:
	void Init();//初期化処理
	int Update();	//計算処理
	int Draw();		//描写処理

	int Blowup(int,int,int);
/*
//宣言例
private:
	int mTest;
public:
	void Set_Test(int);	//privateメンバ変数mTestへの代入
	int Get_Test();		//privateメンバ変数mTestの獲得
*/
};
#endif