#pragma once

#ifndef INGAME_MGR_INCLUDE_
#define INGAME_MGR_INCLUDE_

#include "cBaseEnemy.h"

class cEnemyMgr {
private:
	typedef struct  {
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
	int etype;         //敵の種類(3種分)
	double moveangle[3];  //角度設定の配列
	int countflag[3];     //特定のフレーム数をあれする配列
	int onactive;         //表示・非表示の判定
	}sEnemy;

	sEnemy enemy[32];          //構造体変数だっけの宣言
	sEnemy tmpEnemy;           //一時的に敵データを格納する場所
	//int movetype;            //敵の動作タイプ
	int waveflag[10];          //該当ウェーブに敵が何体いるかを管理する
	int wave;                  //現在のウェーブ数
	int wavecount;             //該当ウェーブで入場行動が終了している敵の数
	
	int input[64];            //ファイルから読み取った文字列の一時保管(int用)
	char inputc[64];          //ファイルから読み取った文字列の一時保管(char用)
	int fileEndFlag;          //ファイル読み込みの終了フラグ
	int StageHandle;          //ファイルを開くはんどる
	char StageFilePath[256];  //読み込むファイルの名前を入れる配列
	int n,num;                //n,num
	int Phaseflag;            //移動段階フラグ
 
	//関数のプロトタイプ宣言
	void Move(sEnemy&);
	void Shifted(sEnemy&,sEnemy&);
	cBaseEnemy* enemies[40];
	//enemies[i] = new(*cBaseEnemy)cBlueEnemy(tmpEnemy.pos.x,tmpEnemy.pos.y);

public:
	cEnemyMgr();
	~cEnemyMgr();

	void Update();
	void Draw();

};
#endif // !_INGAME_MGR_INCLUDE_
