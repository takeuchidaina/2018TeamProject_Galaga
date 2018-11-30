#include <DxLib.h>
#include"hit.h"
#include"InGameMgr.h"
#include"Player.h"
#include"ShotMgr.h"
#include"Shot.h"
#include"Shot.cpp"
#include"Player.cpp"
#include"EnemyMgr.h"
#include"cBaseEnemy.h"


/* コンストラクタ */
cHit::cHit() {


}

/* デストラクタ *
cHitFunc::~cHitFunc() {

}*/

void cHit::Update() {

	//cHit::Hit();	//Hit関数呼び出し

	cHit::Player_EnemyShot();	//自機と敵弾の当たり判定
	cHit::Player_Enemy();		//自機と敵機の当たり判定
	cHit::PlayerShot_Enemy();	//自弾と敵機の当たり判定

}

void cHit::Draw() {

}

/************************************************************

 関数：void cHit::Player_EnemyShot
 説明：自機と敵弾の当たり判定

************************************************************/
void cHit::Player_EnemyShot() {

	for (int i = 0; i < MAXMACHINE; i++) {

		Player = cPlayer::Instance()->GetPlayer(i);

		if (Player.onActive == FALSE) continue;

		for (int j = 0; j < ENEMYSHOTNUM; j++) {

			S_onActive = cShotMgr::Instance()->GetShotOnActive(ENEMY, j);
			S_cx = cShotMgr::Instance()->GetShotCX(ENEMY, j);
			S_cy = cShotMgr::Instance()->GetShotCY(ENEMY, j);
			S_r = cShotMgr::Instance()->GetShotR(ENEMY, j);

			if (S_onActive == FALSE) continue;

			len = ((S_cx - Player.cx) * (S_cx - Player.cx)) + ((S_cy - Player.cy)*(S_cy - Player.cy));

			if (len <= ((S_r + Player.r) * (S_r + Player.r))) {

				if (cPlayer::Instance()->GetDoubleFlg() == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}

				else {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}
			}
		}
	}
}

/************************************************************

 関数：void cHit::Player_Enemy
 説明：自機と敵機の当たり判定

************************************************************/
void cHit::Player_Enemy() {

	static int maxEnemy = cEnemyMgr::Instance()->GetMaxEnemy();

	for (int i = 0; i < MAXMACHINE; i++) {

		Player = cPlayer::Instance()->GetPlayer(i);

		if (Player.onActive == FALSE) continue;

		for (int j = 0; j < maxEnemy; j++) {

			E_onActive = cEnemyMgr::Instance()->GetEnemyonActive(j);
			E_cx = cEnemyMgr::Instance()->GetEnemyPosX(j);
			E_cy = cEnemyMgr::Instance()->GetEnemyPosY(j);
			E_r = cEnemyMgr::Instance()->GetEnemyPosR(j);

			if (E_onActive == FALSE) continue;

			len = (E_cx - Player.cx)*(E_cx - Player.cx) + (E_cy - Player.cy)*(E_cy - Player.cy);

			if (len <= ((E_r + Player.r)*(E_r + Player.r))) {

				if (cPlayer::Instance()->GetDoubleFlg() == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Instance()->GetEnemyDeath(j);
				}

				else {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Instance()->GetEnemyDeath(j);
				}
			}
		}
	}

}

/************************************************************

 関数：void cHit::PlayerShot_Enemy
 説明：自弾と敵機の当たり判定

************************************************************/
void cHit::PlayerShot_Enemy() {

	static int maxEnemy = cEnemyMgr::Instance()->GetMaxEnemy();

	for (int i = 0; i < maxEnemy; i++) {

		E_onActive = cEnemyMgr::Instance()->GetEnemyonActive(i);
		E_cx = cEnemyMgr::Instance()->GetEnemyPosX(i);
		E_cy = cEnemyMgr::Instance()->GetEnemyPosY(i);
		E_r = cEnemyMgr::Instance()->GetEnemyPosR(i);

		if (E_onActive == FALSE) continue;

		for (int j = 0; j < PLAYERSHOTNUM; j++) {

			S_onActive = cShotMgr::Instance()->GetShotOnActive(PLAYER, j);
			S_cx = cShotMgr::Instance()->GetShotCX(PLAYER, j);
			S_cy = cShotMgr::Instance()->GetShotCY(PLAYER, j);
			S_r = cShotMgr::Instance()->GetShotR(PLAYER, j);

			if (S_onActive == FALSE) continue;

			double len = (S_cx - E_cx)*(S_cx - E_cx) + (S_cy - E_cy)*(S_cy - E_cy);

			if (len <= ((E_r + S_r)*(E_r + S_r))) {
				cShotMgr::Instance()->Break(PLAYER, j);
				cEnemyMgr::Instance()->GetEnemyDeath(i);
			}
		}
	}
}

/************************************************************
関数：void cHit::BeemHit
説明：トラクタービームの当たり判定
引数：sOBJPos *Player
：cShot *enemyShot
戻値：なし
************************************************************
void cHit::BeemHit() {

sOBJPos Player[2];


if (((tmpEnemy.cx - beemR) <= Player.cx && (tmpEnemy.cx + beemR) >= Player.cx)) {
cInGameMgr(eTractor);
}

}*/












/************************************************************
	関数：void cHit::Hit
	説明：(自機と敵弾) (自機と敵機) (自弾と敵機) の当たり判定
	引数：なし
	呼び出す関数：
		　cPlayer::Instance()->Break("プレイヤーの状態", "どっちのプレイヤーか")
		  cShotMgr::Instance()->Break("どっちの弾か", "どの弾か")
		  cBaseEnemy::Break("どの敵か")
************************************************************
void cHit::Hit() {

	sOBJPos Player[2];
	cShot *tmpEShot[20];
	cShot *tmpPShot[2];
	sEnemy tmpEnemy[20];

	tmpPShot[0] = cShotMgr::Instance()->GetShot(PLAYER);
	tmpEShot[0] = cShotMgr::Instance()->GetShot(ENEMY);

	static int maxEnemy = cEnemyMgr::Instance()->GetMaxEnemy();


	/* 自機と敵弾 *
	for (int i = 0; i < MAXMACHINE; i++) {

		if (Player.onActive == FALSE) continue;

		for (int j = 0; j < sizeof(tmpEShot); j++) {

			if (tmpEShot[j]->Get_OnActive() == FALSE) continue;

			double len = ( (S_cx - Player.cx) * (S_cx - Player.cx) ) + ( (S_cy - Player.cy)*(S_cy - Player.cy) );

			if ( len <= ((S_r + Player.r) * (S_r + Player.r)) ) {

				if (Player[eLeftMachine].onActive == TRUE && Player[eRightMachine].onActive == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}

				else {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}
			}
		}
	}

	/* 自機と敵機　*
	for (int i = 0; i < MAXMACHINE; i++) {

		if (Player.onActive == FALSE) continue;

		for (int j = 0; j < maxEnemy; j++) {

			//if (tmpEnemy[j].mainpos.onActive == FALSE) continue;

			double E_cx = cEnemyMgr::Instance()->GetEnemyPosX(j);
			double E_cy = cEnemyMgr::Instance()->GetEnemyPosY(j);
			double E_r = cEnemyMgr::Instance()->GetEnemyPosR(j);

			double len = (E_cx - Player.cx)*(E_cx - Player.cx) + (E_cy - Player.cy)*(E_cy - Player.cy);

			if (len <= ((E_r + Player.r)*(E_r + Player.r))) {
				
				if (Player[eLeftMachine].onActive == TRUE && Player[eRightMachine].onActive == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Break(j);
				}

				else {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Break(j);
				}
			}
		}
	}

	/* 自弾と敵機　*
	for (int i = 0; i < maxEnemy; i++) {

		//if (E_onActive == FALSE) continue;

		double E_cx = cEnemyMgr::Instance()->GetEnemyPosX(i);
		double E_cy = cEnemyMgr::Instance()->GetEnemyPosY(i);
		double E_r = cEnemyMgr::Instance()->GetEnemyPosR(i);

		for (int j = 0; j < sizeof(tmpPShot); j++) {

			if (S_onActive == FALSE) continue;

			double len = (S_cx - E_cx)*(S_cx - E_cx) + (S_cy - E_cy)*(S_cy - E_cy);

			if (len <= ((E_r + S_r)*(E_r + S_r)) ) {
				cShotMgr::Instance()->Break(PLAYER, j);
				cEnemyMgr::Break(i);
			}
		}
	}
}*/

