#include "EnemyMgr.h"
#include <Dxlib.h>
#include <math.h>

//コンストラクタ
cEnemyMgr::cEnemyMgr() {
	memset(waveflag, 0x00, sizeof(waveflag));
	wave = 1;
	fileEndFlag = 0;
	n = 0;
	num = 0;
	strcpy(StageFilePath, "Stage_1.csv");

	//Stage_1.csv
	StageHandle = FileRead_open(StageFilePath);
	if (StageHandle == 0);  //エラー処理の記入途中

	//最初の二行　読み飛ばす　処理　
	for (int i = 0; i < 2; i++)while (FileRead_getc(StageHandle) != '\n');

	//ファイルの読み取り処理(breakでwhile文を抜ける処理なので条件式は1に設定されている)

	while (1) {

		for (int i = 0; i < 64; i++) {
			inputc[i] = input[i] = FileRead_getc(StageHandle);
			if (inputc[i] == '/') {
				while (FileRead_getc(StageHandle) != '\n');//改行までループ
				i = -1; //カウンタを最初に戻す
				continue;
			}
			if (input[i] == ',' || input[i] == '\n') {
				inputc[i] = '\0';
				break;
			}
			if (input[i] == EOF) {
				fileEndFlag = 1;
				break;
			}
		}
		//ファイル終了処理フラグが立っている場合は以下の処理を行わない
		if (fileEndFlag == 1)break;
		switch (num) {
		case 0: enemy[n].pos.x = atof(inputc); break;
		case 1: enemy[n].pos.y = atof(inputc); break;
			//case 2: enemy[n].v.x = atof(inputc); break;	        //ここ
			//case 3: enemy[n].v.y = atof(inputc); break;	        //ここ
		case 2: enemy[n].r = atoi(inputc); break;
		case 3: enemy[n].count = atoi(inputc); break;
		case 4: enemy[n].angle = atof(inputc); break;
		case 5: enemy[n].speed = atoi(inputc); break;
			//case 8: enemy[n].moveflag = atoi(inputc); break;   	//ここ
		case 6: enemy[n].maxmove = atoi(inputc); break;
		case 7:enemy[n].RLflag = atoi(inputc); break;
		case 8:enemy[n].target.x = atof(inputc); break;
		case 9:enemy[n].target.y = atof(inputc); break;
		case 10:enemy[n].targetr = atoi(inputc); break;
		case 11:enemy[n].wave = atoi(inputc); break;	        //追加
		case 12:enemy[n].moveangle[0] = atof(inputc); break;	//ここ
		case 13:enemy[n].countflag[0] = atoi(inputc); break;	//ここ
		case 14:enemy[n].moveangle[1] = atof(inputc); break;	//ここ
		case 15:enemy[n].countflag[1] = atoi(inputc); break;	//ここ
		case 16:enemy[n].moveangle[2] = atof(inputc); break;	//ここ
		case 17:enemy[n].countflag[2] = atoi(inputc); break;	//ここ

		//case 16:enemy[n].onactive = atoi(inputc); break;	    //ここ
		//case 17:enemy[n].item_n[5] = atoi(inputc); break;
		}
		enemy[n].v.x = 0;
		enemy[n].v.y = 0;
		enemy[n].moveflag = 0;
		enemy[n].onactive = 0;
		num++;
		if (num = 18) {
			num = 0;
			n++;
		}
	}

	//ファイルを閉じるぅ
	FileRead_close(StageHandle);

	//waveflagの初期化　これするとwaveflag内に該当waveで何体敵が出現するかを把握できる
	for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++){
	waveflag[enemy[i].wave]++;
}


	/*
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
	
	//movetype = 1;  //敵の動作タイプ(ぐるーってなるやつかぎゅいーんってなるやつか)

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
	*/
}

//デコンストラクタ
cEnemyMgr::~cEnemyMgr() {

}


//計算処理
void cEnemyMgr::Update() {
	for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
		if (enemy[i].wave == wave) {
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
				enemy[i].angle += enemy[i].moveangle[enemy[i].moveflag] * 3.1415 / 180;

				//敵を動かす処理(別途関数で行う)
				Move(enemy[i]);
				//片方の列を左または右にずらす
				//if (i % 2 == 1) Shifted(enemy[i], enemy[i - 1]);
				if (enemy[i].RLflag != 0)	Shifted(enemy[i], enemy[i - 1]);

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
		} //activeなエネミーの動作処理終了
		if (enemy[i].moveflag == 11) {
			Phaseflag++;
		}
		  //ウェーブ内で入場行動が終了している敵の数をカウントする
		  if (enemy[i].wave == wave) {
		  	wavecount++;
		  }
		  //ウェーブごとに動く敵の数と入場行動が終了している敵の数が一致している場合、次ウェーブに移行,敵のカウントが初期化
			if (waveflag[wave] == wavecount) {
				wave++;
				wavecount = 0;
			}

	}//配列数分の敵動作終了



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