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

	//�X�R�A�ɉ����č��W�������(�ꌅ�ڈʒu�Œ�)
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

	//score�𕶎���ɕϊ�
	snprintf(snScore, 30, "%d", score);

}
void cScore::Draw() {

	//UI-�n�C�X�R�A�̕\��
	cTextChange::Instance()->DrawTextImage(1000, 80, "20000", eWhite, eMag48);

	//UI-�X�R�A�̕\��
	cTextChange::Instance()->DrawTextImage(scoreX, 140, snScore, eWhite, eMag48);
}

void cScore::Result() {

	//-RESULTS-
	cTextChange::Instance()->DrawTextImage(300, 450, "-RESULTS-", eRed, eMag48);

	//�e����������
	totalShot = cShotMgr::Instance()->GetTotalShot();  //totalShot�̍X�V
	snprintf(snTotalShot, 30, "SHOTS FIRED    %d", totalShot);
	cTextChange::Instance()->DrawTextImage(150, 550, snTotalShot, eYellow, eMag48);

	//�e�𓖂Ă���
	totalHit = cHit::Instance()->GetTotalHit();
	snprintf(snTotalHit, 30, "NUMBER OF HITS %d", totalHit);
	cTextChange::Instance()->DrawTextImage(150, 650, snTotalHit, eYellow, eMag48);

	//�e���O��������
	oneShotRatio = 100.0 / totalShot;   //�e�ꔭ�̊���
	hitMissRatio = oneShotRatio * totalHit;
	snprintf(snRatio, 30, "HIT-MISS RATIO %.1f %%", hitMissRatio);
	cTextChange::Instance()->DrawTextImage(150, 750, snRatio, eWhite, eMag48);

}