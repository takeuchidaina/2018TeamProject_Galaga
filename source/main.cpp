#include "DxLib.h"
#include "Interface.h"
#include "SceneMgr.h"

cInterface Interface;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetWindowSize(1280, 720);
	SetGraphMode(1280, 720, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	//������
	cSceneMgr SceneMgr;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//�����ɏ�����ǉ�
		Interface.Update();

		SceneMgr.Update();
		SceneMgr.Draw();


	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}
