#pragma once
#ifndef PLAYERENEMY_INCLUDE
#define PLAYERENEMY_INCLUDE

#include "cBaseEnemy.h"

class cPlayerEnemy : public cBaseEnemy {
public:
	cPlayerEnemy(/*double, double, double, int, double, double, int, int*/);
	virtual void Move();
	virtual int Update();
	//�g���N�^�[���ꂽ�ۂ̍ŏ��̈ړ�������֐�
	 int TractorStart(sEnemy);
	 //�g���N�^�[���ꂢ�Ă�Ԃ̈ړ�
	// int Tracting(sEnemy);
	virtual int Draw();


};

#endif // !PLAYERENEMY_INCLUDE
