#include <iostream>
using namespace std;

#include "cBaseEnemy.h"
#include "cBlueEnemy.h"
#include "cRedEnemy.h"
#include "cGreenEnemy.h"
#include "Player.h"
#include "tractor.h"
#include "winBox.h"

bool tractor::TractorHit(sEnemy* Tmpenemy) {

	tractorX = Tmpenemy->mainpos.pos.x - 96 / 2;
	tractorWidth = Tmpenemy->mainpos.pos.x + 90 - 1;
	sOBJPos TmpPlayer = cPlayer::Instance()->GetPlayer(0);
	/*DrawLine(tractorX, 900, tractorWidth, 900, GetColor(255, 255, 255), false);
	DrawFormatString(100, 800, GetColor(255, 255, 255), "%lf", tractorX, false);
	DrawFormatString(100, 900, GetColor(255, 255, 255), "%lf", tractorWidth, false);*/
	if (TmpPlayer.pos.x + 48 >= tractorX && TmpPlayer.pos.x <= tractorWidth) {
		//ErrBox("“–‚½‚Á‚½‚æ");
		return true;
	}
	return false;
}
