#include <iostream>
#include "InGameMgr.h"
#include "InGameController.h"
#include "Player.h"
#include "EnemyMgr.h"
#include "UI.h"

//�R���X�g���N�^
cInGameMgr::cInGameMgr() {
	sceneflag = eBefore;
	next_Sceneflag = eInGameNone;
	Init_Module(sceneflag);
	UI_Init();
	Player = new cPlayer;
}

//�f�R���X�g���N�^
cInGameMgr::~cInGameMgr() {
	UI_End();
	delete Player;
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
		Player->Update();
		EnemyMgr.Update();
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
	UI_Update();

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
		Player->Draw();
		EnemyMgr.Draw();
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
	UI_Draw();

}

void cInGameMgr::ChangeScene(eInGameScene nextScene) {
	next_Sceneflag = nextScene;
}


