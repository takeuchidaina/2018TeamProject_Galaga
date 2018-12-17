#include "EffectMgr.h"
#include "DXlib.h"

//Effect�N���X�̎���

//�R���X�g���N�^
cEffectMgr::cEffectMgr(){
	//���� ������1�h�b�g�����A�g�p Player��6,7,8 Enemy��34,35,36
	PcheckGr = LoadDivGraph("../resource/Image/Galaxian_OBJ_token.png",
		8, 4, 2, 34, 34, PBlowupGrHandle);
	if (PcheckGr == -1) ErrBox("Effect�摜�ǂݍ��݃G���[");//�G���[�`�F�b�N

	EcheckGr = LoadDivGraph("../resource/Image/Galaxian_OBJ_enemy.png",
		40, 8, 5, 18, 18, EBlowupGrHandle);
	if (EcheckGr == -1) ErrBox("Effect�摜�ǂݍ��݃G���[");//�G���[�`�F�b�N

	Init();
}

//������
void cEffectMgr::Init() {
	delete[] BlowupArray;
	BlowupArray = new cEffect[BLOWUPNUM];
}

//�f�X�g���N�^
cEffectMgr::~cEffectMgr() {
	delete[] BlowupArray;
}

int cEffectMgr::Update() {
	for (int i = 0; i < BLOWUPNUM; i++) {
		if (BlowupArray[i].Get_Type() == PLAYER) {
			BlowupArray[i].Update(PblowupOrders);
		}
		else if (BlowupArray[i].Get_Type() == ENEMY) {
			BlowupArray[i].Update(EblowupOrders);
		}
	}
	return 0;
}

int cEffectMgr::Draw() {
	for (int i = 0; i < BLOWUPNUM; i++) {
		if (BlowupArray[i].Get_Type() == PLAYER) {
			BlowupArray[i].Draw(PBlowupGrHandle);
		}
		else if (BlowupArray[i].Get_Type() == ENEMY) {
			BlowupArray[i].Draw(EBlowupGrHandle);
		}
	}
	return 0;
}

//��������������֐� ����(Player(0)��Enemy(1)��,cx,cy)
int cEffectMgr::Blowup(int type, int cx, int cy) {
	for (int i = 0; i < BLOWUPNUM; i++) {
		if (BlowupArray[i].Get_OnActive() == FALSE) {
			BlowupArray[i].Set_OnActive(TRUE);
			BlowupArray[i].Set_Type(type);
			BlowupArray[i].Set_CX(cx);
			BlowupArray[i].Set_CY(cy);
			break;
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