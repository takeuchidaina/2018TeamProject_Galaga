#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES
#include <memory.h>
#include "cBaseEnemy.h"
#include "DxLib.h"
#include "Struct.h"
#include "UI.h"



 cBaseEnemy::cBaseEnemy(){
	 /*memset(enemy.graph, 0x00, sizeof(enemy.graph));
	 LoadDivGraph("../resorce/Image/Galaga_OBJ_enemy.png", 20, 5, 4, 22, 16, enemy.graph);*/
	// LoadGraphScreen(100,100,"../Image/Galaga_OBJ_enemy.png",false);
	 ;
}
 cBaseEnemy::cBaseEnemy(double x,double y,double r,int cnt ,double spd ,double ang,int flg,int *graph) {
	 enemy.mainpos.pos.x = x;
	 enemy.mainpos.pos.y = y;
	 enemy.width =16*3;
	 enemy.hight = 16*3;
	 enemy.mainpos.cx = enemy.mainpos.pos.x + (double)(enemy.width / 2);
	 enemy.mainpos.cy = enemy.mainpos.pos.y + (double)(enemy.hight / 2);
	 enemy.ang = ang * M_PI / 180;
	 //memset(enemy.graph, 0x00, sizeof(enemy.graph));
	  enemy.graph = graph;
	  enemy.attackflg = false;
	  a = 0;
	  b = 0;
 }

cBaseEnemy::~cBaseEnemy() {
	;
}

void cBaseEnemy::Move() {
	;
}


int cBaseEnemy::Update() {
	enemy.target.x=cEnemyMgr::Instance()->GetTargetX(this);
	enemy.target.y = cEnemyMgr::Instance()->GetTargetY(this);
	if (enemy.moveflg == 0 && enemy.count == 0) enemy.mainpos.onActive = LadyStart;
	return 0;
}



int cBaseEnemy::Draw() {
#ifdef DEBUG
	DrawFormatString(0, 50, GetColor(255, 255, 255), "%d", enemy.count);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "%d", enemy.attackflg);
	DrawFormatString(0, 70, GetColor(255, 255, 255), "%d", enemy.moveflg);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "%d", enemy.mainpos.pos.x);
	DrawFormatString(0, 90, GetColor(255, 255, 255), "%d", enemy.mainpos.pos.y);
#endif
	return 0;
}


 
void cBaseEnemy::TractorUpdate() {
	;
}


