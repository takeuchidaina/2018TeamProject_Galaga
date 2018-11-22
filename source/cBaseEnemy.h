#pragma once

#ifndef _cBaseEnemy_INCLUDE_
#define _cBaseEnemy_INCLUDE_
#include "Struct.h"
#include <math.h>
#include "DxLib.h"


/*


*/



typedef struct {
	sPos vct;               // ベクトル用x y
	sOBJPos mainpos ;//メインのx y r onActive
	sPos target;          //変える位置かな？
	int targetr;
	double spd;		  //速度
	double ang;	      //向いている角度
	int* graph;		 //マネージャーからもらう画像のアドレス用
	int dir = 1;         //1　右　-1　左
	int width;           //幅
	int hight;         //高さ
	int count; //移動カウント
	int moveflg; //移動制御フラグ 
	int attackflg;//攻撃フラグ
	double moveang[10];//
	double countflg[10];
	
}sEnemy;

class cBaseEnemy {

protected:
	sEnemy enemy;
public:

	     cBaseEnemy();//コンストラクタ
		 cBaseEnemy(double,double,double,int,double,double,int ,int*);//引数付きコンストラクター	
		virtual ~cBaseEnemy();//デストラクタ
		virtual	int Update();//更新処理
		virtual int Draw();//描画処理
		virtual void Move();//移動処理
		//現状態
		enum eActiveType {
			StartMove,
			NoActive,
			YesActive,
			NoMove,
		};
		//右にいるか左にいるか
		enum eRF {
		RIGHT = 1,
		LEFT= -1,
	};
		//
		virtual void Update2() {
			enemy.mainpos.cx = enemy.mainpos.pos.x + (enemy.width / 2);
			enemy.mainpos.cy = enemy.mainpos.pos.y + (enemy.hight / 2);
		}

		// x
		virtual	double GetEnemyX(){
			return enemy.mainpos.pos.x;
		}
		virtual	void SetEnemyX(double x) {
			enemy.mainpos.pos.x = x;
		}
		//y
		virtual	double GetEnemyY() {
			return enemy.mainpos.pos.y;
		}
		virtual	void SetEnemyY(double y) {
			enemy.mainpos.pos.y = y;
		}
		//attackflg
		virtual	int GetEnemyAttackflg() {
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
			if (enemy.mainpos.onActive == YesActive)enemy.mainpos.onActive = NoActive;
			else enemy.mainpos.onActive = YesActive;
		}
		//r
		virtual	double GetEnemyR(){
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
};

#endif // !_cBaseEnemy_INCLUDE_
