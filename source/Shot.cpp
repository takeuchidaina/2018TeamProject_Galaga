#include "Shot.h"
#include "DxLib.h"
#include "UI.h"

//Template�N���X�̎���

//�R���X�g���N�^(������)
cShot::cShot(){
	w = 10*3; h = 12*3;//���f�[�^��3�{�Ɋg��
	OnActive=0;
}

//�f�X�g���N�^
cShot::~cShot() {

}

int cShot::Update() {
	//x��y�̈ړ�(���W�A���Ńx�N�g�����v�Z)
	return 0;
}

int cShot::Draw(int num,int GrHandle[]) {
	if (num == 0) {//0=playerShot 1=enemyShot
		if (OnActive == TRUE) {//0=false,1=true
			DrawExtendGraph(x, y, x + w, y + h, GrHandle[3], FALSE);
		}
	}

	if (num == 1) {//0=playerShot 1=enemyShot
		if (OnActive == TRUE) {
			DrawExtendGraph(x, y, x + w, y + h, GrHandle[0], FALSE);
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