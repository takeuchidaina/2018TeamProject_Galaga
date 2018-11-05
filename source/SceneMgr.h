#pragma once
#ifndef _SCENE_MGR_INCLUDE_
#define _SCENE_MGR_INCLUDE_

#include "Template.h"
#include "InGameMgr.h"
#include "Template.h"
#include "Interface.h"

//����͕ʂɃw�b�_�[������Ă�����
typedef enum {
	eStartMenu,
	eInGame,
	eGameMenu,
	eResult,

	eSceneNone
}eScene;
//�����܂�

//�p�����g���Ƃ����Ɨǂ��Ȃ�@�Ƃ肠����C��C++��
class cSceneMgr {
private:
	eScene sceneflag;
	eScene next_Sceneflag;

	void Init_Module(eScene scene);
	void End_Module(eScene scene);

	cTemplate* test;
	cInGameMgr* InGameMgr;
	cInterface Interfase;

public:
	cSceneMgr();
	~cSceneMgr();

	void Update();
	void Draw();
	void ChangeScene(eScene scene);
};

#endif