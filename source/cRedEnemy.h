#pragma once
#ifndef REDENEMY_INCLUDE
#define REDENEMY_INCLUDE

#include "cBaseEnemy.h"


class cRedEnemy : public cBaseEnemy {
public:
	 cRedEnemy(double, double, double, int, double, double, int,int*);
	virtual void Move();
	virtual int Update();
	virtual int Draw();
	virtual void EndlessUpdate();
};
#endif // !REDENEMY_INCLUDE
