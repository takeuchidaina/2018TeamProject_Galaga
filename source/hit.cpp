#include <DxLib.h>
#include"hit.h"
#include "WinBox.h"


/* コンストラクタ */
cHit::cHit() {

	TractorHitFlg = false;

}

/* デストラクタ *
cHitFunc::~cHitFunc() {

}*/

void cHit::Update() {

	cHit::Player_EnemyShot();		// 自機と敵弾
	cHit::Player_Enemy();			// 自機と敵機
	cHit::PlayerShot_Enemy();		// 自弾と敵機
	cHit::PlayerShot_EnemyPlayer();	// 自弾と自敵機
	cHit::Player_EnemyPlayer();		// 自機と自敵機

}

void cHit::Draw() {
	//cHit::Debug();
}


void cHit::Player_EnemyShot() {

	for (int i = 0; i < MAXMACHINE; i++) {

		Player = cPlayer::Instance()->GetPlayer(i);

		if (Player.onActive == FALSE) continue;

		for (int j = 0; j < ENEMYSHOTNUM; j++) {

			S_onActive = cShotMgr::Instance()->GetEnemyShotOnActive(j);
			S_cx = cShotMgr::Instance()->GetEnemyShotCX(j);
			S_cy = cShotMgr::Instance()->GetEnemyShotCY(j);
			S_r = cShotMgr::Instance()->GetEnemyShotR(j);

			if (S_onActive == FALSE) continue;

			len = ((S_cx - Player.cx) * (S_cx - Player.cx)) + ((S_cy - Player.cy)*(S_cy - Player.cy));

			if (len <= ((S_r + Player.r) * (S_r + Player.r))) {

				if (cPlayer::Instance()->GetDoubleFlg() == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}

				else {
					cPlayer::Instance()->Break(eDeath, i);
					cShotMgr::Instance()->Break(ENEMY, j);
				}

				cSE::Instance()->selectSE(miss);
				cEffectMgr::Instance()->Blowup(PLAYER, Player.cx, Player.cy);
			}
		}
	}
}


void cHit::Player_Enemy() {

	static int maxEnemy = cEnemyMgr::Instance()->GetMaxEnemy();

	for (int i = 0; i < MAXMACHINE; i++) {

		Player = cPlayer::Instance()->GetPlayer(i);

		if (Player.onActive == FALSE) continue;

		for (int j = 0; j < maxEnemy; j++) {

			E_onActive = cEnemyMgr::Instance()->GetEnemyonActive(j);
			E_cx = cEnemyMgr::Instance()->GetEnemyPosX(j);
			E_cy = cEnemyMgr::Instance()->GetEnemyPosY(j);
			E_r = cEnemyMgr::Instance()->GetEnemyPosR(j);

			if (E_onActive == FALSE) continue;

			len = (E_cx - Player.cx)*(E_cx - Player.cx) + (E_cy - Player.cy + 5.0)*(E_cy - Player.cy + 5.0);

			if (len <= ((E_r + Player.r)*(E_r + Player.r))) {

				if (cPlayer::Instance()->GetDoubleFlg() == TRUE) {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Instance()->SetEnemyDeath(j);
				}

				else {
					cPlayer::Instance()->Break(eDeath, i);
					cEnemyMgr::Instance()->SetEnemyDeath(j);
				}

				cSE::Instance()->selectSE(miss);
				cEffectMgr::Instance()->Blowup(PLAYER, Player.cx, Player.cy);
			}
		}
	}

}

void cHit::PlayerShot_Enemy() {

	static int maxEnemy = cEnemyMgr::Instance()->GetMaxEnemy();

	for (int i = 0; i < maxEnemy; i++) {

		E_onActive = cEnemyMgr::Instance()->GetEnemyonActive(i);
		E_cx = cEnemyMgr::Instance()->GetEnemyPosX(i);
		E_cy = cEnemyMgr::Instance()->GetEnemyPosY(i);
		E_r = cEnemyMgr::Instance()->GetEnemyPosR(i);
		E_tractingFlg = cEnemyMgr::Instance()->GetTractingFlg(i);
		E_moveFlg = cEnemyMgr::Instance()->GetEnemyonActive(i);

		if (E_onActive == FALSE) continue;

		for (int j = 0; j < PLAYERSHOTNUM; j++) {
			for (int k = 0; k < 2; k++) {

				S_onActive = cShotMgr::Instance()->GetPlayerShotOnActive(j, k);
				S_cx = cShotMgr::Instance()->GetPlayerShotCX(j, k);
				S_cy = cShotMgr::Instance()->GetPlayerShotCY(j, k);
				S_r = cShotMgr::Instance()->GetPlayerShotR(j, k);

				if (S_onActive == FALSE) continue;

				double len = (S_cx - E_cx)*(S_cx - E_cx) + (S_cy - E_cy)*(S_cy - E_cy);

				if (len <= ((E_r + S_r)*(E_r + S_r))) {

					cEnemyMgr::Instance()->DamageEnemyHp(i);
					int E_hp = cEnemyMgr::Instance()->GetEnemyHP(i);
					if (E_hp <= 0) {
						cEnemyMgr::Instance()->SetEnemyDeath(i);
						cEffectMgr::Instance()->Blowup(ENEMY, E_cx, E_cy);
						if (E_tractingFlg == true) {
							if (E_moveFlg == false) {
								cInGameController::Instance()->InToRevive();
							}
							else {
								//cPlayerEnemy::Instanse()->Break();
							}
						}
					}
					cShotMgr::Instance()->Break(PLAYER, k);

					totalHit++;

				}
			}
		}
	}
}


int cHit::TractorHit(sEnemy* enemy) {

	tractorX = enemy->mainpos.pos.x - 96 / 2;
	tractorWidth = enemy->mainpos.pos.x + 90 - 1;

	for (int i = 0; i < MAXMACHINE; i++) {

		Player = cPlayer::Instance()->GetPlayer(i);
		if (Player.onActive == false) continue;

		if (Player.pos.x + 48 >= tractorX && Player.pos.x <= tractorWidth) {

			//ErrBox("当たった");

			player_x = Player.pos.x;
			player_y = Player.pos.y;

			TractorHitFlg = true;

			cInGameController::Instance()->HitToTractor();
			TraitPlayer = cEnemyMgr::Instance()->PushPlayerEnemy();
			TraitPlayer->SetPenemy(enemy);
			cPlayer::Instance()->Break(eTractorBeam, i);

			enemy->moveflg++;
			enemy->tractingEnemy = true;
			enemy->tractorHitFlg = true;

			return TRUE;

		}

	}

	return FALSE;
}

void cHit::PlayerShot_EnemyPlayer() {

	pEnemy = cEnemyMgr::Instance()->GetPlayerEnemyAdress();
	if (pEnemy != NULL) {
		E_cx = pEnemy->GetEnemyX();
		E_cy = pEnemy->GetEnemyY();
		E_r = pEnemy->GetEnemyR();

		unsigned int Cr;
		Cr = GetColor(255, 0, 0);
		DrawCircle(E_cx, E_cy, E_r, Cr, TRUE);
	}

	for (int j = 0; j < PLAYERSHOTNUM; j++) {
		for (int k = 0; k < 2; k++) {

			S_onActive = cShotMgr::Instance()->GetPlayerShotOnActive(j, k);
			S_cx = cShotMgr::Instance()->GetPlayerShotCX(j, k);
			S_cy = cShotMgr::Instance()->GetPlayerShotCY(j, k);
			S_r = cShotMgr::Instance()->GetPlayerShotR(j, k);

			if (S_onActive == FALSE) continue;

			double len = (S_cx - E_cx)*(S_cx - E_cx) + (S_cy - E_cy)*(S_cy - E_cy);

			if (len <= ((E_r + S_r)*(E_r + S_r))) {
				//ErrBox("当たった");
				cEnemyMgr::Instance()->DeletePlayerEnemy();
				cEffectMgr::Instance()->Blowup(ENEMY, E_cx, E_cy);
			}

		}

	}
}

void cHit::Player_EnemyPlayer() {

	pEnemy = cEnemyMgr::Instance()->GetPlayerEnemyAdress();
	if (pEnemy != NULL) {
		E_cx = pEnemy->GetEnemyX();
		E_cy = pEnemy->GetEnemyY();
		E_r = pEnemy->GetEnemyR();
	}

	for (int i = 0; i < MAXMACHINE; i++) {

		Player = cPlayer::Instance()->GetPlayer(i);

		if (Player.onActive == FALSE) continue;

		len = (E_cx - Player.cx)*(E_cx - Player.cx) + (E_cy - Player.cy + 5.0)*(E_cy - Player.cy + 5.0);

		if (len <= ((E_r + Player.r)*(E_r + Player.r))) {

			//ErrBox("当たった");

			if (cPlayer::Instance()->GetDoubleFlg() == TRUE) {
				cPlayer::Instance()->Break(eDeath, i);
				cEnemyMgr::Instance()->DeletePlayerEnemy();
			}

			else {
				cPlayer::Instance()->Break(eDeath, i);
				cEnemyMgr::Instance()->DeletePlayerEnemy();
			}

			cSE::Instance()->selectSE(miss);
			cEffectMgr::Instance()->Blowup(PLAYER, Player.cx, Player.cy);
		}

	}
}

/**********************************************************
関数名：void cHit::Debug
説明：デバッグ用
**********************************************************/
void cHit::Debug() {

	unsigned int Cr;
	Cr = GetColor(255, 0, 0);

	static int maxEnemy = cEnemyMgr::Instance()->GetMaxEnemy();

	// Player
	Player = cPlayer::Instance()->GetPlayer(0);
	DrawCircle(Player.cx + 1.0, Player.cy + 5.0, Player.r, Cr, TRUE);

	// Shot
	for (int j = 0; j < ENEMYSHOTNUM; j++) {

		S_onActive = cShotMgr::Instance()->GetEnemyShotOnActive(j);
		S_cx = cShotMgr::Instance()->GetEnemyShotCX(j);
		S_cy = cShotMgr::Instance()->GetEnemyShotCY(j);
		S_r = cShotMgr::Instance()->GetEnemyShotR(j);

		if (S_onActive == FALSE) continue;

		DrawCircle(S_cx, S_cy, S_r, Cr, TRUE);

	}

	for (int j = 0; j < PLAYERSHOTNUM; j++) {
		for (int k = 0; k < 2; k++) {

			S_onActive = cShotMgr::Instance()->GetPlayerShotOnActive(j, k);
			S_cx = cShotMgr::Instance()->GetPlayerShotCX(j, k);
			S_cy = cShotMgr::Instance()->GetPlayerShotCY(j, k);
			S_r = cShotMgr::Instance()->GetPlayerShotR(j, k);

			if (S_onActive == FALSE) continue;

			DrawCircle(S_cx, S_cy, S_r, Cr, TRUE);

		}
	}

	// Enemy
	for (int j = 0; j < maxEnemy; j++) {

		E_onActive = cEnemyMgr::Instance()->GetEnemyonActive(j);
		E_cx = cEnemyMgr::Instance()->GetEnemyPosX(j);
		E_cy = cEnemyMgr::Instance()->GetEnemyPosY(j);
		E_r = cEnemyMgr::Instance()->GetEnemyPosR(j);

		if (E_onActive == FALSE) continue;

		DrawCircle(E_cx, E_cy, E_r, Cr, TRUE);

	}
}


