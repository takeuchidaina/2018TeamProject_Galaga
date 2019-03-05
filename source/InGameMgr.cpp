#include <iostream>
#include "InGameMgr.h"
#include "InGameController.h"
#include "Player.h"
#include "ShotMgr.h"
#include "hit.h"
#include "EnemyMgr.h"
#include "UI.h"
#include "tractor.h"
//#include "Score.h"
#include "Debug.h"
#include "EffectMgr.h"
#include "SaveLoad.h"

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
		if (cSE::Instance()->GetSeActive(gamestart) == 0) {
			cInGameController::Instance()->BeforeSceneUpdate();
		}
		
		cEffectMgr::Instance()->Update();
		cSaveLoad::Instance()->Load();
		//
		break;
	case eInGame://�Q�[�����[
		cHit::Instance()->Update();
		cPlayer::Instance()->Update();
		cShotMgr::Instance()->Update();
		cEnemyMgr::Instance()->Update();
		//EnemyMgr.Update();
		
		cScore::Instance()->Update();
		cEffectMgr::Instance()->Update();
		if (Debug::Instance()->Get_Input(Key0) == 1) {
			for (int i = 0; i < cEnemyMgr::Instance()->GetMaxEnemy(); i++) {
				cEnemyMgr::Instance()->SetEnemyDeath(i);
			}
		}

		//
		break;
	case eDeath://�v���C���[���S
		
		cShotMgr::Instance()->Update();
		//cEnemyMgr::Instance()->Update();
		cInGameController::Instance()->PlayerDeathUpdate();
		cEffectMgr::Instance()->Update();
		//
		break;
	case eRevival://�v���C���[����
		//cHit::Instance()->Update();
		//cEnemyMgr::Instance()->Update();
		cInGameController::Instance()->ReviveSceneUpdate();
		cEffectMgr::Instance()->Update();
		cShotMgr::Instance()->Update();
		//
		break;
	case ePause://�|�[�Y���
		//
		break;
	case eTractor://����Ƃ�ꒆ
		cEnemyMgr::Instance()->Update();
		//EnemyMgr.Update();
	//	cHit::Instance()->Update();
		cShotMgr::Instance()->Update();
		cEffectMgr::Instance()->Update();
		//
		break;
	case ePReturn://�v���C���[�A��
		//
		break;
	case eResult://���U���g���
		if (cSE::Instance()->GetSeActive(music_nameentry_2nd_5th) == 0)cSE::Instance()->selectSE(music_nameentry_2nd_5th);
		cInGameController::Instance()->ResultUpdate();
		cSaveLoad::Instance()->Save();
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
		if (cSE::Instance()->GetSeActive(gamestart) == 0) {
			cInGameController::Instance()->BeforeSceneDraw();
			cPlayer::Instance()->Draw();
		}
		else {
		cTextChange::Instance()->DrawTextImage(370, 400, "START", eRed, eMag48);
		}
	
		cSaveLoad::Instance()->Draw();
//		DrawFormatString(0, 20, GetColor(255, 255, 255), "eBefore");
		//
		break;
	case eInGame://�Q�[�����
		cPlayer::Instance()->Draw();
		cEnemyMgr::Instance()->Draw();
		cShotMgr::Instance()->Draw();
		cEffectMgr::Instance()->Draw();
		cSaveLoad::Instance()->Draw();
		//EnemyMgr.Draw();
		//DrawFormatString(0, 20, GetColor(255, 255, 255), "eInGame");
		//
		break;
	case eDeath://�v���C���[���S
		cPlayer::Instance()->Draw();
		cEnemyMgr::Instance()->Draw();
		cShotMgr::Instance()->Draw();
		cEffectMgr::Instance()->Draw();
		cInGameController::Instance()->PlayerDeathDraw();
//		DrawFormatString(0, 20, GetColor(255, 255, 255), "eDeath");
		//
		break;
	case eRevival://�v���C���[����
		cPlayer::Instance()->Draw();
		cEnemyMgr::Instance()->Draw();
		//cShotMgr::Instance()->Draw();
		cEffectMgr::Instance()->Draw();
		//DrawFormatString(0, 20, GetColor(255, 255, 255), "eRevival");
		//
		break;
	case ePause://�|�[�Y���
		cPlayer::Instance()->Draw();
		cEnemyMgr::Instance()->Draw();
		cShotMgr::Instance()->Draw();
		cEffectMgr::Instance()->Draw();
		//tractor::Instance()->draw();
//		DrawFormatString(0, 20, GetColor(255, 255, 255), "ePause");
		//DrawFormatString(420, 400, GetColor(100, 255, 255), "PAUSE");
		cTextChange::Instance()->DrawTextImage(370, 600, "PAUSE", eLBlue, eMag48);
		//
		break;
	case eTractor://����Ƃ�ꒆ
		cPlayer::Instance()->Draw();
		cEnemyMgr::Instance()->Draw();
		cEffectMgr::Instance()->Draw();
//		DrawFormatString(0, 20, GetColor(255, 255, 255), "eTractor");
		//
		break;
	case ePReturn://�v���C���[�A��
		//
		break;
	case eResult://���U���g���
		cInGameController::Instance()->ResultDraw();
//		DrawFormatString(0, 20, GetColor(255, 255, 255), "eResult");
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


