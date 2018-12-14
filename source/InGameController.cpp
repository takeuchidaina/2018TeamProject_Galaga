#include "InGameController.h"
#include "InGameMgr.h"
#include "WinBox.h"
#include "Player.h"
#include "Interface.h"
#include "SceneMgr.h"
#include "TextChange.h"
#include "Score.h"

cInGameController::cInGameController() {}

//�Q�[�����n�܂�O�̂��̃V�[��
int cInGameController::BeforeSceneUpdate() {
	count++;
	if (count > 180) {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eInGame);
		count = 0;
	}
	return 0;
}

int cInGameController::BeforeSceneDraw() {
	DrawFormatString(0, 40, GetColor(255,255,255),"%d",count);
	if (count < 90 && count > 0) {
		char tmp[256];
		snprintf(tmp, 255, "STAGE %d", nowStageNum);
		cTextChange::Instance()->DrawTextImage(350, 400, tmp, eLBlue, eMag48);
		
		//DrawFormatString(400, 400, GetColor(255, 255, 255), "Stage %d", nowStageNum);
	}
	else {
		cTextChange::Instance()->DrawTextImage(370, 400, "READY", eLBlue, eMag48);
		//DrawFormatString(400, 400, GetColor(255, 255, 255), "READY");
	}
	return 0;
}

//�v���C���[���S
int cInGameController::PlayerDeath() {
	if (cPlayer::Instance()->GetPlayerHP() < 0) {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eResult);
	}
	else {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eDeath);
	}
	cEnemyMgr::Instance()->SetChoiseOrderFlag(false);
	cShotMgr::Instance()->SetShotFlg(false);
	//ReportBox("�v���C���[�����񂾂񂶂�\n�G�͎~�܂�܂���B");
	return 0;
}
int cInGameController::PlayerDeathUpdate() {
	//�G�t�F�N�g���o��
	//�G�t�F�N�g���o�I�������READY�\��
	//�v���C���[���Ĕz�u
	cEnemyMgr::Instance()->Update();
	//�S�ẴG�l�~�[���ړ����I����Ă��邩���l��
	if (cEnemyMgr::Instance()->GetEnemyStay() == 0) {

	}
	else {
		count++;
		if (count == 10) {
			cPlayer::Instance()->PlayerRevive();
		}
		if (count > 120) {
			cEnemyMgr::Instance()->SetChoiseOrderFlag(true);
			cShotMgr::Instance()->SetShotFlg(true);
			cInGameMgr::Instance()->ChangeScene(cInGameMgr::eInGame);
			count = 0;
		}
	}

	return 0;
}
int cInGameController::PlayerDeathDraw() {
	if (count > 1) {
		cTextChange::Instance()->DrawTextImage(370, 400, "READY", eLBlue, eMag48);
		//DrawFormatString(400, 400, GetColor(255, 255, 255), "READY");
	}
	return 0;
}



//�v���C���[����



//�|�[�Y���



//����Ƃ�ꒆ
int cInGameController::HitToTractor() {
	cInGameMgr::Instance()->ChangeScene(cInGameMgr::eTractor);
	return 0;
}
int cInGameController::OutToTractor() {
	cInGameMgr::Instance()->ChangeScene(cInGameMgr::eDeath);
	return 0;
}
int cInGameController::TractorSceneUpdate(){
	return 0;
}
int cInGameController::TractorSceneDraw() {
	return 0;
}

//�v���C���[�A��



//���U���g���
int cInGameController::ResultUpdate() {
	if (cInterface::Instance()->Get_Input(InDECISION) == 1) {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eBefore);
		cSceneMgr::Instance()->ChangeScene(eStartMenu);
		nowStageNum = 1;
		cScore::Instance()->ResetScore();
		cEnemyMgr::Instance()->Init();
		cPlayer::Instance()->Init();
		cShotMgr::Instance()->Init();
	}
	return 0;
}
int cInGameController::ResultDraw() {
	cScore::Instance()->Result();
	return 0;
}


//���̃X�e�[�W��
int cInGameController::NextStage() {
	nowStageNum++;
	cInGameMgr::Instance()->ChangeScene(cInGameMgr::eBefore);
	return 0;
}



