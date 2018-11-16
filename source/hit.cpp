#include <DxLib.h>
#include"hit.h"
#include"InGameMgr.h"
#include"Player.h"
#include"ShotMgr.h"
#include"Shot.h"
#include"Player.cpp"
#include"EnemyMgr.h"

/* �R���X�g���N�^ */
cHitFunc::cHitFunc() {


}

/* �f�X�g���N�^ */
cHitFunc::~cHitFunc() {

}

void cHitFunc::Update() {

	cHitFunc::Hit(sOBJPos Player, cShot *enemyShot, cShot *playerShot, sEnemy *enemy);	//Hit�֐��Ăяo��

}

void cHitFunc::Draw() {

}
/************************************************************
	�֐��Fvoid cHitFunc::Hit
	�����F(���@�ƓG�e) (���@�ƓG�@) (���e�ƓG�@) �̓����蔻��
	�����FsOBJPos *Player
		�FcShot *enemyShot
		�F		*playerShot
		�FsEnemy *enemy
	�ߒl�F�Ȃ�
************************************************************/
void cHitFunc::Hit(sOBJPos Player, cShot enemyShot, cShot playerShot, sEnemy enemy) {

	/* �v���C���[�ƓG�e */
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

	/* �v���C���[�ƓG�@�@*/
	for (int i = 0; i < MAXMACHINE; i++) {

		if (Player[i].onActive == false) continue;

		for (int j = 0; j < sizeof(enemy); j++) {

			if (enemy[j].onActive == false) continue;

			int len = (enemy[j].cx - Player[i].cx)*(enemy[j].cx - Player[i].cx) + (enemy[j].cy - Player[i].cy)*(enemy[j].cy - Player[i].cy);

			if (len <= ((enemy[j].r + Player[i].r)*(enemy[j].r + Player[i].r))) {
				if (Player[eLeftMachine].onActive == true && Player[eRightMachine].onActive == true) {
					cPlayer::Break(eDoubleDeath, i);
				}
				else cInGameMgr();
			}
		}
	}

	/* ���e�ƓG�@�@*/
	for (int i = 0; i < sizeof(enemy); i++) {

		if (enemy[i].OnActive == false) continue;

		for (int j = 0; j < sizeof(playerShot); j++) {

			if (playerShot[j].Get_OnActive == false) continue;

			int len = (playerShot[j].cx - enemy[i].cx)*(playerShot[j].cx - enemy[i].cx) + (playerShot[j].cy - enemy[i].cy)*(playerShot[j].cy - enemy[i].cy);

			if (len <= ((enemy[i].r + playerShot[j].r)*(enemy[i].r + playerShot[j].r)) ) {
				enemyDown(i);
			}
		}
	}
}

/************************************************************
�֐��Fvoid cHitFunc::BeemHit
�����F�g���N�^�[�r�[���̓����蔻��
�����FsOBJPos *Player
	�FcShot *enemyShot
�ߒl�F�Ȃ�
************************************************************/
void cHitFunc::BeemHit(sOBJPs Plsyer) {

	if (((ecx - beemR) <= pcx && (ecx + beemR) >= pcx)) {
		InGameMgr();
	}

}