#pragma once
#ifndef PLAYERENEMY_INCLUDE
#define PLAYERENEMY_INCLUDE

#include "cBaseEnemy.h"

class cPlayerEnemy : public cBaseEnemy {
public:
	cPlayerEnemy(/*double, double, double, int, double, double, int, int*/);
	virtual void Move();
	virtual int Update();
	virtual int Draw();


};

#endif // !PLAYERENEMY_INCLUDE
