#include "hit.h"

//hit�N���X�̎���

//�R���X�g���N�^
cHit::cHit(){
	
}

//�f�X�g���N�^
cHit::~cHit() {

}

int cHit::Update() {
	
	return 0;
}

int cHit::Draw() {

	/* �v���C���[�ƓG�e */
	for (int i = 0; i < pNum; i++) {

		if (pActive == false) continue;

		for (int j = 0; j < bNum; j++) {

			if (bActive == false) continue;

			len = (bcx - pcx)*(bcx - pcx) + (bcy - pcy)*(bcy - pcy);

			if (len <= ((br + pr)*(br + pr)) ) {
				bulletHit(enemy, j);
				playerDown(i);
			}
		}
	}

	/* �v���C���[�ƓG�@�@*/
	for (int i = 0; i < pNum; i++) {

		if (pActive == false) continue;

		for (int j = 0; j < eNum; j++) {

			if (eActive == false) continue;

			len = (ecx - pcx)*(ecx - pcx) + (ecy - pcy)*(ecy - pcy);

			if (len <= ((er + pr)*(er + pr))) {
				playerDown(player, i);
				enemyDown(enemy, j)
			}
		}
	}

	/* ���e�ƓG�@�@*/
	for (int i = 0; i < eNum; i++) {

		if (eActive == false) continue;

		for (int j = 0; j < ebNum; j++) {

			if (ebActive == false) continue;

			len = (ebcx - ecx)*(ebcx - ecx) + (ebcy - ecy)*(ebcy - ecy);

			if (len <= ((er + ebr)*(er + ebr))) {
				playerDown();
			}
		}
	}

	
	return 0;
}

//beemHit�N���X�̎���

//�R���X�g���N�^
cBeemHit::cBeemHit() {

}

//�f�X�g���N�^
cBeemHit::~cBeemHit() {

}

int cBeemHit::Update() {

	return 0;
}

int cBeemHit::Draw() {

	if (((ecx - beemR) <= pcx) && ((ecx + beemR) >= pcx)) {
		inGameMgr(numEnemy);
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