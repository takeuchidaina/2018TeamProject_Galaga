#include "InGameController.h"
#include "InGameMgr.h"
#include "WinBox.h"
#include "Player.h"
#include "Interface.h"
#include "SceneMgr.h"
#include "TextChange.h"
#include "Score.h"

cInGameController::cInGameController() {}

//ゲームが始まる前のあのシーン
int cInGameController::BeforeSceneUpdate() {
	int deathcount = 0;
	for (int i = 0; i < MAXMACHINE; i++) {	// 表示中のプレイヤーを調べる
		sOBJPos tmp = cPlayer::Instance()->GetPlayer(i);	// プレイヤー情報受取
		if (tmp.onActive == FALSE) deathcount++;
	}
	if (deathcount == MAXMACHINE) {
		cPlayer::Instance()->PlayerRevive();
		cEnemyMgr::Instance()->SetChoiseOrderFlag(true);
		cShotMgr::Instance()->SetShotFlg(true);
	}
	count++;
	if (count > 180) {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eInGame);
		count = 0;
	}
	return 0;
}

int cInGameController::BeforeSceneDraw() {
	//DrawFormatString(0, 40, GetColor(255, 255, 255), "%d", count);
	if (count < 90 && count > 0) {
		char tmp[256];
		snprintf(tmp, 255, "STAGE %d", nowStageNum);
		cTextChange::Instance()->DrawTextImage(350, 400, tmp, eLBlue, eMag48);

		//DrawFormatString(400, 400, GetColor(255, 255, 255), "Stage %d", nowStageNum);
	}
	else {
		cTextChange::Instance()->DrawTextImage(370, 400, "READY", eLBlue, eMag48);
		//DrawFormatString(400, 400, GetColor(255, 255, 255), "READY");
	}
	return 0;
}

//プレイヤー死亡
int cInGameController::PlayerDeath(int type) {
	if (cPlayer::Instance()->GetPlayerHP() < 0) {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eResult);
	}
	else if (type == 0) {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eDeath);
	}
	else {
		cInGameMgr::Instance()->ChangeScene(cInGameMgr::eTractor);
	}
	cEnemyMgr::Instance()->SetChoiseOrderFlag(false);
	cShotMgr::Instance()->SetShotFlg(false);
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
			cShotMgr::Instance()->SetShotFlg(true);
			cInGameMgr::Instance()->ChangeScene(cInGameMgr::eInGame);
			count = 0;
		}
	}

	return 0;
}
int cInGameController::PlayerDeathDraw() {
	if (count > 1) {
		cTextChange::Instance()->DrawTextImage(370, 400, "READY", eLBlue, eMag48);
		//DrawFormatString(400, 400, GetColor(255, 255, 255), "READY");
	}
	return 0;
}



//プレイヤー復活
int cInGameController::InToRevive() {
	cInGameMgr::Instance()->ChangeScene(cInGameMgr::eRevival);
	return 0;
}
int cInGameController::OutToRevive() {
	cInGameMgr::Instance()->ChangeScene(cInGameMgr::eInGame);
	return 0;
}

int cInGameController::ReviveSceneUpdate() {
	//エフェクトを出す
	//エフェクトが出終わったらREADY表示
	//プレイヤーを再配置

	//全てのエネミーが移動が終わっているかを獲得
	static cPlayerEnemy *pEnemy = NULL;


		pEnemy = cEnemyMgr::Instance()->GetPlayerEnemyAdress();
		if(pEnemy == NULL)cInGameMgr::Instance()->ChangeScene(cInGameMgr::eInGame);
	 if (pEnemy != NULL && pEnemy->GetRemoveFlg() == 0)pEnemy->Rolling();


	 if (cSE::Instance()->GetSeActive(rescue) == 0) {
		 cSE::Instance()->selectSE(rescue);
	 }

	cShotMgr::Instance()->SetShotFlg(false);
	cEnemyMgr::Instance()->SetChoiseOrderFlag(false);
	if (cEnemyMgr::Instance()->GetEnemyStay() == 0) {
		cEnemyMgr::Instance()->Update();
	}
	else {
		cPlayer::Instance()->PlayerTractorMove();
		if (pEnemy != NULL) {
			pEnemy->ReviveUpdate();
			//pEnemy->Move();
		}


		if (pEnemy == NULL) {
			cSE::Instance()->StopSound(rescue);
			cShotMgr::Instance()->SetShotFlg(true);
			cEnemyMgr::Instance()->SetChoiseOrderFlag(true);
			cInGameMgr::Instance()->ChangeScene(cInGameMgr::eInGame);

		}
	}

	return 0;
}

//ポーズ画面



//きゃとられ中
int cInGameController::HitToTractor() {
	cInGameMgr::Instance()->ChangeScene(cInGameMgr::eTractor);
	return 0;
}
int cInGameController::OutToTractor() {
	cInGameMgr::Instance()->ChangeScene(cInGameMgr::eDeath);
	return 0;
}
int cInGameController::TractorSceneUpdate() {
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
		cHit::Instance()->ResetHit();
		cEnemyMgr::Instance()->EndIt();
		cEnemyMgr::Instance()->Init();
		cPlayer::Instance()->Init();
		cShotMgr::Instance()->Init();
	}
	return 0;
}
int cInGameController::ResultDraw() {
	cScore::Instance()->Result();
	return 0;
}


//次のステージへ
int cInGameController::NextStage() {
	if (cInGameMgr::Instance()->GetSceneFlg() == cInGameMgr::eDeath) {

	}
	nowStageNum++;
	cInGameMgr::Instance()->ChangeScene(cInGameMgr::eBefore);
	return 0;
}



