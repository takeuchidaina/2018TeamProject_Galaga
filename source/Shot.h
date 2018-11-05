#pragma once

#ifndef _SHOT_INCLUDE_
#define _SHOT_INCLUDE_

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


class cShot {
private:
	double x, y, vx,vy,cx,cy,s,r, w ,h,rad;
	int OnActive;
	
protected:

public:
	cShot();	//コンストラクタ
	~cShot();	//デストラクタ
	int Update();	//計算処理
	int Draw();		//描写処理
	inline int Get_OnActive() { return OnActive; }//OnActiveの獲得
	void Set_OnActive(int tmp) { OnActive = tmp; }
	void Set_Width(int tmp) { w = tmp; }
	void Set_Height(int tmp) { h = tmp; }
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