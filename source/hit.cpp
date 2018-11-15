#include <DxLib.h>
#include"hit.h"
#include"InGameMgr.h"
#include"Player.h"
#include"ShotMgr.h"
#include"Shot.h"
#include"Player.cpp"

void  cHitFunc::Hit(sOBJPos *Player, cShot *enemyShot) {

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
	for (int i = 0; i < pNum; i++) {

		if (pActive == false) continue;

		for (int j = 0; j < eNum; j++) {

			if (eActive == false) continue;

			len = (ecx - pcx)*(ecx - pcx) + (ecy - pcy)*(ecy - pcy);

			if (len <= ((er + pr)*(er + pr))) {
				if (maxPlayer >= 2) {
					playerDown(player, i);
					enemyDown(enemy, j);
				}
				else InGameMgr();
			}
		}
	}

	/* 自弾と敵機　*/
	for (int i = 0; i < eNum; i++) {

		if (eActive == false) continue;

		for (int j = 0; j < pbNum; j++) {

			if (pbActive == false) continue;

			len = (pbcx - ecx)*(pbcx - ecx) + (pbcy - ecy)*(pbcy - ecy);

			if (len <= ((er + pbr)*(er + pbr))) {
				enemyDown(i);
			}
		}
	}
}

void beemHit() {

	if (((ecx - beemR) <= pcx && (ecx + beemR) >= pcx)) {
		InGameMgr();
	}

}

void hit_Update() {

	bulletHit();
	clashHit();
	beemHit();

}