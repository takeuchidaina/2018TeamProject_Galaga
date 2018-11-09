#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "cBlueEnemy.h"
#include "DxLib.h"
#include "Struct.h"


cBlueEnemy::cBlueEnemy(double x, double y, double r, int cnt, double spd, double ang, int flg) : cBaseEnemy(x,y,r,cnt,spd,ang,flg) {
	enemy.mainpos.pos.x = x;
	enemy.mainpos.pos.y = y;
	enemy.mainpos.r = r;

	enemy.count = cnt;
	enemy.spd = spd;
	enemy.ang = ang * 3.14159265 / 180;
	enemy.onActive = flg;

	enemy.moveflg = 0;

	enemy.vct.x = 0;
	enemy.vct.y = 0;

	memset(enemy.moveang, 0, sizeof(enemy.moveang));
	enemy.moveang[0] = -4;
	enemy.moveang[1] = -0.2;
	enemy.moveang[2] = 3;
	enemy.moveang[3] = 90;
	enemy.moveang[4] = 3;
	enemy.moveang[5] = 0;
	enemy.moveang[6] = 3;

	memset(enemy.countflg, 0, sizeof(enemy.countflg));
	enemy.countflg[0] = 40;
	enemy.countflg[1] = 70;
	enemy.countflg[2] = 20;
	enemy.countflg[3] = 130;
	enemy.countflg[4] = 30;
	enemy.countflg[5] = 20;
	enemy.countflg[6] = 20;

	enemy.target.x = x;
	enemy.target.y = y;
	enemy.targetr = 5;

}


void cBlueEnemy:: Move(cBlueEnemy &unit) {
	if (unit.enemy.attackflg == true) {
		if (unit.enemy.dir == unit.enemy.RIGHT) {
			unit.enemy.vct.x = cos(enemy.ang);
			unit.enemy.vct.y = sin(enemy.ang);
			unit.enemy.mainpos.pos.x += unit.enemy.vct.x*unit.enemy.spd;
			unit.enemy.mainpos.pos.y += unit.enemy.vct.y*unit.enemy.spd;
		}
		else {
			if (unit.enemy.moveflg != 7) {
				unit.enemy.vct.x = -cos(enemy.ang);
				unit.enemy.vct.y = sin(enemy.ang);
				unit.enemy.mainpos.pos.x += unit.enemy.vct.x*unit.enemy.spd;
				unit.enemy.mainpos.pos.y += unit.enemy.vct.y*unit.enemy.spd;
			}
			else {
				unit.enemy.vct.x = cos(enemy.ang);
				unit.enemy.vct.y = sin(enemy.ang);
				unit.enemy.mainpos.pos.x += unit.enemy.vct.x*unit.enemy.spd;
				unit.enemy.mainpos.pos.y += unit.enemy.vct.y*unit.enemy.spd;
			}
		}
	}
}


int cBlueEnemy::Update() {
	enemy.count++;

	if (enemy.count > 0) {
		enemy.onActive = true;
	}
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
				enemy.ang = 0;
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
				enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
				if (enemy.countflg[enemy.moveflg] <= enemy.count) {
					enemy.moveflg++;
					enemy.count = 0;
				}
				break;
			case 6:
				enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
				if (enemy.countflg[enemy.moveflg] <= enemy.count) {
					enemy.moveflg++;
					enemy.count = 0;
				}
				break;

			case 7:
				enemy.ang = atan2(enemy.target.y - enemy.mainpos.pos.y, enemy.target.x - enemy.mainpos.pos.x);
				if ((enemy.target.x - enemy.mainpos.pos.x)*(enemy.target.x - enemy.mainpos.pos.x) +
					(enemy.target.y - enemy.mainpos.pos.y)*(enemy.target.y - enemy.mainpos.pos.y) <=
					(enemy.mainpos.r + enemy.targetr)*(enemy.mainpos.r + enemy.targetr)) {
					//“GÀ•W‚ð–Ú“I’n‚ÉŒÅ’è
					enemy.mainpos.pos.x = enemy.target.x;
					enemy.mainpos.pos.y = enemy.target.y;
					enemy.moveflg++;
					enemy.count = 0;
				}
				break;
			case 8:
				enemy.count = 0;
				enemy.moveflg = 0;
				enemy.ang = 180 * 3.14159265 / 180;
				enemy.dir *= -1;
				enemy.attackflg = false;
				break;

		}
	
	return 0;
}
 
int cBlueEnemy::Draw() {

	DrawCircle((int)enemy.mainpos.pos.x, (int)enemy.mainpos.pos.y, 5, GetColor(0, 0, 255), true);
	DrawCircle(enemy.target.x, enemy.target.y, enemy.targetr, GetColor(0, 0, 255), true);
	DrawFormatString(0, 55, GetColor(255, 255, 255), "%d", enemy.count);
	DrawFormatString(0, 65, GetColor(255, 255, 255), "%d", enemy.attackflg);
	DrawFormatString(0, 75, GetColor(255, 255, 255), "%d", enemy.moveflg);
	DrawFormatString(0, 85, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.x);
	DrawFormatString(0, 95, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.y);
	return 0;
}