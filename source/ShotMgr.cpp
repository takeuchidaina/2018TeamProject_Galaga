#define _USE_MATH_DEFINES
#include <math.h>
#include "ShotMgr.h"
#include "DXlib.h"

//Templateクラスの実装

//コンストラクタ(初期化)
cShotMgr::cShotMgr() {
	enemyShot = new cShot[ENEMYSHOTNUM];
	player1Shot = new cShot[PLAYERSHOTNUM];
	player2Shot = new cShot[PLAYERSHOTNUM];
	totalShot = 0;
	shotRate = 0;
	//LoadDivGraph("../resource/Image/Galaga_OBJ_dualFighter.png", 4, 4, 1, 16, 16, ShotGrHandle);
	checkGr = LoadDivGraph("../resource/Image/Galaga_OBJ_bullet.png", 4, 4, 1, 10, 12, ShotGrHandle);
	if (checkGr == -1) {
		ErrBox("Shot画像読み込みエラー");
	}
	//ErrBox("めう");
}

int cShotMgr::Update() {
	for (int i = 0; i < ENEMYSHOTNUM; i++) {
		enemyShot[i].Update();
	}
	for (int i = 0; i < PLAYERSHOTNUM; i++) {
		player1Shot[i].Update();
		player2Shot[i].Update();
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == TRUE) {
		if (cPlayer::Instance()->GetDoubleFlg()==0) {
			for (int i = 0; i < PLAYERSHOTNUM; i++) {
				if (player1Shot[i].Get_OnActive() == FALSE && shotRate == 0) {
					player1Shot[i].Set_OnActive(TRUE);//0=false,1=true
					//プレイヤーの座標を受け取って座標をセット
					sOBJPos tmp;
					tmp = cPlayer::Instance()->GetPlayer(0);
					player1Shot[i].Set_ShotCX(tmp.cx-6);
					player1Shot[i].Set_ShotCY(tmp.cy-6);
					player1Shot[i].Set_ShotRad(M_PI * 270 / 180);//上
					totalShot++;
					shotRate = 6;
				}
			}
		}
		//二機の場合
		else if (cPlayer::Instance()->GetDoubleFlg() == 1) {
			for (int i = 0; i < PLAYERSHOTNUM; i++) {
				if (player1Shot[i].Get_OnActive() == FALSE && shotRate == 0) {
					player1Shot[i].Set_OnActive(TRUE);//0=false,1=true
					//プレイヤーの座標を受け取って座標をセット
					sOBJPos tmp;
					tmp = cPlayer::Instance()->GetPlayer(0);
					player1Shot[i].Set_ShotCX(tmp.cx-6);
					player1Shot[i].Set_ShotCY(tmp.cy-6);
					player1Shot[i].Set_ShotRad(M_PI * 270 / 180);//上
					totalShot+=2;
					player2Shot[i].Set_OnActive(TRUE);//0=false,1=true
					 //プレイヤーの座標を受け取って座標をセット
					sOBJPos tmp2;
					tmp2 = cPlayer::Instance()->GetPlayer(1);
					player2Shot[i].Set_ShotCX(tmp2.cx-6);
					player2Shot[i].Set_ShotCY(tmp2.cy-6);
					player2Shot[i].Set_ShotRad(M_PI * 270 / 180);//上
					totalShot++;
					shotRate = 6;
				}
			}
		}
	}
	shotRate--;
	if (shotRate < 0) shotRate = 0;
	return 0;
}

int cShotMgr::Draw() {
	//デバッグ用
	//DrawExtendGraph(20, 60, 400, 600, ShotGrHandle[3], TRUE);
	for (int i = 0; i < ENEMYSHOTNUM; i++) {
		enemyShot[i].Draw(ENEMY, ShotGrHandle);
	}
	for (int i = 0; i < PLAYERSHOTNUM; i++) {
		player1Shot[i].Draw(PLAYER, ShotGrHandle);
		player2Shot[i].Draw(PLAYER, ShotGrHandle);
	}

#ifdef PLAYER_SHOT_DEBUG
	DrawFormatString(20, 500, GetColor(255, 0, 255), "totalShot:%d", totalShot);
	DrawFormatString(20, 525, GetColor(255, 0, 255), "pShot1:%d", player1Shot[0].Get_OnActive());
	DrawFormatString(20, 550, GetColor(255, 0, 255), "pShot2:%d", player1Shot[1].Get_OnActive());
	DrawFormatString(20, 575, GetColor(255, 0, 255), "pcx1:%.1lf", player1Shot[0].Get_ShotCX());
	DrawFormatString(20, 600, GetColor(255, 0, 255), "pcy1:%.1lf", player1Shot[0].Get_ShotCY());
	DrawFormatString(20, 625, GetColor(255, 0, 255), "pcx2:%.1lf", player1Shot[1].Get_ShotCX());
	DrawFormatString(20, 650, GetColor(255, 0, 255), "pcy2:%.1lf", player1Shot[1].Get_ShotCY());
#endif
	return 0;
}

//弾を消す処理
//引数 type=0,1 (player or enemy)、num=何番目の弾か
int cShotMgr::Break(int type, int num) {
	if (type == 0) {
		player1Shot[num].Set_OnActive(FALSE);
		player2Shot[num].Set_OnActive(FALSE);
	}else if (type == 1) {
		enemyShot[num].Set_OnActive(FALSE);
	}
	return 0;
}

//敵の弾撃つ処理
//引数enemyX,enemyY
int cShotMgr::EnemyShot(double tmpEX, double tmpEY) {
	sOBJPos tmpPlayer;
	double rad;
	tmpPlayer = cPlayer::Instance()->GetPlayer(0);
	//処理
	for (int i = 0; i < ENEMYSHOTNUM; i++) {
		if (enemyShot[i].Get_OnActive() == FALSE) {
			enemyShot[i].Set_OnActive(TRUE);
			rad = atan2(tmpPlayer.cy - tmpEY, tmpPlayer.cx - tmpEX);
			enemyShot[i].Set_ShotCX(tmpEX);
			enemyShot[i].Set_ShotCY(tmpEY);
			enemyShot[i].Set_ShotRad(rad);
			break;
		}
	}
	return 0;
}



/*
//実装例
//mTestへの代入
void cTemplate::Set_Test(int Test) {
mTest = Test;
}

//mTestの獲得
int cTemplate::Get_Test() {
return mTest;
}
*/