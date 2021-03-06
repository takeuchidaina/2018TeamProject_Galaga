#include <iostream>
#include "DxLib.h"
#include "SceneMgr.h"
#include "Interface.h"
#include "BackGround.h"
#include "SaveLoad.h"

#include "Template.h"
//改良予定


//コンストラクタ
cSceneMgr::cSceneMgr() {
	sceneflag = eStartMenu;
	next_Sceneflag = eSceneNone;
	Init_Module(sceneflag);
	
}

//デコンストラクタ
cSceneMgr::~cSceneMgr() {

}

//指定モジュールの初期化処理
void cSceneMgr::Init_Module(eScene scene) {
	switch (scene) {
	case eStartMenu:
		//スタートメニュー
//		test = new cTemplate;
		break;
	case eInGame:
		//ゲーム画面
//		InGameMgr = new cInGameMgr;
		break;
	case eGameMenu:
		//ゲームメニュー

		break;
	case eResult:
		//リザルト画面

		break;
	}
}

//指定モジュールの終了処理
void cSceneMgr::End_Module(eScene scene) {
	switch (scene) {
	case eStartMenu:
		//スタートメニュー
//		delete test;
		break;
	case eInGame:
		//ゲーム画面
//		delete InGameMgr;
		break;
	case eGameMenu:
		//ゲームメニュー

		break;
	case eResult:
		//リザルト画面

		break;
	}
}




//計算処理
void cSceneMgr::Update() {
	if (next_Sceneflag != eSceneNone) {
		End_Module(sceneflag);
		sceneflag = next_Sceneflag;
		next_Sceneflag = eSceneNone;
		Init_Module(sceneflag);
	}
	cBackGround::Instance()->Update();
	switch (sceneflag) {
	case eStartMenu:
		//スタートメニュー
		if (cInterface::Instance()->Get_Input(InDECISION) == 1) {
			cSE::Instance()->selectSE(gamestart);
			ChangeScene(eInGame);
		}
		cBackGround::Instance()->PauseUpdate();
//		test->Update();
		break;
	case eInGame:
		//ゲーム画面
//		InGameMgr->Update();
		cInGameMgr::Instance()->Update();
		break;
	case eGameMenu:
		//ゲームメニュー

		break;
	case eResult:
		//リザルト画面

		break;
	}
}

//描画処理
void cSceneMgr::Draw() {
	cBackGround::Instance()->Draw();
	switch (sceneflag) {
	case eStartMenu:
		//スタートメニュー
//		DrawFormatString(0, 0, GetColor(255, 255, 255), "SceneMgr StartMenu");
		//DrawFormatString(300, 400, GetColor(255, 255, 255), "Please press Space key");
		cTitle::Instance()->Draw();
//		test->Draw();
		break;
	case eInGame:
		//ゲーム画面
//		InGameMgr->Draw();
		cInGameMgr::Instance()->Draw();
//		DrawFormatString(0, 0, GetColor(255, 255, 255), "SceneMgr InGame");
		break;
	case eGameMenu:
		//ゲームメニュー

		break;
	case eResult:
		//リザルト画面

		break;
	}
	
	cUI::Instance()->UI_Draw();
	cSaveLoad::Instance()->Draw();
	cScore::Instance()->Draw();
}

void cSceneMgr::ChangeScene(eScene nextScene) {
	next_Sceneflag = nextScene;
}

