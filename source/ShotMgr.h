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
	int EnemyShot();
	cShot GetShot(int num) {
		cShot *p = NULL;//エラー時NULL
		//num==PLAYERなら*playerShot num==ENEMYなら*enemyShot
		return (num == PLAYER ? *playerShot : (num == ENEMY ? *enemyShot : *p));
		/*if (num == PLAYER) {
			return *playerShot;
		}
		else if (num == ENEMY) {
			return *enemyShot;
		}
		else {
			return *p;
		}*/
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
