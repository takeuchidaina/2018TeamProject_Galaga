#include <DxLib.h>
#include"hit.h"
#include"InGameMgr.h"
#include"Player.h"
#include"ShotMgr.h"
#include"Shot.h"
#include"Player.cpp"
#include"EnemyMgr.h"

/* コンストラクタ */
cHitFunc::cHitFunc() {


}

/* デストラクタ */
cHitFunc::~cHitFunc() {

}

void cHitFunc::Update() {

	cHitFunc::Hit(sOBJPos Player, cShot *enemyShot, cShot *playerShot, sEnemy *enemy);	//Hit関数呼び出し

}

void cHitFunc::Draw() {

}
/************************************************************
	関数：void cHitFunc::Hit
	説明：(自機と敵弾) (自機と敵機) (自弾と敵機) の当たり判定
	引数：sOBJPos *Player
		：cShot *enemyShot
		：		*playerShot
		：sEnemy *enemy
	戻値：なし
************************************************************/
void cHitFunc::Hit(sOBJPos Player, cShot enemyShot, cShot playerShot, sEnemy enemy) {

	/* プレイヤーと敵弾 */
	for (int i = 0; i < MAXMACHINE; i++) {

		if (Player[i].onActive == false) continue;

		for (int j = 0; j < sizeof(enemyShot); j++) {

			if (enemyShot[j].Get_OnActive == false) continue;

			int len = ( (enemyShot[j].cx - Player[i].cx) * (enemyShot[j].cx - Player[i].cx) ) + ( (enemyShot[j].cy - Player[i].cy)*(enemyShot[j].cy - Player[i].cy) );

			if ( len <= ((enemyShot[j].r + Player[i].r) * (enemyShot[j].r + Player[i].r))) {
				if (Player[eLeftMachine].onActive == true && Player[eRightMachine].onActive == true) {
					cPlayer::Break(eDoubleDeath, i);
				}
				else cInGameMgr();
			}
		}
	}

	/* プレイヤーと敵機　*/
	for (int i = 0; i < MAXMACHINE; i++) {

		if (Player[i].onActive == false) continue;

		for (int j = 0; j < sizeof(enemy); j++) {

			if (enemy[j].onActive == false) continue;

			int len = (enemy[j].cx - Player[i].cx)*(enemy[j].cx - Player[i].cx) + (enemy[j].cy - Player[i].cy)*(enemy[j].cy - Player[i].cy);

			if (len <= ((enemy[j].r + Player[i].r)*(enemy[j].r + Player[i].r))) {
				if (Player[eLeftMachine].onActive == true && Player[eRightMachine].onActive == true) {
					cPlayer::Break(eDoubleDeath, i);
				}
				else cInGameMgr();
			}
		}
	}

	/* 自弾と敵機　*/
	for (int i = 0; i < sizeof(enemy); i++) {

		if (enemy[i].OnActive == false) continue;

		for (int j = 0; j < sizeof(playerShot); j++) {

			if (playerShot[j].Get_OnActive == false) continue;

			int len = (playerShot[j].cx - enemy[i].cx)*(playerShot[j].cx - enemy[i].cx) + (playerShot[j].cy - enemy[i].cy)*(playerShot[j].cy - enemy[i].cy);

			if (len <= ((enemy[i].r + playerShot[j].r)*(enemy[i].r + playerShot[j].r)) ) {
				enemyDown(i);
			}
		}
	}
}

/************************************************************
関数：void cHitFunc::BeemHit
説明：トラクタービームの当たり判定
引数：sOBJPos *Player
	：cShot *enemyShot
戻値：なし
************************************************************/
void cHitFunc::BeemHit(sOBJPs Plsyer) {

	if (((ecx - beemR) <= pcx && (ecx + beemR) >= pcx)) {
		InGameMgr();
	}

}