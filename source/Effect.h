#pragma once

#ifndef _EFFECT_INCLUDE_
#define _EFFECT_INCLUDE_
#define PLAYER 0
#define ENEMY 1


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


class cEffect {
private:
	double x, y, cx, cy, w, h;
	int OnActive, type, nowGr, adjust,i;
protected:

public:
	cEffect();
	~cEffect();
	void Init();//初期化処理
	int Update(int*);	//計算処理
	int Draw(int*);		//描写処理

	inline int Get_OnActive() { return OnActive; }
	void Set_OnActive(int tmp) { OnActive = tmp; }
	inline int Get_Type() { return type; }
	void Set_Type(int tmp) { type = tmp; }
	inline int Get_CX() { return (int)cx; }
	void Set_CX(int tmp) { cx = tmp; }
	inline int Get_CY() { return (int)cy; }
	void Set_CY(int tmp) { cy = tmp; }
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