#pragma once



#ifndef _HIT_INCLUDE_
#define _HIT_INCLUDE_

#define MAXMACHINE 2

#define PLAYER 0
#define ENEMY 1

#include "Singleton.h"
#include "Struct.h"


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

class cHit: public cSingleton<cHit>
{
	cHit();
	friend cSingleton< cHit >;
private:

	void Hit();		//当たり判定

protected:

public:

	void Update();	//計算処理
	void Draw();	//描写処理
	//void BeemHit(); //トラクタービーム当たり判定

};


#endif