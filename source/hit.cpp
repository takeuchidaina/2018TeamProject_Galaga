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

	cHit::Hit();	//Hit�֐��Ăяo��

}

void cHit::Draw() {

}

/************************************************************
	�֐��Fvoid cHit::Hit
	�����F(���@�ƓG�e) (���@�ƓG�@) (���e�ƓG�@) �̓����蔻��
	�����F�Ȃ�
	�Ăяo���֐��F
		�@cPlayer::Instance()->Break("�v���C���[�̏��", "�ǂ����̃v���C���[��")
		  cShotMgr::Instance()->Break("�ǂ����̒e��", "�ǂ̒e��")
		  cBaseEnemy::Break("�ǂ̓G��")
************************************************************/
void cHit::Hit() {

	sOBJPos tmpPlayer[2];
	cShot *tmpEShot[20];
	cShot *tmpPShot[2];
	//sEnemy tmpEnemy[20];

	tmpPShot[0] = cShotMgr::Instance()->GetShot(PLAYER);
	tmpEShot[0] = cShotMgr::Instance()->GetShot(ENEMY);

	static int maxEnemy = cEnemyMgr::Instance()->GetMaxEnemy();


	/* ���@�ƓG�e */
	for (int i = 0; i < MAXMACHINE; i++) {

		if (tmpPlayer[i].onActive == FALSE) continue;

		for (int j = 0; j < sizeof(tmpEShot); j++) {

			if (tmpEShot[j]->Get_OnActive() == FALSE) continue;

			double len = ( (tmpEShot[j]->Get_ShotCX() - tmpPlayer[i].cx) * (tmpEShot[j]->Get_ShotCX() - tmpPlayer[i].cx) ) + ( (tmpEShot[j]->Get_ShotCY() - tmpPlayer[i].cy)*(tmpEShot[j]->Get_ShotCY() - tmpPlayer[i].cy) );

			if ( len <= ((tmpEShot[j]->Get_ShotR() + tmpPlayer[i].r) * (tmpEShot[j]->Get_ShotR() + tmpPlayer[i].r)) ) {

				/* �v���C���[��2�@����Ƃ��ɕЕ����_�E�� */
				if (tmpPlayer[eLeftMachine].onActive == TRUE && tmpPlayer[eRightMachine].onActive == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}

				/* �v���C���[��1�@�̂Ƃ��Ƀ_�E�� */
				else {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}
			}
		}
	}

	/* ���@�ƓG�@�@*/
	for (int i = 0; i < MAXMACHINE; i++) {

		if (tmpPlayer[i].onActive == FALSE) continue;

		for (int j = 0; j < maxEnemy; j++) {

			//if (tmpEnemy[j].mainpos.onActive == FALSE) continue;

			double tmpEnemy_cx = cEnemyMgr::Instance()->GetEnemyPosX(j);
			double tmpEnemy_cy = cEnemyMgr::Instance()->GetEnemyPosY(j);
			double tmpEnemy_r = cEnemyMgr::Instance()->GetEnemyPosR(j);

			double len = (tmpEnemy_cx - tmpPlayer[i].cx)*(tmpEnemy_cx - tmpPlayer[i].cx) + (tmpEnemy_cy - tmpPlayer[i].cy)*(tmpEnemy_cy - tmpPlayer[i].cy);

			if (len <= ((tmpEnemy_r + tmpPlayer[i].r)*(tmpEnemy_r + tmpPlayer[i].r))) {
				
				/* �v���C���[��2�@����Ƃ��ɕЕ����_�E�� */
				if (tmpPlayer[eLeftMachine].onActive == TRUE && tmpPlayer[eRightMachine].onActive == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Break(j);
				}

				/* �v���C���[��1�@�̂Ƃ��Ƀ_�E�� */
				else {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Break(j);
				}
			}
		}
	}

	/* ���e�ƓG�@�@*/
	for (int i = 0; i < maxEnemy; i++) {

		//if (tmpEnemy[i].mainpos.onActive == FALSE) continue;

		double tmpEnemy_cx = cEnemyMgr::Instance()->GetEnemyPosX(i);
		double tmpEnemy_cy = cEnemyMgr::Instance()->GetEnemyPosY(i);
		double tmpEnemy_r = cEnemyMgr::Instance()->GetEnemyPosR(i);

		for (int j = 0; j < sizeof(tmpPShot); j++) {

			if (tmpPShot[j]->Get_OnActive() == FALSE) continue;

			double len = (tmpPShot[j]->Get_ShotCX() - tmpEnemy_cx)*(tmpPShot[j]->Get_ShotCX() - tmpEnemy_cx) + (tmpPShot[j]->Get_ShotCY() - tmpEnemy_cy)*(tmpPShot[j]->Get_ShotCY() - tmpEnemy_cy);

			if (len <= ((tmpEnemy_r + tmpPShot[j]->Get_ShotR())*(tmpEnemy_r + tmpPShot[j]->Get_ShotR())) ) {
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

	sOBJPos tmpPlayer[2];
	

	if (((tmpEnemy.cx - beemR) <= tmpPlayer.cx && (tmpEnemy.cx + beemR) >= tmpPlayer.cx)) {
		cInGameMgr(eTractor);
	}

}*/