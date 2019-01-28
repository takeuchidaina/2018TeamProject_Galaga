#pragma once



#ifndef _HIT_INCLUDE_
#define _HIT_INCLUDE_

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
#include "EffectMgr.h"
#include "SE.h"
#include "cGreenEnemy.h"

class cHit : public cSingleton<cHit>
{
	cHit();
	friend cSingleton< cHit >;
private:

	/************************************************************
	関数：void cHit::Player_EnemyShot
	説明：自機と敵弾の当たり判定
	引数：なし
	戻り値：なし
	************************************************************/
	void Player_EnemyShot();

	/************************************************************
	関数：void cHit::Player_Enemy
	説明：自機と敵機の当たり判定
	引数：なし
	戻り値：なし
	************************************************************/
	void Player_Enemy();

	/************************************************************
	関数：void cHit::PlayerShot_Enemy
	説明：自弾と敵機の当たり判定
	引数：なし
	戻り値：なし
	************************************************************/
	void PlayerShot_Enemy();

	/************************************************************
	関数：void cHit::PlayerShot_EnemyPlayer
	説明：自弾ときゃとられた自機の当たり判定
	引数：なし
	戻り値：なし
	************************************************************/
	void PlayerShot_EnemyPlayer();

	/************************************************************
	関数：void cHit::Player_EnemyPlayer
	説明：自機ときゃとられた自機の当たり判定
	引数：なし
	戻り値：なし
	************************************************************/
	void Player_EnemyPlayer();

	void Debug();				//デバッグ用関数				

	sOBJPos Player;							//プレイヤー
	cPlayerEnemy* pEnemy;					//プレイヤーエネミー
	double S_onActive, S_cx, S_cy, S_r;		//弾
	double E_onActive, E_cx, E_cy, E_r;		//敵
	bool E_tractingFlg, E_moveFlg;			//敵用フラグ

											// トラクタービーム用
	cPlayerEnemy *TraitPlayer;	//敵プレイヤー
	double player_x, player_y;	//プレイヤー座標
	sEnemy *enemyX;				//敵x座標
	double tractorX;			//トラクターx座標
	double tractorWidth;		//トラクター幅

	double len;

	int totalHit;

protected:

public:

	void Update();	//計算処理
	void Draw();	//描写処理

	/************************************************************
	関数：void TractorHit
	説明：トラクタービーム当たり判定
	引数：double enemyX	ビームを撃った敵のx座標
	戻り値：なし
	************************************************************/
	void TractorHit(sEnemy*);

	bool TractorHitFlg;

	/************************************************************
	関数：void TractingEnemyHit
	説明：EnemyPlayerを持ったボスギャラガの移動中の当たり判定
	引数：tractingEnemy
	戻り値：なし
	************************************************************/
	void TractingEnemyHit();

	int GetTotalHit() {
		return totalHit;
	}

	bool GetTractorHitFlg() {
		return TractorHitFlg;
	}

	void ResetHit() { totalHit = 0; }

};


#endif