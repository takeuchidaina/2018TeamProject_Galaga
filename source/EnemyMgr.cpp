#include <DXlib.h>
#include "EnemyMgr.h"

//コンストラクタ
cEnemyMgr::cEnemyMgr() {
	//敵の配列数分の初期化を行う
	for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
		enemy[i].pos.x = 400;
		enemy[i].pos.y = -50;
		enemy[i].r = 5;
		enemy[i].ang = 100 * 3.14159265 / 180;
		enemy[i].speed = 3;
		enemy[i].moveflag = 0;
		enemy[i].maxmove = 3;
		enemy[i].moveangle[0] = 0.5;
		enemy[i].moveangle[1] = 0;
		enemy[i].moveangle[2] = -2.5;
		enemy[i].countflag[0] = 90;
		enemy[i].countflag[1] = 120;
		enemy[i].countflag[2] = 240;
		enemy[i].RLflag = 1;
		enemy[i].target.x = 320.0;
		enemy[i].target.y = 64.0;
		enemy[i].targetr = 1;
		enemy[i].onactive = 0;
	}
}

//デコンストラクタ
cEnemyMgr::~cEnemyMgr() {

}


//計算処理
void cEnemyMgr::Update() {

}

//描写処理
void cEnemyMgr::Draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "x=%.1lf y=%.1lf",enemy[0].pos.x,enemy[0].pos.y);
	//敵配列の描画
	DrawCircle(enemy[0].pos.x, enemy[0].pos.y, enemy[0].r, GetColor(255, 255, 255), TRUE);
	
}




















