#include <iostream>
using namespace std;
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <memory.h>
#include "cBlueEnemy.h"
#include "DxLib.h"
#include "Struct.h"
#include "UI.h"
#include "shot.h"
#include"SE.h"

//�R���X�g���N�^�@�G�l�~�[�}�l�[�W���[����̏��ł��ׂĂ����������܂��@

cBlueEnemy::cBlueEnemy(double x, double y, double r, int cnt, double spd, double ang, int flg, int *graph) : cBaseEnemy(x, y, r, cnt, spd, ang, flg, graph) {
	enemy.mainpos.pos.x = x;
	enemy.mainpos.pos.y = y;
	enemy.mainpos.r = r;

	enemy.count = cnt;
	enemy.spd = spd;
	enemy.ang = ang * M_PI / 180;
	enemy.mainpos.onActive = flg;

	enemy.type = eZako;

	enemy.moveflg = 0;

	enemy.vct.x = 0;
	enemy.vct.y = 0;

	memset(enemy.moveang, 0, sizeof(enemy.moveang));
	enemy.moveang[0] = -4;
	enemy.moveang[1] = -0.2;
	enemy.moveang[2] = 3;
	enemy.moveang[3] = 90;
	enemy.moveang[4] = 3;
	enemy.moveang[5] = 0;
	enemy.moveang[6] = 3;

	enemy.moveang[7] = 2;
	enemy.moveang[8] = 90;

	enemy.moveang[10] = 3;
	memset(enemy.countflg, 0, sizeof(enemy.countflg));
	enemy.countflg[0] = 40;
	enemy.countflg[1] = 35;
	enemy.countflg[2] = 25;
	enemy.countflg[3] = 40;
	enemy.countflg[4] = 30;
	enemy.countflg[5] = 20;
	enemy.countflg[6] = 20;

	enemy.countflg[7] = 100;

	enemy.countflg[10] = 60;

	enemy.target.x = x;
	enemy.target.y = y;
	enemy.targetr = 1;
	AnimationCnt = 0;
	AnimationNum = 0;
	enemy.hp = 1;

	enemy.tractingEnemy = false;
	enemy.tractorflg = false;
	enemy.tractorHitFlg = false;
	enemy.endlessFlg = false;
}

//�x�N�g���Ƒ��x��������Ĉړ�����
void cBlueEnemy::Move() {


	enemy.mainpos.cx = enemy.mainpos.pos.x + (enemy.width / 2);
	enemy.mainpos.cy = enemy.mainpos.pos.y + (enemy.height / 2);

	if (enemy.mainpos.onActive == YesActive) {
		if (enemy.attackflg == TRUE) {
			if ((enemy.endlessFlg == false && enemy.moveflg != 7) || (enemy.endlessFlg == true && enemy.moveflg != 9 )) {
				enemy.vct.x = cos(enemy.ang)*enemy.dir;
				enemy.vct.y = sin(enemy.ang);
				enemy.mainpos.pos.x += enemy.vct.x*enemy.spd;
				enemy.mainpos.pos.y += enemy.vct.y*enemy.spd;
			}
			else if ((enemy.endlessFlg == false && enemy.moveflg == 7) || (enemy.endlessFlg == true && enemy.moveflg == 9)) {
				enemy.vct.x = cos(enemy.ang);
				enemy.vct.y = sin(enemy.ang);
				enemy.mainpos.pos.x += enemy.vct.x*enemy.spd;
				enemy.mainpos.pos.y += enemy.vct.y*enemy.spd;
			}
		}
	}
}

//�ړ��J�E���g�ƕ����ύX�ňړ��x�N�g�������߂�
int cBlueEnemy::Update() {

	enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
	enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);
	if (enemy.count < 0)enemy.count = 0;
	if (enemy.moveflg == 0 && enemy.count == 0) enemy.mainpos.onActive = ReadyStart;
	if (enemy.attackflg == 1 && enemy.mainpos.onActive != NoActive) {


		/*enemy.target.x = 230;
		enemy.target.y = 230;*/
		enemy.count++;

		if (enemy.count > 0) {
			enemy.mainpos.onActive = YesActive;
		}

		switch (enemy.moveflg)
		{
		case 0:
			if (enemy.moveflg < 3) {
				if (enemy.mainpos.pos.x <= 450) {
					enemy.dir = 1;
				}
				else {
					enemy.dir = -1;
				}

				if(enemy.count < 2) {
					if (CheckSoundFile() == 0) cSE::Instance()->selectSE(alien_flying);
				}

				if (enemy.count < 3)enemy.ang = 180 * M_PI / 180;
				enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
				if (enemy.countflg[enemy.moveflg] <= enemy.count) {
					enemy.moveflg++;
					enemy.count = 0;
				}
			}
			break;
		case 1:
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.count == 5 || enemy.count == 25)cShotMgr::Instance()->EnemyShot(enemy.mainpos.pos.x, enemy.mainpos.pos.y);
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 2:
		case 4:
		case 5:
		case 6:
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 3:
			enemy.ang = 0 * M_PI / 180;
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 7:
			enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
			enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);
			enemy.ang = atan2(enemy.target.y - enemy.mainpos.pos.y, enemy.target.x - enemy.mainpos.pos.x);
			if ((enemy.target.x - enemy.mainpos.pos.x)*(enemy.target.x - enemy.mainpos.pos.x) +
				(enemy.target.y - enemy.mainpos.pos.y)*(enemy.target.y - enemy.mainpos.pos.y) <=
				(enemy.mainpos.r / 5 + enemy.targetr)*(enemy.mainpos.r / 5 + enemy.targetr)) {
				//�G���W��ړI�n�ɌŒ�
				enemy.mainpos.pos.x = enemy.target.x;
				enemy.mainpos.pos.y = enemy.target.y;
				enemy.moveflg++;
				enemy.count = 0;
				enemy.mainpos.onActive = SetPos;
			}
			break;
		case 8:
			enemy.moveflg = 0;
			enemy.count = 0;
			enemy.tractorflg = false;
			enemy.ang = -90 * M_PI / 180;
			if (enemy.mainpos.pos.x <= 450) {
				enemy.dir = 1;
			}
			else {
				enemy.dir = -1;
			}
			enemy.mainpos.pos.x = enemy.target.x;
			enemy.mainpos.pos.y = enemy.target.y;
 			enemy.attackflg = false;
			enemy.mainpos.onActive = ReadyStart;
			break;
		}
	}

	return 0;
}

void cBlueEnemy::EndlessUpdate() {
	enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
	enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);
	if (enemy.count < 0)enemy.count = 0;
	if (enemy.moveflg == 0 && enemy.count == 0) enemy.mainpos.onActive = ReadyStart;
	static bool PlayerDeath = false;
	if (enemy.attackflg == 1 && enemy.mainpos.onActive != NoActive && enemy.endlessFlg == true) {


		/*enemy.target.x = 400;
		enemy.target.y = 330;*/
		enemy.count++;

		if (enemy.count > 0) {
			enemy.mainpos.onActive = YesActive;
		}

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
					if (CheckSoundFile() == 0) cSE::Instance()->selectSE(alien_flying);
				}
				if (enemy.count < 3)enemy.ang = 180 * M_PI / 180;
				enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
				if (enemy.countflg[enemy.moveflg] <= enemy.count) {
					enemy.moveflg++;
					enemy.count = 0;
				}
			break;
		case 1:
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.count == 5 || enemy.count == 25)cShotMgr::Instance()->EnemyShot(enemy.mainpos.pos.x, enemy.mainpos.pos.y);
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 2:
		case 4:
		case 5:
		case 6:
		case 7:
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 3:
			enemy.ang = 0 * M_PI / 180;
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 8:
			enemy.ang = 0 * M_PI / 180;
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			if (enemy.mainpos.pos.y >= 960) {
				enemy.mainpos.pos.y = -20;
				enemy.mainpos.pos.x = enemy.target.x;
				enemy.moveflg++;
			}
			else {
				enemy.mainpos.pos.y++;
			}
			break;
			//�h�ꂽ�ق����ǂ����H
		case 9:
			enemy.target.x = cEnemyMgr::Instance()->GetTargetX((cBaseEnemy *)this);
			enemy.target.y = cEnemyMgr::Instance()->GetTargetY((cBaseEnemy *)this);
			/*enemy.target.x = 400;
			enemy.target.y = 330;*/
			enemy.ang = atan2(enemy.target.y - enemy.mainpos.pos.y, enemy.target.x - enemy.mainpos.pos.x);
			if ((enemy.target.x - enemy.mainpos.pos.x)*(enemy.target.x - enemy.mainpos.pos.x) +
				(enemy.target.y - enemy.mainpos.pos.y)*(enemy.target.y - enemy.mainpos.pos.y) <=
				(enemy.mainpos.r / 5 + enemy.targetr)*(enemy.mainpos.r / 5 + enemy.targetr)) {
				//�G���W��ړI�n�ɌŒ�
				enemy.mainpos.pos.x = enemy.target.x;
				enemy.mainpos.pos.y = enemy.target.y;
				enemy.mainpos.onActive = SetPos;
				if (cInGameMgr::Instance()->GetSceneFlg() == cInGameMgr::Instance()->eDeath || cInGameMgr::Instance()->GetSceneFlg() == cInGameMgr::Instance()->eRevival) {
						PlayerDeath = true;
						enemy.count = 0;
						enemy.moveflg++;
					}
					else {
 						PlayerDeath = false;
						enemy.count = 0;
						enemy.moveflg += 2;
					}
			}
			break;
		case 10:
			enemy.ang += enemy.moveang[enemy.moveflg] * M_PI / 180;
			enemy.mainpos.pos.x = enemy.target.x;
			enemy.mainpos.pos.y = enemy.target.y;
			enemy.ang *M_PI / 180;
			if (enemy.countflg[enemy.moveflg] <= enemy.count) {
				enemy.moveflg++;
				enemy.count = 0;
			}
			break;
		case 11:
			enemy.count = 0;
			enemy.tractorflg = false;
			if (enemy.mainpos.pos.x <= 450) {
				enemy.dir = 1;
			}
			else {
				enemy.dir = -1;
			}
			enemy.mainpos.pos.x = enemy.target.x;
			enemy.mainpos.pos.y = enemy.target.y;
			enemy.mainpos.onActive = ReadyStart;
			/*if (PlayerDeath == false) {
				enemy.ang = 28 * M_PI / 180;
				enemy.attackflg = true;
				enemy.moveflg = 1;
			}
			else {*/
				enemy.ang = -90 * M_PI / 180;
				enemy.moveflg = 0;
				if (PlayerDeath == false) {
					enemy.attackflg = true;
				}
				else {
					enemy.attackflg = false;
					PlayerDeath = false;
				}
			//}
			break;

		}
	}
}

//�`�揈��
int cBlueEnemy::Draw() {

	if (enemy.mainpos.onActive != NoActive) {
		if (enemy.dir == RIGHT)
			DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, (enemy.ang + 90 * M_PI / 180), enemy.graph[AnimationCnt / 60 % 2], TRUE, TRUE);
		else {
			DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, -(enemy.ang + 90 * M_PI / 180), enemy.graph[AnimationCnt / 60 % 2], TRUE, TRUE);
		}
	}
#ifdef DEBUG
	DrawFormatString(0, 100, GetColor(255, 255, 255), "%d", AnimationCnt);
	DrawFormatString(800, 825, GetColor(255, 255, 255), "%.2lf", enemy.target.x);
	DrawFormatString(800, 840, GetColor(255, 255, 255), "%.2lf", enemy.target.y);
	DrawFormatString(60, 755, GetColor(255, 255, 255), "enemy.count%d", enemy.count);
	DrawFormatString(60, 770, GetColor(255, 255, 255), "enemy.attackflg%d", enemy.attackflg);
	DrawFormatString(60, 785, GetColor(255, 255, 255), "enemy.moveflg%d", enemy.moveflg);
	DrawFormatString(60, 800, GetColor(255, 255, 255), "enemy.mainpos.pos.x%.2lf", enemy.mainpos.pos.x);
	DrawFormatString(60, 815, GetColor(255, 255, 255), "enemy.mainpos.pos.y%.2lf", enemy.mainpos.pos.y);
	DrawFormatString(60, 835, GetColor(255, 255, 255), "enemy.dir%d", enemy.dir);
	DrawFormatString(60, 855, GetColor(255, 255, 255), "enemy.ang%lf.2", enemy.ang);
#endif // 



	return 0;
}