#pragma once
#ifndef PLAYERENEMY_INCLUDE
#define PLAYERENEMY_INCLUDE

#include "cBaseEnemy.h"

class cPlayerEnemy : public cBaseEnemy {
public:
	cPlayerEnemy(/*double, double, double, int, double, double, int, int*/);
	virtual void Move();
	virtual int Update();
	//トラクターされた際の最初の移動をする関数
	 int TractorStart(sEnemy);
	 //トラクターされいてる間の移動
	// int Tracting(sEnemy);
	virtual int Draw();


};

#endif // !PLAYERENEMY_INCLUDE
