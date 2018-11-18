 #include "ShotMgr.h"
#include "DXlib.h"

//Templateクラスの実装

//コンストラクタ(初期化)
cShotMgr::cShotMgr() {
	enemyShot = new cShot[20];
	playerShot = new cShot[2];
	totalShot = 0;
	shotRate = 0;
	/*checkGr=*/LoadDivGraph("../resource/Image/Galaga_OBJ_bullet.png",4,4,0,10,12,ShotGrHandle);
	/*if (checkGr == -1){
		DrawFormatString(420, 600, GetColor(255, 0, 255), "画像が読み込めませんでした");
		WaitKey();
	}
	else{
		DrawFormatString(420, 600, GetColor(255, 0, 255), "%d",checkGr);
		WaitKey();
	}*/
}

int cShotMgr::Update() {
	for (int i = 0; i < sizeof(enemyShot) / sizeof*(enemyShot); i++) {
		enemyShot[i].Update();
	}
	for (int i = 0; i < sizeof(playerShot) / sizeof*(playerShot); i++) {
		playerShot[i].Update();
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == TRUE&&shotRate==0) {
		for (int i = 0; i < sizeof*(playerShot); i++) {
			if( playerShot[i].Get_OnActive() == false) {
				playerShot[i].Set_OnActive(TRUE);//0=false,1=true
				//プレイヤーの座標を受け取って座標をセット
				sOBJPos tmp;
				tmp = cPlayer::Instance()->GetPlayer(0);
				playerShot[i].Set_ShotX(tmp.pos.x);
				playerShot[i].Set_ShotY(tmp.pos.y);
				playerShot[i].Set_ShotRad(0);
				totalShot++;
				shotRate = 30;
				break;
			}
		}
	}
	shotRate--;
	if (shotRate < 0) shotRate = 0;
	return 0;
}

int cShotMgr::Draw() {
	for (int i = 0; i < sizeof(enemyShot) / sizeof*(enemyShot); i++) {
		enemyShot[i].Draw(ENEMY,ShotGrHandle);
	}
	for (int i = 0; i < sizeof(playerShot) / sizeof*(playerShot); i++) {
		playerShot[i].Draw(PLAYER,ShotGrHandle);
	}
	DrawFormatString(420,500,GetColor(255,0,255),"totalShot:%d",totalShot);
	DrawFormatString(420, 525, GetColor(255, 0, 255), "pShot1:%d", playerShot[0].Get_OnActive());
	DrawFormatString(420, 550, GetColor(255, 0, 255), "pShot2:%d", playerShot[1].Get_OnActive());
	return 0;
}

//弾を消す処理
int cShotMgr::Break(int type,int num) {
	if (type == PLAYER) {
		playerShot[num].Set_OnActive(FALSE);
	}
	else if (type == ENEMY) {
		enemyShot[num].Set_OnActive(FALSE);
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