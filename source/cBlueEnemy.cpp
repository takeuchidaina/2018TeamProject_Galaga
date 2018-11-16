#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "cBlueEnemy.h"
#include "DxLib.h"
#include "Struct.h"
#include "UI.h"


cBlueEnemy::cBlueEnemy(double x, double y, double r, int cnt, double spd, double ang, int flg) : cBaseEnemy(x,y,r,cnt,spd,ang,flg) {
	enemy.mainpos.pos.x = x;
	enemy.mainpos.pos.y = y;
	enemy.mainpos.r = r;

	enemy.count = cnt;
	enemy.spd = spd;
	enemy.ang = ang * 3.14159265 / 180;
	enemy.mainpos.onActive = flg;

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
	enemy.countflg[2] = 25;
	enemy.countflg[3] = 130;
	enemy.countflg[4] = 30;
	enemy.countflg[5] = 20;
	enemy.countflg[6] = 20;

	enemy.target.x = x;
	enemy.target.y = y;
	enemy.targetr = 5;

}


void cBlueEnemy:: Move(cBlueEnemy &unit) {
	enemy.mainpos.cx = enemy.mainpos.pos.x + (enemy.width / 2);
	enemy.mainpos.cy = enemy.mainpos.pos.y + (enemy.hight / 2);
	if (unit.enemy.attackflg == TRUE) {
		if (enemy.mainpos.onActive == StartMove) {
			unit.enemy.vct.x = cos(enemy.ang);
			unit.enemy.vct.y = sin(enemy.ang);
			unit.enemy.mainpos.pos.x += unit.enemy.vct.x*unit.enemy.spd;
			unit.enemy.mainpos.pos.y += unit.enemy.vct.y*unit.enemy.spd;
		}
		else if (enemy.mainpos.onActive == YesActive) {
			if (unit.enemy.moveflg != 7) {
				unit.enemy.vct.x = -cos(enemy.ang)* unit.enemy.dir;
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
		enemy.mainpos.onActive = YesActive;
	}
			switch (enemy.moveflg)
			{
			case 0:
			case 1:
			case 2:
			case 4:
			case 5:
			case 6:
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
			case 7:
				enemy.ang = atan2(enemy.target.y - enemy.mainpos.pos.y, enemy.target.x - enemy.mainpos.pos.x);
				if ((enemy.target.x - enemy.mainpos.pos.x)*(enemy.target.x - enemy.mainpos.pos.x) +
					(enemy.target.y - enemy.mainpos.pos.y)*(enemy.target.y - enemy.mainpos.pos.y) <=
					(enemy.mainpos.r + enemy.targetr)*(enemy.mainpos.r + enemy.targetr)) {
					//敵座標を目的地に固定
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
	static int a = 0;
	static int b = 0;
//	DrawCircle((int)enemy.mainpos.pos.x, (int)enemy.mainpos.pos.y, 5, GetColor(0, 0, 255), true);
	//DrawCircle(enemy.target.x, enemy.target.y, enemy.targetr, GetColor(0, 0, 255), true);
	//DrawRotaGraph((int)enemy.mainpos.pos.x, (int)enemy.mainpos.pos.y,enemy.ang* 3.14159265 / 180,enemy.graph[b],false,false);
	//DrawCircle(enemy.target.x, enemy.target.y, enemy.targetr, GetColor(0, 255, 0), true);0
	DrawRotaGraph((int)enemy.mainpos.cx , (int)enemy.mainpos.cy , 3.0,(enemy.ang + 90*3.1419/180),enemy.graph[b],TRUE,TRUE);
	//DrawCircle(enemy.target.x, enemy.target.y, enemy.targetr, GetColor(0, 255, 0), true8;

	DrawFormatString(0, 855, GetColor(255, 255, 255), "%d", enemy.count);
	DrawFormatString(0, 870, GetColor(255, 255, 255), "%d", enemy.attackflg);
	DrawFormatString(0, 885, GetColor(255, 255, 255), "%d", enemy.moveflg);
	DrawFormatString(0, 900, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.x);
	DrawFormatString(0, 915, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.y);
	a++;
	if (a > 60) {
		a = 0;
		b++;
		if (b > 1)b = 0;
	}
	return 0;
}