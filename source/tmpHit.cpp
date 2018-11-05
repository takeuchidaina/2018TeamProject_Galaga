#include"hit.h"

int bulletHit() {

	/* プレイヤーと敵弾 */
	for (int i = 0; i < pNum; i++) {

		if (pActive == false) continue;

		for (int j = 0; j < bNum; j++) {

			if (bActive == false) continue;

			len = (bcx - pcx)*(bcx - pcx) + (bcy - pcy)*(bcy - pcy);

			if (len <= ((br + pr)*(br + pr))) {
				if (maxPlayer >= 2) {
					bulletHit(enemy, j);
					playerDown(i);
				}
				else inGameMgr();
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

int beemHit() {

	if ( ((ecx - beemR) <= pcx) && (ecx + beemR) >= pcx) ){
	inGameMgr();
	}
	return 0;
}

x y cx cy r ac