#pragma once
#ifndef REDENEMY_INCLUDE
#define REDENEMY_INCLUDE

#include "cBaseEnemy.h"


class cRedEnemy : public cBaseEnemy {
public:
	cRedEnemy(double, double, double, int, double, double, int,int*);
	virtual void Move(cRedEnemy &);
	virtual int Update();
	virtual int Draw();
};
#endif // !REDENEMY_INCLUDE
