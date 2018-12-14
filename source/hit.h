#pragma once



#ifndef _HIT_INCLUDE_
#define _HIT_INCLUDE_

#define MAXMACHINE 2

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

class cHit: public cSingleton<cHit>
{
	cHit();
	friend cSingleton< cHit >;
private:

	//void Hit();		//�����蔻��

	void Player_EnemyShot();	//���@�ƓG�e�̓����蔻��
	void Player_Enemy();		//���@�ƓG�@�̓����蔻��
	void PlayerShot_Enemy();	//���e�ƓG�@�̓����蔻��

	void Debug();				//�f�o�b�O�p�֐�				

	sOBJPos Player;							//�v���C���[
	double S_onActive, S_cx, S_cy, S_r;		//�e
	double E_onActive, E_cx, E_cy, E_r;		//�G
	
	double beemR;
	double len;

	int totalHit;

protected:

public:

	void Update();	//�v�Z����
	void Draw();	//�`�ʏ���
	void BeemHit(int); //�g���N�^�[�r�[�������蔻��

	int GetTotalHit() {
		return totalHit;
	}

};


#endif