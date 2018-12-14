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

	//UI-�n�C�X�R�A�̕\��
	cTextChange::Instance()->DrawTextImage(1000, 80, "00000", eWhite, eMag48);

	//UI-�X�R�A�̕\��
	snprintf(tmp, 30, "%d",score);
	cTextChange::Instance()->DrawTextImage(1130, 140, tmp, eWhite, eMag48);
	//�X�R�A�̌����ɍ��ɍ��W�������悤�ɂ���
}

void cScore::Result() {

	char tmpS[30];
	char tmpH[30];
	char tmpR[30];

	//-RESULTS-
	cTextChange::Instance()->DrawTextImage(350, 450, "-RESULTS-", eRed, eMag48);

	//�e����������
	totalShot = cShotMgr::Instance()->GetTotalShot();  //totalShot�̍X�V
	snprintf(tmpS, 30, "SHOTS FIRED    %d", totalShot);
	cTextChange::Instance()->DrawTextImage(200, 550, tmpS, eYellow, eMag48);

	//�e�𓖂Ă���
	totalHit = cHit::Instance()->GetTotalHit();
	snprintf(tmpH, 30, "NUMBER OF HITS %d", totalHit);
	cTextChange::Instance()->DrawTextImage(200, 650, tmpH, eYellow, eMag48);

	//�e���O��������
	hitMissRatio = 100 - (totalShot / totalHit);
	snprintf(tmpR,30,"HIT-MISS RATIO %d %%",hitMissRatio);
	cTextChange::Instance()->DrawTextImage(200, 750, tmpR, eWhite, eMag48);

}