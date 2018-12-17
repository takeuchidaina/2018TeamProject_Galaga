#include <iostream>
#include "InGameMgr.h"
#include "InGameController.h"
#include "Player.h"
#include "ShotMgr.h"
#include "hit.h"
#include "EnemyMgr.h"
#include "UI.h"
#include "tractor.h"
#include "Score.h"
#include"BackGround.h"

//コンストラクタ
cInGameMgr::cInGameMgr() {
	sceneflag = eBefore;
	next_Sceneflag = eInGameNone;
	Before_Sceneflag = eInGameNone;
	Init_Module(sceneflag);
}

//デコンストラクタ
cInGameMgr::~cInGameMgr() {
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
	case eDeath://プレイヤー死亡
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
	case eDeath://プレイヤー死亡
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
	case eInGame://ゲーム画面[
		cBackGround::Instance()->Update();
		cPlayer::Instance()->Update();
		cShotMgr::Instance()->Update();
		cEnemyMgr::Instance()->Update();
		//EnemyMgr.Update();
		cHit::Instance()->Update();
		cScore::Instance()->Update();

		//
		break;
	case eDeath://プレイヤー死亡
		cBackGround::Instance()->Update();
		cShotMgr::Instance()->Update();
		cEnemyMgr::Instance()->Update();
		cInGameController::Instance()->PlayerDeathUpdate();
		//
		break;
	case eRevival://プレイヤー復活
		//
		break;
	case ePause://ポーズ画面
		//
		break;
	case eTractor://きゃとられ中
		cBackGround::Instance()->Update();
		cEnemyMgr::Instance()->Update();
		//EnemyMgr.Update();
		cHit::Instance()->Update();
		//
		break;
	case ePReturn://プレイヤー帰還
		//
		break;
	case eResult://リザルト画面
		cInGameController::Instance()->ResultUpdate();
		//
		break;
	case eNextStage://次のステージへ
		//
		break;
	}
	//グローバルキー受付（関数化予定
	if (cInterface::Instance()->Get_Input(InSTRAT) == 1) {
		if (sceneflag != ePause) {
			cInGameMgr::ChangeScene(ePause);
			Before_Sceneflag = sceneflag;
		}
		else {//ポーズなら
			cInGameMgr::ChangeScene(Before_Sceneflag);
		}
	}
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
		cBackGround::Instance()->Draw();
		cPlayer::Instance()->Draw();
		cEnemyMgr::Instance()->Draw();
		cShotMgr::Instance()->Draw();
		//EnemyMgr.Draw();
		DrawFormatString(0, 20, GetColor(255, 255, 255), "eInGame");
		//
		break;
	case eDeath://プレイヤー死亡
		cBackGround::Instance()->Draw();
		cPlayer::Instance()->Draw();
		cEnemyMgr::Instance()->Draw();
		cShotMgr::Instance()->Draw();
		cInGameController::Instance()->PlayerDeathDraw();
		DrawFormatString(0, 20, GetColor(255, 255, 255), "eDeath");
		//
		break;
	case eRevival://プレイヤー復活
		//
		break;
	case ePause://ポーズ画面
		cBackGround::Instance()->Draw();
		cPlayer::Instance()->Draw();
		cEnemyMgr::Instance()->Draw();
		cShotMgr::Instance()->Draw();
		tractor::Instance()->draw();
		DrawFormatString(0, 20, GetColor(255, 255, 255), "ePause");
		//DrawFormatString(420, 400, GetColor(100, 255, 255), "PAUSE");
		cTextChange::Instance()->DrawTextImage(370, 600, "PAUSE", eLBlue, eMag48);
		//
		break;
	case eTractor://きゃとられ中
		cBackGround::Instance()->Draw();
		cPlayer::Instance()->Draw();
		cEnemyMgr::Instance()->Draw();
		DrawFormatString(0, 20, GetColor(255, 255, 255), "eTractor");
		//
		break;
	case ePReturn://プレイヤー帰還
		//
		break;
	case eResult://リザルト画面
		cInGameController::Instance()->ResultDraw();
		DrawFormatString(0, 20, GetColor(255, 255, 255), "eResult");
		 //
		break;
	case eNextStage://次のステージへ
		//
		break;
	}

}

void cInGameMgr::ChangeScene(eInGameScene nextScene) {
	next_Sceneflag = nextScene;
}


