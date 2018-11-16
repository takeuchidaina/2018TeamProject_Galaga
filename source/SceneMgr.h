#pragma once
#ifndef _SCENE_MGR_INCLUDE_
#define _SCENE_MGR_INCLUDE_

#include "Template.h"
#include "Singleton.h"
#include "InGameMgr.h"
#include "Template.h"
#include "EnemyMgr.h"

//これは別にヘッダーを作ってもいい
typedef enum {
	eStartMenu,
	eInGame,
	eGameMenu,
	eResult,

	eSceneNone
}eScene;
//ここまで

//継承を使うともっと良くなる　とりあえずC⇒C++へ
class cSceneMgr : public cSingleton <cSceneMgr> {
	cSceneMgr();
	friend cSingleton <cSceneMgr>;
private:
	eScene sceneflag;
	eScene next_Sceneflag;

	void Init_Module(eScene scene);
	void End_Module(eScene scene);

	cTemplate* test;
	//cInGameMgr* InGameMgr;

	~cSceneMgr();

	

public:

	void Update();
	void Draw();
	void ChangeScene(eScene scene);
};

#endif