#include <iostream>
using namespace std;
#include<math.h>
#define _USE_MATH_DEFINES
#include "cBaseEnemy.h"
#include "cBlueEnemy.h"
#include "cRedEnemy.h"
#include "cGreenEnemy.h"
#include"cPlayerEnemy.h"
#include "Player.h"
#include "tractor.h"
#include "winBox.h"
#include "InGameController.h"

tractor::tractor() {
	LoadDivGraph("../resource/Image/Galaga_OBJ_dualFighter.png", 2, 2, 1, 16, 16, graph);
	//enemy.targetr = 3;


}

bool tractor::TractorHit(cGreenEnemy* Tmpenemy) {

	enemy = Tmpenemy->GetEnemy();
	tractorX = enemy->mainpos.pos.x - 96 / 2;
	tractorWidth = enemy->mainpos.pos.x + 90 - 1;

	for (int i = 0; i < 1; i++) {
		sOBJPos TmpPlayer;
		TmpPlayer = cPlayer::Instance()->GetPlayer(i);
		if (TmpPlayer.onActive == false) continue;

		/*DrawLine(tractorX, 900, tractorWidth, 900, GetColor(255, 255, 255), false);
		DrawFormatString(100, 800, GetColor(255, 255, 255), "%lf", tractorX, false);
		DrawFormatString(100, 900, GetColor(255, 255, 255), "%lf", tractorWidth, false);*/

		if (TmpPlayer.pos.x + 48 >= tractorX && TmpPlayer.pos.x <= tractorWidth) {
			//ErrBox("“–‚½‚Á‚½‚æ");
			//sceneˆ— player‚Å‚â‚é‚©‚à
			playerX = TmpPlayer.pos.x;
			playerY = TmpPlayer.pos.y;
			cInGameController::Instance()->HitToTractor();
			TraitPlayer = cEnemyMgr::Instance()->PushPlayerEnemy();
			TraitPlayer->SetPenemy(enemy);
			cPlayer::Instance()->Break(eTractorBeam, i);
			enemy->moveflg++;
			enemy->tractingEnemy = true;


			return true;
		}
		else {
			return false;
		}

	}
}
//
void tractor::Move() {
	;
}


void tractor::draw() {
	;
}