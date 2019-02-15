#include <iostream>
using namespace std;
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "cRedEnemy.h"
#include "DxLib.h"
#include "Struct.h"
#include "UI.h"
#include "shot.h"
#include "shotMgr.h"
#include "InGameMgr.h"
#include"SE.h"


cRedEnemy::cRedEnemy(double x, double y, double r, int cnt, double spd, double ang, int flg, int*graph) : cBaseEnemy(x, y, r, cnt, spd, ang, flg, graph) {
	enemy.mainpos.pos.x = x;
	enemy.mainpos.pos.y = y;
	enemy.mainpos.r = r;
	enemy.count = cnt;
	enemy.spd = spd;
	enemy.ang = ang * M_PI / 180;
	enemy.mainpos.onActive = flg;

	enemy.moveflg = 0;

	enemy.vct.x = 0;
	enemy.vct.y = 0;

	memset(enemy.moveang, 0, sizeof(enemy.moveang));

	enemy.moveang[0] = -3;
	enemy.moveang[1] = 0;
	enemy.moveang[2] = 3;
	enemy.moveang[3] = -3;
	enemy.moveang[4] = -1;
	enemy.moveang[5] = 1;
	enemy.moveang[6] = 90;



	enemy.moveang[8] = 2;

	memset(enemy.countflg, 0, sizeof(enemy.countflg));
	enemy.countflg[0] = 50;
	enemy.countflg[1] = 30;
	enemy.countflg[2] = 40;
	enemy.countflg[3] = 20;
	enemy.countflg[4] = 60;
	enemy.countflg[5] = 60;
	enemy.countflg[6] = 10;



	enemy.countflg[8] = 100;

	enemy.target.x = x;
	enemy.target.y = y;
	enemy.targetr = 1;
	AnimationCnt = 0;
	AnimationNum = 5;
	enemy.hp = 1;

	enemy.tractingEnemy = false;
	enemy.tractorflg = false;
	enemy.tractorHitFlg = false;

}


void cRedEnemy::Move() {


	enemy.mainpos.cx = enemy.mainpos.pos.x + enemy.width / 2;
	enemy.mainpos.cy = enemy.mainpos.pos.y + enemy.height / 2;

	
  if (enemy.mainpos.onActive == YesActive) {
	  if (enemy.attackflg == TRUE) {
		  if (enemy.moveflg != 8 && enemy.moveflg != 7) {
			  enemy.vct.x = cos(enemy.ang)* enemy.dir;
			  enemy.vct.y = sin(enemy.ang);
			  enemy.mainpos.pos.x += enemy.vct.x*enemy.spd;
			  enemy.mainpos.pos.y += enemy.vct.y*enemy.spd;
		  }
		  else if (enemy.moveflg == 7) {
			  enemy.vct.x = cos(enemy.ang);
			  enemy.vct.y = sin(enemy.ang);
			  enemy.mainpos.pos.x += enemy.vct.x*enemy.spd;
			  enemy.mainpos.pos.y += enemy.vct.y*enemy.spd;
		  }
		  else {
			  enemy.vct.x = cos(enemy.ang)* enemy.dir;
			  enemy.vct.y = sin(enemy.ang);
		  }
	  }
	}
}


int cRedEnemy::Update() {

	enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
	enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);

	int tmp = cInGameMgr::Instance()->GetSceneFlg();
	int	 EnemyDeathCount = cEnemyMgr::Instance()->GetEnemyDeathCount();
	if (enemy.count < 0)enemy.count = 0;
	if (enemy.moveflg == 0 && enemy.count == 0) enemy.mainpos.onActive = ReadyStart;


	if (enemy.attackflg == true && enemy.mainpos.onActive != NoActive) {

		/*enemy.target.x = 280;
		enemy.target.y = 130;*/
		enemy.count++;

		if (enemy.count > 0) {
			enemy.mainpos.onActive = YesActive;
		}
		//enemy.ang = -90 * M_PI / 180;
		switch (enemy.moveflg)
		{
		case 0:
			//if (CheckSoundFile() == 0)cSE::Instance()->selectSE(alien_flying);
			if (enemy.count < 2)enemy.ang = 180 * M_PI / 180;
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 2:
		case 3:
		case 4:
		case 5:
		case 8:
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 1:
			if (enemy.count == 5 || enemy.count == 25)cShotMgr::Instance()->EnemyShot(enemy.mainpos.pos.x, enemy.mainpos.pos.y);
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 6:
			enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.mainpos.pos.y >= 960) {
				enemy.mainpos.pos.y = -20;
				enemy.mainpos.pos.x = enemy.target.x;
				enemy.moveflg++;
			}
			break;
		case 7:
			enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
			enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);
			enemy.ang = atan2(enemy.target.y - enemy.mainpos.pos.y, enemy.target.x - enemy.mainpos.pos.x);
			if ((enemy.target.x - enemy.mainpos.pos.x)*(enemy.target.x - enemy.mainpos.pos.x) +
				(enemy.target.y - enemy.mainpos.pos.y)*(enemy.target.y - enemy.mainpos.pos.y) <=
				(enemy.mainpos.r / 5 + enemy.targetr)*(enemy.mainpos.r / 5 + enemy.targetr)) {

				enemy.moveflg++;
				enemy.count = 0;
				enemy.mainpos.onActive = SetPos;
			}
			break;
		case 9:
			enemy.tractorflg = false;
			enemy.count = 0;

			enemy.ang = -90 * M_PI / 180;
			if (enemy.mainpos.pos.x <= 430) {
				enemy.dir = -1;
			}
			else {
				enemy.dir = 1;
			}
			//“GÀ•W‚ð–Ú“I’n‚ÉŒÅ’è
			enemy.mainpos.pos.x = enemy.target.x;
			enemy.mainpos.pos.y = enemy.target.y;

			enemy.attackflg = false;
			enemy.mainpos.onActive = ReadyStart;
			enemy.moveflg = 0;
			break;

		}
	}
	return 0;
}


void cRedEnemy::EndlessUpdate(){
	;
 }


int cRedEnemy::Draw() {
	if (AnimationCnt > 60) {
		AnimationCnt = 0;
		AnimationNum++;
		if (AnimationNum > 6)AnimationNum = 5;
	}

	if (enemy.mainpos.onActive != NoActive) {
		//	DrawCircle((int)enemy.mainpos.pos.x, (int)enemy.mainpos.pos.y, 5, GetColor(255, 0,0), true);
		if (enemy.dir == RIGHT)DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, (enemy.ang + (90 * M_PI) / 180), enemy.graph[AnimationNum], TRUE, TRUE);
		else DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, -(enemy.ang + 90 * M_PI / 180), enemy.graph[AnimationNum], TRUE, TRUE);
	}

#ifdef DEBUG
	//DrawCircle(enemy.target.x, enemy.target.y, enemy.targetr, GetColor(0, 255, 0), true);
	//DrawCircle((int)enemy.target.x, (int)enemy.target.y, enemy.targetr, GetColor(255, 0, 0), true);
	//DrawFormatString(60, 755, GetColor(255, 255, 255), "enemy.count%d", enemy.count);
	//DrawFormatString(60, 770, GetColor(255, 255, 255), "enemy.attackflg%d", enemy.attackflg);
	//DrawFormatString(60, 785, GetColor(255, 255, 255), "enemy.moveflg%d", enemy.moveflg);
	//DrawFormatString(60, 800, GetColor(255, 255, 255), "enemy.mainpos.pos.x%.2lf", enemy.mainpos.pos.x);
	//DrawFormatString(60, 815, GetColor(255, 255, 255), "enemy.mainpos.pos.y%.2lf", enemy.mainpos.pos.y);
	//DrawFormatString(60, 835, GetColor(255, 255, 255), "enemy.dir%d", enemy.dir);
	//DrawFormatString(60, 855, GetColor(255, 255, 255), "enemy.ang%.2lf", enemy.ang);
	DrawFormatString(60, 755, GetColor(255, 255, 255), " enemy.target.x%lf", enemy.target.x);
	DrawFormatString(60, 855, GetColor(255, 255, 255), " enemy.target.y%lf", enemy.target.y);
	DrawFormatString(60, 785, GetColor(255, 255, 255), "enemy.moveflg%d", enemy.moveflg);
#endif // DEBUG

	return 0;
}