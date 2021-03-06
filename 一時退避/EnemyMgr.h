#pragma once

#ifndef INGAME_MGR_INCLUDE_
#define INGAME_MGR_INCLUDE_

#include "cBaseEnemy.h"
#include "cPlayerEnemy.h"
#include "TextChange.h"
#include "FlightText.h"

#include "Singleton.h"
#include "WinBox.h"
#include "Score.h"

class cEnemyMgr : public cSingleton <cEnemyMgr> {
	cEnemyMgr();
	friend cSingleton<cEnemyMgr>;

private:
	typedef struct {
		double x, y;
	}sPos;

	typedef struct {
		sPos pos;             //初期座標
		sPos v;               //ベクトル座標  
		int r;                //半径
		int count;            //フレームカウント
		double angle;         //角度
		double speed;         //速度
		int moveflag;         //動作フラグ
		int maxmove;          //動作フラグの最大数
		int RLflag;           //左右を判定するフラグ
		sPos target;          //目標位置の座標
		int targetr;          //目標位置の半径(当たり判定に利用)
		int wave;             //ウェーブ番号  
		int etype;            //敵の種類(3種分) 0:青 1:赤 2:緑
		sPos shaft;           //敵の列番号
		double moveangle[3];  //角度設定の配列
		int countflag[3];     //特定のフレーム数をあれする配列
		int onactive;         //表示・非表示の判定
		int attackflag;       //攻撃フラグ
		int deathflag;        //敵の死亡フラグ 0:生きてる 1:死んでる
	}sEnemy;

	//EnemyMgr内でのみ扱う変数を格納する構造体
	typedef struct {
		sPos v;               //ベクトル座標  
		int moveflag;         //動作フラグ
		int maxmove;          //動作フラグの最大数
		int RLflag;           //左右を判定するフラグ
		sPos target;          //目標位置の座標
		int targetr;          //目標位置の半径(当たり判定に利用)
		int wave;             //ウェーブ番号  
		int etype;            //敵の種類(3種分)0:青 1:赤 2:緑
		sPos shaft;           //敵の列番号
		double moveangle[3];  //角度設定の配列
		int countflag[3];     //特定のフレーム数を指定する配列
		int deathflag;        //敵の死亡フラグ 0:生きてる 1:死んでる
	}sEnemyMgrData;

	/*csvから読み込むデータの番号
	　新しくデータを追加した場合は、moveangle[0]より前に変数を追加する
	*/
	typedef enum{
		Posx,            //x座標
		Posy,            //y座標
		Radius,          //半径
		Count,           //カウント
		Angle,           //角度
		Speed,           //速度
		Maxmove,         //移動切り替えの最大数
		RLflag,          //左右を判別するフラグ
		Targetx,         //目標地点のx座標
		Targety,         //目標地点のy座標
		Targetr,         //目標地点の半径
		Wave,            //入場番号
		Etype,           //敵の種類
		Shaftx,          //yの拡大数
		Shafty,          //xの拡大数
		FirstMoveangle,  //移動する角度１
		FirstCountflag,  //移動方向を切り替えるカウント１
		SecondMoveangle, //移動する角度２
		SecondCountflag, //移動方向を切り替えるカウント２
		ThirdMoveangle,  //移動する角度３
		ThirdCountflag   //移動方向を切り替えるカウント３
	}eLoadData;

	typedef struct {
		int x, y;
		int onActive;
		int count;
		int score;
	}sScoreText;


	sEnemy enemy[40];         //構造体
	sEnemy tmpEnemy;          //一時的に敵データを格納する場所
	//int movetype;           //敵の動作タイプ
	int waveflag[10];         //該当ウェーブに敵が何体いるかを管理する
	int wave;                 //現在のウェーブ数
	int wavecount;            //該当ウェーブで入場行動が終了している敵の数

	int  input[64];           //ファイルから読み取った文字列の一時保管(int用)
	char inputc[64];          //ファイルから読み取った文字列の一時保管(char用)
	int  fileEndFlag;         //ファイル読み込みの終了フラグ
	int  StageHandle;         //ファイルを開くハンドル
	char StageFilePath[256];  //読み込むファイルの名前を入れる配列
	int  n, num;              //n,num
	int  Phaseflag;           //移動段階フラグ
	int  EnemyGraph[20];      //敵の画像 20体分よみこむ ※enum化予定
	int  Stayflag;            //敵が入場後に動いていないか 0:動いている 1:動いていない ※bool化予定

    //関数のプロトタイプ宣言
	void Move(sEnemy&);              //敵の入場を行う関数
	void Shifted(sEnemy&, sEnemy&);  //敵を二列に表示させる関数
	cBaseEnemy* enemies[40];         //cBaseEnemyの敵配列

	void Scaling(sEnemy&);    //秋の新作関数
	int  ScalingFlag;         //敵の収縮処理用のフラグ true:1 false:-1
	int  ScalingCount;          //収縮カウント
	
	void Sliding(sEnemy&);    //冬の新作関数
	int  SlidingFlag;         //敵の横移動処理用のフラグ true:1 false:-1
	int  SlidingCount;        //横移動カウント

	int phaseFlagCount;       //入場が終了している敵の数
	int onActiveCount;        //入場時にonActiveがtrueになっている敵の数
	   
	int ChoiseOrderFlag;      //外部で操作可能な再抽選フラグ TRUE:抽選可能。抽選を行う  FALSE:抽選不可。抽選を行わない ※bool化予定
	int ReChoiceFlag;         //再抽選フラグ 0:抽選を行わない状態 1:抽選を行う状態 ※bool化予定

	int EnemyAttackFlag;      //攻撃フラグ   0:攻撃を行わない状態 1:攻撃を行う状態 ※bool化予定
	int EnemyDeathCount;      //死亡カウント

	cPlayerEnemy* pEnemy;      //敵になったプレイヤーのアドレス 

	sScoreText scoreText;      //特殊スコアを表示させる構造体

public:
	//~cEnemyMgr();

	void Update();
	void Draw();

	void Init();

	double GetTargetX(cBaseEnemy* p) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (p == enemies[i]) {
				return enemy[i].target.x;
			}
		}
	}
	double GetTargetY(cBaseEnemy* p) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (p == enemies[i]) {
				return enemy[i].target.y;
			}
		}

	}

	/*hitに情報をわたす用の関数*/
	
	//敵の最大数
	int GetMaxEnemy() {
		return 40;
	}

	//敵のcx
	double GetEnemyPosX(int num) {
		return enemies[num]->GetEnemyCx();
	}

	//敵のcy
	double GetEnemyPosY(int num) {
		return enemies[num]->GetEnemyCy();
	}

	//敵のr
	double GetEnemyPosR(int num) {
		return enemies[num]->GetEnemyR();
	}

	double GetEnemyR(int num) {
		return enemies[num]->GetEnemyR();
	}
	
	

	//敵の攻撃判定を行うためのフラグ
	int GetEnemyonActive(int num) {
		//
		return enemies[num]->GetEnemyOnActive() == 1 ? false:true;
	}
	
	//勝手に追加分 by滝
	int GetEnemyHP(int num) {
		return enemies[num]->GetHp();
	}

	void DamageEnemyHp(int num) {
		enemies[num]->DamageHp();
	}

	int GetEnemyDeathCount(){
		return EnemyDeathCount;
	}




	/*****************************************************
	関数名：cPlayerEnemy GetPlayerEnemyAdress()
	説明：敵配列に加えたプレイヤーのアドレスを与える
	引数：なし
	戻り値：敵配列に加えたプレイヤーのアドレス
	******************************************************/
	cPlayerEnemy* GetPlayerEnemyAdress() {
		return pEnemy;
	}



	/*****************************************************
	関数名：cPlayerEnemy PushPlayerEnemy()
	説明：トラクタービームが当たったプレイヤーを敵配列に加える
	引数：cPlayerEnemy型 pEnemy
	戻り値：プッシュ先のアドレス
	******************************************************/
	cPlayerEnemy* PushPlayerEnemy() {
		pEnemy = new cPlayerEnemy();
		return pEnemy;
	}

	/*****************************************************
	関数名：void DeletePlayerEnemy()
	説明：敵配列に加えたプレイヤーのデータをデリートする
	引数：cPlayerEnemy型 pEnemy
	戻り値：プッシュ先のアドレス
	******************************************************/
	void DeletePlayerEnemy() {
		delete pEnemy;
		pEnemy = NULL;
	}

	/*****************************************************
	関数名：cBaseEnemy* GetArrayEnemy()
	説明：
	引数：cBaseEnemy型 enemies
	戻り値：プッシュ先のアドレス
	******************************************************/
	cBaseEnemy* GetArrayEnemy(){
		return *enemies;
	}


	/*****************************************************
	関数名：void SetEnemyDeath(int num)
	説明：この関数が呼ばれたとき、敵の死亡処理を行う
	引数：int型 num
	戻り値：なし
	******************************************************/
	void SetEnemyDeath(int num) {
		//敵の破壊処理を行う
		enemies[num]->Break();

		//敵を非表示にする
		enemy[num].onactive = FALSE;

		//敵の死亡フラグをTRUEにする
		enemy[num].deathflag =TRUE;

		//敵の死亡数をカウントする
		EnemyDeathCount++;	
		
		//条件ごとのスコア加算処理
		//入場中または攻撃してきたボスギャラガを倒した場合
		if (enemy[num].etype==2 && enemy[num].moveflag < 10 || enemies[num]->GetEnemyAttackflg()==1) {
			//スコアを400加算する
			cScore::Instance()->AddScore(400);
			scoreText.x=GetEnemyPosX(num);
			scoreText.y = GetEnemyPosY(num);
			scoreText.score = 400000;
			scoreText.onActive = 1;
			scoreText.count =0;
		}
		/*
		//プレイヤーエネミーを連れているボスギャラガを倒した場合
		else if (enemy[num].type==2 && enemies[num]->GetEnemyAttackflg()=1 && 敵がプレイヤーエネミーを連れている) {
		    //スコアを800加算する
			cScore::Instance()->AddScore(800);
		}*/
		else {  //それ以外
			//スコアを100加算する
			cScore::Instance()->AddScore(100);
		}
		
	}


	/*****************************************************
	関数名：void EndIt()
	説明：この関数が呼ばれたとき、敵の配列を消去する
	引数：なし
	戻り値：なし
	******************************************************/
	void EndIt() {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			delete enemies[i];
		}
	}


	/*
	入場後敵が何も動いていない状態を獲得する
	0:動いている 1:動いていない
	*/
	int GetEnemyStay() {
		return Stayflag;
	}
	
	//InGameControllerで敵の攻撃動作を制御する関数
	void SetEnemyAttackFlag(int flag) {
		EnemyAttackFlag=flag;
	}

	//InGameControllerで敵の抽選命令を制御する関数
	void SetChoiseOrderFlag(int flag) {
		ChoiseOrderFlag = flag;
	}

	bool GetTractingFlg(int num) {
	return enemies[num]->GetTractingFlg();
	}

};
#endif // !_INGAME_MGR_INCLUDE_
