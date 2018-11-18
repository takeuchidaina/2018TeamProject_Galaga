#include "Shot.h"
#include "DxLib.h"
#include "UI.h"

//Templateクラスの実装

//コンストラクタ(初期化)
cShot::cShot(){
	s = 5;
	w = 10*3; h = 12*3;//元データの3倍に拡大
	OnActive=0;
}

//デストラクタ
cShot::~cShot() {

}

int cShot::Update() {
	cx = x + w / 2;//cx,cyのセット
	cy = y + h / 2;
	r = 2;
	//xとyの移動(ラジアンでベクトルを計算)
	y+=s*cos(rad);
	//画面外に行ったらFALSEにする
	if (x-w < 0 || x> 910|| y-h < 0 || y>960) {
		OnActive = FALSE;
	}
	return 0;
}

int cShot::Draw(int num,int GrHandle[]) {
	if (num == PLAYER) {//0=playerShot 1=enemyShot
		if (OnActive == TRUE) {//0=false,1=true
			DrawExtendGraph(x, y, x + w, y + h, GrHandle[3], FALSE);
		}
	}

	if (num == ENEMY) {//0=playerShot 1=enemyShot
		if (OnActive == TRUE) {
			DrawExtendGraph(x, y, x + w, y + h, GrHandle[0], FALSE);
		}
	}



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