#include <DxLib.h>
#include"BackGround.h"

/* �R���X�g���N�^ */
cBackGround::cBackGround() {
	
	for (int i = 0; i < MAXSTAR; i++) {
		Init(i);
	}

	srand((unsigned int)time(NULL)); // ���ݎ����̏��ŏ�����

}

/* �f�X�g���N�^ 
cBackGround::~cBackGround() {

}*/

void cBackGround::Update() {

	for (int i = 0; i < MAXSTAR; i++) {

		/* ���𗬂��i�ʏ�j */
		starArray[i].y += starArray[i].speed;

		if (starArray[i].y >= DISP_SIZE + 50) {		//���܂ōs������Đ���
			starArray[i].y = (rand() % 150) - 150;
			starArray[i].x = rand() % DISP_SIZE;
			starArray[i].r = (rand() % 2) + 1;
			starArray[i].color = GetColor(rand() % 255, rand() % 255, rand() % 255);
		}

		/* ����_�� */
		starArray[i].blinkCnt++;
		if (starArray[i].blinkCnt >= starArray[i].blinkNum) {
			starArray[i].blinkFlg *= -1;
			starArray[i].blinkCnt = 0;
		}

	}
}

void cBackGround::TractingUpdate() {

	for (int i = 0; i < MAXSTAR; i++) {

		starArray[i].y -= starArray[i].speed * 5;

		if (starArray[i].y <= -50) {		//���܂ōs������Đ���
			starArray[i].y = (rand() % 150) + (DISP_SIZE);
			starArray[i].x = rand() % DISP_SIZE;
			starArray[i].r = (rand() % 2) + 1;
			starArray[i].color = GetColor(rand() % 255, rand() % 255, rand() % 255);
		}

	}

}

void cBackGround::Draw() {

	for (int i = 0; i < MAXSTAR; i++) {
		if (starArray[i].blinkFlg == TRUE) {
			//���`��(�~)
			DrawCircle((int)starArray[i].x, (int)starArray[i].y, starArray[i].r, starArray[i].color, TRUE);
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
	starArray[i].y = (rand() % DISP_SIZE+100) - 200;	//�����W
	starArray[i].r = (rand() % 2) + 1;				//���a
	starArray[i].speed = 1;							//�ړ����x
	starArray[i].blinkCnt = 0;						//�_�ŃJ�E���g�p
	starArray[i].blinkNum = (rand() % 100) +10;		//�_�Ń^�C�~���O
	starArray[i].blinkFlg = TRUE;					//TRUE�F�\���@FALSE�F��\��
	starArray[i].color = GetColor(rand() % 255, rand() % 255, rand() % 255);	//�F�ݒ�

}
