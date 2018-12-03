#include "InGameController.h"
#include "InGameMgr.h"
#include "WinBox.h"

cInGameController::cInGameController() {}

//ゲームが始まる前のあのシーン
int cInGameController::BeforeSceneUpdate() {
	count++;
	if (count > 10) {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eInGame);
		count = 0;
	}
	return 0;
}

int cInGameController::BeforeSceneDraw() {
	DrawFormatString(0, 40, GetColor(255,255,255),"%d",count);
	DrawFormatString(400, 400, GetColor(255, 255, 255), "Stage %d", nowStageNum);
	return 0;
}

//プレイヤー死亡
int cInGameController::PlayerDeath() {
	cInGameMgr::Instance()->ChangeScene(cInGameMgr::eDeath);

	ReportBox("プレイヤーが死んだんじゃ\n敵は止まりません。");
	return 0;
}
int cInGameController::PlayerDeathUpdate() {
	count++;
	//エフェクトを出す
	//エフェクトが出終わったらREADY表示
	//プレイヤーを再配置
	cEnemyMgr::Instance()->Update();
	//全てのエネミーが移動が終わっているかを獲得
	if (cEnemyMgr::Instance()->GetEnemyStay() == 0) {

	}
	else {
		if (count > 120) {
			cInGameMgr::Instance()->ChangeScene(cInGameMgr::eInGame);
			count = 0;
		}
	}

	return 0;
}
int cInGameController::PlayerDeathDraw() {
	if (count > 1) {
		DrawFormatString(400, 400, GetColor(255, 255, 255), "READY");
	}
	return 0;
}



//プレイヤー復活



//ポーズ画面



//きゃとられ中
int cInGameController::HitToTractor() {
	return 0;
}
int cInGameController::TractorSceneUpdate(){
	return 0;
}
int cInGameController::TractorSceneDraw() {
	return 0;
}

//プレイヤー帰還



//リザルト画面



//次のステージへ




