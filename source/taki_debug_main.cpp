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



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetGraphMode(1024, 768, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定
	//x y r cnt spd ang flg

	
	cBlueEnemy zako(300, 64, 5, 0, 3, 180, false);
	cRedEnemy  goei(400,64,5,0,3,180,false);
	cGreenEnemy boss(500,64,5,0,3,180,false);
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面更新 & メッセージ処理 & 画面消去
		zako.Update(); 
		goei.Update();
		boss.Update();
	if (zako.enemy.onActive != true) continue;
	if (goei.enemy.onActive != true) continue;
	if (boss.enemy.onActive != true) continue;
	
		
		zako.Move(zako);
		goei.Move(goei);
		boss.Move(boss);
<<<<<<< HEAD

=======
>>>>>>> 2c435cc0f7a627fd228fb34e7fb13a0f3203c279
		DrawFormatString(100, 0, GetColor(255, 255, 255), "%.1lf", zako.enemy.pos.x);
		DrawFormatString(150, 0, GetColor(255, 255, 255), "%.1lf", zako.enemy.pos.y);
		DrawFormatString(100, 15, GetColor(255, 255, 255), "%.1lf", zako.enemy.vct.x);
		DrawFormatString(150, 15, GetColor(255, 255, 255), "%.1lf", zako.enemy.vct.y);
		DrawFormatString(100, 30, GetColor(255, 255, 255), "%.1lf", zako.enemy.target.x);
		DrawFormatString(150, 30, GetColor(255, 255, 255), "%.1lf", zako.enemy.target.y);
		DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", zako.enemy.moveflg);
		DrawFormatString(0, 40, GetColor(255, 255, 255), "%.1lf", zako.enemy.vct.x);
		DrawFormatString(0, 60, GetColor(255, 255, 255), "%.1lf", zako.enemy.vct.y);
		DrawFormatString(0, 80, GetColor(255, 255, 0), "%d", zako.enemy.dir);

		DrawFormatString(230, 0, GetColor(255, 255, 255), "%.1lf", goei.enemy.pos.x);
		DrawFormatString(280, 0, GetColor(255, 255, 255), "%.1lf", goei.enemy.pos.y);
		DrawFormatString(230, 15, GetColor(255, 255, 255), "%.1lf", goei.enemy.vct.x);
		DrawFormatString(280, 15, GetColor(255, 255, 255), "%.1lf", goei.enemy.vct.y);
		DrawFormatString(230, 30, GetColor(255, 255, 255), "%.1lf", goei.enemy.target.x);
		DrawFormatString(280, 30, GetColor(255, 255, 255), "%.1lf", goei.enemy.target.y);
		DrawFormatString(50, 20, GetColor(255, 255, 255), "%d", goei.enemy.moveflg);
		DrawFormatString(50, 40, GetColor(255, 255, 255), "%.1lf", goei.enemy.vct.x);
		DrawFormatString(60, 60, GetColor(255, 255, 255), "%.1lf", goei.enemy.vct.y);
		DrawFormatString(60, 80, GetColor(255, 255, 0), "%d", goei.enemy.dir);

		zako.Draw();
		goei.Draw();
		boss.Draw();
	}

	WaitKey();
	DxLib_End(); // DXライブラリ終了処理
	return 0;
}