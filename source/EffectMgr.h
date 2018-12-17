#pragma once

#ifndef _EFFECTMGR_INCLUDE_
#define _EFFECTMGR_INCLUDE_
#define BLOWUPNUM 10
#define PLAYER 0
#define ENEMY 1

#include "Singleton.h"
#include "Winbox.h"
#include "Effect.h"


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


class cEffectMgr :public cSingleton<cEffectMgr> {
	cEffectMgr();
	~cEffectMgr();
	friend cSingleton<cEffectMgr>;
private:
	cEffect *BlowupArray;
	int BlowupCnt;
	//Player
	int PBlowupGrHandle[8];
	int PcheckGr;
	int PblowupOrders[6] = {0,0,1,1,2,2};
	//Enemy
	int EBlowupGrHandle[40];
	int EcheckGr;
	int EblowupOrders[6] = {0,0,1,1,2,2};
	
protected:

public:
	void Init();//����������
	int Update();	//�v�Z����
	int Draw();		//�`�ʏ���

	int Blowup(int,int,int);
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