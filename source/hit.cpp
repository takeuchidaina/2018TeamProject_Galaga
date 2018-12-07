#include <DxLib.h>
#include"hit.h"


/* �R���X�g���N�^ */
cHit::cHit() {

	beemR = 10.0;

}

/* �f�X�g���N�^ *
cHitFunc::~cHitFunc() {

}*/

void cHit::Update() {

	cHit::Player_EnemyShot();	//���@�ƓG�e�̓����蔻��
	cHit::Player_Enemy();		//���@�ƓG�@�̓����蔻��
	cHit::PlayerShot_Enemy();	//���e�ƓG�@�̓����蔻��

}

void cHit::Draw() {
	//cHit::Debug();
}

/************************************************************

 �֐��Fvoid cHit::Player_EnemyShot
 �����F���@�ƓG�e�̓����蔻��

************************************************************/
void cHit::Player_EnemyShot() {

	for (int i = 0; i < MAXMACHINE; i++) {	// �\�����̃v���C���[�𒲂ׂ�

		Player = cPlayer::Instance()->GetPlayer(i);	// �v���C���[�̏����

		if (Player.onActive == FALSE) continue;

		for (int j = 0; j < ENEMYSHOTNUM; j++) {	// �\�����̓G�e�𒲂ׂ�

			/* �G�e�̏���� */
			S_onActive = cShotMgr::Instance()->GetEnemyShotOnActive(j);
			S_cx = cShotMgr::Instance()->GetEnemyShotCX(j);
			S_cy = cShotMgr::Instance()->GetEnemyShotCY(j);
			S_r = cShotMgr::Instance()->GetEnemyShotR(j);

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

	static int maxEnemy = cEnemyMgr::Instance()->GetMaxEnemy();	// �G�@�̐��擾

	for (int i = 0; i < MAXMACHINE; i++) {	// �\�����̃v���C���[�𒲂ׂ�

		Player = cPlayer::Instance()->GetPlayer(i);	// �v���C���[�����

		if (Player.onActive == FALSE) continue;

		for (int j = 0; j < maxEnemy; j++) {	// �\�����̓G�@�𒲂ׂ�

			/* �G�@�̏���� */
			E_onActive = cEnemyMgr::Instance()->GetEnemyonActive(j);
			E_cx = cEnemyMgr::Instance()->GetEnemyPosX(j);
			E_cy = cEnemyMgr::Instance()->GetEnemyPosY(j);
			E_r = cEnemyMgr::Instance()->GetEnemyPosR(j);

			if (E_onActive == FALSE) continue;

			len = (E_cx - Player.cx)*(E_cx - Player.cx) + (E_cy - Player.cy+5.0)*(E_cy - Player.cy+5.0);

			if (len <= ((E_r + Player.r)*(E_r + Player.r))) {

				if (cPlayer::Instance()->GetDoubleFlg() == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Instance()->SetEnemyDeath(j);
				}

				else {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Instance()->SetEnemyDeath(j);
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

	static int maxEnemy = cEnemyMgr::Instance()->GetMaxEnemy();	// �G�@�̐��擾

	for (int i = 0; i < maxEnemy; i++) {	// �\�����̓G�@�𒲂ׂ�

		/* �G�@�̏���� */
		E_onActive = cEnemyMgr::Instance()->GetEnemyonActive(i);
		E_cx = cEnemyMgr::Instance()->GetEnemyPosX(i);
		E_cy = cEnemyMgr::Instance()->GetEnemyPosY(i);
		E_r = cEnemyMgr::Instance()->GetEnemyPosR(i);

		if (E_onActive == FALSE) continue;

		for (int j = 0; j < PLAYERSHOTNUM; j++) {	// �e���������v���C���[
			for (int k = 0; k < 2; k++) {	// �v���C���[�̒e�𒲂ׂ�

				/* ���@�e�̏���� */
				S_onActive = cShotMgr::Instance()->GetPlayerShotOnActive(j, k);
				S_cx = cShotMgr::Instance()->GetPlayerShotCX(j, k);
				S_cy = cShotMgr::Instance()->GetPlayerShotCY(j, k);
				S_r = cShotMgr::Instance()->GetPlayerShotR(j, k);

				if (S_onActive == FALSE) continue;

				double len = (S_cx - E_cx)*(S_cx - E_cx) + (S_cy - E_cy)*(S_cy - E_cy);

				if (len <= ((E_r + S_r)*(E_r + S_r))) {
					cShotMgr::Instance()->Break(PLAYER, k);
					cEnemyMgr::Instance()->SetEnemyDeath(i);
				}

			}
		}
	}
}

/************************************************************

 �֐��Fvoid cHit::BeemHit
 �����F�g���N�^�[�r�[���̓����蔻��
 �����F�g���N�^�[�r�[�����������G

************************************************************
void cHit::BeemHit(int cntEnemy) {

	for (int i = 0; i < MAXMACHINE; i++) {	// �\�����̃v���C���[�𒲂ׂ�

		Player = cPlayer::Instance()->GetPlayer(i);
		E_cx = cEnemyMgr::Instance()->GetEnemyPosX(cntEnemy);

		if (((E_cx - beemR) <= Player.cx+Player.r) && ((E_cx + beemR) >= Player.cx-Player.r)) {
			cInGameMgr::Instance()->ChangeScene(eTractor);
		}

	}
}

/**********************************************************

 �֐��Fvoid cHit::Debug
 �����F�f�o�b�O�p

**********************************************************/
void cHit::Debug() {

	unsigned int Cr;
	Cr = GetColor(255, 0, 0);

	static int maxEnemy = cEnemyMgr::Instance()->GetMaxEnemy();

	/* Player */
	Player = cPlayer::Instance()->GetPlayer(0);
	DrawCircle(Player.cx+1.0, Player.cy+5.0, Player.r, Cr, TRUE);

	/* Shot */
	for (int j = 0; j < ENEMYSHOTNUM; j++) {

		S_onActive = cShotMgr::Instance()->GetEnemyShotOnActive(j);
		S_cx = cShotMgr::Instance()->GetEnemyShotCX(j);
		S_cy = cShotMgr::Instance()->GetEnemyShotCY(j);
		S_r = cShotMgr::Instance()->GetEnemyShotR(j);

		if (S_onActive == FALSE) continue;

		DrawCircle(S_cx, S_cy, S_r, Cr, TRUE);

	}

	for (int j = 0; j < PLAYERSHOTNUM; j++) {
		for (int k = 0; k < 2; k++) {

			S_onActive = cShotMgr::Instance()->GetPlayerShotOnActive(j, k);
			S_cx = cShotMgr::Instance()->GetPlayerShotCX(j, k);
			S_cy = cShotMgr::Instance()->GetPlayerShotCY(j, k);
			S_r = cShotMgr::Instance()->GetPlayerShotR(j, k);

			if (S_onActive == FALSE) continue;

			DrawCircle(S_cx, S_cy, S_r, Cr, TRUE);

		}
	}

	/* Enemy */
	for (int j = 0; j < maxEnemy; j++) {

		E_onActive = cEnemyMgr::Instance()->GetEnemyonActive(j);
		E_cx = cEnemyMgr::Instance()->GetEnemyPosX(j);
		E_cy = cEnemyMgr::Instance()->GetEnemyPosY(j);
		E_r = cEnemyMgr::Instance()->GetEnemyPosR(j);

		if (E_onActive == FALSE) continue;

		DrawCircle(E_cx, E_cy, E_r, Cr, TRUE);

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

