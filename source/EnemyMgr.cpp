#include "EnemyMgr.h"
#include <Dxlib.h>
#include <math.h>

//�R���X�g���N�^
cEnemyMgr::cEnemyMgr() {
	//�G�̔z�񐔕��̏��������s��
	for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
		enemy[i].pos.x = 400;
		enemy[i].pos.y = -50;
		enemy[i].r = 5;
		enemy[i].count = 0 - (i / 2);
		enemy[i].angle = 100 * 3.1415 / 180;
		enemy[i].speed = 3;
		enemy[i].moveflag = 0;
		enemy[i].maxmove = 3;
		memset(enemy[i].moveangle, 0, sizeof(enemy[i].moveangle));
		enemy[i].moveangle[0] = 0.5;
		enemy[i].moveangle[1] = 0;
		enemy[i].moveangle[2] = -2.5;
		memset(enemy[i].countflag, 0, sizeof(enemy[i].countflag));
		enemy[i].countflag[0] = 100;
		enemy[i].countflag[1] = 20;
		enemy[i].countflag[2] = 90;
		enemy[i].RLflag = 1;
		enemy[i].target.x = 320 + i / 2 * 32;
		enemy[i].target.y = 64 + (i % 2) * 32;
		enemy[i].targetr = 1;
		enemy[i].onactive = 0;
	}
	
	movetype = 1;  //�G�̓���^�C�v(����[���ĂȂ������ア�[����ĂȂ���)

	if (movetype == 1) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (i < 8) {
				enemy[i].count = 0 - (i % 8 / 2) * 20;
				enemy[i].target.x = 160 + 32 + (i + 8) / 2 * 32;
				continue;
			}
			enemy[i].pos.x = 240;
			enemy[i].angle = 80 * 3.1415 / 180;
			enemy[i].count = 0 - (i % 8 / 2) * 20;
			enemy[i].moveangle[0] = -0.5;
			enemy[i].moveangle[1] = 0;
			enemy[i].moveangle[2] = 2.5;
			enemy[i].RLflag = -1;
			enemy[i].target.x = 320 - 32 - (i - 8) / 2 * 32;
		}
	}
}

//�f�R���X�g���N�^
cEnemyMgr::~cEnemyMgr() {

}


//�v�Z����
void cEnemyMgr::Update() {

	for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
		//���t���[���J�E���g�𑝂₷
		enemy[i].count++;
		//�J�E���g��0��葽����΁A�G�̕\�������true(1)�ɂ���
		if (enemy[i].count > 0) {
			enemy[i].onactive = 1;
		}
		//�G�̔������肪true�łȂ��ꍇ�͈ȍ~�̏����𖳎�(continue)����i�����Z����
		if (enemy[i].onactive != 1)continue;
		
		//moveflag��10�ɂȂ�܂ŉ��L�̏������s��
		if (enemy[i].moveflag < 10) {
		    
			//�G�̊p�x�����Z����(���W�A���P��)
			enemy[i].angle += enemy[i].moveangle[enemy[i].moveflag]*3.1415/180;

			//�G�𓮂�������(�ʓr�֐��ōs��)
			Move(enemy[i]);
			//�Е��̗�����܂��͉E�ɂ��炷
			if (i % 2 == 1) Shifted(enemy[i], enemy[i - 1]);

			//���̃t���[�����ɂȂ����玟�̓���ֈڍs����
			if (enemy[i].countflag[enemy[i].moveflag] == enemy[i].count) {
				enemy[i].moveflag++;
				//�t���[���J�E���g�����Z�b�g����
				enemy[i].count = 0;
				//moveflag��maxmove(3)�ɂȂ�����moveflag��10�ɂ��ė�O�����ֈڍs
				if (enemy[i].moveflag == enemy[i].maxmove) {
					enemy[i].moveflag = 10;
				}
			}
		} //�G��̂��Ƃ̓��ꓮ��I��
		//moveflag��10�ɂȂ����ꍇ�A�ڕW�ʒu�܂ňړ�
			if (enemy[i].moveflag == 10) {
				enemy[i].angle = atan2(enemy[i].target.y - enemy[i].pos.y, enemy[i].target.x - enemy[i].pos.x); 
				Move(enemy[i]);
				if ((enemy[i].target.x - enemy[i].pos.x)*(enemy[i].target.x - enemy[i].pos.x) +
					(enemy[i].target.y - enemy[i].pos.y)*(enemy[i].target.y - enemy[i].pos.y) <=
					(enemy[i].r - 3 + enemy[i].targetr)*(enemy[i].r - 3 + enemy[i].targetr)) {
					enemy[i].pos.x = enemy[i].target.x;
					enemy[i].pos.y = enemy[i].target.y;
					enemy[i].moveflag++;
					enemy[i].count = 0;
				}
				/*else {
					enemy[i].pos.x = enemy[i].target.x;
					enemy[i].pos.y = enemy[i].target.y;
				}*/
		    } //��O�����I��
	} //�z�񐔕��̓G����I��

}

	void cEnemyMgr::Move(sEnemy& enemy) {
		//�p�x���瓮�������̍��W���v�Z����
		enemy.v.x = cos(enemy.angle);
		enemy.v.y = sin(enemy.angle);

		//���W�Ɉړ������Ƒ��x�����Z������
		enemy.pos.x += enemy.v.x * enemy.speed;
		enemy.pos.y += enemy.v.y * enemy.speed;
	}

	//���ڂ̓G�����ɂ��炷
	void cEnemyMgr::Shifted(sEnemy& ene1, sEnemy& ene2) {
		//���ڂ̍��W�ɓ��ڂ̓G�̍��W���R�s�[����
		ene1.pos.x = ene2.pos.x;
		ene1.pos.y = ene2.pos.y;

		//�i�s����(angle)�ɑ΂���90�x�̊p�x(RLflag)��30�h�b�g���炷(*30)
		ene1.pos.x += cos(ene1.angle + 90 * 3.1415 / 180 * ene1.RLflag) * 30;
		ene1.pos.y += sin(ene1.angle + 90 * 3.1415 / 180 * ene1.RLflag) * 30;
	}


//�`�ʏ���
void cEnemyMgr::Draw() {
	DrawFormatString(0, 20, GetColor(255, 255, 255), "[0]:x=%.1lf y=%.1lf",enemy[0].pos.x,enemy[0].pos.y);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "[7]:x=%.1lf y=%.1lf", enemy[7].pos.x, enemy[7].pos.y);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "atan2=%.3lf", atan2(enemy[0].target.y - enemy[0].pos.y, enemy[0].target.x - enemy[0].pos.x));
	
	for (int i = 0; i < sizeof(enemy) / sizeof(*enemy); i++) {
		//�G�z��̕`��
		if (i % 2 == 0) {
			DrawCircle(enemy[i].pos.x, enemy[i].pos.y, enemy[i].r, GetColor(255, 255, 255), TRUE);
		}
		else {
			DrawCircle(enemy[i].pos.x, enemy[i].pos.y, enemy[i].r, GetColor(255, 0, 0), TRUE);
		}

	}
}