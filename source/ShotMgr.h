#pragma once

#ifndef _SHOTMGR_INCLUDE_
#define _SHOTMGR_INCLUDE_
#include "Shot.h"
#include "Singleton.h"
#include "Player.h"
#include "Struct.h"
#include "Winbox.h"
#define PLAYER 0
#define ENEMY 1
#define PLAYERSHOTNUM 2
#define ENEMYSHOTNUM 20
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


class cShotMgr:public cSingleton<cShotMgr> {
	cShotMgr();
	friend cSingleton<cShotMgr>;
private:
	cShot *enemyShot, *playerShot;
	int totalShot;
	int ShotGrHandle[4];
	int shotRate;
	int checkGr;

protected:

public:
	int Update();	//計算処理
	int Draw();		//描写処理
	int Break(int,int);    //弾を消す関数
	int EnemyShot(double,double);

	//Get関数、引数(type, 配列の何番目か)
	double GetShotCX(int num,int num2) {
		return (num == PLAYER ? playerShot[num2].Get_ShotCX() : (num == ENEMY ? enemyShot[num2].Get_ShotCX() : NULL));
	}
	double GetShotCY(int num, int num2) {
		return (num == PLAYER ? playerShot[num2].Get_ShotCY() : (num == ENEMY ? enemyShot[num2].Get_ShotCY() : NULL));
	}
	double GetShotR(int num, int num2) {
		return (num == PLAYER ? playerShot[num2].Get_ShotR() : (num == ENEMY ? enemyShot[num2].Get_ShotR() : NULL));
	}
	double GetShotOnActive(int num, int num2) {
		return (num == PLAYER ? playerShot[num2].Get_OnActive() : (num == ENEMY ? enemyShot[num2].Get_OnActive() : NULL));
	}


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
