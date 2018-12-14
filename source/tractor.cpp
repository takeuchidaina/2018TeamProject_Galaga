#include <iostream>
using namespace std;

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

bool tractor::TractorHit(sEnemy* Tmpenemy) {

	tractorX = Tmpenemy->mainpos.pos.x - 96 / 2;
	tractorWidth = Tmpenemy->mainpos.pos.x + 90 - 1;
	for (int i = 0; i < 1; i++) {
		sOBJPos TmpPlayer = cPlayer::Instance()->GetPlayer(i);
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
			cPlayer::Instance()->Break(eDeath,i);
			Tmpenemy->moveflg++;
			cInGameController::Instance()->OutToTractor();
			return true;
		}
		else {
			return false;
		}
	}
}
void tractor::draw() {
	static int i=0;
	i += 20;
	if (i >= 360)i = 0;
	DrawRotaGraph(playerX, playerY, 3, i, graph[0], false, false);
}