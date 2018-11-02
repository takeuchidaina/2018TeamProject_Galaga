#include <iostream>
#include "InGameMgr.h"

//コンストラクタ
cInGameMgr::cInGameMgr() {
	sceneflag = eBefore;
	next_Sceneflag = eInGameNone;
	Init_Module(sceneflag);
}

//デコンストラクタ
cInGameMgr::~cInGameMgr() {

}

//指定モジュールの初期化処理
void cInGameMgr::Init_Module(eInGameScene scene) {
	switch (scene) {
	case eBefore:
		//
		break;
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
	case eBefore:
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
	case eBefore:
			//
			break;
	}
}

//描写処理
void cInGameMgr::Draw() {
	switch (sceneflag) {
	case eBefore:
		//
		break;
	}
}

void cInGameMgr::ChangeScene(eInGameScene nextScene) {
	next_Sceneflag = nextScene;
}



















