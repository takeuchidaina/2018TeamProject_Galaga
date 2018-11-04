#include <iostream>
#include "DxLib.h"
#include "Interface.h"
#include "SceneMgr.h"


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
		test = new cTemplate;
		break;
	case eInGame:
		//ゲーム画面
		InGameMgr = new cInGameMgr;
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
		delete test;
		break;
	case eInGame:
		//ゲーム画面
		delete InGameMgr;
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

	switch (sceneflag) {
	case eStartMenu:
		//スタートメニュー
		test->Update();
		break;
	case eInGame:
		//ゲーム画面
		InGameMgr->Update();
		break;
	case eGameMenu:
		//ゲームメニュー

		break;
	case eResult:
		//リザルト画面

		break;
	}

	if (Interface.Get_Input(InRIGHT) != 0) {
		DrawFormatString(0, 0, GetColor(255, 255, 255), "→キーが%dフレーム押されています", Interface.Get_Input(InRIGHT));
	}

}

//描画処理
void cSceneMgr::Draw() {
	switch (sceneflag) {
	case eStartMenu:
		//スタートメニュー
		test->Draw();
		break;
	case eInGame:
		//ゲーム画面
		InGameMgr->Draw();
		break;
	case eGameMenu:
		//ゲームメニュー

		break;
	case eResult:
		//リザルト画面

		break;
	}

}

void cSceneMgr::ChangeScene(eScene nextScene) {
	next_Sceneflag = nextScene;
}

