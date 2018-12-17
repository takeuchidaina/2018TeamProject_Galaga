#include <iostream>
using namespace std;
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <memory.h>
#include "cBaseEnemy.h"
#include "cGreenEnemy.h"
#include "cPlayerEnemy.h"
#include "InGameMgr.h"
#include "DxLib.h"
#include "Struct.h"
#include "shot.h"
#include "Player.h"


cPlayerEnemy::cPlayerEnemy() {

	for (int i = 0; i < 2; i++) {
		tmpPlayer = cPlayer::Instance()->GetPlayer(i);
		if (tmpPlayer.onActive == false)continue;
		break;
	}
	enemy.mainpos.pos.x = tmpPlayer.pos.x;
	enemy.mainpos.pos.y = tmpPlayer.pos.y;
	enemy.mainpos.cx = enemy.mainpos.pos.x + enemy.mainpos.pos.x / 2.0;
	enemy.mainpos.cy = enemy.mainpos.pos.y + enemy.mainpos.pos.y / 2.0;
	/*enemy.width = 16;
	enemy.height = 16;*/
	enemy.mainpos.onActive = 2;

	enemy.spd = 3;
	LoadDivGraph("../resource/Image/Galaga_OBJ_myMachine1616.png", 12, 4, 3, 16, 16, graph);
}

void cPlayerEnemy::Move() {
	enemy.mainpos.cx = enemy.mainpos.pos.x + enemy.mainpos.pos.x / 2;
	enemy.mainpos.cy = enemy.mainpos.pos.y + enemy.mainpos.pos.y / 2;
	enemy.vct.x = cos(enemy.ang);
	enemy.vct.y = sin(enemy.ang);
	enemy.mainpos.pos.x += enemy.vct.x*enemy.spd;
	enemy.mainpos.pos.y += enemy.vct.y*enemy.spd;
}
int cPlayerEnemy::Update(sEnemy* TmpEnemy) {

	switch (enemy.moveflg)
	{
	case 0:
		enemy.ang = atan2((TmpEnemy->mainpos.pos.y + 160) - enemy.mainpos.pos.y, TmpEnemy->mainpos.pos.x - enemy.mainpos.pos.x);
		if ((TmpEnemy->mainpos.pos.x - enemy.mainpos.pos.x)*(TmpEnemy->mainpos.pos.x - enemy.mainpos.pos.x) +
			((TmpEnemy->mainpos.pos.y + 160) - enemy.mainpos.pos.y)*((TmpEnemy->mainpos.pos.y +160) - enemy.mainpos.pos.y) <=
			(TmpEnemy->mainpos.r - 1 + enemy.targetr)*(TmpEnemy->mainpos.r - 1 + enemy.targetr)) {
			enemy.moveflg++;
			TmpEnemy->moveflg++;
		}
		break;
	case 2:
		enemy.mainpos.pos.x = TmpEnemy->mainpos.pos.x;
		enemy.mainpos.pos.y = TmpEnemy->mainpos.pos.y + 48;
		enemy.ang = TmpEnemy->ang;
		if (TmpEnemy->mainpos.onActive == 1)enemy.moveflg++;
		break;
	}
	/*enemy.mainpos.pos.x = tmpenemy.mainpos.pos.x;
	enemy.mainpos.pos.y = tmpenemy.mainpos.pos.y;*/
	/*
		enemy.ang = tmpenemy.ang;*/
	return 0;
}

int cPlayerEnemy::TractorStart(sEnemy Tmpenemy) {
	enemy.ang = atan2((Tmpenemy.mainpos.pos.y + Tmpenemy.height) - tmpPlayer.pos.y, Tmpenemy.mainpos.pos.x - tmpPlayer.pos.x);
	return 0;
}

int cPlayerEnemy::Draw() {
	/*if (enemy.dir == RIGHT)DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, (enemy.ang + (90 * M_PI) / 180), enemy.graph[0], TRUE, TRUE);
	//else DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, -(enemy.ang + 90 * M_PI / 180), enemy.graph[0], TRUE, TRUE);
	*/

	DrawRotaGraph((int)enemy.mainpos.pos.x, (int)enemy.mainpos.pos.y, 3, 0, graph[0], TRUE);
	return 0;
}

