#include "DxLib.h"
#include "Interface.h"
#include "SceneMgr.h"
#include "Fps.h"
#include "WinBox.h"
#include "Debug.h"
//#include "Resource.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetMainWindowText("2018進級制作 チームA ギャラガ");
	SetWindowIconID(101);
	SetWindowSize(1280, 960);
	SetGraphMode(1280, 960, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	//初期化
	//cSceneMgr SceneMgr;
	//cInterface Interfase;
	if (InterfaceYesNoBox() == IDYES)cInterface::Instance()->Set_InputType(InGamepad);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//ここに処理を追加
		//Interfase.Update();
		cFps::Instance()->Update();

		//Debug::Instance()->Update();
		cInterface::Instance()->Update();

		cSceneMgr::Instance()->Update();
		cSceneMgr::Instance()->Draw();

		//cFps::Instance()->Draw();

		cFps::Instance()->Wait();


		//SceneMgr.Update();
		//SceneMgr.Draw();
		/*
		if (cInterface::Instance()->Get_Input(InRIGHT) != 0) {
			DrawFormatString(0, 0, GetColor(255,255,255),"→キーが%dフレーム押されています", cInterface::Instance()->Get_Input(InRIGHT));
		}
		*/
	}

	DxLib_End(); // DXライブラリ終了処理
	return 0;
}
