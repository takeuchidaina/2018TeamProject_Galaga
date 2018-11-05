#include "hit.h"

//hitクラスの実装

//コンストラクタ
cHit::cHit(){
	
}

//デストラクタ
cHit::~cHit() {

}

int cHit::Update() {
	
	return 0;
}

int cHit::Draw() {

	/* プレイヤーと敵弾 */
	for (int i = 0; i < pNum; i++) {

		if (pActive == false) continue;

		for (int j = 0; j < bNum; j++) {

			if (bActive == false) continue;

			len = (bcx - pcx)*(bcx - pcx) + (bcy - pcy)*(bcy - pcy);

			if (len <= ((br + pr)*(br + pr)) ) {
				bulletHit(enemy, j);
				playerDown(i);
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
				playerDown(player, i);
				enemyDown(enemy, j)
			}
		}
	}

	/* 自弾と敵機　*/
	for (int i = 0; i < eNum; i++) {

		if (eActive == false) continue;

		for (int j = 0; j < ebNum; j++) {

			if (ebActive == false) continue;

			len = (ebcx - ecx)*(ebcx - ecx) + (ebcy - ecy)*(ebcy - ecy);

			if (len <= ((er + ebr)*(er + ebr))) {
				playerDown();
			}
		}
	}

	
	return 0;
}

//beemHitクラスの実装

//コンストラクタ
cBeemHit::cBeemHit() {

}

//デストラクタ
cBeemHit::~cBeemHit() {

}

int cBeemHit::Update() {

	return 0;
}

int cBeemHit::Draw() {

	if (((ecx - beemR) <= pcx) && ((ecx + beemR) >= pcx)) {
		inGameMgr(numEnemy);
	}

	return 0;
}


/*
//実装例
//mTestへの代入
void cTemplate::Set_Test(int Test) {
	mTest = Test;
}

//mTestの獲得
int cTemplate::Get_Test() {
	return mTest;
}
*/