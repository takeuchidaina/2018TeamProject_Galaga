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


/* �R���X�g���N�^ */
cHit::cHit() {


}

/* �f�X�g���N�^ *
cHitFunc::~cHitFunc() {

}*/

void cHit::Update() {

	//cHit::Hit();	//Hit�֐��Ăяo��

	cHit::Player_EnemyShot();	//���@�ƓG�e�̓����蔻��
	cHit::Player_Enemy();		//���@�ƓG�@�̓����蔻��
	cHit::PlayerShot_Enemy();	//���e�ƓG�@�̓����蔻��

}

void cHit::Draw() {

}

/************************************************************

 �֐��Fvoid cHit::Player_EnemyShot
 �����F���@�ƓG�e�̓����蔻��

************************************************************/
void cHit::Player_EnemyShot() {

	for (int i = 0; i < MAXMACHINE; i++) {

		Player = cPlayer::Instance()->GetPlayer(i);

		if (Player.onActive == FALSE) continue;

		for (int j = 0; j < ENEMYSHOTNUM; j++) {

			S_onActive = cShotMgr::Instance()->GetShotOnActive(ENEMY, j);
			S_cx = cShotMgr::Instance()->GetShotCX(ENEMY, j);
			S_cy = cShotMgr::Instance()->GetShotCY(ENEMY, j);
			S_r = cShotMgr::Instance()->GetShotR(ENEMY, j);

			if (S_onActive == FALSE) continue;

			len = ((S_cx - Player.cx) * (S_cx - Player.cx)) + ((S_cy - Player.cy)*(S_cy - Player.cy));

			if (len <= ((S_r + Player.r) * (S_r + Player.r))) {

				if (cPlayer::Instance()->GetDoubleFlg() == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}

				else {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}
			}
		}
	}
}

/************************************************************

 �֐��Fvoid cHit::Player_Enemy
 �����F���@�ƓG�@�̓����蔻��

************************************************************/
void cHit::Player_Enemy() {

	static int maxEnemy = cEnemyMgr::Instance()->GetMaxEnemy();

	for (int i = 0; i < MAXMACHINE; i++) {

		Player = cPlayer::Instance()->GetPlayer(i);

		if (Player.onActive == FALSE) continue;

		for (int j = 0; j < maxEnemy; j++) {

			E_onActive = cEnemyMgr::Instance()->GetEnemyonActive(j);
			E_cx = cEnemyMgr::Instance()->GetEnemyPosX(j);
			E_cy = cEnemyMgr::Instance()->GetEnemyPosY(j);
			E_r = cEnemyMgr::Instance()->GetEnemyPosR(j);

			if (E_onActive == FALSE) continue;

			len = (E_cx - Player.cx)*(E_cx - Player.cx) + (E_cy - Player.cy)*(E_cy - Player.cy);

			if (len <= ((E_r + Player.r)*(E_r + Player.r))) {

				if (cPlayer::Instance()->GetDoubleFlg() == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Instance()->GetEnemyDeath(j);
				}

				else {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Instance()->GetEnemyDeath(j);
				}
			}
		}
	}

}

/************************************************************

 �֐��Fvoid cHit::PlayerShot_Enemy
 �����F���e�ƓG�@�̓����蔻��

************************************************************/
void cHit::PlayerShot_Enemy() {

	static int maxEnemy = cEnemyMgr::Instance()->GetMaxEnemy();

	for (int i = 0; i < maxEnemy; i++) {

		E_onActive = cEnemyMgr::Instance()->GetEnemyonActive(i);
		E_cx = cEnemyMgr::Instance()->GetEnemyPosX(i);
		E_cy = cEnemyMgr::Instance()->GetEnemyPosY(i);
		E_r = cEnemyMgr::Instance()->GetEnemyPosR(i);

		if (E_onActive == FALSE) continue;

		for (int j = 0; j < PLAYERSHOTNUM; j++) {

			S_onActive = cShotMgr::Instance()->GetShotOnActive(PLAYER, j);
			S_cx = cShotMgr::Instance()->GetShotCX(PLAYER, j);
			S_cy = cShotMgr::Instance()->GetShotCY(PLAYER, j);
			S_r = cShotMgr::Instance()->GetShotR(PLAYER, j);

			if (S_onActive == FALSE) continue;

			double len = (S_cx - E_cx)*(S_cx - E_cx) + (S_cy - E_cy)*(S_cy - E_cy);

			if (len <= ((E_r + S_r)*(E_r + S_r))) {
				cShotMgr::Instance()->Break(PLAYER, j);
				cEnemyMgr::Instance()->GetEnemyDeath(i);
			}
		}
	}
}

/************************************************************
�֐��Fvoid cHit::BeemHit
�����F�g���N�^�[�r�[���̓����蔻��
�����FsOBJPos *Player
�FcShot *enemyShot
�ߒl�F�Ȃ�
************************************************************
void cHit::BeemHit() {

sOBJPos Player[2];


if (((tmpEnemy.cx - beemR) <= Player.cx && (tmpEnemy.cx + beemR) >= Player.cx)) {
cInGameMgr(eTractor);
}

}*/












/************************************************************
	�֐��Fvoid cHit::Hit
	�����F(���@�ƓG�e) (���@�ƓG�@) (���e�ƓG�@) �̓����蔻��
	�����F�Ȃ�
	�Ăяo���֐��F
		�@cPlayer::Instance()->Break("�v���C���[�̏��", "�ǂ����̃v���C���[��")
		  cShotMgr::Instance()->Break("�ǂ����̒e��", "�ǂ̒e��")
		  cBaseEnemy::Break("�ǂ̓G��")
************************************************************
void cHit::Hit() {

	sOBJPos Player[2];
	cShot *tmpEShot[20];
	cShot *tmpPShot[2];
	sEnemy tmpEnemy[20];

	tmpPShot[0] = cShotMgr::Instance()->GetShot(PLAYER);
	tmpEShot[0] = cShotMgr::Instance()->GetShot(ENEMY);

	static int maxEnemy = cEnemyMgr::Instance()->GetMaxEnemy();


	/* ���@�ƓG�e *
	for (int i = 0; i < MAXMACHINE; i++) {

		if (Player.onActive == FALSE) continue;

		for (int j = 0; j < sizeof(tmpEShot); j++) {

			if (tmpEShot[j]->Get_OnActive() == FALSE) continue;

			double len = ( (S_cx - Player.cx) * (S_cx - Player.cx) ) + ( (S_cy - Player.cy)*(S_cy - Player.cy) );

			if ( len <= ((S_r + Player.r) * (S_r + Player.r)) ) {

				if (Player[eLeftMachine].onActive == TRUE && Player[eRightMachine].onActive == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}

				else {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}
			}
		}
	}

	/* ���@�ƓG�@�@*
	for (int i = 0; i < MAXMACHINE; i++) {

		if (Player.onActive == FALSE) continue;

		for (int j = 0; j < maxEnemy; j++) {

			//if (tmpEnemy[j].mainpos.onActive == FALSE) continue;

			double E_cx = cEnemyMgr::Instance()->GetEnemyPosX(j);
			double E_cy = cEnemyMgr::Instance()->GetEnemyPosY(j);
			double E_r = cEnemyMgr::Instance()->GetEnemyPosR(j);

			double len = (E_cx - Player.cx)*(E_cx - Player.cx) + (E_cy - Player.cy)*(E_cy - Player.cy);

			if (len <= ((E_r + Player.r)*(E_r + Player.r))) {
				
				if (Player[eLeftMachine].onActive == TRUE && Player[eRightMachine].onActive == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Break(j);
				}

				else {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Break(j);
				}
			}
		}
	}

	/* ���e�ƓG�@�@*
	for (int i = 0; i < maxEnemy; i++) {

		//if (E_onActive == FALSE) continue;

		double E_cx = cEnemyMgr::Instance()->GetEnemyPosX(i);
		double E_cy = cEnemyMgr::Instance()->GetEnemyPosY(i);
		double E_r = cEnemyMgr::Instance()->GetEnemyPosR(i);

		for (int j = 0; j < sizeof(tmpPShot); j++) {

			if (S_onActive == FALSE) continue;

			double len = (S_cx - E_cx)*(S_cx - E_cx) + (S_cy - E_cy)*(S_cy - E_cy);

			if (len <= ((E_r + S_r)*(E_r + S_r)) ) {
				cShotMgr::Instance()->Break(PLAYER, j);
				cEnemyMgr::Break(i);
			}
		}
	}
}*/

