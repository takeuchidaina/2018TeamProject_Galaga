#include "player.h"

//hitクラスの実装

//コンストラクタ
cHit::cHit(){
	
}

//デストラクタ
cHit::~cHit() {

}

int cHit::Update() {


	double pcx, pcy, pr, pNum, pActive;
	double bcx, bcy, bActive, br, bNum;
	double len;
	
	return 0;
}

int cHit::Draw() {

	for (int i = 0; i < pNum; i++) {

		if (pActive == false) continue;

		for (int j = 0; j < bNum; j++) {

			if (bActive == false) continue;

			len = (bcx - pcx)*(bcx - pcx) + (bcy - pcy)*(bcy - pcy);

			if (len <= ((br + pr)*(br + pr))) {
				playerDown();
			}
		}
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