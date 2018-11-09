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
	sPos pos;
	sPos target;
	int targetr;
	double spd;
	double ang;
	int* graph;
	int r;
	int dir = 1;//1�@�E�@-1�@��
	int width;
	int hight;
	int count;
	int onActive;
	int moveflg;
	int attackflg;
	double moveang[10];
	double countflg[10];
}sEnemy;

class cBaseEnemy {
public:
        cBaseEnemy();//�R���X�g���N�^
		 cBaseEnemy(double,double,double,int,double,double,int );	
		 ~cBaseEnemy();//�f�X�g���N�^
		virtual	int Update();//�X�V����
		virtual int Draw();//�`�揈��
		virtual void Move(cBaseEnemy &);

		int GetAttackflg() {
			return enemy.attackflg;
		}

		void SetAttackflg() {
			enemy.attackflg = true;
		}

		int GetEnemyAngle() {
			return enemy.ang;
		}

		void SetEnemyAngleg(double ang) {
			enemy.ang = ang;
		}
protected:
		sEnemy enemy;

};

#endif // !_cBaseEnemy_INCLUDE_
