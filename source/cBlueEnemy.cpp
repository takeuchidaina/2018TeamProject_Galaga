#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "cBlueEnemy.h"
#include "DxLib.h"
#include "Struct.h"
#include "UI.h"


cBlueEnemy::cBlueEnemy(double x, double y, double r, int cnt, double spd, double ang, int flg,int *graph) : cBaseEnemy(x,y,r,cnt,spd,ang,flg, graph) {
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


void cBlueEnemy:: Move() {
	enemy.mainpos.cx = enemy.mainpos.pos.x + (enemy.width / 2);
	enemy.mainpos.cy = enemy.mainpos.pos.y + (enemy.hight / 2);
	
		if (enemy.mainpos.onActive == StartMove) {
			enemy.vct.x = cos(enemy.ang);
			enemy.vct.y = sin(enemy.ang);
			enemy.mainpos.pos.x += enemy.vct.x*enemy.spd;
			enemy.mainpos.pos.y += enemy.vct.y*enemy.spd;
		}
		else if (enemy.mainpos.onActive == YesActive) {
			if (enemy.attackflg == TRUE) {
				if (enemy.moveflg != 7) {
					enemy.vct.x = cos(enemy.ang)*enemy.dir;
					enemy.vct.y = sin(enemy.ang);
					enemy.mainpos.pos.x += enemy.vct.x*enemy.spd;
					enemy.mainpos.pos.y += enemy.vct.y*enemy.spd;
				}
				else {
					enemy.vct.x = cos(enemy.ang);
					enemy.vct.y = sin(enemy.ang);
					enemy.mainpos.pos.x += enemy.vct.x*enemy.spd;
					enemy.mainpos.pos.y += enemy.vct.y*enemy.spd;
				}
			}
		}
}


int cBlueEnemy::Update() {
	enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
	enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);
	enemy.count++;

	if (enemy.count > 0) {
		enemy.mainpos.onActive = YesActive;
	}
	//enemy.ang = -90 * 3.14159265 / 180;


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
	static int a = 0;
	static int b = 0;
	a++;
	if (a > 60) {
		a = 0;
		b++;
		if (b > 1)b = 0;
	}

	if (enemy.dir == RIGHT) 
		DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, (enemy.ang + 90*3.14159265 / 180), enemy.graph[b], TRUE, TRUE);
	else {
		DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, -(enemy.ang + 90 * 3.14159265 / 180), enemy.graph[b], TRUE, TRUE);
	}

	DrawFormatString(0, 825, GetColor(255, 255, 255), "%.2lf", enemy.target.x);
	DrawFormatString(0, 840, GetColor(255, 255, 255), "%.2lf", enemy.target.y);
	DrawFormatString(0, 855, GetColor(255, 255, 255), "%d", enemy.count);
	DrawFormatString(0, 870, GetColor(255, 255, 255), "%d", enemy.attackflg);
	DrawFormatString(0, 885, GetColor(255, 255, 255), "%d", enemy.moveflg);
	DrawFormatString(0, 900, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.x);
	DrawFormatString(0, 915, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.y);
	DrawFormatString(0, 935, GetColor(255, 255, 255), "%d", enemy.dir);
	
	return 0;
}