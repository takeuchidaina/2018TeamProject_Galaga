#pragma once

#ifndef _cBaseEnemy_INCLUDE_
#define _cBaseEnemy_INCLUDE_
#include "Struct.h"
#include <math.h>
#include "DxLib.h"

typedef struct {
	enum eRF {
		RIGHT = 1,
		LEFT = -1,
	};
	sPos vct;
	sOBJPos mainpos ;
	sPos target;
	int targetr;
	double spd;
	double ang;
	int graph[20];
	int dir = 1;//1　右　-1　左
	int width;
	int hight;
	int count;
	int moveflg;
	int attackflg;
	int flg;
	double moveang[10];
	double countflg[10];
}sEnemy;

class cBaseEnemy {
protected:
	sEnemy enemy;
public:
	     cBaseEnemy();//コンストラクタ
		 cBaseEnemy(double,double,double,int,double,double,int );	
		virtual ~cBaseEnemy();//デストラクタ
		virtual	int Update();//更新処理
		virtual int Draw();//描画処理
		virtual void Move(cBaseEnemy &);

		int GetEnemyAttackflg() {
			return enemy.attackflg;
		}

		void SetEnemyAttackflg() {
			enemy.attackflg = true;
		}

		double GetEnemyAngle() {
			return enemy.ang;
		}

		void SetEnemyAngleg(double ang) {
			enemy.ang = ang;
		}

		int GetEnemyOnActive() {
			return enemy.mainpos.onActive;
		}
		void SetEnemyOnActive() {
			
			if (enemy.mainpos.onActive == true)enemy.mainpos.onActive = false;
			else enemy.mainpos.onActive = true;
		}


};

#endif // !_cBaseEnemy_INCLUDE_
