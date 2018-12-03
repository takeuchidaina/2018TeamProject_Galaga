#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>
#include "cBaseEnemy.h"
#include "cBlueEnemy.h"
#include "cRedEnemy.h"
#include "cGreenEnemy.h"
#include "DxLib.h"
#include "Struct.h"
int EnemyGraph[20];
 static int i = 0;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetGraphMode(1280, 960, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定
	LoadDivGraph("../resource/Image/Galaga_OBJ_enemy1616.png", 20, 5, 4, 16, 16, EnemyGraph);
																		 
																		 
																		 
	//x y r cnt spd ang flg

	cBlueEnemy zako(300, 330, 5, 0, 3, -90, false, EnemyGraph);
	cRedEnemy  goei(400,330,5,0,3,-90,false, EnemyGraph);
	cGreenEnemy boss(500,330,5,0,3,-90,false, EnemyGraph);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面更新 & メッセージ処理 & 画面消去
			zako.SetEnemyAttackflg();
			goei.SetEnemyAttackflg();
			boss.SetEnemyAttackflg();

		zako.Update(); 
		goei.Update();
		boss.Update();

	/*if (zako.enemy.mainpos.onActive != true) continue;
	if (goei.enemy.mainpos.onActive != true) continue;
	if (boss.enemy.mainpos.onActive != true) continue;
	*/
		
		zako.Move();
		goei.Move();
		boss.Move();

		
		zako.Draw();
		goei.Draw();
		boss.Draw();
	}


	DxLib_End(); // DXライブラリ終了処理
	return 0;
}