#include "DxLib.h"
#include "Interface.h"
#include "SceneMgr.h"

cInterface Interface;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetWindowSize(1280, 720);
	SetGraphMode(1280, 720, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	//初期化
	cSceneMgr SceneMgr;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//ここに処理を追加
		Interface.Update();

		SceneMgr.Update();
		SceneMgr.Draw();


	}

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}
