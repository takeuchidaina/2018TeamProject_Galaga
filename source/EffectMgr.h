#pragma once

#ifndef _EFFECTMGR_INCLUDE_
#define _EFFECTMGR_INCLUDE_

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
	int PBlowupGrHandle[3];
	int PcheckGr;
	int PblowupOrders;
	//Enemy
	int EBlowupGrHandle[3];
	int EcheckGr;
	int EblowupOrders;
	
protected:

public:
	void Init();//����������
	int Update();	//�v�Z����
	int Draw();		//�`�ʏ���
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