#include "EnemyMgr.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <Dxlib.h>
#include "cBaseEnemy.h"
#include "cBlueEnemy.h"
#include "cRedEnemy.h"
#include "cGreenEnemy.h"
#include "Struct.h"
#include "InGameController.h"
#include "Debug.h"

//コンストラクタ
cEnemyMgr::cEnemyMgr() {
	//画像の読み込み処理
	LoadDivGraph("../resource/Image/Galaga_OBJ_enemy1616.png", 20, 5, 4, 16, 16, EnemyGraph);

	Init();
}

void cEnemyMgr::Init() {
	memset(waveflag, 0x00, sizeof(waveflag));
	wave = 1;
	fileEndFlag = 0;
	n = 0;
	num = 0;
	snprintf(StageFilePath, 255, "../resource/MAP/Stage_%d.csv", cInGameController::Instance()->GetNowStageNum());
	//strcpy(StageFilePath, "../resource/MAP/Stage_2.csv");
	Phaseflag = 0;
	onActiveCount = 0;
	Stayflag = 0;
	EnemyAttackFlag = 1;     //攻撃フラグ 0:攻撃を行わない状態 1:攻撃を行う状態
	ChoiseOrderFlag = TRUE;
	
	EnemyDeathCount = 0;

	ScalingFlag = -1;
	ScalingCount = 120;

	SlidingFlag = 1;
	SlidingCount = 120;

	DrawScoreFlag = 0;


	//Stage_1.csv
	StageHandle = FileRead_open(StageFilePath);
	if (StageHandle == 0) {
		//エラー処理の記入途中
		StageHandle = FileRead_open("../resource/MAP/Stage_2.csv");
	}
	//最初の二行　読み飛ばす　処理　
	for (int i = 0; i < 2; i++)while (FileRead_getc(StageHandle) != '\n');

	//ファイルの読み取り処理(breakでwhile文を抜ける処理なので条件式は1に設定されている)
	while (1) {

		for (int i = 0; i < 64; i++) {
			inputc[i] = input[i] = FileRead_getc(StageHandle);//1文字取得する
			if (inputc[i] == '/') {//スラッシュがあれば
				while (FileRead_getc(StageHandle) != '\n');//改行までループ
				i = -1;//カウンタを最初に戻して
				continue;
			}
			if (input[i] == ',' || input[i] == '\n') {//カンマか改行なら
				inputc[i] = '\0';//そこまでを文字列とし
				break;
			}
			if (input[i] == EOF) {//ファイルの終わりなら
				fileEndFlag = 1;//終了
				break;
			}
		}

		//ファイル終了処理フラグが立っている場合は以下の処理を行わない
		if (fileEndFlag == 1)break;
		switch (num) {
		case Posx: tmpEnemy.pos.x = atof(inputc); break;
		case Posy: tmpEnemy.pos.y = atof(inputc); break;
		case Radius: tmpEnemy.r = atoi(inputc); break;
		case Count: tmpEnemy.count = atoi(inputc); break;
		case Angle: tmpEnemy.angle = atof(inputc)* M_PI / 180; break;
		case Speed: tmpEnemy.speed = atoi(inputc); break;
		case Maxmove: tmpEnemy.maxmove = atoi(inputc); break;
		case RLflag:tmpEnemy.RLflag = atoi(inputc); break;
		case Targetx:tmpEnemy.target.x = atof(inputc); break;
		case Targety:tmpEnemy.target.y = atof(inputc); break;
		case Targetr:tmpEnemy.targetr = atoi(inputc); break;
		case Wave:tmpEnemy.wave = atoi(inputc); break;
		case Etype:tmpEnemy.etype = atoi(inputc); break;
		case Shaftx:tmpEnemy.shaft.x = atoi(inputc); break;
		case Shafty:tmpEnemy.shaft.y = atoi(inputc); break;
		case FirstMoveangle:tmpEnemy.moveangle[0] = atof(inputc); break;
		case FirstCountflag:tmpEnemy.countflag[0] = atoi(inputc); break;
		case SecondMoveangle:tmpEnemy.moveangle[1] = atof(inputc); break;
		case SecondCountflag:tmpEnemy.countflag[1] = atoi(inputc); break;
		case ThirdMoveangle:tmpEnemy.moveangle[2] = atof(inputc); break;
		case ThirdCountflag:tmpEnemy.countflag[2] = atoi(inputc); break;
		}

		switch (num) {
		case Posx: enemy[n].pos.x = atof(inputc); break;
		case Posy: enemy[n].pos.y = atof(inputc); break;
		case Radius: enemy[n].r = atoi(inputc); break;
		case Count: enemy[n].count = atoi(inputc); break;
		case Angle: enemy[n].angle = atof(inputc) *M_PI / 180; break;
		case Speed: enemy[n].speed = atoi(inputc); break;
		case Maxmove: enemy[n].maxmove = atoi(inputc); break;
		case RLflag:enemy[n].RLflag = atoi(inputc); break;
		case Targetx:enemy[n].target.x = atof(inputc); break;
		case Targety:enemy[n].target.y = atof(inputc); break;
		case Targetr:enemy[n].targetr = atoi(inputc); break;
		case Wave:enemy[n].wave = atoi(inputc); break;
		case Etype:enemy[n].etype = atoi(inputc); break;
		case Shaftx:enemy[n].shaft.x = atoi(inputc); break;
		case Shafty:enemy[n].shaft.y = atoi(inputc); break;
		case FirstMoveangle:enemy[n].moveangle[0] = atof(inputc); break;
		case FirstCountflag:enemy[n].countflag[0] = atoi(inputc); break;
		case SecondMoveangle:enemy[n].moveangle[1] = atof(inputc); break;
		case SecondCountflag:enemy[n].countflag[1] = atoi(inputc); break;
		case ThirdMoveangle:enemy[n].moveangle[2] = atof(inputc); break;
		case ThirdCountflag:enemy[n].countflag[2] = atoi(inputc); break;
		}

		//同じ値で初期化する変数
		enemy[n].v.x = 0;
		enemy[n].v.y = 0;
		enemy[n].moveflag = 0;
		enemy[n].onactive = FALSE;
		enemy[n].deathflag = FALSE;

		num++;
		if (num == 21) {
			num = 0;
			/*switch文でtypeをみて,結果に合わせてtmpEnemyのデータをそれぞれのcbaseEnemyにいれる*/
			switch (tmpEnemy.etype) {
			case 0:
				enemies[n] = (cBaseEnemy*) new cBlueEnemy(tmpEnemy.pos.x, tmpEnemy.pos.y, tmpEnemy.r, tmpEnemy.count, tmpEnemy.speed, tmpEnemy.angle, tmpEnemy.onactive, EnemyGraph);
				break;
			case 1:
				enemies[n] = (cBaseEnemy*) new cRedEnemy(tmpEnemy.pos.x, tmpEnemy.pos.y, tmpEnemy.r, tmpEnemy.count, tmpEnemy.speed, tmpEnemy.angle, tmpEnemy.onactive, EnemyGraph);
				break;
			case 2:
				enemies[n] = (cBaseEnemy*) new cGreenEnemy(tmpEnemy.pos.x, tmpEnemy.pos.y, tmpEnemy.r, tmpEnemy.count, tmpEnemy.speed, tmpEnemy.angle, tmpEnemy.onactive, EnemyGraph);
				break;

				/*case3:playerが敵になった時の処理を入れよう*/

			}
			n++;
		}
	}

	//ファイルを閉じる
	FileRead_close(StageHandle);

	//waveflagの初期化　これするとwaveflag内に該当waveで何体敵が出現するかを把握できる
	for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
		waveflag[enemy[i].wave]++;
	}

	if (pEnemy != NULL) {
		DeletePlayerEnemy();
		pEnemy = NULL;
	}

}

//デコンストラクタ
//cEnemyMgr::~cEnemyMgr() {

//}


//計算処理
void cEnemyMgr::Update() {
	phaseFlagCount = 0;
	wavecount = 0;
	onActiveCount = 0;
	SlidingCount++;
	ScalingCount++;

	if (Phaseflag == 0) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			//敵の横移動処理
			Sliding(enemy[i]);
			if (enemy[i].wave == wave) {
				//毎フレームカウントを増やす
				enemy[i].count++;
				//カウントが0より多ければ、敵の表示判定をtrue(1)にする
				if (enemy[i].count > 0) {
					enemy[i].onactive = TRUE;
				}
				//敵の発生判定がtrueでない場合は以降の処理を無視(continue)してiを加算する
				if (enemy[i].onactive != TRUE)continue;

				onActiveCount++;

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
						(enemy[i].r /5 + enemy[i].targetr)*(enemy[i].r /5 + enemy[i].targetr)) {
						enemy[i].pos.x = enemy[i].target.x;
						enemy[i].pos.y = enemy[i].target.y;
						enemy[i].moveflag++;
						enemy[i].count = 0;
						enemy[i].angle = -90 * M_PI / 180;
					}
				} //例外処理終了
			} //activeなエネミーの動作処理終了

			if (enemy[i].moveflag == 11) {

				enemy[i].pos.x = enemy[i].target.x;
				//enemy[i].pos.y = enemy[i].target.y;

				//入場行動が終了している敵の数をカウントする
				phaseFlagCount++;
				//ウェーブ内で入場行動が終了している敵の数をカウントする
				if (enemy[i].wave == wave) {
					wavecount++;
				}
			}
			//ウェーブごとに動く敵の数と入場行動が終了している敵の数が一致している場合、次ウェーブに移行,敵のカウントが初期化
			if (waveflag[wave] == wavecount) {
				wave++;
				wavecount = 0;
			}

			//クラスのEnemy配列のi番目にクラスでないほうのEnemy(sEnemyMgrData)を代入する
			enemies[i]->SetEnemyX(enemy[i].pos.x);
			enemies[i]->SetEnemyY(enemy[i].pos.y);
			enemies[i]->SetEnemyAngle(enemy[i].angle);

		}//配列数分の敵動作終了
		
		 //敵が動いていないフラグをonにする
		Stayflag = 1;
	}
	else {

		//Phaseflagが1の場合
		if (Phaseflag == 1) {

     		//Stayflagをfalseにする
			Stayflag = 0;

		    //phaseflagを2にする
		    Phaseflag = 2;

			//EnemyのAttackflagをtrueにする
			enemies[GetRand(39)]->SetEnemyAttackflg();
		}
	}
	if (wave == 10 && Phaseflag == 0) {
		Phaseflag = 1;
	}
	if (Phaseflag == 2) {
		Stayflag = 0;
		ReChoiceFlag = 1;

		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {

			Scaling(enemy[i]);

			if (enemies[i]->GetEnemyAttackflg() != 1) {

				enemy[i].pos.x = enemy[i].target.x;
				enemy[i].pos.y = enemy[i].target.y;

				enemies[i]->SetEnemyX(enemy[i].pos.x);
				enemies[i]->SetEnemyY(enemy[i].pos.y);
			}

			//敵が非表示もしくは攻撃中ではないときもしくは敵が死んでいるときは以下の処理を飛ばす
			if (enemy[i].onactive != TRUE || enemies[i]->GetEnemyAttackflg() != 1 || enemy[i].deathflag == TRUE) {
				continue;
			}

			enemies[i]->Update();
			enemies[i]->Move();
			if (enemies[i]->GetTractorfFlg() == true) {
				enemies[i]->TractorUpdate();
			}

			if (pEnemy != NULL) {
				pEnemy->Move();
				pEnemy->Update();
			}
		}
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (enemy[i].onactive != TRUE || enemies[i]->GetEnemyChoiseOrder() != 1 || enemy[i].deathflag == TRUE)continue;
			
			ReChoiceFlag = 0;
		
		}

			//再抽選
				//再抽選フラグがTRUEになっているもしくは敵が死んでいる場合は敵の再抽選を行う
			if (ReChoiceFlag == 1 && ChoiseOrderFlag == TRUE) {
				int debug = 0;		
				while (1) {
					debug++;
					int tmp = GetRand(39);
					if (enemy[tmp].deathflag != TRUE) {
						enemies[tmp]->SetEnemyAttackflg();
						break;
					}
					if (debug == 1000) {
						ErrBox("えねみーまねーじゃー\n無限ループってこわくね");
						break;
					}

					int tmpcount = 0;
					for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
						if (enemy[i].deathflag == true)tmpcount++;
					}

					if (tmpcount == sizeof(enemy) / sizeof*(enemy)) {
						cInGameController::Instance()->NextStage();
						EndIt();
						Init();
						return;
					}

				}
			}
			else if (ReChoiceFlag == 1 && ChoiseOrderFlag == FALSE) {
				Stayflag = 1;
			}
		
	}

	for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
		enemies[i]->AnimationCount();
	}

	if (EnemyDeathCount == GetMaxEnemy()) {
		//InGameControllerの全滅報告関数を呼び出す
		cInGameController::Instance()->NextStage();
		EndIt();
		Init();
		return;
	}

	if (Debug::Instance()->Get_Input(Key8) == 1) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (enemy[i].etype != 2) {
				SetEnemyDeath(i);
			}
		}
	}

	if (Debug::Instance()->Get_Input(Key9) == 1) {
		for (int i = 1; i < sizeof(enemy) / sizeof*(enemy); i++) {
				SetEnemyDeath(i);
				Phaseflag = 2;
		}
	}

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

/*****************************************************
関数名：void Scalings(sEnemy& enemy)
説明：敵が攻撃待機中に大きくなったり小さくなったりする
引数：sEnemy型 enemy
戻り値：なし
******************************************************/
void cEnemyMgr::Scaling(sEnemy& enemy) {

	if (ScalingCount >=180 ) {
		ScalingFlag *= -1;
		ScalingCount = 0;
	}

	if (ScalingCount % 30 == 0) {
		enemy.target.x += enemy.shaft.x * 2 * ScalingFlag;
		enemy.target.y += enemy.shaft.y * 2 * ScalingFlag;
	}

}

/*****************************************************
関数名：void Slidings(sEnemy& enemy)
説明：敵が入場待機中に横移動する
引数：sEnemy型 enemy
戻り値：なし
******************************************************/
void cEnemyMgr::Sliding(sEnemy& enemy) {

	if (SlidingCount >= 240) {
		SlidingFlag *= -1;
		SlidingCount = 0;
	}

	if (SlidingCount % 60 == 0) {
		enemy.target.x += 10 * SlidingFlag;
	}
}





//描写処理
void cEnemyMgr::Draw() {
	//勝手に追加分　by滝　
	//PlayerEnemyが生成されていた時だけ表示

	if (pEnemy !=NULL) {
		if (pEnemy->GetEnemyOnActive() != 1) {
			pEnemy->Draw();
		}
	}

	for (int i = 0; i < sizeof(enemy) / sizeof(*enemy); i++) {
		if (enemies[i]->GetEnemyOnActive() == 1)continue;
		enemies[i]->Update2();
		enemies[i]->Draw();
	}
	if (Phaseflag == 2) {
		DrawFormatString(100, 100, GetColor(255, 255, 255), "攻撃フェーズ");
	}
	
	/*
	DrawFormatString(0, 120, GetColor(255, 255, 255), "enemy[0]:%lf", enemy[0].target.x);
	DrawFormatString(0, 140, GetColor(255, 255, 255), "enemy[2]:%lf", enemy[2].target.x);
	*/

}