#pragma once

#ifndef _SHOTMGR_INCLUDE_
#define _SHOTMGR_INCLUDE_
#include "Shot.h"
#include "Singleton.h"
#include "Player.h"
#include "Struct.h"
#include "Winbox.h"
#define PLAYER 0
#define ENEMY 1
#define PLAYERSHOTNUM 2
#define ENEMYSHOTNUM 20
/*
//�e���v���[�g�� �N���X���e���v���[�g���\
template <typename TYPE>
void Swap(TYPE& a, TYPE& b) {
TYPE tmp;
tmp = a;
a = b;
b = tmp;
}
*/


class cShotMgr:public cSingleton<cShotMgr> {
	cShotMgr();
	~cShotMgr();
	friend cSingleton<cShotMgr>;
private:
	cShot *enemyShot, *player1Shot, *player2Shot;
	int totalShot;
	int ShotGrHandle[4];
	int shotRate;
	int checkGr;
	int ShotFlg;

protected:

public:
	int Update();	//�v�Z����
	int Draw();		//�`�ʏ���
	void Init();
	int Break(int,int);    //�e�������֐�
	int EnemyShot(double,double);

	//ShotFlg�̊֐�(TRUE FALSE)
	void SetShotFlg(int num) { ShotFlg = num; }

	//GetPlayerShot�֐��A����(player1��player2, �z��̉��Ԗڂ�(0��1))
	double GetPlayerShotCX(int num,int num2) {
		return (num == 0 ? player1Shot[num2].Get_ShotCX() : (num == 1 ? player2Shot[num2].Get_ShotCX() : NULL));
	}
	double GetPlayerShotCY(int num, int num2) {
		return (num == 0 ? player1Shot[num2].Get_ShotCY() : (num == 1 ? player2Shot[num2].Get_ShotCY() : NULL));
	}
	double GetPlayerShotR(int num, int num2) {
		return (num == 0 ? player1Shot[num2].Get_ShotR() : (num == 1 ? player2Shot[num2].Get_ShotR() : NULL));
	}
	double GetPlayerShotOnActive(int num, int num2) {
		return (num == 0 ? player1Shot[num2].Get_OnActive() : (num == 1 ? player2Shot[num2].Get_OnActive() : NULL));
	}

	//GetEnemyShot�֐��A����(�z��̉��Ԗڂ�(0-19))
	double GetEnemyShotCX(int num) {
		return enemyShot[num].Get_ShotCX();
	}
	double GetEnemyShotCY(int num) {
		return enemyShot[num].Get_ShotCY();
	}
	double GetEnemyShotR(int num) {
		return enemyShot[num].Get_ShotR();
	}
	double GetEnemyShotOnActive(int num) {
		return enemyShot[num].Get_OnActive();
	}



	/*
	//�錾��
	private:
	int mTest;
	public:
	void Set_Test(int);	//private�����o�ϐ�mTest�ւ̑��
	int Get_Test();		//private�����o�ϐ�mTest�̊l��
	*/
};
#endif
