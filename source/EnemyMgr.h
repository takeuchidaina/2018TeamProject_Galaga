#pragma once
#pragma once
#ifndef _INGAME_MGR_INCLUDE_
#define _INGAME_MGR_INCLUDE_


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
	double angle;           //角度
	double speed;         //速度
	int moveflag;         //動作フラグ
	int maxmove;          //動作フラグの最大数
	double moveangle[3];  //角度設定の配列
	int countflag[3];     //特定のフレーム数をあれする配列
	int RLflag;           //左右を判定するフラグ
	sPos target;          //目標位置の座標
	double targetr;       //目標位置の半径(当たり判定に利用)
	int onactive;         //表示・非表示の判定
	//int enemytype[3];     //敵の種類(3種分)
	}sEnemy;

	sEnemy enemy[16];  //構造体変数だっけの宣言
	int movetype;         //敵の動作タイプ


public:
	cEnemyMgr();
	~cEnemyMgr();

	void Move(sEnemy&);
	void Shifted(sEnemy&,sEnemy);

	void Update();
	void Draw();

};

#endif