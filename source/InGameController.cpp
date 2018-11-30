#include "InGameController.h"
#include "InGameMgr.h"
#include "WinBox.h"

cInGameController::cInGameController() {}

//�Q�[�����n�܂�O�̂��̃V�[��
int cInGameController::BeforeSceneUpdate() {
	count++;
	if (count > 10) {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eInGame);
		count = 0;
	}
	return 0;
}

int cInGameController::BeforeSceneDraw() {
	DrawFormatString(0, 40, GetColor(255,255,255),"%d",count);
	DrawFormatString(400, 400, GetColor(255, 255, 255), "Stage %d", nowStageNum);
	return 0;
}

//�v���C���[���S
int cInGameController::PlayerDeath() {
	cInGameMgr::Instance()->ChangeScene(cInGameMgr::eDeath);

	ReportBox("�v���C���[�����񂾂񂶂�\n�G�͎~�܂�܂���B");
	return 0;
}
int cInGameController::PlayerDeathUpdate() {
	count++;
	//�G�t�F�N�g���o��
	//�G�t�F�N�g���o�I�������READY�\��
	//�v���C���[���Ĕz�u
	
	//�S�ẴG�l�~�[���ړ����I����Ă��邩���l��
	//�I����Ă�����
	if (count > 120) {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eInGame);
		count = 0;
	}

	return 0;
}
int cInGameController::PlayerDeathDraw() {
	DrawFormatString(400, 400, GetColor(255, 255, 255), "READY");
	return 0;
}



//�v���C���[����



//�|�[�Y���



//����Ƃ�ꒆ
int cInGameController::HitToTractor() {
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



//���̃X�e�[�W��




