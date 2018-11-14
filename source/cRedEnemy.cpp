#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "cRedEnemy.h"
#include "DxLib.h"
#include "Struct.h"
#include "UI.h"


cRedEnemy::cRedEnemy(double x, double y, double r, int cnt, double spd, double ang, int flg) : cBaseEnemy(x, y, r, cnt, spd, ang, flg) {
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
	enemy.moveang[2] = 1;
	enemy.moveang[3] = -0.1;
	enemy.moveang[4] = -1;
	enemy.moveang[5] = 90;

	memset(enemy.countflg, 0, sizeof(enemy.countflg));
	enemy.countflg[0] = 40;
	enemy.countflg[1] = 50;
	enemy.countflg[2] = 150;
	enemy.countflg[3] = 70;
	enemy.countflg[4] = 40;
	enemy.countflg[5] = 100;

	enemy.target.x = x;
	enemy.target.y = y;
	enemy.targetr = 5;


}


void cRedEnemy::Move(cRedEnemy &unit) {
	if (unit.enemy.attackflg == true) {
		if (unit.enemy.moveflg != 6) {
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


int cRedEnemy::Update() {
	enemy.count++;

	if (enemy.count > 0) {
		enemy.mainpos.onActive = true;
	}
		switch (enemy.moveflg)
		{
		case 0:
		case 1:
		case 2:
		case 3:
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
			if (enemy.mainpos.pos.y >= 960) {
				enemy.mainpos.pos.y = -20;
				enemy.mainpos.pos.x = enemy.target.x;
				enemy.moveflg++;
			}
			break; 
		case 6:
			enemy.ang = atan2(enemy.target.y - enemy.mainpos.pos.y, enemy.target.x - enemy.mainpos.pos.x);
			if ((enemy.target.x - enemy.mainpos.pos.x)*(enemy.target.x - enemy.mainpos.pos.x) +
				(enemy.target.y - enemy.mainpos.pos.y)*(enemy.target.y - enemy.mainpos.pos.y) <=
				(enemy.mainpos.r + enemy.targetr)*(enemy.mainpos.r + enemy.targetr)) {
				
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 7:
			enemy.count = 0;
			enemy.moveflg = 0;
			enemy.ang = 180 * 3.14159265 / 180;
			enemy.dir *= -1;
			//“GÀ•W‚ð–Ú“I’n‚ÉŒÅ’è
			enemy.mainpos.pos.x = enemy.target.x;
			enemy.mainpos.pos.y = enemy.target.y;
			enemy.attackflg = false;
			break;

		}
	
	return 0;
}





int cRedEnemy::Draw() {
	static int a = 0;
	static int b = 5;
//	DrawCircle((int)enemy.mainpos.pos.x, (int)enemy.mainpos.pos.y, 5, GetColor(255, 0,0), true);
	DrawExtendGraph((int)enemy.mainpos.pos.x - (int)enemy.width / 2, (int)enemy.mainpos.pos.y - (int)enemy.hight / 2, (int)enemy.mainpos.pos.x + IMAGEMAG - (int)enemy.width / 2, (int)enemy.mainpos.pos.y + IMAGEMAG - (int)enemy.hight / 2, enemy.graph[b], TRUE);
	//DrawCircle(enemy.target.x, enemy.target.y, enemy.targetr, GetColor(0, 255, 0), true);
	//DrawCircle((int)enemy.target.x, (int)enemy.target.y, enemy.targetr, GetColor(255, 0, 0), true);
	DrawFormatString(60, 855, GetColor(255, 255, 255), "%d", enemy.count);
	DrawFormatString(60, 870, GetColor(255, 255, 255), "%d", enemy.attackflg);
	DrawFormatString(60, 885, GetColor(255, 255, 255), "%d", enemy.moveflg);
	DrawFormatString(60, 900, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.x);
	DrawFormatString(60, 915, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.y);
	a++;
	if (a > 60) {
		a = 0;
		b++;
		if (b > 6)b = 5;
	}
	return 0;
}