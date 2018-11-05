#include "ShotMgr.h"
#include "DXlib.h"

//Templateクラスの実装

//コンストラクタ(初期化)
cShotMgr::cShotMgr() {
	enemyShot = new cShot[20];
	playerShot = new cShot[2];
	enemyShotGrHandle = LoadGraph("");
	playerShotGrHandle = LoadGraph("");
}

//デストラクタ
cShotMgr::~cShotMgr() {

}

int cShotMgr::Update() {
	for (int i = 0; i < sizeof(enemyShot) / sizeof*(enemyShot); i++) {
		enemyShot[i].Update();
	}
	for (int i = 0; i < sizeof(playerShot) / sizeof*(playerShot); i++) {
		playerShot[i].Update();
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 1) {
		for (int i = 0; i < sizeof*(playerShot); i++) {
			if( playerShot[i].Get_OnActive() == false) {
				playerShot[i].Set_OnActive(1);//0=false,1=true
				//プレイヤーの座標を受け取って座標をセット
				break;
			}
		}
	}
	return 0;
}

int cShotMgr::Draw() {
	for (int i = 0; i < sizeof(enemyShot) / sizeof*(enemyShot); i++) {
		enemyShot[i].Draw();
	}
	for (int i = 0; i < sizeof(playerShot) / sizeof*(playerShot); i++) {
		playerShot[i].Draw();
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