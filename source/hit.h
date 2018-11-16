#pragma once



#ifndef _HITFUNC_INCLUDE_
#define _HITFUNC_INCLUDE_

#define MAXMACHINE 2

#define PLAYER 0
#define ENEMY 1

#include "Singleton.h"
#include "Struct.h"


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

class cHit: public cSingleton<cHit>
{
	cHit();
	friend cSingleton< cHit >;
private:

	sOBJPos Player;
	void Hit();		//�����蔻��

protected:

public:

	void Update();	//�v�Z����
	void Draw();	//�`�ʏ���
	
//	void BeemHit(sOBJPos); //�g���N�^�[�r�[�������蔻��

};


#endif