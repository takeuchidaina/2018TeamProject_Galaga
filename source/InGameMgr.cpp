#include <iostream>
#include "InGameMgr.h"
#include "InGameController.h"
#include "Player.h"
#include "ShotMgr.h"
#include "hit.h"
#include "EnemyMgr.h"
#include "UI.h"
#include "tractor.h"
#include "Score.h"
#include"BackGround.h"

//�R���X�g���N�^
cInGameMgr::cInGameMgr() {
	sceneflag = eBefore;
	next_Sceneflag = eInGameNone;
	Before_Sceneflag = eInGameNone;
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
	case eDeath://�v���C���[���S
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
	case eDeath://�v���C���[���S
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
	case eInGame://�Q�[�����[
		cBackGround::Instance()->Update();
		cPlayer::Instance()->Update();
		cShotMgr::Instance()->Update();
		cEnemyMgr::Instance()->Update();
		//EnemyMgr.Update();
		cHit::Instance()->Update();
		cScore::Instance()->Update();

		//
		break;
	case eDeath://�v���C���[���S
		cBackGround::Instance()->Update();
		cShotMgr::Instance()->Update();
		cEnemyMgr::Instance()->Update();
		cInGameController::Instance()->PlayerDeathUpdate();
		//
		break;
	case eRevival://�v���C���[����
		//
		break;
	case ePause://�|�[�Y���
		//
		break;
	case eTractor://����Ƃ�ꒆ
		cBackGround::Instance()->Update();
		cEnemyMgr::Instance()->Update();
		//EnemyMgr.Update();
		cHit::Instance()->Update();
		//
		break;
	case ePReturn://�v���C���[�A��
		//
		break;
	case eResult://���U���g���
		cInGameController::Instance()->ResultUpdate();
		//
		break;
	case eNextStage://���̃X�e�[�W��
		//
		break;
	}
	//�O���[�o���L�[��t�i�֐����\��
	if (cInterface::Instance()->Get_Input(InSTRAT) == 1) {
		if (sceneflag != ePause) {
			cInGameMgr::ChangeScene(ePause);
			Before_Sceneflag = sceneflag;
		}
		else {//�|�[�Y�Ȃ�
			cInGameMgr::ChangeScene(Before_Sceneflag);
		}
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
		cBackGround::Instance()->Draw();
		cPlayer::Instance()->Draw();
		cEnemyMgr::Instance()->Draw();
		cShotMgr::Instance()->Draw();
		//EnemyMgr.Draw();
		DrawFormatString(0, 20, GetColor(255, 255, 255), "eInGame");
		//
		break;
	case eDeath://�v���C���[���S
		cBackGround::Instance()->Draw();
		cPlayer::Instance()->Draw();
		cEnemyMgr::Instance()->Draw();
		cShotMgr::Instance()->Draw();
		cInGameController::Instance()->PlayerDeathDraw();
		DrawFormatString(0, 20, GetColor(255, 255, 255), "eDeath");
		//
		break;
	case eRevival://�v���C���[����
		//
		break;
	case ePause://�|�[�Y���
		cBackGround::Instance()->Draw();
		cPlayer::Instance()->Draw();
		cEnemyMgr::Instance()->Draw();
		cShotMgr::Instance()->Draw();
		tractor::Instance()->draw();
		DrawFormatString(0, 20, GetColor(255, 255, 255), "ePause");
		//DrawFormatString(420, 400, GetColor(100, 255, 255), "PAUSE");
		cTextChange::Instance()->DrawTextImage(370, 600, "PAUSE", eLBlue, eMag48);
		//
		break;
	case eTractor://����Ƃ�ꒆ
		cBackGround::Instance()->Draw();
		cPlayer::Instance()->Draw();
		cEnemyMgr::Instance()->Draw();
		DrawFormatString(0, 20, GetColor(255, 255, 255), "eTractor");
		//
		break;
	case ePReturn://�v���C���[�A��
		//
		break;
	case eResult://���U���g���
		cInGameController::Instance()->ResultDraw();
		DrawFormatString(0, 20, GetColor(255, 255, 255), "eResult");
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


