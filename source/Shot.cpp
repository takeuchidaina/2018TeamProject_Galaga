#include "Shot.h"
#include "DXlib.h"

//Template�N���X�̎���

//�R���X�g���N�^(������)
cShot::cShot(){
	x=y=r=w=h=c=0;
	OnActive=0;

}

//�f�X�g���N�^
cShot::~cShot() {

}

int cShot::Update() {
	y++;
	return 0;
}

int cShot::Draw() {
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