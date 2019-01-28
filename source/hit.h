#pragma once



#ifndef _HIT_INCLUDE_
#define _HIT_INCLUDE_

#define PLAYER 0
#define ENEMY 1

#include "Singleton.h"
#include "Struct.h"
#include "Player.h"
#include "InGameMgr.h"
#include "ShotMgr.h"
#include "Shot.h"
#include "EnemyMgr.h"
#include "cBaseEnemy.h"
#include "EffectMgr.h"
#include "SE.h"
#include "cGreenEnemy.h"

class cHit : public cSingleton<cHit>
{
	cHit();
	friend cSingleton< cHit >;
private:

	/************************************************************
	�֐��Fvoid cHit::Player_EnemyShot
	�����F���@�ƓG�e�̓����蔻��
	�����F�Ȃ�
	�߂�l�F�Ȃ�
	************************************************************/
	void Player_EnemyShot();

	/************************************************************
	�֐��Fvoid cHit::Player_Enemy
	�����F���@�ƓG�@�̓����蔻��
	�����F�Ȃ�
	�߂�l�F�Ȃ�
	************************************************************/
	void Player_Enemy();

	/************************************************************
	�֐��Fvoid cHit::PlayerShot_Enemy
	�����F���e�ƓG�@�̓����蔻��
	�����F�Ȃ�
	�߂�l�F�Ȃ�
	************************************************************/
	void PlayerShot_Enemy();

	/************************************************************
	�֐��Fvoid cHit::PlayerShot_EnemyPlayer
	�����F���e�Ƃ���Ƃ�ꂽ���@�̓����蔻��
	�����F�Ȃ�
	�߂�l�F�Ȃ�
	************************************************************/
	void PlayerShot_EnemyPlayer();

	/************************************************************
	�֐��Fvoid cHit::Player_EnemyPlayer
	�����F���@�Ƃ���Ƃ�ꂽ���@�̓����蔻��
	�����F�Ȃ�
	�߂�l�F�Ȃ�
	************************************************************/
	void Player_EnemyPlayer();

	void Debug();				//�f�o�b�O�p�֐�				

	sOBJPos Player;							//�v���C���[
	cPlayerEnemy* pEnemy;					//�v���C���[�G�l�~�[
	double S_onActive, S_cx, S_cy, S_r;		//�e
	double E_onActive, E_cx, E_cy, E_r;		//�G
	bool E_tractingFlg, E_moveFlg;			//�G�p�t���O

											// �g���N�^�[�r�[���p
	cPlayerEnemy *TraitPlayer;	//�G�v���C���[
	double player_x, player_y;	//�v���C���[���W
	sEnemy *enemyX;				//�Gx���W
	double tractorX;			//�g���N�^�[x���W
	double tractorWidth;		//�g���N�^�[��

	double len;

	int totalHit;

protected:

public:

	void Update();	//�v�Z����
	void Draw();	//�`�ʏ���

	/************************************************************
	�֐��Fvoid TractorHit
	�����F�g���N�^�[�r�[�������蔻��
	�����Fdouble enemyX	�r�[�����������G��x���W
	�߂�l�F�Ȃ�
	************************************************************/
	void TractorHit(sEnemy*);

	bool TractorHitFlg;

	/************************************************************
	�֐��Fvoid TractingEnemyHit
	�����FEnemyPlayer���������{�X�M�����K�̈ړ����̓����蔻��
	�����FtractingEnemy
	�߂�l�F�Ȃ�
	************************************************************/
	void TractingEnemyHit();

	int GetTotalHit() {
		return totalHit;
	}

	bool GetTractorHitFlg() {
		return TractorHitFlg;
	}

	void ResetHit() { totalHit = 0; }

};


#endif