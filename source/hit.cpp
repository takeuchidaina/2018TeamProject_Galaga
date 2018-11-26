#include <DxLib.h>
#include"hit.h"
#include"InGameMgr.h"
#include"Player.h"
#include"ShotMgr.h"
#include"Shot.h"
#include"Shot.cpp"
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
	引数：sOBJPos tmpPlayer
		：cShot tmpEShot
		：		tmpPShot
		：sEnemy tmpEnemy
	戻値：なし
************************************************************/
void cHit::Hit() {

	sOBJPos tmpPlayer[2];
	cShot tmpEShot[20];
	cShot tmpPShot[2];
	sEnemy tmpEnemy[20];


	/* 自機と敵弾 */
	for (int i = 0; i < MAXMACHINE; i++) {

		if (tmpPlayer[i].onActive == FALSE) continue;



		for (int j = 0; j < sizeof(tmpEShot); j++) {

			if (tmpEShot[j].Get_OnActive == FALSE) continue;

			int len = ( (tmpEShot[j].Get_ShotCX - tmpPlayer[i].cx) * (tmpEShot[j].Get_ShotCX - tmpPlayer[i].cx) ) + ( (tmpEShot[j].Get_ShotCY - tmpPlayer[i].cy)*(tmpEShot[j].Get_ShotCY - tmpPlayer[i].cy) );

			if ( len <= ((tmpEShot[j].Get_ShotR + tmpPlayer[i].r) * (tmpEShot[j].Get_ShotR + tmpPlayer[i].r)) ) {

				/* プレイヤーが2機いるときに片方がダウン
				   呼び出し関数：cPlayer::Braik("プレイヤーの状態", "どっちのプレイヤーか") */
				if (tmpPlayer[eLeftMachine].onActive == TRUE && tmpPlayer[eRightMachine].onActive == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}

				/* プレイヤーが1機のときにダウン
				   呼び出し関数：cPlayer::Braik("プレイヤーの状態", "どっちのプレイヤーか") */
				else {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}
			}
		}
	}

	/* 自機と敵機　*/
	/*for (int i = 0; i < MAXMACHINE; i++) {

		if (tmpPlayer[i].onActive == FALSE) continue;

		for (int j = 0; j < sizeof(tmpEnemy); j++) {

			if (tmpEnemy[j].onActive == FALSE) continue;

			int len = (tmpEnemy[j].cx - tmpPlayer[i].cx)*(tmpEnemy[j].cx - tmpPlayer[i].cx) + (tmpEnemy[j].cy - tmpPlayer[i].cy)*(tmpEnemy[j].cy - tmpPlayer[i].cy);

			if (len <= ((tmpEnemy[j].r + tmpPlayer[i].r)*(tmpEnemy[j].r + tmpPlayer[i].r))) {
				
				/* プレイヤーが2機いるときに片方がダウン
				呼び出し関数：cPlayer::Braik("プレイヤーの状態", "どっちのプレイヤーか") *
				if (tmpPlayer[eLeftMachine].onActive == TRUE && tmpPlayer[eRightMachine].onActive == TRUE) {
					cPlayer::Instance()->Break(eDoubleDeath, i);
					sEnemy::Instance()->Break(j);
				}

				/* プレイヤーが1機のときにダウン
				呼び出し関数：cPlayer::Braik("プレイヤーの状態", "どっちのプレイヤーか") *
				else {
					cPlayer::Instance()->Break(eDeath, i);
					sEnemy::Instance()->Break(j);
				}
			}
		}
	}*/

	/* 自弾と敵機　*/
	/*for (int i = 0; i < sizeof(enemy); i++) {

		if (enemy[i].OnActive == FALSE) continue;

		for (int j = 0; j < sizeof(tmpPShot); j++) {

			if (tmpPShot[j].Get_OnActive == FALSE) continue;

			int len = (tmpPShot[j].Get_ShotCX - enemy[i].cx)*(tmpPShot[j].Get_ShotCX - enemy[i].cx) + (tmpPShot[j].Get_ShotCY - enemy[i].cy)*(tmpPShot[j].Get_ShotCY - enemy[i].cy);

			if (len <= ((enemy[i].r + tmpPShot[j].Get_ShotR)*(enemy[i].r + tmpPShot[j].Get_ShotR)) ) {
				cShotMgr::Instance()->Break(PLAYER, j);
				sEnemy::Instance()->Break(i);
			}
		}
	}*/
}

/************************************************************
関数：void cHit::BeemHit 
説明：トラクタービームの当たり判定
引数：sOBJPos *Player
	：cShot *enemyShot
戻値：なし
************************************************************
void cHit::BeemHit(sOBJPos Player ,sEnemy enemy) {

	sOBJPos tmpPlayer[2];
	sEnemy tmpEnemy[20];

	if (((tmpEnemy.cx - beemR) <= tmpPlayer.cx && (tmpEnemy.cx + beemR) >= tmpPlayer.cx)) {
		cInGameMgr(eTractor);
	}

}*/