#pragma once
#ifndef GREENENEMY_INCLUDE
#define GREENENEMY_INCLUDE

#include "cBaseEnemy.h"
#include "cPlayerEnemy.h"


class cGreenEnemy : public cBaseEnemy {
private:
	int tractorAnimation[23] = { 0,1,2,3,4,5,6,7,8,9,10,11,10,9,8,7,6,5,4,3,2,1,0 };
	double tractormoveang[10];
	double tractorcountflg[10];
	int tractor[15];
	sOBJPos tmpplayer;
	double tmpx, tmpy;
	double tracotr;
	bool hit;
	cPlayerEnemy *traitPlayer;
public:
	cGreenEnemy(double, double, double, int, double, double, int, int*);
	virtual ~cGreenEnemy();
	virtual void Move();
	int TractorUpdate();
	virtual int Update();
	virtual int Draw();
	
	/*bool GetTractorFlg() {
		return tractorflg;
	}*/
	virtual void EndlessUpdate();
	virtual void AnimationCount() { AnimationCnt++; TractorCnt++; };
	void SetTraitPlayer(cPlayerEnemy *point) { traitPlayer = point; };
};
#endif // !REDENEMY_INCLUDE