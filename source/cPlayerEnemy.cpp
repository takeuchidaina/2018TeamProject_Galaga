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
#include"EnemyMgr.h"


cPlayerEnemy::cPlayerEnemy() {

	rotecnt = 0;
	playerGraphNum = 0;

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
	reMoveFlg = 0;
	LoadDivGraph("../resource/Image/Galaga_OBJ_myMachine1616.png", 12, 4, 3, 16, 16, graph);
}



cPlayerEnemy::~cPlayerEnemy() {
	if (this != NULL) {
		cEnemyMgr::Instance()->DeletePlayerEnemy();
		tmpEnemy = NULL;
	}
}


void cPlayerEnemy::Move() {

	enemy.mainpos.cx = enemy.mainpos.pos.x + enemy.mainpos.pos.x / 2;
	enemy.mainpos.cy = enemy.mainpos.pos.y + enemy.mainpos.pos.y / 2;
	if (enemy.moveflg != 4 || enemy.moveflg != 3) {
		enemy.vct.x = cos(enemy.ang);
		enemy.vct.y = sin(enemy.ang);
		enemy.mainpos.pos.x += enemy.vct.x*enemy.spd;
		enemy.mainpos.pos.y += enemy.vct.y*enemy.spd;
	}
}
int cPlayerEnemy::Update() {
	cTextChange::Instance()->DrawTextImage(250, 400, "FIGHTER", eRed, eMag48);
	cTextChange::Instance()->DrawTextImage(500, 400, "CAPTURE", eRed, eMag48);


	//tmpEnemyのところをtmpEnemyに帰れば敵の下まで行く
	switch (enemy.moveflg)
	{
	case 0:
		rotecnt += 0.3;
		enemy.ang = atan2((tmpEnemy->mainpos.pos.y + 48) - enemy.mainpos.pos.y, tmpEnemy->mainpos.pos.x + 22 - enemy.mainpos.pos.x);
		if ((tmpEnemy->mainpos.pos.x + 22 - enemy.mainpos.pos.x)*(tmpEnemy->mainpos.pos.x + 22 - enemy.mainpos.pos.x) +
			((tmpEnemy->mainpos.pos.y + 48) - enemy.mainpos.pos.y)*((tmpEnemy->mainpos.pos.y + 48) - enemy.mainpos.pos.y) <=
			(tmpEnemy->mainpos.r / 5 + enemy.targetr)*(tmpEnemy->mainpos.r / 5 + enemy.targetr)) {
			if (rotecnt > 30) {
				rotecnt = 0;
				enemy.mainpos.pos.x = tmpEnemy->mainpos.pos.x + 22;
				enemy.mainpos.pos.y = tmpEnemy->mainpos.pos.y + 48;
				playerGraphNum = 4;
				enemy.moveflg++;
			}
		}
		break;
	case 1:
		enemy.ang = atan2((tmpEnemy->mainpos.pos.y + 48) - enemy.mainpos.pos.y, tmpEnemy->mainpos.pos.x + 25 - enemy.mainpos.pos.x);
		if ((tmpEnemy->mainpos.pos.x + 22 - enemy.mainpos.pos.x)*(tmpEnemy->mainpos.pos.x + 22 - enemy.mainpos.pos.x) +
			((tmpEnemy->mainpos.pos.y + 48) - enemy.mainpos.pos.y)*((tmpEnemy->mainpos.pos.y + 48) - enemy.mainpos.pos.y) <=
			(tmpEnemy->mainpos.r / 5 + enemy.targetr)*(tmpEnemy->mainpos.r / 5 + enemy.targetr)) {
			enemy.ang = 180;
			enemy.count++;
			enemy.mainpos.pos.x = tmpEnemy->mainpos.pos.x+22;
			enemy.mainpos.pos.y = tmpEnemy->mainpos.pos.y + 48;
			/*cTextChange::Instance()->DrawTextImage(300, 400, "FIGHTER", eRed, eMag32);
			cTextChange::Instance()->DrawTextImage(400, 400, "CAPTURE", eRed, eMag32);*/
		}

		if (enemy.count > 200) {

			enemy.count = 0;
			enemy.moveflg++;
			//tmpEnemy->moveflg++;
		}

		break;
	case 2:
		enemy.mainpos.pos.x = tmpEnemy->mainpos.pos.x+22;
		enemy.mainpos.pos.y = tmpEnemy->mainpos.pos.y + 48;
		enemy.ang =180;
		if (tmpEnemy->mainpos.pos.x ==  tmpEnemy->target.x  &&  tmpEnemy->mainpos.pos.y == tmpEnemy->target.y) {
		/*	if (enemy.mainpos.pos.y > 100) {
				enemy.mainpos.pos.y--;
			}
			else {*/
				enemy.moveflg++;
		//	}
		}
		break;

	case 3:
		enemy.mainpos.pos.x = tmpEnemy->mainpos.pos.x+22;
		enemy.mainpos.pos.y = tmpEnemy->mainpos.pos.y + 48;
		enemy.ang = 180;
		atan2((tmpEnemy->mainpos.pos.y - 48) - enemy.mainpos.pos.y, tmpEnemy->mainpos.pos.x + 22 - enemy.mainpos.pos.x);
		//ここの処理がおかしいみたいです
		//while (enemy.mainpos.pos.y > tmpEnemy->mainpos.pos.y - 48) enemy.mainpos.pos.y-=1.0;
		enemy.moveflg++;
		
		break;
	case 4:
		if (cInGameMgr::Instance()->GetSceneFlg() == cInGameMgr::Instance()->eTractor) {
			cInGameController::Instance()->OutToTractor();
		}
		if (tmpEnemy->moveflg == 3 && (tmpEnemy->count == 5 || tmpEnemy->count == 25))cShotMgr::Instance()->EnemyShot(enemy.mainpos.pos.x, enemy.mainpos.pos.y);
		enemy.mainpos.pos.x = tmpEnemy->mainpos.pos.x +25;
		enemy.mainpos.pos.y = tmpEnemy->mainpos.pos.y - 48;
		enemy.ang = tmpEnemy->ang;
		enemy.dir = tmpEnemy->dir;
	}
	return 0;
}


int cPlayerEnemy::ReviveUpdate() {
	switch (reMoveFlg)
	{
	case 0:
		rotecnt += 0.3;
		if (rotecnt > 30)
		{
			rotecnt = 0;
			reMoveFlg++;
		}
		break;
	case 1:

		if ((enemy.mainpos.pos.x - 450.0)*(enemy.mainpos.pos.x - 450.0) +
			(enemy.mainpos.pos.y - enemy.mainpos.pos.y)*(enemy.mainpos.pos.y - enemy.mainpos.pos.y) <=
			(tmpEnemy->mainpos.r / 5 + enemy.targetr)*(tmpEnemy->mainpos.r / 5 + enemy.targetr)) {
			reMoveFlg++;
		}
		break;
	case 2:
		enemy.ang = atan2(enemy.mainpos.pos.y - 850.0, enemy.mainpos.pos.x - enemy.mainpos.pos.x);
		if ((enemy.mainpos.pos.x - enemy.mainpos.pos.x)*(enemy.mainpos.pos.x - enemy.mainpos.pos.x) +
			(enemy.mainpos.pos.y - 850.0)*(enemy.mainpos.pos.y - 850.0) <=
			(tmpEnemy->mainpos.r / 5 + enemy.targetr)*(tmpEnemy->mainpos.r / 5 + enemy.targetr)) {
			cPlayer::Instance()->Double();
			if (this != NULL) {
				cInGameController::Instance()->OutToRevive();
				cEnemyMgr::Instance()->DeletePlayerEnemy();
			}


		}
		break;
	default:
		break;
	}

	return 0;
}

int cPlayerEnemy::Draw() {
	/*if (enemy.dir == RIGHT)DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, (enemy.ang + (90 * M_PI) / 180), enemy.graph[0], TRUE, TRUE);
	//else DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, -(enemy.ang + 90 * M_PI / 180), enemy.graph[0], TRUE, TRUE);
	*/

	if (enemy.moveflg == 0 || reMoveFlg == 0)DrawRotaGraph((int)enemy.mainpos.pos.x, (int)enemy.mainpos.pos.y, 3, rotecnt, graph[playerGraphNum], TRUE);
	else DrawRotaGraph((int)enemy.mainpos.pos.x, (int)enemy.mainpos.pos.y, 3, (enemy.ang + (90 * M_PI) / 180)*enemy.dir, graph[playerGraphNum], TRUE);

#ifndef DEBUG
	DrawFormatString(120, 885, GetColor(255, 255, 255), "%d", enemy.moveflg);
	DrawFormatString(120, 900, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.x);
	DrawFormatString(120, 915, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.y);
	//DrawFormatString(900,0, GetColor(255,255,255),"%d",enemy.moveflg);
#endif // DEBUG





	return 0;
}

