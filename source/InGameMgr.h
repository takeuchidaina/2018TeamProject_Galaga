#pragma once
#pragma once
#ifndef _INGAME_MGR_INCLUDE_
#define _INGAME_MGR_INCLUDE_


#include "Singleton.h"
#include "Player.h"
#include "EnemyMgr.h"
#include "ShotMgr.h"
#include "hit.h"
#include "Struct.h"

class cPlayer;

class cInGameMgr : public cSingleton <cInGameMgr> {
	cInGameMgr();
	friend cSingleton <cInGameMgr>;
public:
	typedef enum {
		eBefore,	//実際ゲームが始まる前のあれ
		eInGame,	//ゲーム画面
		eDeath,		//プレイヤー死亡
		eRevival,	//プレイヤー復活　いらないかも
		ePause,		//ポーズ画面
		eTractor,	//きゃとられ中
		ePReturn,	//プレイヤー帰還
		eResult,	//リザルト画面
		eNextStage,	//次のステージへ

					//考え中
					eInGameNone
	}eInGameScene;

private:
//	cEnemyMgr EnemyMgr;

	eInGameScene sceneflag;
	eInGameScene next_Sceneflag;
	eInGameScene Before_Sceneflag;

	void Init_Module(eInGameScene scene);
	void End_Module(eInGameScene scene);

	~cInGameMgr();



public:

	void Update();
	void Draw();
	void ChangeScene(eInGameScene scene);


};

#endif