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
	virtual ~cPlayerEnemy();
	virtual void Move();
	virtual int Update(sEnemy*);
	int ReviveUpdate();
	//トラクターされた際の最初の移動をする関数
	 //トラクターされいてる間の移動
	virtual int Draw();


};

#endif // !PLAYERENEMY_INCLUDE
