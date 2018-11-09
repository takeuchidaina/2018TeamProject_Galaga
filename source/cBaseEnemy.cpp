#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "cBaseEnemy.h"
#include "DxLib.h"
#include "Struct.h"


 cBaseEnemy::cBaseEnemy(){
	 ;
}
 cBaseEnemy::cBaseEnemy(double x,double y,double r,int cnt ,double spd ,double ang,int flg) {
	 ;
 }

cBaseEnemy::~cBaseEnemy() {
	;
}

void cBaseEnemy::Move(cBaseEnemy &unit) {
	;
}


int cBaseEnemy::Update() {
	;
	return 0;
}



int cBaseEnemy::Draw() {
	
	DrawFormatString(0, 50, GetColor(255, 255, 255), "%d", enemy.count);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "%d", enemy.attackflg);
	DrawFormatString(0, 70, GetColor(255, 255, 255), "%d", enemy.moveflg);
	DrawFormatString(0, 80, GetColor(255, 255, 255), "%d", enemy.mainpos.pos.x);
	DrawFormatString(0, 90, GetColor(255, 255, 255), "%d", enemy.mainpos.pos.y);
	return 0;
}