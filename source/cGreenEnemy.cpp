#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "cGreenEnemy.h"
#include "DxLib.h"
#include "Struct.h"
#include"UI.h"


cGreenEnemy::cGreenEnemy(double x, double y, double r, int cnt, double spd, double ang, int flg) : cBaseEnemy(x, y, r, cnt, spd, ang, flg) {
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

	enemy.target.x = x;
	enemy.target.y = y;
	enemy.targetr = 5;

	

}


void cGreenEnemy::Move(cGreenEnemy &unit) {
	enemy.mainpos.cx = enemy.mainpos.pos.x +enemy.width/2;
	enemy.mainpos.cy = enemy.mainpos.pos.y+enemy.hight/2;
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


int cGreenEnemy::Update() {
	enemy.count++;

	if (enemy.count > 0) {
		enemy.mainpos.onActive = true;
	}

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

int cGreenEnemy::Draw() {
	static int a = 0;
	static int b = 10;
	
	DrawExtendGraph((int)enemy.mainpos.pos.x-(int)enemy.width/2, (int)enemy.mainpos.pos.y-(int)enemy.hight/2, (int)enemy.mainpos.pos.x + IMAGEMAG-(int)enemy.width/2, (int)enemy.mainpos.pos.y + IMAGEMAG-(int)enemy.hight/2 ,enemy.graph[b], TRUE);
	//DrawCircle(enemy.target.x, enemy.target.y, enemy.targetr, GetColor(0, 255, 0), true);
	DrawFormatString(120, 855, GetColor(255, 255, 255), "%d", enemy.count);
	DrawFormatString(120, 870, GetColor(255, 255, 255), "%d", enemy.attackflg);
	DrawFormatString(120, 885, GetColor(255, 255, 255), "%d", enemy.moveflg);
	DrawFormatString(120, 900, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.x);
	DrawFormatString(120, 915, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.y);
/*	DrawLine((int)enemy.mainpos.pos.x - (int)enemy.width / 2, (int)enemy.mainpos.pos.y - (int)enemy.hight / 2, (int)enemy.mainpos.pos.x+ IMAGEMAG, (int)enemy.mainpos.pos.y - (int)enemy.hight / 2,GetColor(255, 255, 255));
	DrawLine((int)enemy.mainpos.pos.x - (int)enemy.width / 2, (int)enemy.mainpos.pos.y - (int)enemy.hight / 2+ IMAGEMAG, (int)enemy.mainpos.pos.x - (int)enemy.width / 2 + IMAGEMAG/2, (int)enemy.mainpos.pos.y - (int)enemy.hight / 2+IMAGEMAG, GetColor(255, 255, 255));
	DrawCircle(enemy.mainpos.pos.x, enemy.mainpos.pos.y, 3, GetColor(0, 255, 0), true);
	DrawCircle((int)enemy.mainpos.cx - enemy.width / 2, (int)enemy.mainpos.cy-enemy.hight/2, 3, GetColor(0, 255, 255), TRUE);*/
	a++;
	if (a > 60) {
		a = 0;
		b++;
		if (b > 11)b = 10;
	}
	return 0;
}