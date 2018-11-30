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

void cHit::Player_EnemyShot() {

	for (int i = 0; i < MAXMACHINE; i++) {

		Player = cPlayer::Instance()->GetPlayer(i);

		if (Player.onActive == FALSE) continue;

		for (int j = 0; j < ENEMYSHOTNUM; j++) {

			S_onActive = cShotMgr::Instance()->GetShotonActive(j);
			S_cx = cShotMgr::Instance()->GetShotX(j);
			S_cy = cShotMgr::Instance()->GetEnemyPosY(j);
			S_r = cShotMgr::Instance()->GetEnemyPosR(j);

			if (S_onActive == FALSE) continue;

			len = ((tmpEShot[j]->Get_ShotCX() - Player.cx) * (tmpEShot[j]->Get_ShotCX() - Player.cx)) + ((tmpEShot[j]->Get_ShotCY() - Player.cy)*(tmpEShot[j]->Get_ShotCY() - Player.cy));

			if (len <= ((tmpEShot[j]->Get_ShotR() + Player.r) * (tmpEShot[j]->Get_ShotR() + Player.r))) {

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
					cEnemyMgr::Break(j);
				}

				else {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Break(j);
				}
			}
		}
	}

}
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

			double len = ( (tmpEShot[j]->Get_ShotCX() - Player.cx) * (tmpEShot[j]->Get_ShotCX() - Player.cx) ) + ( (tmpEShot[j]->Get_ShotCY() - Player.cy)*(tmpEShot[j]->Get_ShotCY() - Player.cy) );

			if ( len <= ((tmpEShot[j]->Get_ShotR() + Player.r) * (tmpEShot[j]->Get_ShotR() + Player.r)) ) {

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

		//if (tmpEnemy[i].mainpos.onActive == FALSE) continue;

		double E_cx = cEnemyMgr::Instance()->GetEnemyPosX(i);
		double E_cy = cEnemyMgr::Instance()->GetEnemyPosY(i);
		double E_r = cEnemyMgr::Instance()->GetEnemyPosR(i);

		for (int j = 0; j < sizeof(tmpPShot); j++) {

			if (tmpPShot[j]->Get_OnActive() == FALSE) continue;

			double len = (tmpPShot[j]->Get_ShotCX() - E_cx)*(tmpPShot[j]->Get_ShotCX() - E_cx) + (tmpPShot[j]->Get_ShotCY() - E_cy)*(tmpPShot[j]->Get_ShotCY() - E_cy);

			if (len <= ((E_r + tmpPShot[j]->Get_ShotR())*(E_r + tmpPShot[j]->Get_ShotR())) ) {
				cShotMgr::Instance()->Break(PLAYER, j);
				cEnemyMgr::Break(i);
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