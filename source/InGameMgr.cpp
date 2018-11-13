#include <iostream>
#include "InGameMgr.h"
#include "InGameController.h"

//�R���X�g���N�^
cInGameMgr::cInGameMgr() {
	sceneflag = eBefore;
	next_Sceneflag = eInGameNone;
	Init_Module(sceneflag);
}

//�f�R���X�g���N�^
cInGameMgr::~cInGameMgr() {

}

//�w�胂�W���[���̏���������
void cInGameMgr::Init_Module(eInGameScene scene) {
	switch (scene) {
	case eBefore://���ۃQ�[�����n�܂�O�̂���
		//
		break;						
	case eInGame://�Q�[�����
		//
		break;
	case eRevival://�v���C���[����
		//
		break;
	case ePause://�|�[�Y���
		//
		break;
	case eTractor://����Ƃ�ꒆ
		//
		break;
	case ePReturn://�v���C���[�A��
		//
		break;
	case eResult://���U���g���
		//
		break;
	case eNextStage://���̃X�e�[�W��
		//
		break;
		/*
	case eBefore://���ۃQ�[�����n�܂�O�̂���
		//
		break;						
	case eInGame://�Q�[�����
		//
		break;
	case eRevival://�v���C���[����
		//
		break;
	case ePause://�|�[�Y���
		//
		break;
	case eTractor://����Ƃ�ꒆ
		//
		break;
	case ePReturn://�v���C���[�A��
		//
		break;
	case eResult://���U���g���
		//
		break;
	case eNextStage://���̃X�e�[�W��
		//
		break;

		*/
		/*
		//�R�s�y�e���v���[�g
	case :
		//
		break;
		*/
	}
}

//�w�胂�W���[���̏I������
void cInGameMgr::End_Module(eInGameScene scene) {
	switch (scene) {
	case eBefore://���ۃQ�[�����n�܂�O�̂���
		//
		break;
	case eInGame://�Q�[�����
		//
		break;
	case eRevival://�v���C���[����
		//
		break;
	case ePause://�|�[�Y���
		//
		break;
	case eTractor://����Ƃ�ꒆ
		//
		break;
	case ePReturn://�v���C���[�A��
		//
		break;
	case eResult://���U���g���
		//
		break;
	case eNextStage://���̃X�e�[�W��
		//
		break;
	}
}

//�v�Z����
void cInGameMgr::Update() {
	if (next_Sceneflag != eInGameNone) {
		End_Module(sceneflag);
		sceneflag = next_Sceneflag;
		next_Sceneflag = eInGameNone;
		Init_Module(sceneflag);
	}
	switch (sceneflag) {
	case eBefore://���ۃQ�[�����n�܂�O�̂���
				
		cInGameController::Instance()->BeforeSceneUpdate();
		//
		break;
	case eInGame://�Q�[�����
		//
		break;
	case eRevival://�v���C���[����
		//
		break;
	case ePause://�|�[�Y���
		//
		break;
	case eTractor://����Ƃ�ꒆ
		//
		break;
	case ePReturn://�v���C���[�A��
		//
		break;
	case eResult://���U���g���
		//
		break;
	case eNextStage://���̃X�e�[�W��
		//
		break;
	}
}

//�`�ʏ���
void cInGameMgr::Draw() {
	switch (sceneflag) {
	case eBefore://���ۃQ�[�����n�܂�O�̂���
		cInGameController::Instance()->BeforeSceneDraw();
		DrawFormatString(0, 20, GetColor(255, 255, 255), "eBefore");
		//
		break;
	case eInGame://�Q�[�����
		DrawFormatString(0, 20, GetColor(255, 255, 255), "eInGame");
		//
		break;
	case eRevival://�v���C���[����
		//
		break;
	case ePause://�|�[�Y���
		//
		break;
	case eTractor://����Ƃ�ꒆ
		//
		break;
	case ePReturn://�v���C���[�A��
		//
		break;
	case eResult://���U���g���
		 //
		break;
	case eNextStage://���̃X�e�[�W��
		//
		break;
	}
}

void cInGameMgr::ChangeScene(eInGameScene nextScene) {
	next_Sceneflag = nextScene;
}


