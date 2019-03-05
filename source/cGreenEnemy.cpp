#include <iostream>
#define _USE_MATH_DEFINES
using namespace std;
#include <stdio.h>
#include <math.h>
#include <memory.h>
#include "cGreenEnemy.h"
#include "DxLib.h"
#include "Struct.h"
#include"UI.h"
#include "Player.h"
#include "shot.h"
#include "shotMgr.h"
#include "tractor.h"
#include"cPlayerEnemy.h"
#include "SE.h"
//ｙ674からビーム描画

cGreenEnemy::cGreenEnemy(double x, double y, double r, int cnt, double spd, double ang, int flg, int *graph) : cBaseEnemy(x, y, r, cnt, spd, ang, flg, graph) {
	enemy.mainpos.pos.x = x;
	enemy.mainpos.pos.y = y;
	enemy.mainpos.r = r;
	enemy.count = cnt;
	enemy.spd = spd;
	enemy.ang = ang * M_PI / 180;
	enemy.mainpos.onActive = flg;

	enemy.type = eBoss;
	enemy.height = 16;


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
	enemy.moveang[8] = 2;

	memset(enemy.countflg, 0, sizeof(enemy.countflg));
	enemy.countflg[0] = 20;
	enemy.countflg[1] = 40;
	enemy.countflg[2] = 20;
	enemy.countflg[3] = 75;
	enemy.countflg[4] = 50;
	enemy.countflg[5] = 20;
	enemy.countflg[6] = 80;
	enemy.countflg[8] = 90;

	memset(tractormoveang, 0, sizeof(tractormoveang));
	tractormoveang[0] = -5;



	memset(tractorcountflg, 0, sizeof(tractorcountflg));
	tractorcountflg[0] = 20;


	enemy.target.x = x;
	enemy.target.y = y;
	enemy.targetr = 3;

	tmpx = 0;
	tmpy = 0;

	AnimationCnt = 0;
	AnimationNum = 10;

	enemy.hp = 2;

	LoadDivGraph("../resource/Image/Galaga_OBJ_effect.png", 15, 5, 3, 50, 82, tractor);
	enemy.endlessFlg = false;
	enemy.tractingEnemy = false;
	enemy.tractorflg = true;
	enemy.tractorHitFlg = false;
}

cGreenEnemy::~cGreenEnemy() {
	cShotMgr::Instance()->InitTractorCnt();
	if (cSE::Instance()->GetSeActive(tractor_beam) == 1)cSE::Instance()->StopSound(tractor_beam);
	enemy.tractingEnemy = false;
	enemy.tractorflg = false;
	enemy.tractorHitFlg = false;
}

void cGreenEnemy::Move() {


	enemy.mainpos.cx = enemy.mainpos.pos.x + enemy.width / 2;
	enemy.mainpos.cy = enemy.mainpos.pos.y + enemy.height / 2;

	if (enemy.mainpos.onActive == YesActive) {
		if (enemy.attackflg == TRUE) {
			if (enemy.moveflg != 8 && enemy.moveflg != 7) {
				enemy.vct.x = cos(enemy.ang)*enemy.dir;
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
				enemy.vct.x = cos(enemy.ang);
				enemy.vct.y = sin(enemy.ang);
			}
		}
	}
}


int cGreenEnemy::Update() {

	if (cEnemyMgr::Instance()->GetPlayerEnemyAdress() == NULL)enemy.tractingEnemy = false;

	if (enemy.count < 0)enemy.count = 0;
	if (enemy.moveflg == 0 && enemy.count == 0) enemy.mainpos.onActive = ReadyStart;
	enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
	enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);
	/*enemy.target.x = 380;
	enemy.target.y = 80;*/


	if (enemy.attackflg == true && enemy.tractorflg == false) {
		enemy.count++;

		if (enemy.count > 0) {
			enemy.mainpos.onActive = YesActive;
		}
		/*	DrawFormatString(0, 0, GetColor(255, 255, 255), "%lf", enemy.target.x);
				DrawFormatString(0, 50, GetColor(255, 255, 255), "%lf", enemy.target.y);
				DrawFormatString(0, 100, GetColor(255, 255, 255), "%lf", enemy.mainpos.pos.x);
				DrawFormatString(0, 125, GetColor(255, 255, 255), "%lf", enemy.mainpos.pos.y);
				DrawFormatString(0, 150, GetColor(255, 255, 255), "%d", enemy.targetr);
				DrawFormatString(0, 175, GetColor(255, 255, 255), "%lf", enemy.mainpos.r);
				DrawFormatString(0, 225, GetColor(255, 255, 255), "%d", enemy.dir);
				DrawFormatString(0, 200, GetColor(255, 255, 255), "%d", enemy.moveflg);*/
		switch (enemy.moveflg)
		{
		case 0:
			if (enemy.mainpos.pos.x <= 450) {
				enemy.dir = 1;
			}
			else {
				enemy.dir = -1;
			}
			if (enemy.count < 2) {
				enemy.ang = 180 * M_PI / 180;
				if (CheckSoundFile() == 0) cSE::Instance()->selectSE(alien_flying);
			}
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;

		case 3:
			if (enemy.mainpos.onActive != NoActive && enemy.count == 5 || enemy.count == 25)cShotMgr::Instance()->EnemyShot(enemy.mainpos.pos.x, enemy.mainpos.pos.y);
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;

		case 1:
		case 5:
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 2:
		case 4:
			enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 6:
			enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.mainpos.pos.y > 980) {
				enemy.mainpos.pos.y = -20;
				enemy.mainpos.pos.x = enemy.target.x;
				enemy.moveflg++;
				enemy.count = 0;
				enemy.mainpos.onActive = EndMove;
			}
			break;
		case 7:
			/*	enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
				enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);*/
			enemy.ang = atan2(enemy.target.y - enemy.mainpos.pos.y, enemy.target.x - enemy.mainpos.pos.x);
			if ((enemy.target.x - enemy.mainpos.pos.x)*(enemy.target.x - enemy.mainpos.pos.x) +
				(enemy.target.y - enemy.mainpos.pos.y)*(enemy.target.y - enemy.mainpos.pos.y) <=
				(enemy.mainpos.r / 5 + enemy.targetr)*(enemy.mainpos.r / 5 + enemy.targetr)) {
				//敵座標を目的地に固定
				enemy.mainpos.pos.x = enemy.target.x;
				enemy.mainpos.pos.y = enemy.target.y;
				enemy.moveflg++;
				enemy.count = 0;
				enemy.mainpos.onActive = ReadyStart;
			}
			break;
		case 8:
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			enemy.mainpos.pos.x = enemy.target.x;
			enemy.mainpos.pos.y = enemy.target.y;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 9:
			enemy.mainpos.pos.x = enemy.target.x;
			enemy.mainpos.pos.y = enemy.target.y;
			enemy.count = 0;

			enemy.ang = -90 * M_PI / 180;
			if (enemy.mainpos.pos.x <= 450) {
				enemy.dir = 1;
			}
			else {
				enemy.dir = -1;
			}
			enemy.tractorHitFlg = false;
			enemy.attackflg = false;
			enemy.mainpos.onActive = ReadyStart;
			enemy.tractorflg = true;//ここ
			enemy.moveflg = 0;
			break;
		}
	}
	return 0;
}


int cGreenEnemy::TractorUpdate() {



	//traitPlayer = tractor::Instance()->GetAdress();

	if (enemy.moveflg == 0 && cEnemyMgr::Instance()->GetPlayerEnemyAdress() != NULL || cPlayer::Instance()->GetDoubleFlg() == true) {
		enemy.tractorflg = false;
		return 0;
	}

	if (enemy.count < 0)enemy.count = 0;

	enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
	enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);


	if (enemy.tractorflg != false && enemy.attackflg == true) {
		enemy.count++;




		if (enemy.count > 0) {
			enemy.mainpos.onActive = YesActive;
		}


		switch (enemy.moveflg)
		{

		case 0:
			cShotMgr::Instance()->InitTractorCnt();
			if (enemy.count == 0) {
				enemy.ang = 180 * M_PI / 180;

			}
			if (enemy.count < 2) cSE::Instance()->selectSE(alien_flying);
			enemy.ang += tractormoveang[enemy.moveflg] * M_PI / 180;
			if (tractorcountflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 1:
			if (enemy.count < 10) {
				for (int i = 0; i < 2; i++) {
					tmpplayer = cPlayer::Instance()->GetPlayer(i);
					if (tmpplayer.onActive == false) continue;
					break;
				}
			}
			enemy.ang = atan2(tmpplayer.pos.y - 160 - enemy.mainpos.pos.y, (tmpplayer.pos.x - enemy.mainpos.pos.x)*enemy.dir);
			if ((tmpplayer.pos.x - enemy.mainpos.pos.x)*(tmpplayer.pos.x - enemy.mainpos.pos.x) +
				(tmpplayer.pos.y - 160 - enemy.mainpos.pos.y)*(tmpplayer.pos.y - 160 - enemy.mainpos.pos.y) <=
				(enemy.mainpos.r / 5 + enemy.targetr)*(enemy.mainpos.r / 5 + enemy.targetr)) {
				//敵座標を目的地に固定

				enemy.mainpos.pos.x = tmpplayer.pos.x;
				enemy.mainpos.pos.y = tmpplayer.pos.x - 160;
				enemy.count = 0;
				enemy.moveflg++;
			}
			break;
		case 2:
			enemy.mainpos.pos.x = tmpplayer.pos.x;
			enemy.mainpos.pos.y = tmpplayer.pos.y - 160;
			enemy.ang = 90 * M_PI / 180;
			cShotMgr::Instance()->TractorShot(&enemy);
			break;
		case 3:
			enemy.mainpos.pos.x = tmpplayer.pos.x;
			enemy.mainpos.pos.y = tmpplayer.pos.y - 160;

			enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
			enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);
			//enemy.moveflg++;
			//トラクターの描画がおかしい
			//そのため二回呼んでいた
			//カウントを0にできればよいか
			cShotMgr::Instance()->TractorShot(&enemy);
			enemy.count = 0;
			//if()enemy.moveflg++;

			break;
		case 4:
			cShotMgr::Instance()->InitTractorCnt();
			enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
			enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);
			enemy.ang = atan2(enemy.target.y - enemy.mainpos.pos.y, (enemy.target.x - enemy.mainpos.pos.x)*enemy.dir);
			if ((enemy.target.x - enemy.mainpos.pos.x)*(enemy.target.x - enemy.mainpos.pos.x) +
				(enemy.target.y - enemy.mainpos.pos.y)*(enemy.target.y - enemy.mainpos.pos.y) <=
				(enemy.mainpos.r / 5 + enemy.targetr)*(enemy.mainpos.r / 5 + enemy.targetr)) {
				//敵座標を目的地に固定
				enemy.mainpos.pos.x = enemy.target.x;
				enemy.mainpos.pos.y = enemy.target.y;
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 5:

			if (cSE::Instance()->GetSeActive(capture) == 1)cSE::Instance()->StopSound(capture);
			if (enemy.mainpos.pos.x <= 450) {
				enemy.dir = 1;
			}
			else {
				enemy.dir = -1;
			}

			enemy.mainpos.onActive = ReadyStart;
			enemy.mainpos.pos.x = enemy.target.x;
			enemy.mainpos.pos.y = enemy.target.y;
			enemy.ang = -90 * M_PI / 180;


			if (enemy.tractingEnemy == true) {
				enemy.tractingEnemy = true;
			}
			else {
				enemy.tractingEnemy = false;
			}
			enemy.tractorHitFlg = false;
			enemy.tractorflg = FALSE;
			enemy.attackflg = FALSE;

			enemy.count = 0;
			enemy.moveflg = 0;

			break;
		}
	}

	return 0;
}

void cGreenEnemy::EndlessUpdate() {

	if (enemy.count < 0)enemy.count = 0;
	if (enemy.moveflg == 0 && enemy.count == 0) enemy.mainpos.onActive = ReadyStart;
	enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
	enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);
	/*enemy.target.x = 380;
	enemy.target.y = 80;*/
	static bool PlayerDeath = false;


	if (enemy.attackflg == true && enemy.tractorflg == false && enemy.endlessFlg == true) {
		enemy.count++;

		if (enemy.count > 0) {
			enemy.mainpos.onActive = YesActive;
		}

		switch (enemy.moveflg)
		{
		case 0:
			if (enemy.count < 2) {
				enemy.ang = 180 * M_PI / 180;
				if (CheckSoundFile() == 0) cSE::Instance()->selectSE(alien_flying);
				enemy.tractorflg = false;
			}
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;

		case 3:
			if (enemy.count == 5 || enemy.count == 25)cShotMgr::Instance()->EnemyShot(enemy.mainpos.pos.x, enemy.mainpos.pos.y);
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;

		case 1:
		case 5:
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 2:
		case 4:
			enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 6:
			enemy.ang = 0;
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.mainpos.pos.y > 980) {
				enemy.mainpos.pos.y = -20;
				enemy.mainpos.pos.x = enemy.target.x;
				enemy.moveflg++;
				enemy.count = 0;
				enemy.mainpos.onActive = EndMove;
			}
			break;
		case 7:
			/*	enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
				enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);*/
			enemy.ang = atan2(enemy.target.y - enemy.mainpos.pos.y, enemy.target.x - enemy.mainpos.pos.x);
			if ((enemy.target.x - enemy.mainpos.pos.x)*(enemy.target.x - enemy.mainpos.pos.x) +
				(enemy.target.y - enemy.mainpos.pos.y)*(enemy.target.y - enemy.mainpos.pos.y) <=
				(enemy.mainpos.r / 5 + enemy.targetr)*(enemy.mainpos.r / 5 + enemy.targetr)) {
				//敵座標を目的地に固定
				enemy.mainpos.pos.x = enemy.target.x;
				enemy.mainpos.pos.y = enemy.target.y;
				enemy.mainpos.onActive = SetPos;
				enemy.count = 0;
				if (enemy.countflg[enemy.moveflg] <= enemy.count) {
					if (cInGameMgr::Instance()->GetSceneFlg() == cInGameMgr::Instance()->eDeath) {
						PlayerDeath = true;
						enemy.moveflg++;
					}
					else {
						PlayerDeath = false;
						enemy.moveflg += 2;
					}
				}
			}
			break;
		case 8:
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			enemy.mainpos.pos.x = enemy.target.x;
			enemy.mainpos.pos.y = enemy.target.y;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;

		case 9:
			enemy.mainpos.pos.x = enemy.target.x;
			enemy.mainpos.pos.y = enemy.target.y;
			enemy.count = 0;

			if (enemy.mainpos.pos.x <= 450) {
				enemy.dir = 1;
			}
			else {
				enemy.dir = -1;
			}

			enemy.tractorHitFlg = false;
			enemy.attackflg = false;
			enemy.mainpos.onActive = ReadyStart;
			enemy.tractorflg = false;//ここ

			if (PlayerDeath == false) {
				enemy.ang = 100 * M_PI / 180;
				enemy.attackflg = true;
				enemy.moveflg = 1;
			}
			else {
				enemy.ang = -90 * M_PI / 180;
				enemy.attackflg = false;
				PlayerDeath == false;
				enemy.moveflg = 0;
			}
			break;
		}
	}
}

int cGreenEnemy::Draw() {




	if (AnimationCnt > 60) {
		AnimationCnt = 0;
		AnimationNum++;
		if (enemy.hp == 2) {
			if (AnimationNum > 11)AnimationNum = 10;
		}
		else {
			if (AnimationNum < 15)AnimationNum = 15;
			if (AnimationNum > 16)AnimationNum = 15;

		}
	}
	if (enemy.mainpos.onActive != NoActive) {
		if (enemy.dir == RIGHT)DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, (enemy.ang + (90 * M_PI) / 180), enemy.graph[AnimationNum], TRUE, TRUE);
		else DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, -(enemy.ang + 90 * M_PI / 180), enemy.graph[AnimationNum], TRUE, TRUE);
	}

#ifdef DEBUG
	DrawLine(450, 0, 450, 900, GetColor(255, 255, 255));
	//DrawFormatString(120, 855, GetColor(255, 255, 255), "%d", enemy.count);
	//DrawFormatString(120, 835, GetColor(255, 255, 255), "onactive%d", enemy.mainpos.onActive);
	//DrawFormatString(120, 870, GetColor(255, 255, 255), "%d", enemy.attackflg);
	//DrawFormatString(150, 885, GetColor(255, 255, 255), "%d", enemy.moveflg);
	//DrawFormatString(120, 900, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.x);
	//DrawFormatString(120, 915, GetColor(255, 255, 255), "%.2lf", enemy.mainpos.pos.y);
	DrawFormatString(120, 935, GetColor(255, 255, 255), "%d", enemy.moveflg);
	/*	DrawLine((int)enemy.mainpos.pos.x - (int)enemy.width / 2, (int)enemy.mainpos.pos.y - (int)enemy.height / 2, (int)enemy.mainpos.pos.x+ IMAGEMAG, (int)enemy.mainpos.pos.y - (int)enemy.height / 2,GetColor(255, 255, 255));
		DrawLine((int)enemy.mainpos.pos.x - (int)enemy.width / 2, (int)enemy.mainpos.pos.y - (int)enemy.height / 2+ IMAGEMAG, (int)enemy.mainpos.pos.x - (int)enemy.width / 2 + IMAGEMAG/2, (int)enemy.mainpos.pos.y - (int)enemy.height / 2+IMAGEMAG, GetColor(255, 255, 255));
		DrawCircle(enemy.mainpos.pos.x, enemy.mainpos.pos.y, 3, GetColor(0, 255, 0), true);
		DrawCircle((int)enemy.mainpos.cx - enemy.width / 2, (int)enemy.mainpos.cy-enemy.height/2, 3, GetColor(0, 255, 255), TRUE);*/
#endif // DEBUG



	return 0;
}