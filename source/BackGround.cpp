#include <DxLib.h>
#include"BackGround.h"

/* コンストラクタ */
cBackGround::cBackGround() {
	
	for (int i = 0; i < MAXSTAR; i++) {
		Init(i);
	}

}

/* デストラクタ *
cBackGround::~cBackGround() {

}*/

void cBackGround::Update() {

	for (int i = 0; i < MAXSTAR; i++) {

		/* 星を流す */
		starArray[i].y += 10;
		if (starArray[i].y >= DISP_SIZE) Init(i);

		/* 星を点滅 */
		starArray[i].blinkCnt++;
		if (starArray[i].blinkCnt >= starArray[i].blinkNum) {
			starArray[i].blinkFlg *= -1;
		}

	}
}

void cBackGround::Draw() {

	for (int i = 0; i < MAXSTAR; i++) {
		if (starArray[i].blinkFlg == TRUE) {
			LoadGraphScreen((int)starArray[i].x, (int)starArray[i].y, 
				"../resource/Image/Star.png", TRUE);
		}
	}
}

/***************************************************************
	関数：void cBackGround::Init
	説明：星の初期化 or 再生成を行う
	引数：初期化する配列番号(int)
	戻値：なし
***************************************************************/
void cBackGround::Init(int i) {

		starArray[i].x = Rand(0, DISP_SIZE);	//ｘ座標
		starArray[i].y = Rand(-100, 300);		//ｙ座標
		starArray[i].blinkCnt = 0;				//点滅カウント用
		starArray[i].blinkNum = Rand(10, 100);	//点滅タイミング
		starArray[i].blinkFlg = TRUE;			//TRUE：表示　FALSE：非表示

}
/***************************************************************
	関数：int cBackGround::Rand(int lo, int hi)
	説明：ランダム処理を行う
	引数：ランダム範囲の低数(int), ランダム範囲(int)
	戻値：ランダム結果(int)
***************************************************************/
int cBackGround::Rand(int lo, int hi) {

	int r = 0;
	srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化
	r = (rand() % hi) + lo;

	return r;
}