#pragma once

#ifndef _INGAMECONTROLLER_INCLUDE_
#define _INGAMECONTROLLER_INCLUDE_

#include "Singleton.h"
#include "InGameMgr.h"

class cInGameController : public Singleton <cInGameController> {
	cInGameController();
	friend Singleton < cInGameController>;
private:
	int nowStageNum = 1;
	int count = 0;

public:
	int BeforeSceneUpdate();
	int BeforeSceneDraw();
	int GetNowStageNum() { return nowStageNum; }
};


#endif