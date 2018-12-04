#include "Shot.h"
#include "DxLib.h"
#include "UI.h"

//Template�N���X�̎���

//�R���X�g���N�^(������)
cShot::cShot(){
	s = 10;
	w = 10*3; h = 12*3;//���f�[�^��3�{�Ɋg��
	OnActive=0;
	r = 8;
	adjust = 6;
}

//�f�X�g���N�^
cShot::~cShot() {

}

int cShot::Update() {
	/*cx = x + (w / 2);//cx,cy�̃Z�b�g
	cy = y + (h / 2);
	r = 3*3;*/

	//x��y�̈ړ�(���W�A���Ńx�N�g�����v�Z)
	cx += s*cos(rad);
	cy += s*sin(rad);
	//��ʊO�ɍs������FALSE�ɂ���
	if (cx-w/2 < 0 || cx+w/2> 910|| cy-h/2 < 0 || cy+h/2>960) {
		OnActive = FALSE;
	}
	return 0;
}

int cShot::Draw(int num,int *GrHandle) {
	if (num == PLAYER) {//0=playerShot 1=enemyShot
		if (OnActive == TRUE) {//0=false,1=true
		  //DrawBox(cx-w/2, cy-h/2, cx+w/2, cy+h/2, GetColor(255, 255, 255), TRUE);
			//DrawExtendGraph(cx-w/2, cy-h/2, cx+w/2, cy+h/2, *(GrHandle + 3), TRUE);
			DrawExtendGraph((int)cx-IMAGEMAG/2-adjust, (int)cy-IMAGEMAG/2, 
				(int)cx+IMAGEMAG/2-adjust, (int)cy+IMAGEMAG/2, *GrHandle, TRUE);
			//DrawGraph(cx, cy, *(GrHandle+3), TRUE);
		}
	
	}

	if (num == ENEMY) {//0=playerShot 1=enemyShot
		if (OnActive == TRUE) {
			//DrawBox(cx-w/2, cy-h/2, cx+w/2, cy+h/2, GetColor(255, 255, 255), TRUE);
			//DrawCircle(x, y, x + w, y + h, GetColor(255, 255, 255), TRUE);
			//DrawExtendGraph(cx-w/2, cy-h/2, cx+w/2, cy+h/2, *GrHandle, TRUE);
			DrawExtendGraph((int)cx - IMAGEMAG / 2-adjust, (int)cy - IMAGEMAG / 2, 
				(int)cx + IMAGEMAG / 2-adjust, (int)cy + IMAGEMAG / 2, *(GrHandle + 3), TRUE);
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