#include <iostream>
#define _USE_MATH_DEFINES
using namespace std;
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "cGreenEnemy.h"
#include "DxLib.h"
#include "Struct.h"
#include"UI.h"
//ｙ674からビーム描画

cGreenEnemy::cGreenEnemy(double x, double y, double r, int cnt, double spd, double ang, int flg,int *graph) : cBaseEnemy(x, y, r, cnt, spd, ang, flg, graph) {
	enemy.mainpos.pos.x = x;
	enemy.mainpos.pos.y = y;
	enemy.mainpos.r = r;
	enemy.count = cnt;
	enemy.spd = spd;
	enemy.ang = ang * M_PI / 180;
	enemy.mainpos.onActive = flg;

	enemy.moveflg = 0;
	tractorflg = false;

	enemy.vct.x = 0;
	enemy.vct.y = 0;

	memset(enemy.moveang, 0, sizeof(enemy.moveang));
	enemy.moveang[0] = -4;
	enemy.moveang[1] = -1;
	enemy.moveang[2] = 35;
	enemy.moveang[3] = -5;
	enemy.moveang[4] = 40;
	enemy.moveang[5] = 3;
	enemy.moveang[6] = 90;
	enemy.moveang[8] = 2;

	memset(enemy.countflg, 0, sizeof(enemy.countflg));
	enemy.countflg[0] = 20;
	enemy.countflg[1] = 40;
	enemy.countflg[2] = 20;
	enemy.countflg[3] = 75;
	enemy.countflg[4] = 50;
	enemy.countflg[5] = 20;
	enemy.countflg[6] = 80;
	enemy.countflg[8] = 90;

	memset(tractormoveang, 0, sizeof(tractormoveang));
	tractormoveang[0] = -4;

	

	memset(tractorcountflg, 0, sizeof(tractorcountflg));
	tractorcountflg[0] = 20;


	enemy.target.x = x;
	enemy.target.y = y;
	enemy.targetr = 5;

	LoadDivGraph("../resource/Image/Galaga_OBJ_effect.png", 15, 5, 3, 50, 82, tractor);
}


void cGreenEnemy::Move( ) {
	enemy.mainpos.cx = enemy.mainpos.pos.x +enemy.width/2;
	enemy.mainpos.cy = enemy.mainpos.pos.y+enemy.hight/2;
	if (enemy.mainpos.onActive == StartMove) {
		enemy.vct.x = cos(enemy.ang);
		enemy.vct.y = sin(enemy.ang);
		enemy.mainpos.pos.x += enemy.vct.x*enemy.spd;
		enemy.mainpos.pos.y += enemy.vct.y*enemy.spd;
	}
	else if(enemy.mainpos.onActive == YesActive){
		if (enemy.attackflg == TRUE) {
			if (enemy.moveflg != 8) {
				enemy.vct.x = cos(enemy.ang)*enemy.dir;
				enemy.vct.y = sin(enemy.ang);
				enemy.mainpos.pos.x += enemy.vct.x*enemy.spd;
				enemy.mainpos.pos.y += enemy.vct.y*enemy.spd;
			}
			else {
				enemy.vct.x = cos(enemy.ang)*enemy.dir;;
				enemy.vct.y = sin(enemy.ang);
			}
		}
	}
}


int cGreenEnemy::Update() {
	enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
	enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);
	if (tractorflg == 0) {
		enemy.count++;

		if (enemy.count > 0) {
			enemy.mainpos.onActive = YesActive;
		}

		switch (enemy.moveflg)
		{
		case 0:
			if (enemy.count == 1)enemy.ang = 180 * M_PI / 180;
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 1:
		case 3:
		case 5:
		case 8:
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 2:
		case 4:
			enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 6:
			enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.mainpos.pos.y > 980) {
				enemy.mainpos.pos.y = -20;
				enemy.mainpos.pos.x = enemy.target.x;
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 7:
			enemy.ang = atan2(enemy.target.y - enemy.mainpos.pos.y, enemy.target.x - enemy.mainpos.pos.x);
			if ((enemy.target.x - enemy.mainpos.pos.x)*(enemy.target.x - enemy.mainpos.pos.x) +
				(enemy.target.y - enemy.mainpos.pos.y)*(enemy.target.y - enemy.mainpos.pos.y) <=
				(enemy.mainpos.r - 1 + enemy.targetr)*(enemy.mainpos.r - 1 + enemy.targetr)) {
				//敵座標を目的地に固定
				enemy.mainpos.pos.x = enemy.target.x;
				enemy.mainpos.pos.y = enemy.target.y;
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 9:
			enemy.count = 0;
			enemy.moveflg = 0;
			enemy.ang = 180 * M_PI / 180;
			enemy.dir *= -1;
			//enemy.attackflg = falseflg =
			tractorflg = true;
			break;
		}
	}
	return 0;
}


void cGreenEnemy::TractorUpdate() {
	enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
	enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);
	if (tractorflg !=0) {
		enemy.count++;
	
		if (enemy.count > 0) {
			enemy.mainpos.onActive = YesActive;
		}

		switch (enemy.moveflg)
		{

		case 0:
			if (enemy.count == 0)enemy.ang = 180 * M_PI / 180;
			enemy.ang += tractormoveang[enemy.moveflg] * M_PI / 180;
			if (tractorcountflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 1:
			enemy.ang = atan2(674 - 64 - enemy.mainpos.pos.y, (300 - enemy.mainpos.pos.x)*enemy.dir);
			if ((300 - enemy.mainpos.pos.x)*(300 - enemy.mainpos.pos.x) +
				(674 - 64 - enemy.mainpos.pos.y)*(674 - 64 - enemy.mainpos.pos.y) <=
				(enemy.mainpos.r - 1 + enemy.targetr)*(enemy.mainpos.r - 1 + enemy.targetr)) {
				//敵座標を目的地に固定
				enemy.mainpos.pos.x = 300;
				enemy.mainpos.pos.y = 674 - 64;
				enemy.count = 0;
				enemy.moveflg++;
			}
			break;
		case 2:
			enemy.mainpos.pos.x = 300;
			enemy.mainpos.pos.y = 674 - 64;
			enemy.ang = 90 * M_PI / 180;
			break;
		case 3:
			enemy.ang = atan2(enemy.target.y - enemy.mainpos.pos.y, (enemy.target.x - enemy.mainpos.pos.x)*enemy.dir);
			if ((enemy.target.x - enemy.mainpos.pos.x)*(enemy.target.x - enemy.mainpos.pos.x) +
				(enemy.target.y - enemy.mainpos.pos.y)*(enemy.target.y - enemy.mainpos.pos.y) <=
				(enemy.mainpos.r - 1 + enemy.targetr)*(enemy.mainpos.r - 1 + enemy.targetr)) {
				//敵座標を目的地に固定
				enemy.mainpos.pos.x = enemy.target.x;
				enemy.mainpos.pos.y = enemy.target.y;
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 4:
			enemy.count = 0;
			enemy.moveflg = 0;
			enemy.ang = 180 * M_PI / 180;
			enemy.dir *= -1;
			tractorflg = 0;
			break;
		}
	}
}


int cGreenEnemy::Draw() {
	static int a = 0;
	static int b = 10;
	static int c = 0;
	static int d = 0;
	a++;
	if (a > 60) {
		a = 0;
		b++;
		if (b > 11)b = 10;
	}
	if(enemy.dir == RIGHT)DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, (enemy.ang + (90 * M_PI) / 180), enemy.graph[b], TRUE, TRUE);
	else DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, -(enemy.ang + 90 * M_PI / 180), enemy.graph[b], TRUE, TRUE);
	if (tractorflg == 1) {
		if (enemy.moveflg == 2) {
			c++;
			if (c > 60) {
				c = 0;
				d++;
				if (d > 11){
					d = 0;
					enemy.moveflg++;
				}
			}
			DrawGraph((int)enemy.mainpos.pos.x-5, (int)enemy.mainpos.pos.y + enemy.hight, tractor[d], TRUE);
		}
	}

#ifdef DEBUG
	DrawFormatString(120, 855, GetColor(255, 255, 255), "%d", enemy.count);
	DrawFormatString(120, 870, GetColor(255, 255, 255), "%d", enemy.attackflg);
	DrawFormatString(120, 885, GetColor(255, 255, 255), "%d", enemy.moveflg);
	DrawFormatString(120, 900, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.x);
	DrawFormatString(120, 915, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.y);
	DrawFormatString(120, 935, GetColor(255, 255, 255), "%d", enemy.dir);
	/*	DrawLine((int)enemy.mainpos.pos.x - (int)enemy.width / 2, (int)enemy.mainpos.pos.y - (int)enemy.hight / 2, (int)enemy.mainpos.pos.x+ IMAGEMAG, (int)enemy.mainpos.pos.y - (int)enemy.hight / 2,GetColor(255, 255, 255));
		DrawLine((int)enemy.mainpos.pos.x - (int)enemy.width / 2, (int)enemy.mainpos.pos.y - (int)enemy.hight / 2+ IMAGEMAG, (int)enemy.mainpos.pos.x - (int)enemy.width / 2 + IMAGEMAG/2, (int)enemy.mainpos.pos.y - (int)enemy.hight / 2+IMAGEMAG, GetColor(255, 255, 255));
		DrawCircle(enemy.mainpos.pos.x, enemy.mainpos.pos.y, 3, GetColor(0, 255, 0), true);
		DrawCircle((int)enemy.mainpos.cx - enemy.width / 2, (int)enemy.mainpos.cy-enemy.hight/2, 3, GetColor(0, 255, 255), TRUE);*/
#endif // DEBUG


	
	return 0;
}