#pragma once
#ifndef PLAYERENEMY_INCLUDE
#define PLAYERENEMY_INCLUDE

#include "cBaseEnemy.h"

class cPlayerEnemy : public cBaseEnemy {
private:
	int graph[4];
	sOBJPos tmpPlayer;
	double rotecnt;
	int playerNum;
public:
	cPlayerEnemy(/*double, double, double, int, double, double, int, int*/);
	virtual void Move();
	virtual int Update(sEnemy*);
	int ReviveUpdate();
	//�g���N�^�[���ꂽ�ۂ̍ŏ��̈ړ�������֐�
	 int TractorStart(sEnemy);
	 //�g���N�^�[���ꂢ�Ă�Ԃ̈ړ�
	// int Tracting(sEnemy);
	// void EternalUpdate();
	virtual int Draw();


};

#endif // !PLAYERENEMY_INCLUDE
