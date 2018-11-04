#include <iostream>
#include "DxLib.h"
#include "Interface.h"
#include "SceneMgr.h"


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
		test = new cTemplate;
		break;
	case eInGame:
		//�Q�[�����
		InGameMgr = new cInGameMgr;
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
		delete test;
		break;
	case eInGame:
		//�Q�[�����
		delete InGameMgr;
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
		test->Update();
		break;
	case eInGame:
		//�Q�[�����
		InGameMgr->Update();
		break;
	case eGameMenu:
		//�Q�[�����j���[

		break;
	case eResult:
		//���U���g���

		break;
	}

	if (Interface.Get_Input(InRIGHT) != 0) {
		DrawFormatString(0, 0, GetColor(255, 255, 255), "���L�[��%d�t���[��������Ă��܂�", Interface.Get_Input(InRIGHT));
	}

}

//�`�揈��
void cSceneMgr::Draw() {
	switch (sceneflag) {
	case eStartMenu:
		//�X�^�[�g���j���[
		test->Draw();
		break;
	case eInGame:
		//�Q�[�����
		InGameMgr->Draw();
		break;
	case eGameMenu:
		//�Q�[�����j���[

		break;
	case eResult:
		//���U���g���

		break;
	}

}

void cSceneMgr::ChangeScene(eScene nextScene) {
	next_Sceneflag = nextScene;
}

