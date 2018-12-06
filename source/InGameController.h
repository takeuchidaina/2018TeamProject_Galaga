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
	//ゲーム開始前のあれ
	int BeforeSceneUpdate();
	int BeforeSceneDraw();
	//プレイヤー死亡
	int PlayerDeath();
	int PlayerDeathUpdate();
	int PlayerDeathDraw();

	//プレイヤー復活
//	int RevivalSceneUpdate();
//	int RevivalSceneDraw();
	//ポーズ画面
	

	//きゃとられ中
	int HitToTractor();
	int TractorSceneUpdate();
	int TractorSceneDraw();
	//プレイヤー帰還



	//リザルト画面



	//次のステージへ
	int NextStage();


	//現在のステージ数を獲得
	int GetNowStageNum() { return nowStageNum; }
};


#endif