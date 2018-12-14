#include <iostream>
using namespace std;
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <memory.h>
#include "cBaseEnemy.h"
#include "cGreenEnemy.h"
#include "cPlayerEnemy.h"
#include "DxLib.h"
#include "Struct.h"
#include "shot.h"
#include "Player.h"


cPlayerEnemy::cPlayerEnemy(){
	sOBJPos tmpPlayer = cPlayer::Instance()->GetPlayer(0);
	enemy.mainpos.pos.x = tmpPlayer.pos.x;
	enemy.mainpos.pos.y = tmpPlayer.pos.y;
	LoadDivGraph("../resource/Image/Galaga_OBJ_myMachine1616.png", 12, 4, 3, 16, 16, enemy.graph);
}

void cPlayerEnemy :: Move() {
	enemy.vct.x = cos(enemy.ang)*enemy.dir;
	enemy.vct.y = sin(enemy.ang);
	enemy.mainpos.pos.x += enemy.vct.x*enemy.spd;
	enemy.mainpos.pos.y += enemy.vct.y*enemy.spd;
}
int cPlayerEnemy::Update() {
	return 0;
}

int cPlayerEnemy::TractorStart(sEnemy enemy) {
	sOBJPos tmpPlayer = cPlayer::Instance()->GetPlayer(0);
	enemy.ang = atan2(enemy.mainpos.pos.y+enemy.hight - enemy.mainpos.pos.y, enemy.target.x - enemy.mainpos.pos.x);
	return 0;
}

int cPlayerEnemy::Draw() {
	if (enemy.dir == RIGHT)DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, (enemy.ang + (90 * M_PI) / 180), enemy.graph[AnimationNum], TRUE, TRUE);
	else DrawRotaGraph((int)enemy.mainpos.cx, (int)enemy.mainpos.cy, 3.0, -(enemy.ang + 90 * M_PI / 180), enemy.graph[AnimationNum], TRUE, TRUE);
	return 0;
}

