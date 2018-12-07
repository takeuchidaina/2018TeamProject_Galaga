#include <iostream>
#include "DxLib.h"
#include "SceneMgr.h"
#include "Interface.h"

#include "Template.h"
//���Ǘ\��


//�R���X�g���N�^
cSceneMgr::cSceneMgr() {
	sceneflag = eStartMenu;
	next_Sceneflag = eSceneNone;
	Init_Module(sceneflag);
	
}

//�f�R���X�g���N�^
cSceneMgr::~cSceneMgr() {

}

//�w�胂�W���[���̏���������
void cSceneMgr::Init_Module(eScene scene) {
	switch (scene) {
	case eStartMenu:
		//�X�^�[�g���j���[
//		test = new cTemplate;
		break;
	case eInGame:
		//�Q�[�����
//		InGameMgr = new cInGameMgr;
		break;
	case eGameMenu:
		//�Q�[�����j���[

		break;
	case eResult:
		//���U���g���

		break;
	}
}

//�w�胂�W���[���̏I������
void cSceneMgr::End_Module(eScene scene) {
	switch (scene) {
	case eStartMenu:
		//�X�^�[�g���j���[
//		delete test;
		break;
	case eInGame:
		//�Q�[�����
//		delete InGameMgr;
		break;
	case eGameMenu:
		//�Q�[�����j���[

		break;
	case eResult:
		//���U���g���

		break;
	}
}




//�v�Z����
void cSceneMgr::Update() {
	if (next_Sceneflag != eSceneNone) {
		End_Module(sceneflag);
		sceneflag = next_Sceneflag;
		next_Sceneflag = eSceneNone;
		Init_Module(sceneflag);
	}

	switch (sceneflag) {
	case eStartMenu:
		//�X�^�[�g���j���[
		if (cInterface::Instance()->Get_Input(InDECISION) == 1) {
			ChangeScene(eInGame);
		}
//		test->Update();
		break;
	case eInGame:
		//�Q�[�����
//		InGameMgr->Update();
		cInGameMgr::Instance()->Update();
		break;
	case eGameMenu:
		//�Q�[�����j���[

		break;
	case eResult:
		//���U���g���

		break;
	}
}

//�`�揈��
void cSceneMgr::Draw() {
	switch (sceneflag) {
	case eStartMenu:
		//�X�^�[�g���j���[
		DrawFormatString(0, 0, GetColor(255, 255, 255), "SceneMgr StartMenu");
		//DrawFormatString(300, 400, GetColor(255, 255, 255), "Please press Space key");
		cTitle::Instance()->Draw();
//		test->Draw();
		break;
	case eInGame:
		//�Q�[�����
//		InGameMgr->Draw();
		cInGameMgr::Instance()->Draw();
		DrawFormatString(0, 0, GetColor(255, 255, 255), "SceneMgr InGame");
		break;
	case eGameMenu:
		//�Q�[�����j���[

		break;
	case eResult:
		//���U���g���

		break;
	}
	
	cUI::Instance()->UI_Draw();
	cScore::Instance()->Draw();
}

void cSceneMgr::ChangeScene(eScene nextScene) {
	next_Sceneflag = nextScene;
}

