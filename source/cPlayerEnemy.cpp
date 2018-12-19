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
#include"TextChange.h"
#include"cBaseEnemy.h"


cPlayerEnemy::cPlayerEnemy() {

	rotecnt = 0;
	playerNum = 0;

	for (int i = 0; i < 2; i++) {
		tmpPlayer = cPlayer::Instance()->GetPlayer(i);
		if (tmpPlayer.onActive == false)continue;
		break;
	}

	enemy.vct.x = 0;
	enemy.vct.y = 0;
	enemy.ang = -90 * M_PI / 180;
	enemy.mainpos.r = 18;
	enemy.mainpos.pos.x = tmpPlayer.pos.x;
	enemy.mainpos.pos.y = tmpPlayer.pos.y;
	enemy.mainpos.cx = enemy.mainpos.pos.x + enemy.mainpos.pos.x / 2.0;
	enemy.mainpos.cy = enemy.mainpos.pos.y + enemy.mainpos.pos.y / 2.0;
	/*enemy.width = 16;
	enemy.height = 16;*/
	enemy.mainpos.onActive = YesActive;
	enemy.count = 0;
	enemy.moveflg = 0;
	enemy.spd = 3;
	LoadDivGraph("../resource/Image/Galaga_OBJ_myMachine1616.png", 12, 4, 3, 16, 16, graph);
}

/*
void cPlayerEnemy::EternalUpdate() {
	sEnemy TmpEnemy;
	TmpEnemy =
	enemy.mainpos.pos.x = TmpEnemy->mainpos.pos.x + 22;
	enemy.mainpos.pos.y = TmpEnemy->mainpos.pos.y + 50;
	enemy.ang = TmpEnemy->ang;
}
*/

cPlayerEnemy::~cPlayerEnemy() {
	;
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
	enemy.count++;



	switch (enemy.moveflg)
	{
	case 0:
		rotecnt += 0.3;
		enemy.ang = atan2((TmpEnemy->mainpos.pos.y + 48) - enemy.mainpos.pos.y, TmpEnemy->mainpos.pos.x + 22 - enemy.mainpos.pos.x);
		if ((TmpEnemy->mainpos.pos.x + 22 - enemy.mainpos.pos.x)*(TmpEnemy->mainpos.pos.x + 22 - enemy.mainpos.pos.x) +
			((TmpEnemy->mainpos.pos.y + 48) - enemy.mainpos.pos.y)*((TmpEnemy->mainpos.pos.y + 48) - enemy.mainpos.pos.y) <=
			(TmpEnemy->mainpos.r / 5 + enemy.targetr)*(TmpEnemy->mainpos.r / 5 + enemy.targetr)) {
			if (rotecnt > 30) {
				playerNum = 4;
				enemy.moveflg++;
			}
		}
		break;
	case 1:
		enemy.ang = atan2((TmpEnemy->mainpos.pos.y + 48) - enemy.mainpos.pos.y, TmpEnemy->mainpos.pos.x + 25 - enemy.mainpos.pos.x);
		if (enemy.count > 200) {

			enemy.count = 0;
			enemy.moveflg++;
			TmpEnemy->moveflg++;
		}
		cTextChange::Instance()->DrawTextImage(300, 400, "FIGHTER", eRed, eMag32);
		cTextChange::Instance()->DrawTextImage(400, 400, "CAPTURE", eRed, eMag32);
		break;
	case 2:
		enemy.mainpos.pos.x = TmpEnemy->mainpos.pos.x + 22;
		enemy.mainpos.pos.y = TmpEnemy->mainpos.pos.y + 50;
		enemy.ang = TmpEnemy->ang;
		if (enemy.count > 50) {
			enemy.moveflg++;
		}
		break;
	case 3:
		enemy.mainpos.pos.x = TmpEnemy->mainpos.pos.x + 25;
		enemy.mainpos.pos.y = TmpEnemy->mainpos.pos.y - 30;
		enemy.ang = TmpEnemy->ang;

		if (cInGameMgr::Instance()->GetSceneFlg() == cInGameMgr::Instance()->eTractor)
			cInGameController::Instance()->OutToTractor();
		break;
	}
	return 0;
}


int cPlayerEnemy::ReviveUpdate() {
	sOBJPos TmpPlayer;

	for (int i = 0; i < 2; i++) {
		TmpPlayer = cPlayer::Instance()->GetPlayer(i);
		if (TmpPlayer.onActive == false) continue;
		if (i == 0) {
			TmpPlayer.pos.x + 48;
		}
		else {
			TmpPlayer.pos.x - 48;
		}
	}
	rotecnt += 0.3;
	enemy.ang = atan2(TmpPlayer.pos.y - enemy.mainpos.pos.y, TmpPlayer.pos.x - enemy.mainpos.pos.x);
	if ((TmpPlayer.pos.y - enemy.mainpos.pos.y)*(TmpPlayer.pos.y - enemy.mainpos.pos.y) +
		(TmpPlayer.pos.x - enemy.mainpos.pos.x)*(TmpPlayer.pos.x - enemy.mainpos.pos.x)
		<= (TmpPlayer.r - 1 + enemy.mainpos.r)*(TmpPlayer.r - 1 + enemy.mainpos.r)) {
		cPlayer::Instance()->Double();
		cEnemyMgr::Instance()->DeletePlayerEnemy();
		cInGameController::Instance()->OutToRevive();
	}
	return 0;
}

int cPlayerEnemy::Draw() {
	/*if (enemy.dir == RIGHT)DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, (enemy.ang + (90 * M_PI) / 180), enemy.graph[0], TRUE, TRUE);
	//else DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, -(enemy.ang + 90 * M_PI / 180), enemy.graph[0], TRUE, TRUE);
	*/

	if (enemy.moveflg == 0)DrawRotaGraph((int)enemy.mainpos.pos.x, (int)enemy.mainpos.pos.y, 3, rotecnt, graph[playerNum], TRUE);
	else DrawRotaGraph((int)enemy.mainpos.pos.x, (int)enemy.mainpos.pos.y, 3, enemy.ang*M_PI / 180, graph[playerNum], TRUE);

#ifndef DEBUG
	DrawFormatString(120, 885, GetColor(255, 255, 255), "%d", enemy.moveflg);
	DrawFormatString(120, 900, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.x);
	DrawFormatString(120, 915, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.y);
	//DrawFormatString(900,0, GetColor(255,255,255),"%d",enemy.moveflg);
#endif // DEBUG





	return 0;
}

