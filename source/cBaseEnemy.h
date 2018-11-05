#pragma once

#ifndef _cBaseEnemy_INCLUDE_
#define _cBaseEnemy_INCLUDE_
#include "Struct.h"
#include <math.h>
#include "DxLib.h"

typedef struct {
	sPos vct;
	sPos pos;
	sPos target;
	int targetr;
	double spd;
	double ang;
	int* graph;
	int r;
	int width;
	int hight;
	int count;
	int onActive;
	int moveflg;
	double moveang[10];
	double countflg[10];
}sEnemy;

class cBaseEnemy {
	public:
        cBaseEnemy();//コンストラクタ
		 cBaseEnemy(double,double,double,int,double,double,int );
		 ~cBaseEnemy();//デストラクタ
		virtual	int Update();//更新処理
		virtual int Draw();//描画処理
		virtual void Move(cBaseEnemy &);
		sEnemy enemy;
};

#endif // !_cBaseEnemy_INCLUDE_
