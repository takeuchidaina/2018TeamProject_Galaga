#include "EnemyMgr.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <Dxlib.h>
#include "cBaseEnemy.h"
#include "cBlueEnemy.h"
#include "cRedEnemy.h"
#include "cGreenEnemy.h"
#include "Struct.h"

//�R���X�g���N�^
cEnemyMgr::cEnemyMgr() {
	memset(waveflag, 0x00, sizeof(waveflag));
	wave = 1;
	fileEndFlag = 0;
	n = 0;
	num = 0;
	strcpy(StageFilePath, "../resource/MAP/Stage_2.csv");
	Phaseflag = 0;
	onActiveCount = 0;
	Stayflag = 0;

	//�摜�̓ǂݍ��ݏ���
	LoadDivGraph("../resource/Image/Galaga_OBJ_enemy1616.png", 20, 5, 4, 16, 16, EnemyGraph);

	//Stage_1.csv
	StageHandle = FileRead_open(StageFilePath);
	if (StageHandle == 0);  //�G���[�����̋L���r��

							//�ŏ��̓�s�@�ǂݔ�΂��@�����@
	for (int i = 0; i < 2; i++)while (FileRead_getc(StageHandle) != '\n');

	//�t�@�C���̓ǂݎ�菈��(break��while���𔲂��鏈���Ȃ̂ŏ�������1�ɐݒ肳��Ă���)
	while (1) {

		for (int i = 0; i < 64; i++) {
			inputc[i] = input[i] = FileRead_getc(StageHandle);//1�����擾����
			if (inputc[i] == '/') {//�X���b�V���������
				while (FileRead_getc(StageHandle) != '\n');//���s�܂Ń��[�v
				i = -1;//�J�E���^���ŏ��ɖ߂���
				continue;
			}
			if (input[i] == ',' || input[i] == '\n') {//�J���}�����s�Ȃ�
				inputc[i] = '\0';//�����܂ł𕶎���Ƃ�
				break;
			}
			if (input[i] == EOF) {//�t�@�C���̏I���Ȃ�
				fileEndFlag = 1;//�I��
				break;
			}
		}

		//�t�@�C���I�������t���O�������Ă���ꍇ�͈ȉ��̏������s��Ȃ�
		if (fileEndFlag == 1)break;
		switch (num) {
		case 0: tmpEnemy.pos.x = atof(inputc); break;
		case 1: tmpEnemy.pos.y = atof(inputc); break;
		case 2: tmpEnemy.r = atoi(inputc); break;
		case 3: tmpEnemy.count = atoi(inputc); break;
		case 4: tmpEnemy.angle = atof(inputc)* M_PI / 180; break;
		case 5: tmpEnemy.speed = atoi(inputc); break;
		case 6: tmpEnemy.maxmove = atoi(inputc); break;
		case 7:tmpEnemy.RLflag = atoi(inputc); break;
		case 8:tmpEnemy.target.x = atof(inputc); break;
		case 9:tmpEnemy.target.y = atof(inputc); break;
		case 10:tmpEnemy.targetr = atoi(inputc); break;
		case 11:tmpEnemy.wave = atoi(inputc); break;
		case 12:tmpEnemy.etype = atoi(inputc); break;
		case 13:tmpEnemy.moveangle[0] = atof(inputc); break;
		case 14:tmpEnemy.countflag[0] = atoi(inputc); break;
		case 15:tmpEnemy.moveangle[1] = atof(inputc); break;
		case 16:tmpEnemy.countflag[1] = atoi(inputc); break;
		case 17:tmpEnemy.moveangle[2] = atof(inputc); break;
		case 18:tmpEnemy.countflag[2] = atoi(inputc); break;
		}

		switch (num) {
		case 0: enemy[n].pos.x = atof(inputc); break;
		case 1: enemy[n].pos.y = atof(inputc); break;
		case 2: enemy[n].r = atoi(inputc); break;
		case 3: enemy[n].count = atoi(inputc); break;
		case 4: enemy[n].angle = atof(inputc) *M_PI / 180; break;
		case 5: enemy[n].speed = atoi(inputc); break;
		case 6: enemy[n].maxmove = atoi(inputc); break;
		case 7:enemy[n].RLflag = atoi(inputc); break;
		case 8:enemy[n].target.x = atof(inputc); break;
		case 9:enemy[n].target.y = atof(inputc); break;
		case 10:enemy[n].targetr = atoi(inputc); break;
		case 11:enemy[n].wave = atoi(inputc); break;
		case 12:enemy[n].etype = atoi(inputc); break;
		case 13:enemy[n].moveangle[0] = atof(inputc); break;
		case 14:enemy[n].countflag[0] = atoi(inputc); break;
		case 15:enemy[n].moveangle[1] = atof(inputc); break;
		case 16:enemy[n].countflag[1] = atoi(inputc); break;
		case 17:enemy[n].moveangle[2] = atof(inputc); break;
		case 18:enemy[n].countflag[2] = atoi(inputc); break;
		}

		enemy[n].v.x = 0;
		enemy[n].v.y = 0;
		enemy[n].moveflag = 0;
		enemy[n].onactive = false;

		num++;
		if (num == 19) {
			num = 0;
			/*switch����type���݂�,���ʂɍ��킹��tmpEnemy�̃f�[�^�����ꂼ���cbaseEnemy�ɂ����*/
			switch (tmpEnemy.etype) {
			case 0:
				enemies[n] = (cBaseEnemy*) new cBlueEnemy(tmpEnemy.pos.x, tmpEnemy.pos.y, tmpEnemy.r, tmpEnemy.count, tmpEnemy.speed, tmpEnemy.angle, tmpEnemy.onactive, EnemyGraph);
				break;
			case 1:
				enemies[n] = (cBaseEnemy*) new cRedEnemy(tmpEnemy.pos.x, tmpEnemy.pos.y, tmpEnemy.r, tmpEnemy.count, tmpEnemy.speed, tmpEnemy.angle, tmpEnemy.onactive, EnemyGraph);
				break;
			case 2:
				enemies[n] = (cBaseEnemy*) new cGreenEnemy(tmpEnemy.pos.x, tmpEnemy.pos.y, tmpEnemy.r, tmpEnemy.count, tmpEnemy.speed, tmpEnemy.angle, tmpEnemy.onactive, EnemyGraph);
				break;

				/*case3:player���G�ɂȂ������̏��������悤*/

			}
			n++;
		}
	}

	//�t�@�C�������
	FileRead_close(StageHandle);

	//waveflag�̏������@���ꂷ���waveflag���ɊY��wave�ŉ��̓G���o�����邩��c���ł���
	for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
		waveflag[enemy[i].wave]++;
	}
}

//�f�R���X�g���N�^
//cEnemyMgr::~cEnemyMgr() {

//}


//�v�Z����
void cEnemyMgr::Update() {
	phaseFlagCount = 0;
	wavecount = 0;
	onActiveCount = 0;
	if (Phaseflag == 0) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (enemy[i].wave == wave) {
				//���t���[���J�E���g�𑝂₷
				enemy[i].count++;
				//�J�E���g��0��葽����΁A�G�̕\�������true(1)�ɂ���
				if (enemy[i].count > 0) {
					enemy[i].onactive = 1;
				}
				//�G�̔������肪true�łȂ��ꍇ�͈ȍ~�̏����𖳎�(continue)����i�����Z����
				if (enemy[i].onactive != 1)continue;

				onActiveCount++;

				//moveflag��10�ɂȂ�܂ŉ��L�̏������s��
				if (enemy[i].moveflag < 10) {

					//�G�̊p�x�����Z����(���W�A���P��)
					enemy[i].angle += enemy[i].moveangle[enemy[i].moveflag] * 3.1415 / 180;

					//�G�𓮂�������(�ʓr�֐��ōs��)
					Move(enemy[i]);
					//�Е��̗�����܂��͉E�ɂ��炷
					//if (i % 2 == 1) Shifted(enemy[i], enemy[i - 1]);
					if (enemy[i].RLflag != 0)	Shifted(enemy[i], enemy[i - 1]);

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
						enemy[i].angle = -90 * M_PI / 180;
					}
				} //��O�����I��
			} //active�ȃG�l�~�[�̓��쏈���I��

			if (enemy[i].moveflag == 11) {

				//����s�����I�����Ă���G�̐����J�E���g����
				phaseFlagCount++;
				//�E�F�[�u���œ���s�����I�����Ă���G�̐����J�E���g����
				if (enemy[i].wave == wave) {
					wavecount++;
				}
			}
			//�E�F�[�u���Ƃɓ����G�̐��Ɠ���s�����I�����Ă���G�̐�����v���Ă���ꍇ�A���E�F�[�u�Ɉڍs,�G�̃J�E���g��������
			if (waveflag[wave] == wavecount) {
				wave++;
				wavecount = 0;
			}

			//�N���X��Enemy�z���i�ԖڂɃN���X�łȂ��ق���Enemy(sEnemyMgrData)��������
			enemies[i]->SetEnemyX(enemy[i].pos.x);
			enemies[i]->SetEnemyY(enemy[i].pos.y);
			enemies[i]->SetEnemyAngle(enemy[i].angle);

			/*
			if (phaseFlagCount == onActiveCount) {
			Phaseflag = 1;
			}
			*/
		}//�z�񐔕��̓G����I��

		 //�G�������Ă��Ȃ��t���O��on�ɂ���
		Stayflag = 1;

	}
	else {

		//Phaseflag��1�̏ꍇ
		if (Phaseflag == 1) {
			//�G40�̕�
			for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
				//Stayflag��false�ɂ���
				Stayflag = 0;

				//Attackflag��true�ɂ���
				enemies[30]->SetEnemyAttackflg();

				//phaseflag��2�ɂ���
				Phaseflag = 2;
			}
		}
	}
	if (wave == 10 && Phaseflag == 0) {
		Phaseflag = 1;
	}
	if (Phaseflag == 2) {
		ReChoiceFlag = 1;
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (enemy[i].onactive != 1 || enemies[i]->GetEnemyAttackflg() != true)continue;
			enemies[i]->Update();
			enemies[i]->Move();
			enemies[i]->TractorUpdate();
			ReChoiceFlag = 0;
			break;
		}

		//�Ē��I

		//�{�X�M�����K����������(�������R�����g�A�E�g����ƑS�Ă̓G�������_���ɓ����܂�)
		int random = GetRand(39);
		/*switch (random) {
		case 0:
			random = 8;
			break;
		case 1:
			random = 10;
			break;
		case 2:
			random = 12;
			break;
		case 3:
			random = 14;
			break;
		}*/
		if (ReChoiceFlag == 1)enemies[random]->SetEnemyAttackflg();
	}

	for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
		enemies[i]->AnimationCount();
	}

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

	for (int i = 0; i < sizeof(enemy) / sizeof(*enemy); i++) {
		if (enemies[i]->GetEnemyOnActive() == 1)continue;
		enemies[i]->Update2();
		enemies[i]->Draw();
	}
	if (Phaseflag == 2) {
		DrawFormatString(100, 100, GetColor(255, 255, 255), "�U���t�F�[�Y");
	}

	DrawFormatString(0, 120, GetColor(255, 255, 255), "�Ē��I�t���O:%d", ReChoiceFlag);

}