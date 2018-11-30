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

	cHit::Hit();	//Hit関数呼び出し

}

void cHit::Draw() {

}

/************************************************************
	関数：void cHit::Hit
	説明：(自機と敵弾) (自機と敵機) (自弾と敵機) の当たり判定
	引数：なし
	呼び出す関数：
		　cPlayer::Instance()->Break("プレイヤーの状態", "どっちのプレイヤーか")
		  cShotMgr::Instance()->Break("どっちの弾か", "どの弾か")
		  cBaseEnemy::Break("どの敵か")
************************************************************/
void cHit::Hit() {

	sOBJPos tmpPlayer[2];
	cShot *tmpEShot[20];
	cShot *tmpPShot[2];
	//sEnemy tmpEnemy[20];

	tmpPShot[0] = cShotMgr::Instance()->GetShot(PLAYER);
	tmpEShot[0] = cShotMgr::Instance()->GetShot(ENEMY);

	static int maxEnemy = cEnemyMgr::Instance()->GetMaxEnemy();


	/* 自機と敵弾 */
	for (int i = 0; i < MAXMACHINE; i++) {

		if (tmpPlayer[i].onActive == FALSE) continue;

		for (int j = 0; j < sizeof(tmpEShot); j++) {

			if (tmpEShot[j]->Get_OnActive() == FALSE) continue;

			double len = ( (tmpEShot[j]->Get_ShotCX() - tmpPlayer[i].cx) * (tmpEShot[j]->Get_ShotCX() - tmpPlayer[i].cx) ) + ( (tmpEShot[j]->Get_ShotCY() - tmpPlayer[i].cy)*(tmpEShot[j]->Get_ShotCY() - tmpPlayer[i].cy) );

			if ( len <= ((tmpEShot[j]->Get_ShotR() + tmpPlayer[i].r) * (tmpEShot[j]->Get_ShotR() + tmpPlayer[i].r)) ) {

				/* プレイヤーが2機いるときに片方がダウン */
				if (tmpPlayer[eLeftMachine].onActive == TRUE && tmpPlayer[eRightMachine].onActive == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}

				/* プレイヤーが1機のときにダウン */
				else {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}
			}
		}
	}

	/* 自機と敵機　*/
	for (int i = 0; i < MAXMACHINE; i++) {

		if (tmpPlayer[i].onActive == FALSE) continue;

		for (int j = 0; j < maxEnemy; j++) {

			//if (tmpEnemy[j].mainpos.onActive == FALSE) continue;

			double tmpEnemy_cx = cEnemyMgr::Instance()->GetEnemyPosX(j);
			double tmpEnemy_cy = cEnemyMgr::Instance()->GetEnemyPosY(j);
			double tmpEnemy_r = cEnemyMgr::Instance()->GetEnemyPosR(j);

			double len = (tmpEnemy_cx - tmpPlayer[i].cx)*(tmpEnemy_cx - tmpPlayer[i].cx) + (tmpEnemy_cy - tmpPlayer[i].cy)*(tmpEnemy_cy - tmpPlayer[i].cy);

			if (len <= ((tmpEnemy_r + tmpPlayer[i].r)*(tmpEnemy_r + tmpPlayer[i].r))) {
				
				/* プレイヤーが2機いるときに片方がダウン */
				if (tmpPlayer[eLeftMachine].onActive == TRUE && tmpPlayer[eRightMachine].onActive == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Break(j);
				}

				/* プレイヤーが1機のときにダウン */
				else {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Break(j);
				}
			}
		}
	}

	/* 自弾と敵機　*/
	for (int i = 0; i < maxEnemy; i++) {

		//if (tmpEnemy[i].mainpos.onActive == FALSE) continue;

		double tmpEnemy_cx = cEnemyMgr::Instance()->GetEnemyPosX(i);
		double tmpEnemy_cy = cEnemyMgr::Instance()->GetEnemyPosY(i);
		double tmpEnemy_r = cEnemyMgr::Instance()->GetEnemyPosR(i);

		for (int j = 0; j < sizeof(tmpPShot); j++) {

			if (tmpPShot[j]->Get_OnActive() == FALSE) continue;

			double len = (tmpPShot[j]->Get_ShotCX() - tmpEnemy_cx)*(tmpPShot[j]->Get_ShotCX() - tmpEnemy_cx) + (tmpPShot[j]->Get_ShotCY() - tmpEnemy_cy)*(tmpPShot[j]->Get_ShotCY() - tmpEnemy_cy);

			if (len <= ((tmpEnemy_r + tmpPShot[j]->Get_ShotR())*(tmpEnemy_r + tmpPShot[j]->Get_ShotR())) ) {
				cShotMgr::Instance()->Break(PLAYER, j);
				cEnemyMgr::Break(i);
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

	sOBJPos tmpPlayer[2];
	

	if (((tmpEnemy.cx - beemR) <= tmpPlayer.cx && (tmpEnemy.cx + beemR) >= tmpPlayer.cx)) {
		cInGameMgr(eTractor);
	}

}*/