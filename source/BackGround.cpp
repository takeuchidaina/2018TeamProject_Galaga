#include <DxLib.h>
#include"BackGround.h"

/* �R���X�g���N�^ */
cBackGround::cBackGround() {
	
	for (int i = 0; i < MAXSTAR; i++) {
		Init(i);
	}

}

/* �f�X�g���N�^ *
cBackGround::~cBackGround() {

}*/

void cBackGround::Update() {

	for (int i = 0; i < MAXSTAR; i++) {

		/* ���𗬂� */
		starArray[i].y += 10;
		if (starArray[i].y >= DISP_SIZE) Init(i);

		/* ����_�� */
		starArray[i].blinkCnt++;
		if (starArray[i].blinkCnt >= starArray[i].blinkNum) {
			starArray[i].blinkFlg *= -1;
		}

	}
}

void cBackGround::Draw() {

	for (int i = 0; i < MAXSTAR; i++) {
		if (starArray[i].blinkFlg == TRUE) {
			LoadGraphScreen((int)starArray[i].x, (int)starArray[i].y, 
				"../resource/Image/Star.png", TRUE);
		}
	}
}

/***************************************************************
	�֐��Fvoid cBackGround::Init
	�����F���̏����� or �Đ������s��
	�����F����������z��ԍ�(int)
	�ߒl�F�Ȃ�
***************************************************************/
void cBackGround::Init(int i) {

		starArray[i].x = Rand(0, DISP_SIZE);	//�����W
		starArray[i].y = Rand(-100, 300);		//�����W
		starArray[i].blinkCnt = 0;				//�_�ŃJ�E���g�p
		starArray[i].blinkNum = Rand(10, 100);	//�_�Ń^�C�~���O
		starArray[i].blinkFlg = TRUE;			//TRUE�F�\���@FALSE�F��\��

}
/***************************************************************
	�֐��Fint cBackGround::Rand(int lo, int hi)
	�����F�����_���������s��
	�����F�����_���͈͂̒ᐔ(int), �����_���͈�(int)
	�ߒl�F�����_������(int)
***************************************************************/
int cBackGround::Rand(int lo, int hi) {

	int r = 0;
	srand((unsigned int)time(NULL)); // ���ݎ����̏��ŏ�����
	r = (rand() % hi) + lo;

	return r;
}