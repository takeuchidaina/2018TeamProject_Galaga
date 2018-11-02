#pragma once
#pragma once
#ifndef _INGAME_MGR_INCLUDE_
#define _INGAME_MGR_INCLUDE_




class cInGameMgr {
private:
	typedef enum {
		eBefore,//実際ゲームが始まる前のあれ
		eInGame,
		//eResult,
		//ePause,
		//考え中
		eInGameNone,
	}eInGameScene;

	eInGameScene sceneflag;
	eInGameScene next_Sceneflag;

	void Init_Module(eInGameScene scene);
	void End_Module(eInGameScene scene);


public:
	cInGameMgr();
	~cInGameMgr();

	void Update();
	void Draw();
	void ChangeScene(eInGameScene scene);
};

#endif