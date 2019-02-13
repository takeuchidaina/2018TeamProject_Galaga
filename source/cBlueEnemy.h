#pragma once
#ifndef BLUEENEMY_INCLUDE
#define BLUEENEMY_INCLUDE

#include "cBaseEnemy.h"

class cBlueEnemy : public cBaseEnemy {
	public :
	cBlueEnemy(double, double, double, int, double, double, int,int*);
	virtual void Move();
	virtual int Update();
	virtual int Draw();
	virtual void EndlessUpdate();


};

#endif // !REDENEMY_INCLUDE
