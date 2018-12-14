#include "DxLib.h"
#include "Score.h"
#include "TextChange.h"
#include "ShotMgr.h"

cScore::cScore() {
	score = 0;
	totalShot = 0;
	totalHit = 0;
	hitMissRatio = 0.0;
}

void cScore::Draw() {

	char tmp[30];

	//UI-ハイスコアの表示
	cTextChange::Instance()->DrawTextImage(1000, 80, "00000", eWhite, eMag48);

	//UI-スコアの表示
	snprintf(tmp, 30, "%d",score);
	cTextChange::Instance()->DrawTextImage(1130, 140, tmp, eWhite, eMag48);
	//スコアの桁毎に左に座標がずれるようにする
}

void cScore::Result() {

	char tmpS[30];
	char tmpH[30];
	char tmpR[30];

	//-RESULTS-
	cTextChange::Instance()->DrawTextImage(350, 450, "-RESULTS-", eRed, eMag48);

	//弾を撃った数
	totalShot = cShotMgr::Instance()->GetTotalShot();  //totalShotの更新
	snprintf(tmpS, 30, "SHOTS FIRED    %d", totalShot);
	cTextChange::Instance()->DrawTextImage(200, 550, tmpS, eYellow, eMag48);

	//弾を当てた数
	totalHit = cHit::Instance()->GetTotalHit();
	snprintf(tmpH, 30, "NUMBER OF HITS %d", totalHit);
	cTextChange::Instance()->DrawTextImage(200, 650, tmpH, eYellow, eMag48);

	//弾を外した割合
	hitMissRatio = 100 - (totalShot / totalHit);
	snprintf(tmpR,30,"HIT-MISS RATIO %d %%",hitMissRatio);
	cTextChange::Instance()->DrawTextImage(200, 750, tmpR, eWhite, eMag48);

}