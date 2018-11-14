#include <iostream>
#include "InGameMgr.h"
#include "InGameController.h"
#include "Player.h"
#include "EnemyMgr.h"
#include "UI.h"

//コンストラクタ
cInGameMgr::cInGameMgr() {
	sceneflag = eBefore;
	next_Sceneflag = eInGameNone;
	Init_Module(sceneflag);
	UI_Init();
	Player = new cPlayer;
}

//デコンストラクタ
cInGameMgr::~cInGameMgr() {
	UI_End();
	delete Player;
}

//指定モジュールの初期化処理
void cInGameMgr::Init_Module(eInGameScene scene) {
	switch (scene) {
	case eBefore://実際ゲームが始まる前のあれ
		//
		break;						
	case eInGame://ゲーム画面
		//
		break;
	case eRevival://プレイヤー復活
		//
		break;
	case ePause://ポーズ画面
		//
		break;
	case eTractor://きゃとられ中
		//
		break;
	case ePReturn://プレイヤー帰還
		//
		break;
	case eResult://リザルト画面
		//
		break;
	case eNextStage://次のステージへ
		//
		break;
		/*
	case eBefore://実際ゲームが始まる前のあれ
		//
		break;						
	case eInGame://ゲーム画面
		//
		break;
	case eRevival://プレイヤー復活
		//
		break;
	case ePause://ポーズ画面
		//
		break;
	case eTractor://きゃとられ中
		//
		break;
	case ePReturn://プレイヤー帰還
		//
		break;
	case eResult://リザルト画面
		//
		break;
	case eNextStage://次のステージへ
		//
		break;

		*/
		/*
		//コピペテンプレート
	case :
		//
		break;
		*/
	}
}

//指定モジュールの終了処理
void cInGameMgr::End_Module(eInGameScene scene) {
	switch (scene) {
	case eBefore://実際ゲームが始まる前のあれ
		//
		break;
	case eInGame://ゲーム画面
		//
		break;
	case eRevival://プレイヤー復活
		//
		break;
	case ePause://ポーズ画面
		//
		break;
	case eTractor://きゃとられ中
		//
		break;
	case ePReturn://プレイヤー帰還
		//
		break;
	case eResult://リザルト画面
		//
		break;
	case eNextStage://次のステージへ
		//
		break;
	}
}

//計算処理
void cInGameMgr::Update() {
	if (next_Sceneflag != eInGameNone) {
		End_Module(sceneflag);
		sceneflag = next_Sceneflag;
		next_Sceneflag = eInGameNone;
		Init_Module(sceneflag);
	}
	switch (sceneflag) {
	case eBefore://実際ゲームが始まる前のあれ
				
		cInGameController::Instance()->BeforeSceneUpdate();
		//
		break;
	case eInGame://ゲーム画面
		Player->Update();
		EnemyMgr.Update();
		//
		break;
	case eRevival://プレイヤー復活
		//
		break;
	case ePause://ポーズ画面
		//
		break;
	case eTractor://きゃとられ中
		//
		break;
	case ePReturn://プレイヤー帰還
		//
		break;
	case eResult://リザルト画面
		//
		break;
	case eNextStage://次のステージへ
		//
		break;
	}
	UI_Update();

}

//描写処理
void cInGameMgr::Draw() {
	switch (sceneflag) {
	case eBefore://実際ゲームが始まる前のあれ
		cInGameController::Instance()->BeforeSceneDraw();
		DrawFormatString(0, 20, GetColor(255, 255, 255), "eBefore");
		//
		break;
	case eInGame://ゲーム画面
		Player->Draw();
		EnemyMgr.Draw();
		DrawFormatString(0, 20, GetColor(255, 255, 255), "eInGame");
		//
		break;
	case eRevival://プレイヤー復活
		//
		break;
	case ePause://ポーズ画面
		//
		break;
	case eTractor://きゃとられ中
		//
		break;
	case ePReturn://プレイヤー帰還
		//
		break;
	case eResult://リザルト画面
		 //
		break;
	case eNextStage://次のステージへ
		//
		break;
	}
	UI_Draw();

}

void cInGameMgr::ChangeScene(eInGameScene nextScene) {
	next_Sceneflag = nextScene;
}


