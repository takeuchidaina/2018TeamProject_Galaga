#pragma once

#include "Singleton.h"

#define MAXMACHINE 2

#define PLAYER 0
#define ENEMY 1

#ifndef _HITFUNC_INCLUDE_
#define _HITFUNC_INCLUDE_

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

class cHitFunc: public Singleton<cHitFunc>
{
	cHitFunc();
	friend Singleton< cHitFunc >;
private:

	sOBJPos Player;
	void Hit(sOBJPos, cShot *, cShot *, sEnemy *);		//当たり判定

protected:

public:

	void Update();	//計算処理
	void Draw();	//描写処理
	
	void BeemHit(sOBJPos); //トラクタービーム当たり判定

};


#endif