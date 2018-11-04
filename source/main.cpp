#include "DxLib.h"
#include "Interface.h"
#include "SceneMgr.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetWindowSize(1280, 720);
	SetGraphMode(1280, 720, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	//������
	cSceneMgr SceneMgr;
	cInterface Interfase;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//�����ɏ�����ǉ�
		Interfase.Update();

		SceneMgr.Update();
		SceneMgr.Draw();

		//if (Interfase.Get_Input(InRIGHT) != 0) {
		//	DrawFormatString(0, 0, GetColor(255,255,255),"���L�[��%d�t���[��������Ă��܂�", Interfase.Get_Input(InRIGHT));
		//}

	}

	DxLib_End(); // DX���C�u�����I������
	return 0;
}
