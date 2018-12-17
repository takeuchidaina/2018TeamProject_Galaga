#include "Effect.h"
#include "DXlib.h"
#include "UI.h"


//Effect�N���X�̎���

//�R���X�g���N�^
cEffect::cEffect() {
	w = 30;
	h = 30;
	OnActive = FALSE;
	adjust = 6;
	i = 0;
	nowGr = 0;
}

//�f�X�g���N�^
cEffect::~cEffect() {

}

int cEffect::Update(int* order) {
	if (OnActive == TRUE) {
		static int cnt = 0;
		cnt++;
		if (cnt > 30) {
			cnt = 0;
			i++;
		};
		if (i > 6) {
			OnActive = FALSE;
			i = 0;
		}
		nowGr = *(order + i);
	}
	return 0;
}

int cEffect::Draw(int* GrHandle) {
	if (OnActive == TRUE) {
		switch (nowGr) {
		case 0:
			if (type == PLAYER) {
				DrawExtendGraph((int)cx - IMAGEMAG / 2 - adjust, (int)cy - IMAGEMAG / 2,
					(int)cx + IMAGEMAG / 2 - adjust, (int)cy + IMAGEMAG / 2, *(GrHandle + 6), TRUE);
			}
			else if (type == ENEMY) {
				DrawExtendGraph((int)cx - IMAGEMAG / 2 - adjust, (int)cy - IMAGEMAG / 2,
					(int)cx + IMAGEMAG / 2 - adjust, (int)cy + IMAGEMAG / 2, *(GrHandle + 34), TRUE);
			}
			break;
		case 1:
			if (type == PLAYER) {
				DrawExtendGraph((int)cx - IMAGEMAG / 2 - adjust, (int)cy - IMAGEMAG / 2,
					(int)cx + IMAGEMAG / 2 - adjust, (int)cy + IMAGEMAG / 2, *(GrHandle + 7), TRUE);
			}
			else if (type == ENEMY) {
				DrawExtendGraph((int)cx - IMAGEMAG / 2 - adjust, (int)cy - IMAGEMAG / 2,
					(int)cx + IMAGEMAG / 2 - adjust, (int)cy + IMAGEMAG / 2, *(GrHandle + 35), TRUE);
			}
			break;
		case 2:
			if (type == PLAYER) {
				DrawExtendGraph((int)cx - IMAGEMAG / 2 - adjust, (int)cy - IMAGEMAG / 2,
					(int)cx + IMAGEMAG / 2 - adjust, (int)cy + IMAGEMAG / 2, *(GrHandle + 8), TRUE);
			}
			else if (type == ENEMY) {
				DrawExtendGraph((int)cx - IMAGEMAG / 2 - adjust, (int)cy - IMAGEMAG / 2,
					(int)cx + IMAGEMAG / 2 - adjust, (int)cy + IMAGEMAG / 2, *(GrHandle + 36), TRUE);
			}
			break;
		default:
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