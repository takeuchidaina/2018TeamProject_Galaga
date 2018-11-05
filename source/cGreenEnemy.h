#pragma once
#ifndef GREENENEMY_INCLUDE
#define GREENENEMY_INCLUDE

#include "cBaseEnemy.h"


class cGreenEnemy : public cBaseEnemy {
public:
	cGreenEnemy(double, double, double, int, double, double, int);
	virtual void Move(cGreenEnemy &);
	virtual int Update();
	virtual int Draw();
};
#endif // !REDENEMY_INCLUDE