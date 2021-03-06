#include <DxLib.h>
#include"BackGround.h"

/* コンストラクタ */
cBackGround::cBackGround() {
	
	for (int i = 0; i < MAXSTAR; i++) {
		Init(i);
	}

	srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化

}

/* デストラクタ 
cBackGround::~cBackGround() {

}*/

void cBackGround::Update() {

	for (int i = 0; i < MAXSTAR; i++) {

		/* 星を流す（通常） */
		starArray[i].y += starArray[i].speed;

		if (starArray[i].y >= DISP_SIZE + 50) {		//下まで行ったら再生成
			starArray[i].y = (rand() % 150) - 150;
			starArray[i].x = rand() % DISP_SIZE;
			starArray[i].r = (rand() % 2) + 1;
			starArray[i].color = GetColor(rand() % 255, rand() % 255, rand() % 255);
		}

		/* 星を点滅 */
		starArray[i].blinkCnt++;
		if (starArray[i].blinkCnt >= starArray[i].blinkNum) {
			starArray[i].blinkFlg *= -1;
			starArray[i].blinkCnt = 0;
		}

	}
}

void cBackGround::TractingUpdate() {

	for (int i = 0; i < MAXSTAR; i++) {

		starArray[i].y -= starArray[i].speed * 5;

		if (starArray[i].y <= -50) {		//下まで行ったら再生成
			starArray[i].y = (rand() % 150) + (DISP_SIZE);
			starArray[i].x = rand() % DISP_SIZE;
			starArray[i].r = (rand() % 2) + 1;
			starArray[i].color = GetColor(rand() % 255, rand() % 255, rand() % 255);
		}

	}

}

void cBackGround::PauseUpdate() {
	
	for (int i = 0;i < MAXSTAR; i++) {
		starArray[i].y -= starArray[i].speed;
	}

}

void cBackGround::Draw() {

	for (int i = 0; i < MAXSTAR; i++) {
		if (starArray[i].blinkFlg == TRUE) {
			//星描画(円)
			DrawCircle((int)starArray[i].x, (int)starArray[i].y, starArray[i].r, starArray[i].color, TRUE);
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

	starArray[i].x = rand() % DISP_SIZE;			//ｘ座標
	starArray[i].y = (rand() % DISP_SIZE+100) - 200;	//ｙ座標
	starArray[i].r = (rand() % 2) + 1;				//半径
	starArray[i].speed = 1;							//移動速度
	starArray[i].blinkCnt = 0;						//点滅カウント用
	starArray[i].blinkNum = (rand() % 100) +10;		//点滅タイミング
	starArray[i].blinkFlg = TRUE;					//TRUE：表示　FALSE：非表示
	starArray[i].color = GetColor(rand() % 255, rand() % 255, rand() % 255);	//色設定

}
