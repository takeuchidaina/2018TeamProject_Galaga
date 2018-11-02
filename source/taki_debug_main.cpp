#include <iostream>
using namespace std;
#include <stdio.h>
#include <math.h>
#include "cBaseEnemy.h"
#include "DxLib.h"
#include "Struct.h"



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetGraphMode(1024, 768, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定
	//x y r cnt spd ang flg

	cBaseEnemy unit(160,64,5,0,3,180,false);


	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//画面更新 & メッセージ処理 & 画面消去
		unit.enemy.count++;
		if (unit.enemy.count > 0) {
			unit.enemy.onActive = true;
		}
		if (unit.enemy.onActive != true) continue;
		
		switch (unit.enemy.moveflg)
		{
		case 0:
			unit.enemy.ang += unit.enemy.moveang[unit.enemy.moveflg] * 3.1419265 / 180;
			unit.Move(unit);
			if (unit.enemy.countflg[unit.enemy.moveflg] <= unit.enemy.count) {
				unit.enemy.moveflg++;
				unit.enemy.count = 0;
			}
			break;
		case 1:
			unit.enemy.ang += unit.enemy.moveang[unit.enemy.moveflg] * 3.1419265 / 180;
			unit.Move(unit);
			if (unit.enemy.countflg[unit.enemy.moveflg] <= unit.enemy.count) {
				unit.enemy.moveflg++;
				unit.enemy.count = 0;
			}
			break;
		case 2:
			unit.enemy.ang += unit.enemy.moveang[unit.enemy.moveflg] * 3.1419265 / 180;
			unit.Move(unit);
			if (unit.enemy.countflg[unit.enemy.moveflg] <= unit.enemy.count) {
				unit.enemy.moveflg++;
				unit.enemy.count = 0;
			}
			break;
		case 3:
			unit.enemy.ang = 0;
			unit.enemy.ang += unit.enemy.moveang[unit.enemy.moveflg] * 3.1419265 / 180;
			unit.Move(unit);
			if (unit.enemy.countflg[unit.enemy.moveflg] <= unit.enemy.count) {
				unit.enemy.moveflg++;
				unit.enemy.count = 0;
			}
			break;
		case 4:
			//unit.enemy.ang = 0;
			unit.enemy.ang += unit.enemy.moveang[unit.enemy.moveflg] * 3.1419265 / 180;
			unit.Move(unit);
			if (unit.enemy.countflg[unit.enemy.moveflg] <= unit.enemy.count) {
				unit.enemy.moveflg++;
				unit.enemy.count = 0;
			}
			break;
		case 5:
			unit.enemy.ang += atan2( unit.enemy.target.y- unit.enemy.pos.y, unit.enemy.target.x- unit.enemy.pos.x);
			unit.Move(unit);
			if ((unit.enemy.target.x - unit.enemy.pos.x)*(unit.enemy.target.x - unit.enemy.pos.x) *
				(unit.enemy.target.y - unit.enemy.pos.y)*(unit.enemy.target.y - unit.enemy.pos.y) <=
				(unit.enemy.r - 3 + unit.enemy.targetr)*(unit.enemy.r - 3 + unit.enemy.targetr)) {
				//敵座標を目的地に固定
				unit.enemy.pos.x = unit.enemy.target.x;
				unit.enemy.pos.y = unit.enemy.target.y;
				unit.enemy.moveflg++;
				unit.enemy.count = 0;
			}
			break;
		case 6:
			unit.enemy.count = 0;
			break;
			
		}
		DrawFormatString(100, 0, GetColor(255, 255, 255), "%.1lf", unit.enemy.pos.x);
		DrawFormatString(150, 0, GetColor(255, 255, 255), "%.1lf", unit.enemy.pos.y);
		DrawFormatString(100, 15, GetColor(255, 255, 255), "%.1lf", unit.enemy.vct.x);
		DrawFormatString(150, 15, GetColor(255, 255, 255), "%.1lf", unit.enemy.vct.y);
		DrawFormatString(100, 25, GetColor(255, 255, 255), "%.1lf", unit.enemy.target.x);
		DrawFormatString(150, 25, GetColor(255, 255, 255), "%.1lf", unit.enemy.target.y);
		DrawFormatString(0, 20, GetColor(255, 255, 255), "%d", unit.enemy.moveflg);
		DrawFormatString(0, 40, GetColor(255, 255, 255), "%.1lf", unit.enemy.vct.x);
		DrawFormatString(0, 60, GetColor(255, 255, 255), "%.1lf", unit.enemy.vct.y);
		unit.Draw();
	}
	WaitKey();
	DxLib_End(); // DXライブラリ終了処理
	return 0;
}