#include "InGameController.h"
#include "InGameMgr.h"
#include "WinBox.h"
#include "Player.h"
#include "Interface.h"
#include "SceneMgr.h"

cInGameController::cInGameController() {}

//ゲームが始まる前のあのシーン
int cInGameController::BeforeSceneUpdate() {
	count++;
	if (count > 180) {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eInGame);
		count = 0;
	}
	return 0;
}

int cInGameController::BeforeSceneDraw() {
	DrawFormatString(0, 40, GetColor(255,255,255),"%d",count);
	if (count < 90 && count > 0) {
		DrawFormatString(400, 400, GetColor(255, 255, 255), "Stage %d", nowStageNum);
	}
	else {
		DrawFormatString(400, 400, GetColor(255, 255, 255), "READY");
	}
	return 0;
}

//プレイヤー死亡
int cInGameController::PlayerDeath() {
	if (cPlayer::Instance()->GetPlayerHP() < 0) {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eResult);
	}
	else {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eDeath);
	}
	cEnemyMgr::Instance()->SetChoiseOrderFlag(false);
	//ReportBox("プレイヤーが死んだんじゃ\n敵は止まりません。");
	return 0;
}
int cInGameController::PlayerDeathUpdate() {
	//エフェクトを出す
	//エフェクトが出終わったらREADY表示
	//プレイヤーを再配置
	cEnemyMgr::Instance()->Update();
	//全てのエネミーが移動が終わっているかを獲得
	if (cEnemyMgr::Instance()->GetEnemyStay() == 0) {

	}
	else {
		count++;
		if (count == 10) {
			cPlayer::Instance()->PlayerRevive();
		}
		if (count > 120) {
			cEnemyMgr::Instance()->SetChoiseOrderFlag(true);
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
int cInGameController::ResultUpdate() {
	if (cInterface::Instance()->Get_Input(InDECISION) == 1) {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eBefore);
		cSceneMgr::Instance()->ChangeScene(eStartMenu);
		nowStageNum = 1;
		cScore::Instance()->ResetScore();
		cEnemyMgr::Instance()->Init();
		cPlayer::Instance()->Init();
		cShotMgr::Instance()->Init();
	}
	return 0;
}
int cInGameController::ResultDraw() {
	DrawFormatString(400, 400, GetColor(255, 0, 0), "RESULT");
	DrawFormatString(400, 440, GetColor(255, 255, 255), "調節中");
	DrawFormatString(400, 460, GetColor(255, 255, 255), "スペースキーでタイトルへ戻るだけ");
	return 0;
}


//次のステージへ
int cInGameController::NextStage() {
	nowStageNum++;
	cInGameMgr::Instance()->ChangeScene(cInGameMgr::eBefore);
	return 0;
}



