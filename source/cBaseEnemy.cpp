#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "cBaseEnemy.h"
#include "DxLib.h"
#include "Struct.h"


 cBaseEnemy::cBaseEnemy(){
	

}
 cBaseEnemy::cBaseEnemy(double x,double y,double r,int cnt ,double spd ,double ang,int flg) {
	 enemy.pos.x = x;
	 enemy.pos.y = y;
	 enemy.r = r;
	 enemy.count = cnt;
	 enemy.spd = spd;
	 enemy.ang = ang * 3.14159265 / 180;
	 enemy.onActive = flg;

	 enemy.moveflg = 0;

	 enemy.vct.x = 0;
	 enemy.vct.y = 0;

	 memset(enemy.moveang,0,sizeof(enemy.moveang));
	 enemy.moveang[0] = -5;
	 enemy.moveang[1] = -0.2;
	 enemy.moveang[2] = 5;
	 enemy.moveang[3] = 90;
	 enemy.moveang[4] = 3;

	 memset(enemy.countflg, 0, sizeof(enemy.countflg));
	 enemy.countflg[0] = 30;
	 enemy.countflg[1] = 40;
	 enemy.countflg[2] = 15;
	 enemy.countflg[3] = 30;
	 enemy.countflg[4] = 45;

	 enemy.target.x = x;
	 enemy.target.y = y;
	 enemy.targetr = 5;
	 
 }

 cBaseEnemy::cBaseEnemy(cBaseEnemy &unit) {
	 
 }


cBaseEnemy::~cBaseEnemy() {

}

void cBaseEnemy::Move(cBaseEnemy &unit) {
	if (unit.enemy.dir == unit.enemy.RIGHT) {
		unit.enemy.vct.x = cos(enemy.ang);
		unit.enemy.vct.y = sin(enemy.ang);
		unit.enemy.pos.x += unit.enemy.vct.x*unit.enemy.spd;
		unit.enemy.pos.y += unit.enemy.vct.y*unit.enemy.spd;
	}
	else {
		if (unit.enemy.moveflg != 5) {
			unit.enemy.vct.x = -cos(enemy.ang);
			unit.enemy.vct.y = sin(enemy.ang);
			unit.enemy.pos.x += unit.enemy.vct.x*unit.enemy.spd;
			unit.enemy.pos.y += unit.enemy.vct.y*unit.enemy.spd;
		}
		else {
			unit.enemy.vct.x = cos(enemy.ang);
			unit.enemy.vct.y = sin(enemy.ang);
			unit.enemy.pos.x += unit.enemy.vct.x*unit.enemy.spd;
			unit.enemy.pos.y += unit.enemy.vct.y*unit.enemy.spd;
		}
	}
}


int cBaseEnemy::Update() {

	enemy.count++;

	if (enemy.count > 0) {
		enemy.onActive = true;
	}
	if (enemy.RIGHT == enemy.dir) {
		switch (enemy.moveflg)
		{
		case 0:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			//	Move(unit);
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 1:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			//	Move(unit);
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 2:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			//	Move(unit);
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 3:
			enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			//	Move(unit);
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 4:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			//Move(unit);
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 5:
			enemy.ang = atan2(enemy.target.y - enemy.pos.y, enemy.target.x - enemy.pos.x);
			//Move(unit);
			if ((enemy.target.x - enemy.pos.x)*(enemy.target.x - enemy.pos.x) *
				(enemy.target.y - enemy.pos.y)*(enemy.target.y - enemy.pos.y) <=
				(enemy.r + enemy.targetr)*(enemy.r + enemy.targetr)) {
				//敵座標を目的地に固定
				enemy.pos.x = enemy.target.x;
				enemy.pos.y = enemy.target.y;
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 6:
			enemy.count = 0;
			enemy.moveflg = 0;
			enemy.ang = 180 * 3.14159265 / 180;
			enemy.dir *= -1;
			break;

		}
	}
	else {
		switch (enemy.moveflg)
		{
		case 0:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			//	Move(unit);
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 1:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			//	Move(unit);
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 2:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			//	Move(unit);
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 3:
			enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			//	Move(unit);
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 4:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			//Move(unit);
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 5:
			enemy.ang = atan2(enemy.target.y - enemy.pos.y, enemy.target.x - enemy.pos.x);
			//Move(unit);
			if ((enemy.target.x - enemy.pos.x)*(enemy.target.x - enemy.pos.x) *
				(enemy.target.y - enemy.pos.y)*(enemy.target.y - enemy.pos.y) <=
				(enemy.r + enemy.targetr)*(enemy.r + enemy.targetr)) {
				//敵座標を目的地に固定
				enemy.pos.x = enemy.target.x;
				enemy.pos.y = enemy.target.y;
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 6:
			enemy.count = 0;
			enemy.moveflg = 0;
			enemy.ang = 180 * 3.14159265 / 180;
			enemy.dir *= -1;
			break;

		}
	}
	return 0;
}



int cBaseEnemy::Draw() {
	
	DrawFormatString(0, 100, GetColor(255, 255, 255), "%d", enemy.count);
	DrawCircle(enemy.pos.x, enemy.pos.y,5, GetColor(255, 255, 255), true);
	DrawCircle(enemy.target.x, enemy.target.y, enemy.targetr, GetColor(255, 255, 255), true);
	DrawCircle(100, 300, 5, GetColor(255, 0,0), true);
	DrawCircle(700, 450, 5, GetColor(255, 0, 0), true);
	return 0;
}