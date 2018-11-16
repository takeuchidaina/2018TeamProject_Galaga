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

 static int i = 0;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetGraphMode(1280, 960, 32);
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
	
																		 
																		 
																		 
	//x y r cnt spd ang flg

	cBlueEnemy zako(300, 330, 5, 0, 3, 180, false);
	cRedEnemy  goei(400,330,5,0,3,180,false);
	cGreenEnemy boss(500,330,5,0,3,180,false);

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {//��ʍX�V & ���b�Z�[�W���� & ��ʏ���
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
		
		zako.Move(zako);
		goei.Move(goei);
		boss.Move(boss);

		
		zako.Draw();
		goei.Draw();
		boss.Draw();
	}

	WaitKey();
	DxLib_End(); // DX���C�u�����I������
	return 0;
}