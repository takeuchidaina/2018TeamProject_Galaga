#include <DxLib.h>
#include"BackGround.h"

/* �R���X�g���N�^ */
cBackGround::cBackGround() {
	
	for (int i = 0; i < MAXSTAR; i++) {
		Init(i);
	}

	srand((unsigned int)time(NULL)); // ���ݎ����̏��ŏ�����

	image = LoadGraph("../resource/Image/Star.png");
}

/* �f�X�g���N�^ 
cBackGround::~cBackGround() {

}*/

void cBackGround::Update() {

	for (int i = 0; i < MAXSTAR; i++) {

		/* ���𗬂� */
		starArray[i].y += starArray[i].speed;
		if (starArray[i].y >= DISP_SIZE + 50) {
			starArray[i].y = (rand() % 100) - 100;
			starArray[i].x = rand() % DISP_SIZE;
		}

		/* ����_�� */
		starArray[i].blinkCnt++;
		if (starArray[i].blinkCnt >= starArray[i].blinkNum) {
			starArray[i].blinkFlg *= -1;
			starArray[i].blinkCnt = 0;
		}

	}
}

void cBackGround::Draw() {

	for (int i = 0; i < MAXSTAR; i++) {
		if (starArray[i].blinkFlg == TRUE) {
			DrawGraph((int)starArray[i].x, (int)starArray[i].y,
				image, TRUE);
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

	starArray[i].x = rand() % DISP_SIZE;			//�����W
	starArray[i].y = (rand() % DISP_SIZE) - 100;	//�����W
	starArray[i].speed = 2;							//�ړ����x
	starArray[i].blinkCnt = 0;						//�_�ŃJ�E���g�p
	starArray[i].blinkNum = (rand() % 100) +10;		//�_�Ń^�C�~���O
	starArray[i].blinkFlg = TRUE;					//TRUE�F�\���@FALSE�F��\��

}
