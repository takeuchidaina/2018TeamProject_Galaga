#include <iostream>
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
	enemy.ang = ang * 3.14159265 / 180;
	enemy.mainpos.onActive = flg;

	enemy.moveflg = 0;

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

	memset(enemy.countflg, 0, sizeof(enemy.countflg));
	enemy.countflg[0] = 20;
	enemy.countflg[1] = 50;
	enemy.countflg[2] = 20;
	enemy.countflg[3] = 75;
	enemy.countflg[4] = 100;
	enemy.countflg[5] = 20;
	enemy.countflg[6] = 80;

	memset(tractormoveang, 0, sizeof(tractormoveang));
	tractormoveang[0] = -4;
	tractormoveang[1] = 90;
	tractormoveang[2] = 90;
	

	memset(tractorcountflg, 0, sizeof(tractorcountflg));
	tractorcountflg[0] = 20;
	tractorcountflg[1] = 50;
	tractorcountflg[2] = 50;
	tractorcountflg[3] = 75;
	tractorcountflg[4] = 100;
	tractorcountflg[5] = 20;
	tractorcountflg[6] = 80;


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
				enemy.vct.x = cos(enemy.ang)*enemy.dir;
				enemy.vct.y = sin(enemy.ang);
				enemy.mainpos.pos.x += enemy.vct.x*enemy.spd;
				enemy.mainpos.pos.y += enemy.vct.y*enemy.spd;
		}
	}
}


int cGreenEnemy::Update() {
	enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
	enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);
	enemy.count++;

	if (enemy.count > 0) {
		enemy.mainpos.onActive = YesActive;
	}
	//enemy.ang =-90 * 3.14159265 / 180;
		switch (enemy.moveflg)
		{
		case 0:
		case 1:
		case 3:
		case 5:
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 2:
		case 4:
			enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 6:
			enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
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
				(enemy.mainpos.r-1 + enemy.targetr)*(enemy.mainpos.r-1 + enemy.targetr)) {
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


void cGreenEnemy::TractorUpdate() {
	enemy.count++;
	/*if (enemy.moveflg == 2) {
		static int a = 0;
		static int b = 0;
		a++;
		if (a >= 30) {
			b++;
			a = 0;
		}
		if (b > 11) {
			b = 0;
			enemy.moveflg++;
		}
	}*/
	if (enemy.count > 0) {
		enemy.mainpos.onActive = YesActive;
	}
	
	switch (enemy.moveflg)
	{
		
	case 0:
	//case 1:
		enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
		if (tractorcountflg[enemy.moveflg] <= enemy.count) {
			enemy.moveflg++;
			enemy.count = 0;
		}
		break;
	/*case 2:
		enemy.ang = 0;
		enemy.ang += enemy.moveang[enemy.moveflg] * 3.1419265 / 180;
		if (tractorcountflg[enemy.moveflg] <= enemy.count) {
			enemy.moveflg++;
			enemy.count = 0;
		}
		break;*/
	case 1:
		enemy.ang = atan2(674-64 - enemy.mainpos.pos.y, (300- enemy.mainpos.pos.x)*enemy.dir);
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
		//enemy.count = 0;
		//enemy.moveflg = 0;
		enemy.ang = 90 * 3.14159265 / 180;
		DrawGraph(300,674,tractor[0],TRUE);
		//enemy.dir *= -1;
		//enemy.attackflg = false;
		break;
	case 3:
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
	}
}


int cGreenEnemy::Draw() {
	static int a = 0;
	static int b = 10;
	a++;
	if (a > 60) {
		a = 0;
		b++;
		if (b > 11)b = 10;
	}
	if(enemy.dir == RIGHT)DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, (enemy.ang + (90 * 3.14159265) / 180), enemy.graph[b], TRUE, TRUE);
	else DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, -(enemy.ang + 90 * 3.14159265 / 180), enemy.graph[b], TRUE, TRUE);
	//DrawCircle(enemy.target.x, enemy.target.y, enemy.targetr, GetColor(0, 255, 0), true);
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
	
	return 0;
}