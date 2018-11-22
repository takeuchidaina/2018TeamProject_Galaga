#include "DxLib.h"
#include "Interface.h"
#include "SceneMgr.h"
#include "Fps.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetWindowSize(1280, 960);
	SetGraphMode(1280, 960, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	//������
	//cSceneMgr SceneMgr;
	//cInterface Interfase;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//�����ɏ�����ǉ�
		//Interfase.Update();
		cFps::Instance()->Update();

		cInterface::Instance()->Update();

		cSceneMgr::Instance()->Update();
		cSceneMgr::Instance()->Draw();

		cFps::Instance()->Draw();

		//cFps::Instance()->Wait();


		//SceneMgr.Update();
		//SceneMgr.Draw();
		/*
		if (cInterface::Instance()->Get_Input(InRIGHT) != 0) {
			DrawFormatString(0, 0, GetColor(255,255,255),"���L�[��%d�t���[��������Ă��܂�", cInterface::Instance()->Get_Input(InRIGHT));
		}
		*/
	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}
