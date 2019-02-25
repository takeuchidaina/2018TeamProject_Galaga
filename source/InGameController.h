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
	//ゲーム開始前シーンの更新、描写
	int BeforeSceneUpdate();
	int BeforeSceneDraw();
	
	/*********************************
	関数名：int PlayerDeath(int)
	説明：
	引数：int型 プレイヤーの死因番号　0:残機あり死亡
	戻り値：0:正常　0以外:異常
	**********************************/
	int PlayerDeath(int);
	//プレイヤー死亡シーンの更新、描写
	int PlayerDeathUpdate();
	int PlayerDeathDraw();

	//プレイヤー復活
//	int RevivalSceneUpdate();
//	int RevivalSceneDraw();
	//ポーズ画面
	

	//トラクタービームに当たった時、解放された時の処理
	int HitToTractor();
	int OutToTractor();
	//きゃとられ中の更新、描画
	int TractorSceneUpdate();
	int TractorSceneDraw();

	//プレイヤー帰還
	int InToRevive();
	int OutToRevive();
	int ReviveSceneUpdate();

	//リザルト画面
	int ResultUpdate();
	int ResultDraw();



	//次のステージへ
	int NextStage();


	//現在のステージ数を獲得
	int GetNowStageNum() { return nowStageNum; }
};


#endif