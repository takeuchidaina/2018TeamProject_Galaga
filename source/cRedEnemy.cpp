#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "cRedEnemy.h"
#include "DxLib.h"
#include "Struct.h"


cRedEnemy::cRedEnemy(double x, double y, double r, int cnt, double spd, double ang, int flg) : cBaseEnemy(x, y, r, cnt, spd, ang, flg) {
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

	memset(enemy.moveang, 0, sizeof(enemy.moveang));
	enemy.moveang[0] = -5;
	enemy.moveang[1] = -0.2;
	enemy.moveang[2] = 5;
	enemy.moveang[3] = 5;
	enemy.moveang[4] = -0.2;
	enemy.moveang[5] = 90;

	memset(enemy.countflg, 0, sizeof(enemy.countflg));
	enemy.countflg[0] = 30;
	enemy.countflg[1] = 30;
	enemy.countflg[2] = 15;
	enemy.countflg[3] = 10;
	enemy.countflg[4] = 25;
	enemy.countflg[5] = 30;

	enemy.target.x = x;
	enemy.target.y = y;
	enemy.targetr = 5;


}


void cRedEnemy::Move(cRedEnemy &unit) {
	if (unit.enemy.attackflg == true) {
		if (unit.enemy.dir == unit.enemy.RIGHT) {
			unit.enemy.vct.x = cos(enemy.ang);
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


int cRedEnemy::Update() {
	enemy.count++;

	if (enemy.count > 0) {
		enemy.onActive = true;
	}
	if (enemy.RIGHT == enemy.dir) {
		switch (enemy.moveflg)
		{
		case 0:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 1:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 2:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 3:
			//enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 4:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 5:
			enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			if (enemy.pos.y >= 350 ) enemy.pos.y = -20;
			break;
		case 6:
			enemy.ang = atan2(enemy.target.y - enemy.pos.y, enemy.target.x - enemy.pos.x);
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
		case 7:
			enemy.count = 0;
			enemy.moveflg = 0;
			enemy.ang = 180 * 3.14159265 / 180;
			enemy.dir *= -1;
			enemy.attackflg = false;
			break;

		}
	}
	else {
		switch (enemy.moveflg)
		{
		case 0:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 1:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 2:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 3:
			//enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 4:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 5:
			enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			if (enemy.pos.y >= 350) enemy.pos.y = -20;
			break;
		case 6:
			enemy.ang = atan2(enemy.target.y - enemy.pos.y, enemy.target.x - enemy.pos.x);
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
		case 7:
			enemy.count = 0;
			enemy.moveflg = 0;
			enemy.ang = 180 * 3.14159265 / 180;
			enemy.dir *= -1;
			enemy.attackflg = false;
			break;

		}
	}
	return 0;
}

int cRedEnemy::Draw() {

	DrawCircle((int)enemy.pos.x, (int)enemy.pos.y, 5, GetColor(255, 0,0), true);
	DrawCircle((int)enemy.target.x, (int)enemy.target.y, enemy.targetr, GetColor(255, 0, 0), true);
	DrawFormatString(50, 55, GetColor(255, 255, 255), "%d", enemy.count);
	DrawFormatString(50, 65, GetColor(255, 255, 255), "%d", enemy.attackflg);
	DrawFormatString(50, 75, GetColor(255, 255, 255), "%d", enemy.moveflg);
	DrawFormatString(50, 85, GetColor(255, 255, 255), "%.2lf", enemy.pos.x);
	DrawFormatString(50, 95, GetColor(255, 255, 255), "%.2lf", enemy.pos.y);
	return 0;
}