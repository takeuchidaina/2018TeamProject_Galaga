#pragma once

#ifndef _TEMPLATE_INCLUDE_
#define _TEMPLATE_INCLUDE_

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


class cTemplate {
private:
	
protected:

public:
	cTemplate();	//コンストラクタ
	~cTemplate();	//デストラクタ
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