#include <iostream>
using namespace std;
#include<math.h>
#define _USE_MATH_DEFINES
#include "cBaseEnemy.h"
#include "cBlueEnemy.h"
#include "cRedEnemy.h"
#include "cGreenEnemy.h"
#include "Player.h"
#include "tractor.h"
#include "winBox.h"
#include "InGameController.h"
 
 tractor::tractor() {
	LoadDivGraph("../resource/Image/Galaga_OBJ_dualFighter.png", 2, 2, 1, 16, 16, graph);
}

bool tractor::TractorHit(cGreenEnemy* Tmpenemy) {
	
	enemy= Tmpenemy->GetEnemy();
	tractorX = enemy.mainpos.pos.x - 96 / 2;
	tractorWidth = enemy.mainpos.pos.x + 90 - 1;

	for (int i = 0; i < 1; i++) {
		sOBJPos TmpPlayer;
		TmpPlayer= cPlayer::Instance()->GetPlayer(i);
		if (TmpPlayer.onActive == false) continue;

		/*DrawLine(tractorX, 900, tractorWidth, 900, GetColor(255, 255, 255), false);
		DrawFormatString(100, 800, GetColor(255, 255, 255), "%lf", tractorX, false);
		DrawFormatString(100, 900, GetColor(255, 255, 255), "%lf", tractorWidth, false);*/

		if (TmpPlayer.pos.x + 48 >= tractorX && TmpPlayer.pos.x <= tractorWidth) {
			//ErrBox("当たったよ");
			//scene処理 playerでやるかも
			playerX = TmpPlayer.pos.x;
			playerY = TmpPlayer.pos.y;
			cInGameController::Instance()->HitToTractor();
			cPlayer::Instance()->Break(eTractorBeam,i);
			//御バグり召された　おそらくポインタ
			TraitPlayer =	cEnemyMgr::Instance()->PushPlayerEnemy();
           // Tmpenemy->SetTraitPlayer(cPlayerEnemy * );
			if (enemy.count >= 120) {
				enemy.moveflg++;
				enemy.count = 0;
				//cInGameController::Instance()->OutToTractor();
			}
			
			return true;
		}
		else {
			return false;
		}
	}
}

void tractor::draw() {
	static int i=0;
	i += 10;
	if (i >= 360)i = 0;
	DrawRotaGraph(playerX, playerY, 3, i*M_PI/180, graph[0], TRUE);
}