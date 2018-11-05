#include "Shot.h"
#include "DxLib.h"

//Templateクラスの実装

//コンストラクタ(初期化)
cShot::cShot(){
	OnActive=0;
}

//デストラクタ
cShot::~cShot() {

}

int cShot::Update() {
	//xとyの移動(ラジアンでベクトルを計算)
	return 0;
}

int cShot::Draw() {
	return 0;
}

/*
//実装例
//mTestへの代入
void cTemplate::Set_Test(int Test) {
	mTest = Test;
}

//mTestの獲得
int cTemplate::Get_Test() {
	return mTest;
}
*/