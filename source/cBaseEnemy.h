#pragma once

#ifndef _cBaseEnemy_INCLUDE_
#define _cBaseEnemy_INCLUDE_
#include "Struct.h"
#include <math.h>
#include "DxLib.h"


/*
全てのエネミーの継承元

*/



typedef struct {
	bool tractorflg;      //トラクターを行うかのフラグ
	bool tractorHitFlg; //トラクターが当たったかの判定
	bool tractingEnemy; //捕まえている敵の捕捉用flg

	sPos vct;               // ベクトル用x y
	sOBJPos mainpos;//メインのx y r onActive
	sPos target;          //定位置
	int targetr;          //エネミーの定位置の半径
	double spd;		  //速度
	double ang;	      //向いている角度
	int* graph;		 //マネージャーからもらう画像のアドレス用
	int dir = 1;         //1　右　-1　左
	int width;           //幅
	int height;         //高さ
	int count; //移動カウント
	int moveflg; //移動制御フラグ 
	int attackflg;//攻撃フラグ
	double moveang[15];//移動中の方向変化量
	double countflg[15];//移動のフェーズ切り替えのカウント
	int hp;
}sEnemy;

class cBaseEnemy {

protected:
	//アニメーションのカウント
	int AnimationCnt, AnimationNum;
	int TractorCnt, TractorNum;
	sEnemy enemy;


public:
	cBaseEnemy();//コンストラクタ
	cBaseEnemy(double, double, double, int, double, double, int, int*);//引数付きコンストラクター	
	virtual ~cBaseEnemy();//デストラクタ
	virtual	int Update();//更新処理
	virtual int Draw();//描画処理
	/***********************************
	移動処理
	引数なし : 戻り値なし
	****************************************/
	virtual void Move();
	/***********************************
	トラクター用の関数　緑以外ではよんでもなにもない
	引数なし : 戻り値なし
	****************************************/
	virtual int TractorUpdate();
	/***********************************
	エネミーの破壊関数　
	引数なし : 戻り値なし
	****************************************/
	virtual void Break() { enemy.mainpos.onActive = NoActive; };
	/***********************************
	アニメーションの描画関数
	引数なし : 戻り値なし
	****************************************/
	virtual void AnimationCount() { AnimationCnt++; };

	//OnAcitveの状態
	enum eActiveType {
		StartMove, //スタート時
		NoActive,  // 破壊時
		YesActive, //起動時
		ReadyStart, //移動可能時
		SetPos //移動終了時
	};

	//右にいるか左にいるか
	enum eRF {
		RIGHT = 1,
		LEFT = -1,
	};
	//エネミーマネージャーで使う移動
	virtual void Update2() {
		enemy.mainpos.cx = enemy.mainpos.pos.x + (enemy.width / 2);
		enemy.mainpos.cy = enemy.mainpos.pos.y + (enemy.height / 2);
	}
	//ここら辺から自分の情報を返す関数
	//情報を自分に代入する関数

	virtual	sEnemy* GetEnemy() {
		return &enemy;
	}

	// x
	virtual	double GetEnemyX() {
		return enemy.mainpos.pos.x;
	}
	virtual	void SetEnemyX(double x) {
		enemy.mainpos.pos.x = x;
	}
	//y
	virtual	double GetEnemyY() {
		return enemy.mainpos.pos.y;
	}
	//
	virtual	void SetEnemyY(double y) {
		enemy.mainpos.pos.y = y;
	}
	//attackflg
	virtual	int GetEnemyAttackflg() {
		//if (enemy.attackflg == true && enemy.mainpos.onActive == SetPos)return false;

		return enemy.attackflg;
	}

	//作水野　攻撃する敵を選択するときに使うもの
	virtual int GetEnemyChoiseOrder() {
		if (enemy.attackflg == true && enemy.mainpos.onActive == SetPos)return FALSE;
		return enemy.attackflg;
	}

	virtual	void SetEnemyAttackflg() {
		enemy.attackflg = true;
	}

	//ang
	virtual	double GetEnemyAngle() {
		return enemy.ang;
	}
	virtual	void SetEnemyAngle(double ang) {
		enemy.ang = ang;
	}
	virtual	void SetEnemyAddAngle(double ang) {
		enemy.ang += ang;
	}

	//activeflg
	virtual	int GetEnemyOnActive() {
		return enemy.mainpos.onActive;
	}
	virtual	void SetEnemyOnActive() {
		if (enemy.mainpos.onActive != NoActive)enemy.mainpos.onActive = NoActive;
		else enemy.mainpos.onActive = YesActive;
	}
	//r
	virtual	double GetEnemyR() {
		return enemy.mainpos.r;
	}
	virtual	void SetEnemyR(double r) {
		enemy.mainpos.r = r;
	}
	//cx
	virtual	double GetEnemyCx() {
		return enemy.mainpos.cx;
	}
	virtual	void SetEnemyCx(double cx) {
		enemy.mainpos.cx = cx;
	}
	//cy
	virtual	double GetEnemyCy() {
		return enemy.mainpos.cy;
	}
	virtual	void SetEnemyCy(double cy) {
		enemy.mainpos.cy = cy;
	}

	virtual bool GetTractorfFlg() {
		return enemy.tractorflg;
	}
	virtual void SetTractorfFlg() {
		enemy.tractorflg = true;
	}

	virtual bool GetTractorHitFlg() {
		return enemy.tractorHitFlg;
	}

	virtual void SettractorHitFlg() {
		enemy.tractorHitFlg = true;
	}


	virtual bool GetTractingFlg() {
		return enemy.tractingEnemy;
	}


	virtual	int GetHp() { return enemy.hp; };

	virtual	void DamageHp() { enemy.hp--; };
	virtual	void SetHp() { enemy.hp = 0; };
};

#endif // !_cBaseEnemy_INCLUDE_
