#pragma once

#ifndef _INGAMECONTROLLER_INCLUDE_
#define _INGAMECONTROLLER_INCLUDE_

#include "Singleton.h"
#include "InGameMgr.h"

class cInGameController : public cSingleton <cInGameController> {
	cInGameController();
	friend cSingleton < cInGameController>;
private:
	int nowStageNum = 1;
	int count = 0;

public:
	//�Q�[���J�n�O�̂���
	int BeforeSceneUpdate();
	int BeforeSceneDraw();
	//�v���C���[���S
	int PlayerDeath(int);
	int PlayerDeathUpdate();
	int PlayerDeathDraw();

	//�v���C���[����
//	int RevivalSceneUpdate();
//	int RevivalSceneDraw();
	//�|�[�Y���
	

	//����Ƃ�ꒆ
	int HitToTractor();
	int OutToTractor();
	int TractorSceneUpdate();
	int TractorSceneDraw();
	//�v���C���[�A��

	int InToRevive();
	int OutToRevive();
	int ReviveSceneUpdate();

	//���U���g���
	int ResultUpdate();
	int ResultDraw();



	//���̃X�e�[�W��
	int NextStage();


	//���݂̃X�e�[�W�����l��
	int GetNowStageNum() { return nowStageNum; }
};


#endif