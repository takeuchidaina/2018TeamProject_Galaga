#pragma once

#ifndef _SHOTMGR_INCLUDE_
#define _SHOTMGR_INCLUDE_
#include "Shot.h"
#include "Singleton.h"
#include "Player.h"
#include "Struct.h"
#include "Winbox.h"
#include "hit.h"

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
	~cShotMgr();
	friend cSingleton<cShotMgr>;
private:
	cShot *enemyShot, *player1Shot, *player2Shot;
	int totalShot;
	int ShotGrHandle[4];
	int shotRate;
	int checkGr;
	int ShotFlg;

	//トラクター関係
	int tractorGrHandle[12];
	int tractorOnActive;
	int hitFlg;
	int tractorCnt;
	int tmpCnt;
	int tractorAnimation[23] = { 0,1,2,3,4,5,6,7,8,9,10,11,10,9,8,7,6,5,4,3,2,1,0 };

protected:

public:
	int Update();	//計算処理
	int Draw();		//描写処理
	void Init();
	int Break(int,int);    //弾を消す関数
	int EnemyShot(double,double);
	int TractorShot(sEnemy*);

	//ShotFlgの関数(TRUE FALSE)
	void SetShotFlg(int num) { ShotFlg = num; }

	//GetPlayerShot関数、引数(player1かplayer2, 配列の何番目か(0か1))
	double GetPlayerShotCX(int num,int num2) {
		return (num == 0 ? player1Shot[num2].Get_ShotCX() : (num == 1 ? player2Shot[num2].Get_ShotCX() : NULL));
	}
	double GetPlayerShotCY(int num, int num2) {
		return (num == 0 ? player1Shot[num2].Get_ShotCY() : (num == 1 ? player2Shot[num2].Get_ShotCY() : NULL));
	}
	double GetPlayerShotR(int num, int num2) {
		return (num == 0 ? player1Shot[num2].Get_ShotR() : (num == 1 ? player2Shot[num2].Get_ShotR() : NULL));
	}
	double GetPlayerShotOnActive(int num, int num2) {
		return (num == 0 ? player1Shot[num2].Get_OnActive() : (num == 1 ? player2Shot[num2].Get_OnActive() : NULL));
	}

	//GetEnemyShot関数、引数(配列の何番目か(0-19))
	double GetEnemyShotCX(int num) {
		return enemyShot[num].Get_ShotCX();
	}
	double GetEnemyShotCY(int num) {
		return enemyShot[num].Get_ShotCY();
	}
	double GetEnemyShotR(int num) {
		return enemyShot[num].Get_ShotR();
	}
	double GetEnemyShotOnActive(int num) {
		return enemyShot[num].Get_OnActive();
	}

	//totalShotの受け渡し
	int GetTotalShot() {
		return totalShot;
	}

	//Tractor用
	int GetTractorHit() {
		return hitFlg;
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
