#include <DxLib.h>
#include"hit.h"
#include"InGameMgr.h"
#include"Player.h"
#include"ShotMgr.h"
#include"Shot.h"
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
	�����FsOBJPos *Player
		�FcShot *enemyShot
		�F		*playerShot
		�FsEnemy *enemy
	�ߒl�F�Ȃ�
************************************************************/
void cHit::Hit() {

	sOBJPos tmpPlayer[2];
	cShot tmpEShot[20];
	cShot tmpPShot[2];
	sEnemy tmpEnemy[20];


	/* �v���C���[�ƓG�e */
	for (int i = 0; i < MAXMACHINE; i++) {

		if (tmpPlayer[i].onActive == false) continue;

		for (int j = 0; j < sizeof(tmpEShot); j++) {

			if (tmpEShot[j].Get_OnActive == false) continue;

			int len = ( (tmpEShot[j].cx - tmpPlayer[i].cx) * (tmpEShot[j].cx - tmpPlayer[i].cx) ) + ( (tmpEShot[j].cy - tmpPlayer[i].cy)*(tmpEShot[j].cy - tmpPlayer[i].cy) );

			if ( len <= ((tmpEShot[j].r + tmpPlayer[i].r) * (tmpEShot[j].r + tmpPlayer[i].r))) {

				/* �v���C���[��2�@����Ƃ��ɕЕ����_�E��
				   �Ăяo���֐��FcPlayer::Braik("�v���C���[�̏��", "�ǂ����̃v���C���[��") */
				if (tmpPlayer[eLeftMachine].onActive == true && tmpPlayer[eRightMachine].onActive == true) {
					cPlayer::Instance()->Break(eDoubleDeath, i);
					cShot::Instance()->Break(ENEMY, j);
				}

				/* �v���C���[��1�@�̂Ƃ��Ƀ_�E��
				   �Ăяo���֐��FcPlayer::Braik("�v���C���[�̏��", "�ǂ����̃v���C���[��") */
				else {
					cPlayer::Instance()->Break(eDeath, i);
					cShot::Instance()->Break(ENEMY, j);
				}
			}
		}
	}

	/* �v���C���[�ƓG�@�@*/
	for (int i = 0; i < MAXMACHINE; i++) {

		if (tmpPlayer[i].onActive == false) continue;

		for (int j = 0; j < sizeof(tmpEnemy); j++) {

			if (tmpEnemy[j].onActive == false) continue;

			int len = (tmpEnemy[j].cx - tmpPlayer[i].cx)*(tmpEnemy[j].cx - tmpPlayer[i].cx) + (tmpEnemy[j].cy - tmpPlayer[i].cy)*(tmpEnemy[j].cy - tmpPlayer[i].cy);

			if (len <= ((tmpEnemy[j].r + tmpPlayer[i].r)*(tmpEnemy[j].r + tmpPlayer[i].r))) {
				
				/* �v���C���[��2�@����Ƃ��ɕЕ����_�E��
				�Ăяo���֐��FcPlayer::Braik("�v���C���[�̏��", "�ǂ����̃v���C���[��") */
				if (tmpPlayer[eLeftMachine].onActive == true && tmpPlayer[eRightMachine].onActive == true) {
					cPlayer::Instance()->Break(eDoubleDeath, i);
					sEnemy::Instance()->Break(j);
				}

				/* �v���C���[��1�@�̂Ƃ��Ƀ_�E��
				�Ăяo���֐��FcPlayer::Braik("�v���C���[�̏��", "�ǂ����̃v���C���[��") */
				else {
					cPlayer::Instance()->Break(eDeath, i);
					sEnemy::Instance()->Break(j);
				}
			}
		}
	}

	/* ���e�ƓG�@�@*/
	for (int i = 0; i < sizeof(enemy); i++) {

		if (enemy[i].OnActive == false) continue;

		for (int j = 0; j < sizeof(tmpPShot); j++) {

			if (tmpPShot[j].Get_OnActive == false) continue;

			int len = (tmpPShot[j].cx - enemy[i].cx)*(tmpPShot[j].cx - enemy[i].cx) + (tmpPShot[j].cy - enemy[i].cy)*(tmpPShot[j].cy - enemy[i].cy);

			if (len <= ((enemy[i].r + tmpPShot[j].r)*(enemy[i].r + tmpPShot[j].r)) ) {
				cShot::Instance()->Break(PLAYER, j);
				sEnemy::Instance()->Break(i);
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
void cHit::BeemHit(sOBJPos Player ,sEnemy enemy) {

	if (((enemy.cx - beemR) <= Player.cx && (enemy.cx + beemR) >= Player.cx)) {
		cInGameMgr(eTractor);
	}

}*/