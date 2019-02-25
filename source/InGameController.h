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
	//�Q�[���J�n�O�V�[���̍X�V�A�`��
	int BeforeSceneUpdate();
	int BeforeSceneDraw();
	
	/*********************************
	�֐����Fint PlayerDeath(int)
	�����F
	�����Fint�^ �v���C���[�̎����ԍ��@0:�c�@���莀�S
	�߂�l�F0:����@0�ȊO:�ُ�
	**********************************/
	int PlayerDeath(int);
	//�v���C���[���S�V�[���̍X�V�A�`��
	int PlayerDeathUpdate();
	int PlayerDeathDraw();

	//�v���C���[����
//	int RevivalSceneUpdate();
//	int RevivalSceneDraw();
	//�|�[�Y���
	

	//�g���N�^�[�r�[���ɓ����������A������ꂽ���̏���
	int HitToTractor();
	int OutToTractor();
	//����Ƃ�ꒆ�̍X�V�A�`��
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