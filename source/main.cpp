#include "DxLib.h"
#include "Interface.h"
#include "SceneMgr.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetWindowSize(1280, 960);
	SetGraphMode(1280, 960, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	//初期化
	//cSceneMgr SceneMgr;
	//cInterface Interfase;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//ここに処理を追加
		//Interfase.Update();

		cInterface::Instance()->Update();

		cSceneMgr::Instance()->Update();
		cSceneMgr::Instance()->Draw();

		//SceneMgr.Update();
		//SceneMgr.Draw();

		if (cInterface::Instance()->Get_Input(InRIGHT) != 0) {
			DrawFormatString(0, 0, GetColor(255,255,255),"→キーが%dフレーム押されています", cInterface::Instance()->Get_Input(InRIGHT));
		}

	}

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}
