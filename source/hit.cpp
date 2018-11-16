#include <DxLib.h>
#include"hit.h"
#include"InGameMgr.h"
#include"Player.h"
#include"ShotMgr.h"
#include"Shot.h"
#include"Player.cpp"
#include"EnemyMgr.h"


/* コンストラクタ */
cHit::cHit() {


}

/* デストラクタ *
cHitFunc::~cHitFunc() {

}*/

void cHit::Update() {

	cHit::Hit();	//Hit関数呼び出し

}

void cHit::Draw() {

}
/************************************************************
	関数：void cHit::Hit
	説明：(自機と敵弾) (自機と敵機) (自弾と敵機) の当たり判定
	引数：sOBJPos *Player
		：cShot *enemyShot
		：		*playerShot
		：sEnemy *enemy
	戻値：なし
************************************************************/
void cHit::Hit() {

	sOBJPos tmpPlayer[2];
	cShot tmpEShot[20];
	cShot tmpPShot[2];
	sEnemy tmpEnemy[20];


	/* プレイヤーと敵弾 */
	for (int i = 0; i < MAXMACHINE; i++) {

		if (tmpPlayer[i].onActive == false) continue;

		for (int j = 0; j < sizeof(tmpEShot); j++) {

			if (tmpEShot[j].Get_OnActive == false) continue;

			int len = ( (tmpEShot[j].cx - tmpPlayer[i].cx) * (tmpEShot[j].cx - tmpPlayer[i].cx) ) + ( (tmpEShot[j].cy - tmpPlayer[i].cy)*(tmpEShot[j].cy - tmpPlayer[i].cy) );

			if ( len <= ((tmpEShot[j].r + tmpPlayer[i].r) * (tmpEShot[j].r + tmpPlayer[i].r))) {

				/* プレイヤーが2機いるときに片方がダウン
				   呼び出し関数：cPlayer::Braik("プレイヤーの状態", "どっちのプレイヤーか") */
				if (tmpPlayer[eLeftMachine].onActive == true && tmpPlayer[eRightMachine].onActive == true) {
					cPlayer::Instance()->Break(eDoubleDeath, i);
					cShot::Instance()->Break(ENEMY, j);
				}

				/* プレイヤーが1機のときにダウン
				   呼び出し関数：cPlayer::Braik("プレイヤーの状態", "どっちのプレイヤーか") */
				else {
					cPlayer::Instance()->Break(eDeath, i);
					cShot::Instance()->Break(ENEMY, j);
				}
			}
		}
	}

	/* プレイヤーと敵機　*/
	for (int i = 0; i < MAXMACHINE; i++) {

		if (tmpPlayer[i].onActive == false) continue;

		for (int j = 0; j < sizeof(tmpEnemy); j++) {

			if (tmpEnemy[j].onActive == false) continue;

			int len = (tmpEnemy[j].cx - tmpPlayer[i].cx)*(tmpEnemy[j].cx - tmpPlayer[i].cx) + (tmpEnemy[j].cy - tmpPlayer[i].cy)*(tmpEnemy[j].cy - tmpPlayer[i].cy);

			if (len <= ((tmpEnemy[j].r + tmpPlayer[i].r)*(tmpEnemy[j].r + tmpPlayer[i].r))) {
				
				/* プレイヤーが2機いるときに片方がダウン
				呼び出し関数：cPlayer::Braik("プレイヤーの状態", "どっちのプレイヤーか") */
				if (tmpPlayer[eLeftMachine].onActive == true && tmpPlayer[eRightMachine].onActive == true) {
					cPlayer::Instance()->Break(eDoubleDeath, i);
					sEnemy::Instance()->Break(j);
				}

				/* プレイヤーが1機のときにダウン
				呼び出し関数：cPlayer::Braik("プレイヤーの状態", "どっちのプレイヤーか") */
				else {
					cPlayer::Instance()->Break(eDeath, i);
					sEnemy::Instance()->Break(j);
				}
			}
		}
	}

	/* 自弾と敵機　*/
	for (int i = 0; i < sizeof(enemy); i++) {

		if (enemy[i].OnActive == false) continue;

		for (int j = 0; j < sizeof(tmpPShot); j++) {

			if (tmpPShot[j].Get_OnActive == false) continue;

			int len = (tmpPShot[j].cx - enemy[i].cx)*(tmpPShot[j].cx - enemy[i].cx) + (tmpPShot[j].cy - enemy[i].cy)*(tmpPShot[j].cy - enemy[i].cy);

			if (len <= ((enemy[i].r + tmpPShot[j].r)*(enemy[i].r + tmpPShot[j].r)) ) {
				cShot::Instance()->Break(PLAYER, j);
				sEnemy::Instance()->Break(i);
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
void cHit::BeemHit(sOBJPos Player ,sEnemy enemy) {

	if (((enemy.cx - beemR) <= Player.cx && (enemy.cx + beemR) >= Player.cx)) {
		cInGameMgr(eTractor);
	}

}*/