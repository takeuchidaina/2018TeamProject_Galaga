#pragma once

#ifndef _SHOTMGR_INCLUDE_
#define _SHOTMGR_INCLUDE_
#include "Shot.h"
#include "Singleton.h"
/*
//テンプレート例 クラスもテンプレート化可能
template <typename TYPE>
void Swap(TYPE& a, TYPE& b) {
TYPE tmp;
tmp = a;
a = b;
b = tmp;
}
*/


class cShotMgr:public cSingleton<cShotMgr> {
	cShotMgr();
	friend cSingleton<cShotMgr>;
private:
	cShot *enemyShot, *playerShot;
	int totalShot;
	int ShotGrHandle[4];

protected:

public:
	int Update();	//計算処理
	int Draw();		//描写処理
	/*
	//宣言例
	private:
	int mTest;
	public:
	void Set_Test(int);	//privateメンバ変数mTestへの代入
	int Get_Test();		//privateメンバ変数mTestの獲得
	*/
};
#endif
