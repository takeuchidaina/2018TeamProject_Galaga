#include <DxLib.h>
#include"hit.h"
#include"InGameMgr.h"
#include"Player.h"
#include"ShotMgr.h"
#include"Shot.h"
#include"Shot.cpp"
#include"Player.cpp"
#include"EnemyMgr.h"


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
	�����FsOBJPos tmpPlayer
		�FcShot tmpEShot
		�F		tmpPShot
		�FsEnemy tmpEnemy
	�ߒl�F�Ȃ�
************************************************************/
void cHit::Hit() {

	sOBJPos tmpPlayer[2];
	cShot tmpEShot[20];
	cShot tmpPShot[2];
	sEnemy tmpEnemy[20];


	/* ���@�ƓG�e */
	for (int i = 0; i < MAXMACHINE; i++) {

		if (tmpPlayer[i].onActive == FALSE) continue;



		for (int j = 0; j < sizeof(tmpEShot); j++) {

			if (tmpEShot[j].Get_OnActive == FALSE) continue;

			int len = ( (tmpEShot[j].Get_ShotCX - tmpPlayer[i].cx) * (tmpEShot[j].Get_ShotCX - tmpPlayer[i].cx) ) + ( (tmpEShot[j].Get_ShotCY - tmpPlayer[i].cy)*(tmpEShot[j].Get_ShotCY - tmpPlayer[i].cy) );

			if ( len <= ((tmpEShot[j].Get_ShotR + tmpPlayer[i].r) * (tmpEShot[j].Get_ShotR + tmpPlayer[i].r)) ) {

				/* �v���C���[��2�@����Ƃ��ɕЕ����_�E��
				   �Ăяo���֐��FcPlayer::Braik("�v���C���[�̏��", "�ǂ����̃v���C���[��") */
				if (tmpPlayer[eLeftMachine].onActive == TRUE && tmpPlayer[eRightMachine].onActive == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}

				/* �v���C���[��1�@�̂Ƃ��Ƀ_�E��
				   �Ăяo���֐��FcPlayer::Braik("�v���C���[�̏��", "�ǂ����̃v���C���[��") */
				else {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}
			}
		}
	}

	/* ���@�ƓG�@�@*/
	/*for (int i = 0; i < MAXMACHINE; i++) {

		if (tmpPlayer[i].onActive == FALSE) continue;

		for (int j = 0; j < sizeof(tmpEnemy); j++) {

			if (tmpEnemy[j].onActive == FALSE) continue;

			int len = (tmpEnemy[j].cx - tmpPlayer[i].cx)*(tmpEnemy[j].cx - tmpPlayer[i].cx) + (tmpEnemy[j].cy - tmpPlayer[i].cy)*(tmpEnemy[j].cy - tmpPlayer[i].cy);

			if (len <= ((tmpEnemy[j].r + tmpPlayer[i].r)*(tmpEnemy[j].r + tmpPlayer[i].r))) {
				
				/* �v���C���[��2�@����Ƃ��ɕЕ����_�E��
				�Ăяo���֐��FcPlayer::Braik("�v���C���[�̏��", "�ǂ����̃v���C���[��") *
				if (tmpPlayer[eLeftMachine].onActive == TRUE && tmpPlayer[eRightMachine].onActive == TRUE) {
					cPlayer::Instance()->Break(eDoubleDeath, i);
					sEnemy::Instance()->Break(j);
				}

				/* �v���C���[��1�@�̂Ƃ��Ƀ_�E��
				�Ăяo���֐��FcPlayer::Braik("�v���C���[�̏��", "�ǂ����̃v���C���[��") *
				else {
					cPlayer::Instance()->Break(eDeath, i);
					sEnemy::Instance()->Break(j);
				}
			}
		}
	}*/

	/* ���e�ƓG�@�@*/
	/*for (int i = 0; i < sizeof(enemy); i++) {

		if (enemy[i].OnActive == FALSE) continue;

		for (int j = 0; j < sizeof(tmpPShot); j++) {

			if (tmpPShot[j].Get_OnActive == FALSE) continue;

			int len = (tmpPShot[j].Get_ShotCX - enemy[i].cx)*(tmpPShot[j].Get_ShotCX - enemy[i].cx) + (tmpPShot[j].Get_ShotCY - enemy[i].cy)*(tmpPShot[j].Get_ShotCY - enemy[i].cy);

			if (len <= ((enemy[i].r + tmpPShot[j].Get_ShotR)*(enemy[i].r + tmpPShot[j].Get_ShotR)) ) {
				cShotMgr::Instance()->Break(PLAYER, j);
				sEnemy::Instance()->Break(i);
			}
		}
	}*/
}

/************************************************************
�֐��Fvoid cHit::BeemHit 
�����F�g���N�^�[�r�[���̓����蔻��
�����FsOBJPos *Player
	�FcShot *enemyShot
�ߒl�F�Ȃ�
************************************************************
void cHit::BeemHit(sOBJPos Player ,sEnemy enemy) {

	sOBJPos tmpPlayer[2];
	sEnemy tmpEnemy[20];

	if (((tmpEnemy.cx - beemR) <= tmpPlayer.cx && (tmpEnemy.cx + beemR) >= tmpPlayer.cx)) {
		cInGameMgr(eTractor);
	}

}*/