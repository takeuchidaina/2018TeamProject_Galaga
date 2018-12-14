#include "EffectMgr.h"
#include "DXlib.h"

//Effectクラスの実装

//コンストラクタ
cEffectMgr::cEffectMgr(){
	//注意 左下に1ドットずれる、使用 Player→6,7,8 Enemy→34,35,36
	PcheckGr = LoadDivGraph("../resource/Image/Galaxian_OBJ_token.png",
		8, 4, 2, 34, 34, PBlowupGrHandle);
	if (PcheckGr == -1) ErrBox("Effect画像読み込みエラー");//エラーチェック

	EcheckGr = LoadDivGraph("../resource/Image/Galaxian_OBJ_enemy.png",
		40, 8, 5, 18, 18, EBlowupGrHandle);
	if (EcheckGr == -1) ErrBox("Effect画像読み込みエラー");//エラーチェック

	Init();
}

//初期化
void cEffectMgr::Init() {
	delete[] BlowupArray;
	BlowupArray = new cEffect[10];
}

//デストラクタ
cEffectMgr::~cEffectMgr() {
	delete[] BlowupArray;
}

int cEffectMgr::Update() {
	return 0;
}

int cEffectMgr::Draw() {
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