 #include "ShotMgr.h"
#include "DXlib.h"

//Template�N���X�̎���

//�R���X�g���N�^(������)
cShotMgr::cShotMgr() {
	enemyShot = new cShot[20];
	playerShot = new cShot[2];
	totalShot = 0;
	LoadDivGraph("../resource/Image/Galaga_OBJ_bullet.png",4,4,0,10,12,ShotGrHandle);
}

int cShotMgr::Update() {
	for (int i = 0; i < sizeof(enemyShot) / sizeof*(enemyShot); i++) {
		enemyShot[i].Update();
	}
	for (int i = 0; i < sizeof(playerShot) / sizeof*(playerShot); i++) {
		playerShot[i].Update();
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == TRUE) {
		for (int i = 0; i < sizeof*(playerShot); i++) {
			if( playerShot[i].Get_OnActive() == false) {
				playerShot[i].Set_OnActive(TRUE);//0=false,1=true
				//�v���C���[�̍��W���󂯎���č��W���Z�b�g
				sOBJPos tmp;
				tmp = cPlayer::Instance()->GetPlayer(0);
				playerShot[i].Set_ShotX(tmp.pos.x);
				playerShot[i].Set_ShotY(tmp.pos.y);
				totalShot++;
				break;
			}
		}
	}
	return 0;
}

int cShotMgr::Draw() {
	for (int i = 0; i < sizeof(enemyShot) / sizeof*(enemyShot); i++) {
		enemyShot[i].Draw(ENEMY,ShotGrHandle);
	}
	for (int i = 0; i < sizeof(playerShot) / sizeof*(playerShot); i++) {
		playerShot[i].Draw(PLAYER,ShotGrHandle);
	}
	DrawFormatString(420,500,GetColor(255,0,255),"totalShot:%d",totalShot);
	return 0;
}

//�e����������
int cShotMgr::Break(int type,int num) {
	if (type == PLAYER) {
		playerShot[num].Set_OnActive(FALSE);
	}
	else if (type == ENEMY) {
		enemyShot[num].Set_OnActive(FALSE);
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