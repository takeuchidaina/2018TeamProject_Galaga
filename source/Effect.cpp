#include "Effect.h"
#include "DXlib.h"

//Effectクラスの実装

//コンストラクタ
cEffect::cEffect(){
	Init();
}

//初期化
void cEffect::Init() {
}

//デストラクタ
cEffect::~cEffect() {
}

int cEffect::Update() {
	return 0;
}

int cEffect::Draw(int* GrHandle) {
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