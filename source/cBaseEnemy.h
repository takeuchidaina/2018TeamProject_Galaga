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
	int dir = 1;//1�@�E�@-1�@��
	int width;
	int hight;
	int count;
	int moveflg;
	int attackflg;
	//int flg;
	double moveang[10];
	double countflg[10];
	
}sEnemy;

class cBaseEnemy {
protected:
	sEnemy enemy;
public:
	     cBaseEnemy();//�R���X�g���N�^
		 cBaseEnemy(double,double,double,int,double,double,int );	
		virtual ~cBaseEnemy();//�f�X�g���N�^
		virtual	int Update();//�X�V����
		virtual int Draw();//�`�揈��
		virtual void Move(cBaseEnemy &);
		enum eActiveType {
			StartMove,
			NoActive,
			YesActive,
			NoMove,
		};




		// x
		virtual	double GetEnemyX(){
			return enemy.mainpos.pos.x;
		}
		virtual	void SetEnemyX(double x) {
			enemy.mainpos.pos.x = x;
		}
		//y
		virtual	double GetEnemyY() {
			return enemy.mainpos.pos.y;
		}
		virtual	void SetEnemyY(double y) {
			enemy.mainpos.pos.y = y;
		}
		//attackflg
		virtual	int GetEnemyAttackflg() {
			return enemy.attackflg;
		}
		virtual	void SetEnemyAttackflg() {
			enemy.attackflg = true;
		}
		//ang
		virtual	double GetEnemyAngle() {
			return enemy.ang;
		}
		virtual	void SetEnemyAngle(double ang) {
			enemy.ang = ang;
		}
		virtual	void SetEnemyAddAngle(double ang) {
			enemy.ang += ang;
		}
		//activeflg
		virtual	int GetEnemyOnActive() {
			return enemy.mainpos.onActive;
		}
		virtual	void SetEnemyOnActive() {
			if (enemy.mainpos.onActive == YesActive)enemy.mainpos.onActive = NoActive;
			else enemy.mainpos.onActive = YesActive;
		}
		//r
		virtual	double GetEnemyR(){
			return enemy.mainpos.r;
		}
		virtual	void SetEnemyR(double r) {
			enemy.mainpos.r = r;
		}

};

#endif // !_cBaseEnemy_INCLUDE_
