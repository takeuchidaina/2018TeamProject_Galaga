#pragma once

#include "Singleton.h"

#define MAXMACHINE 2

#define PLAYER 0
#define ENEMY 1

#ifndef _HITFUNC_INCLUDE_
#define _HITFUNC_INCLUDE_

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

class cHitFunc: public Singleton<cHitFunc>
{
	cHitFunc();
	friend Singleton< cHitFunc >;
private:

	sOBJPos Player;
	void Hit(sOBJPos, cShot *, cShot *, sEnemy *);		//�����蔻��

protected:

public:

	void Update();	//�v�Z����
	void Draw();	//�`�ʏ���
	
	void BeemHit(sOBJPos); //�g���N�^�[�r�[�������蔻��

};


#endif