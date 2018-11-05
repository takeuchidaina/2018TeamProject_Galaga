#include "ShotMgr.h"
#include "DXlib.h"

//Template�N���X�̎���

//�R���X�g���N�^(������)
cShotMgr::cShotMgr() {
	enemyShot = new cShot[20];
	playerShot = new cShot[2];
	enemyShotGrHandle = LoadGraph("");
	playerShotGrHandle = LoadGraph("");
}

//�f�X�g���N�^
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
				//�v���C���[�̍��W���󂯎���č��W���Z�b�g
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
//������
//mTest�ւ̑��
void cTemplate::Set_Test(int Test) {
mTest = Test;
}

//mTest�̊l��
int cTemplate::Get_Test() {
return mTest;
}
*/