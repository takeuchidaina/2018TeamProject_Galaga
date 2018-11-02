#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "cBaseEnemy.h"
#include "DxLib.h"
#include "Struct.h"


 cBaseEnemy::cBaseEnemy(){
	 enemy.pos.x = 700;
	 enemy.pos.y = 450;
	 enemy.r = 5;
	 enemy.count = 0;
	 enemy.spd = 3;
	 enemy.ang = 180 * 3.14159265 / 180;
	 enemy.onActive = 0;

	 enemy.moveflg = 0;

	 enemy.vct.x = 0;
	 enemy.vct.y = 0;

	 memset(enemy.moveang, 0, sizeof(enemy.moveang));
	 enemy.moveang[0] = 0.5;
	 enemy.moveang[1] = 3;

	 memset(enemy.countflg, 0, sizeof(enemy.countflg));
	 enemy.countflg[0] = 120;
	 enemy.countflg[1] = 120;

	 enemy.target.x = 160;
	 enemy.target.y = 64;
	 enemy.targetr = 1;

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
	 enemy.countflg[1] = 120;
	 enemy.countflg[2] = 15;
	 enemy.countflg[3] = 30;
	 enemy.countflg[4] = 45;

	 enemy.target.x = x;
	 enemy.target.y = y;
	 enemy.targetr = 5;
	 
 }

cBaseEnemy::~cBaseEnemy() {

}

int cBaseEnemy::Update() {
	
	return 0;
}

void cBaseEnemy::Move(cBaseEnemy &unit) {
	unit.enemy.vct.x = cos(enemy.ang);
	unit.enemy.vct.y = sin(enemy.ang);
	unit.enemy.pos.x += unit.enemy.vct.x*unit.enemy.spd;
	unit.enemy.pos.y += unit.enemy.vct.y*unit.enemy.spd;
}

int cBaseEnemy::Draw() {
	
	DrawFormatString(0, 100, GetColor(255, 255, 255), "%d", enemy.count);
	DrawCircle(enemy.pos.x, enemy.pos.y,5, GetColor(255, 255, 255), true);
	DrawCircle(enemy.target.x, enemy.target.y, enemy.targetr, GetColor(255, 255, 255), true);
	DrawCircle(100, 300, 5, GetColor(255, 0,0), true);
	DrawCircle(700, 450, 5, GetColor(255, 0, 0), true);
	return 0;
}