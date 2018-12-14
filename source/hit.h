#pragma once



#ifndef _HIT_INCLUDE_
#define _HIT_INCLUDE_

#define MAXMACHINE 2

#define PLAYER 0
#define ENEMY 1

#include "Singleton.h"
#include "Struct.h"
#include "Player.h"
#include "InGameMgr.h"
#include "ShotMgr.h"
#include "Shot.h"
#include "EnemyMgr.h"
#include "cBaseEnemy.h"

class cHit: public cSingleton<cHit>
{
	cHit();
	friend cSingleton< cHit >;
private:

	//void Hit();		//当たり判定

	void Player_EnemyShot();	//自機と敵弾の当たり判定
	void Player_Enemy();		//自機と敵機の当たり判定
	void PlayerShot_Enemy();	//自弾と敵機の当たり判定

	void Debug();				//デバッグ用関数				

	sOBJPos Player;							//プレイヤー
	double S_onActive, S_cx, S_cy, S_r;		//弾
	double E_onActive, E_cx, E_cy, E_r;		//敵
	
	double beemR;
	double len;

	int totalHit;

protected:

public:

	void Update();	//計算処理
	void Draw();	//描写処理
	void BeemHit(int); //トラクタービーム当たり判定

	int GetTotalHit() {
		return totalHit;
	}

};


#endif