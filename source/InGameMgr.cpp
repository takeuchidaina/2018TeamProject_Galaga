#include <iostream>
#include "InGameMgr.h"

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
	case eBefore:
		//
		break;
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
	case eBefore:
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
	case eBefore:
			//
			break;
	}
}

//�`�ʏ���
void cInGameMgr::Draw() {
	switch (sceneflag) {
	case eBefore:
		//
		break;
	}
}

void cInGameMgr::ChangeScene(eInGameScene nextScene) {
	next_Sceneflag = nextScene;
}



















