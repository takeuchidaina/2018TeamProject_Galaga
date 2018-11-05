#include "EnemyMgr.h"
#include <Dxlib.h>
#include <math.h>

//コンストラクタ
cEnemyMgr::cEnemyMgr() {
	//敵の配列数分の初期化を行う
	for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
		enemy[i].pos.x = 400;
		enemy[i].pos.y = -50;
		enemy[i].r = 5;
		enemy[i].count = 0 - (i / 2);
		enemy[i].angle = 100 * 3.1415 / 180;
		enemy[i].speed = 3;
		enemy[i].moveflag = 0;
		enemy[i].maxmove = 3;
		memset(enemy[i].moveangle, 0, sizeof(enemy[i].moveangle));
		enemy[i].moveangle[0] = 0.5;
		enemy[i].moveangle[1] = 0;
		enemy[i].moveangle[2] = -2.5;
		memset(enemy[i].countflag, 0, sizeof(enemy[i].countflag));
		enemy[i].countflag[0] = 100;
		enemy[i].countflag[1] = 20;
		enemy[i].countflag[2] = 90;
		enemy[i].RLflag = 1;
		enemy[i].target.x = 320 + i / 2 * 32;
		enemy[i].target.y = 64 + (i % 2) * 32;
		enemy[i].targetr = 1;
		enemy[i].onactive = 0;
	}
	
	movetype = 1;  //敵の動作タイプ(ぐるーってなるやつかぎゅいーんってなるやつか)

	if (movetype == 1) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (i < 8) {
				enemy[i].count = 0 - (i % 8 / 2) * 20;
				enemy[i].target.x = 160 + 32 + (i + 8) / 2 * 32;
				continue;
			}
			enemy[i].pos.x = 240;
			enemy[i].angle = 80 * 3.1415 / 180;
			enemy[i].count = 0 - (i % 8 / 2) * 20;
			enemy[i].moveangle[0] = -0.5;
			enemy[i].moveangle[1] = 0;
			enemy[i].moveangle[2] = 2.5;
			enemy[i].RLflag = -1;
			enemy[i].target.x = 320 - 32 - (i - 8) / 2 * 32;
		}
	}
}

//デコンストラクタ
cEnemyMgr::~cEnemyMgr() {

}


//計算処理
void cEnemyMgr::Update() {

	for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
		//毎フレームカウントを増やす
		enemy[i].count++;
		//カウントが0より多ければ、敵の表示判定をtrue(1)にする
		if (enemy[i].count > 0) {
			enemy[i].onactive = 1;
		}
		//敵の発生判定がtrueでない場合は以降の処理を無視(continue)してiを加算する
		if (enemy[i].onactive != 1)continue;
		
		//moveflagが10になるまで下記の処理を行う
		if (enemy[i].moveflag < 10) {
		    
			//敵の角度を加算する(ラジアン単位)
			enemy[i].angle += enemy[i].moveangle[enemy[i].moveflag]*3.1415/180;

			//敵を動かす処理(別途関数で行う)
			Move(enemy[i]);
			//片方の列を左または右にずらす
			if (i % 2 == 1) Shifted(enemy[i], enemy[i - 1]);

			//一定のフレーム数になったら次の動作へ移行する
			if (enemy[i].countflag[enemy[i].moveflag] == enemy[i].count) {
				enemy[i].moveflag++;
				//フレームカウントをリセットする
				enemy[i].count = 0;
				//moveflagがmaxmove(3)になったらmoveflagを10にして例外処理へ移行
				if (enemy[i].moveflag == enemy[i].maxmove) {
					enemy[i].moveflag = 10;
				}
			}
		} //敵一体ごとの入場動作終了
		//moveflagが10になった場合、目標位置まで移動
			if (enemy[i].moveflag == 10) {
				enemy[i].angle = atan2(enemy[i].target.y - enemy[i].pos.y, enemy[i].target.x - enemy[i].pos.x); 
				Move(enemy[i]);
				if ((enemy[i].target.x - enemy[i].pos.x)*(enemy[i].target.x - enemy[i].pos.x) +
					(enemy[i].target.y - enemy[i].pos.y)*(enemy[i].target.y - enemy[i].pos.y) <=
					(enemy[i].r - 3 + enemy[i].targetr)*(enemy[i].r - 3 + enemy[i].targetr)) {
					enemy[i].pos.x = enemy[i].target.x;
					enemy[i].pos.y = enemy[i].target.y;
					enemy[i].moveflag++;
					enemy[i].count = 0;
				}
				/*else {
					enemy[i].pos.x = enemy[i].target.x;
					enemy[i].pos.y = enemy[i].target.y;
				}*/
		    } //例外処理終了
	} //配列数分の敵動作終了

}

	void cEnemyMgr::Move(sEnemy& enemy) {
		//角度から動く方向の座標を計算する
		enemy.v.x = cos(enemy.angle);
		enemy.v.y = sin(enemy.angle);

		//座標に移動方向と速度を加算させる
		enemy.pos.x += enemy.v.x * enemy.speed;
		enemy.pos.y += enemy.v.y * enemy.speed;
	}

	//二列目の敵を横にずらす
	void cEnemyMgr::Shifted(sEnemy& ene1, sEnemy& ene2) {
		//一列目の座標に二列目の敵の座標をコピーする
		ene1.pos.x = ene2.pos.x;
		ene1.pos.y = ene2.pos.y;

		//進行方向(angle)に対して90度の角度(RLflag)で30ドットずらす(*30)
		ene1.pos.x += cos(ene1.angle + 90 * 3.1415 / 180 * ene1.RLflag) * 30;
		ene1.pos.y += sin(ene1.angle + 90 * 3.1415 / 180 * ene1.RLflag) * 30;
	}


//描写処理
void cEnemyMgr::Draw() {
	DrawFormatString(0, 20, GetColor(255, 255, 255), "[0]:x=%.1lf y=%.1lf",enemy[0].pos.x,enemy[0].pos.y);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "[7]:x=%.1lf y=%.1lf", enemy[7].pos.x, enemy[7].pos.y);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "atan2=%.3lf", atan2(enemy[0].target.y - enemy[0].pos.y, enemy[0].target.x - enemy[0].pos.x));
	
	for (int i = 0; i < sizeof(enemy) / sizeof(*enemy); i++) {
		//敵配列の描画
		if (i % 2 == 0) {
			DrawCircle(enemy[i].pos.x, enemy[i].pos.y, enemy[i].r, GetColor(255, 255, 255), TRUE);
		}
		else {
			DrawCircle(enemy[i].pos.x, enemy[i].pos.y, enemy[i].r, GetColor(255, 0, 0), TRUE);
		}

	}
}