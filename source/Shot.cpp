#define _USE_MATH_DEFINES
#include <math.h>
#include "Shot.h"
#include "DxLib.h"
#include "UI.h"

//Template�N���X�̎���

//�R���X�g���N�^(������)
cShot::cShot(){
	s = 10;
	w = 10*3; h = 12*3;//���f�[�^��3�{�Ɋg��
	OnActive=0;
	r = 5;
}

//�f�X�g���N�^
cShot::~cShot() {

}

int cShot::Update() {
	/*cx = x + (w / 2);//cx,cy�̃Z�b�g
	cy = y + (h / 2);
	r = 3*3;*/
	//x��y�̈ړ�(���W�A���Ńx�N�g�����v�Z)
	cx += s*sin(rad* M_PI / 180);
	cy += s*cos(rad* M_PI / 180);
	//��ʊO�ɍs������FALSE�ɂ���
	if (cx-w/2 < 0 || cx+w/2> 910|| cy-h/2 < 0 || cy+h/2>960) {
		OnActive = FALSE;
	}
	return 0;
}

int cShot::Draw(int num,int *GrHandle) {
	if (num == PLAYER) {//0=playerShot 1=enemyShot
		//if (OnActive == TRUE) {//0=false,1=true
		DrawBox(cx-w/2, cy-h/2, cx+w/2, cy+h/2, GetColor(255, 255, 255), TRUE);
		  //DrawExtendGraph(x, y, x + w, y + h, *GrHandle+3, FALSE);
		  //DrawGraph(cx, cy, *GrHandle+3, FALSE);
	  //}
	}

	if (num == ENEMY) {//0=playerShot 1=enemyShot
		if (OnActive == TRUE) {
			DrawCircle(x, y, x + w, y + h, GetColor(255, 255, 255), TRUE);
			//DrawExtendGraph(x, y, x + w, y + h, GrHandle[0], FALSE);
		}
	}
	return 0;
}

/*
//������
//mTest�ւ̑��
void cTemplate::Set_Test(int Test) {
	mTest = Test;
}

//mTest�̊l��
int cTemplate::Get_Test() {
	return mTest;
}
*/