#pragma once

#ifndef _INGAMECONTROLLER_INCLUDE_
#define _INGAMECONTROLLER_INCLUDE_

#include "Singleton.h"
#include "InGameMgr.h"

class cInGameController :public cInGameMgr , public Singleton <cInGameController> {
	cInGameController();
	friend cInGameMgr;
	friend Singleton < cInGameController>;
private:
	static int nowStageNum;

public:


};


#endif