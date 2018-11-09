#include <DxLib.h>
#include"Hit.h"
#include"InGameMgr.h"
#include"player.h"

int bulletHit(int *player, int *eBullet, int *pBullet, int*enemy) {

	/* ポインタアドレス割当 */
	int pcx = player._cx;
	int pcy = player._cy;
	int pr = player._r;

	int ecx = enemy._cx;
	int ecy = enemy._cy;
	int er = enemy._r;

	int eBcx = eBullet._cx;
	int eBcy = eBullet._cy;
	int ebr = eBullet._r;

	int pBcx = pBullet._cx;
	int pBcy = pBullet._cy;
	int pbr = pBullet._r;

	/* プレイヤーと敵弾 */
	for (int i = 0; i < MAXMACHINE; i++) {

		if (*(player.onActive + i) == false) continue;

		for (int j = 0; j < numB; j++) {

			if (*(eBullet.onActive + j) == false) continue;

			int len = ((*(eBcx + j) - *(pcx + i)) * (*(eBcx + j) - *(pcx + i))) + ((*(eBcy + j) - *(pcy + i))*(*(eBcy + j) - *(pcy + i)));

			if (len <= ((*(ebr + j) + *(pr + i)) * (*(ebr + j) + *(pr + i)))) {
				if (*player.onActive == true && *(player.onActive + 1) == true) {
					bulletHit(enemy, j);
					playerDown(i);
				}
				else inGameMgr();
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


	return 0;
}

int clashHit() {

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
}

int beemHit() {

	if (((ecx - beemR) <= pcx && (ecx + beemR) >= pcx)) {
		InGameMgr();
	}
	return 0;
}

void hit_Update() {

	bulletHit();
	clashHit();
	beemHit();

}