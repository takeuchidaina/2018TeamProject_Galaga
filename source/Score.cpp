#include "DxLib.h"
#include "Score.h"
#include "TextChange.h"
#include "ShotMgr.h"

cScore::cScore() {
	score = 0;
	totalShot = 0;
	totalHit = 0;
	oneShotRatio = 0.0;
	hitMissRatio = 0.0;
	scoreX = 1130;
}

void cScore::Update() {

	//スコアに応じて座標がずれる(一桁目位置固定)
	if (score >= 10 && score < 100) {
		scoreX = 1098;
	}
	else if (score >= 100 && score < 1000) {
		scoreX = 1066;
	}
	else if (score >= 1000 && score < 10000) {
		scoreX = 1034;
	}
	else {
		scoreX = 1002;
	}

	//scoreを文字列に変換
	snprintf(snScore, 30, "%d", score);

}
void cScore::Draw() {

	//UI-ハイスコアの表示
	cTextChange::Instance()->DrawTextImage(1000, 80, "20000", eWhite, eMag48);

	//UI-スコアの表示
	cTextChange::Instance()->DrawTextImage(scoreX, 140, snScore, eWhite, eMag48);
}

void cScore::Result() {

	//-RESULTS-
	cTextChange::Instance()->DrawTextImage(300, 450, "-RESULTS-", eRed, eMag48);

	//弾を撃った数
	totalShot = cShotMgr::Instance()->GetTotalShot();  //totalShotの更新
	snprintf(snTotalShot, 30, "SHOTS FIRED    %d", totalShot);
	cTextChange::Instance()->DrawTextImage(150, 550, snTotalShot, eYellow, eMag48);

	//弾を当てた数
	totalHit = cHit::Instance()->GetTotalHit();
	snprintf(snTotalHit, 30, "NUMBER OF HITS %d", totalHit);
	cTextChange::Instance()->DrawTextImage(150, 650, snTotalHit, eYellow, eMag48);

	//弾を外した割合
	oneShotRatio = 100.0 / totalShot;   //弾一発の割合
	hitMissRatio = oneShotRatio * totalHit;
	snprintf(snRatio, 30, "HIT-MISS RATIO %.1f %%", hitMissRatio);
	cTextChange::Instance()->DrawTextImage(150, 750, snRatio, eWhite, eMag48);

}