#pragma once
#ifndef GREENENEMY_INCLUDE
#define GREENENEMY_INCLUDE

#include "cBaseEnemy.h"


class cGreenEnemy : public cBaseEnemy {
private:
	double tractormoveang[10];
	double tractorcountflg[10];
	int tractor[11];
public:
	cGreenEnemy(double, double, double, int, double, double, int, int*);
	virtual void Move(cGreenEnemy &);
	void TractorUpdate();
	virtual int Update();
	virtual int Draw();
};
#endif // !REDENEMY_INCLUDE