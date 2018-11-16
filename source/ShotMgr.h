#pragma once

#ifndef _SHOTMGR_INCLUDE_
#define _SHOTMGR_INCLUDE_
#include "Shot.h"
#include "Singleton.h"
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
	friend cSingleton<cShotMgr>;
private:
	cShot *enemyShot, *playerShot;
	int totalShot;
	int ShotGrHandle[4];

protected:

public:
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
