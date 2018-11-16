#include "EnemyMgr.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <Dxlib.h>
#include "cBlueEnemy.h"
#include "cRedEnemy.h"
#include "cGreenEnemy.h"

//�R���X�g���N�^
cEnemyMgr::cEnemyMgr() {
	memset(waveflag, 0x00, sizeof(waveflag));
	wave = 1;
	fileEndFlag = 0;
	n = 0;
	num = 0;
	strcpy(StageFilePath, "../resource/MAP/Stage_1.csv");

	//Stage_1.csv
	StageHandle = FileRead_open(StageFilePath);
	if (StageHandle == 0);  //�G���[�����̋L���r��

							//�ŏ��̓�s�@�ǂݔ�΂��@�����@
	for (int i = 0; i < 2; i++)while (FileRead_getc(StageHandle) != '\n');

	//�t�@�C���̓ǂݎ�菈��(break��while���𔲂��鏈���Ȃ̂ŏ�������1�ɐݒ肳��Ă���)

	while (1) {

		/*for (int i = 0; i < 64; i++) {
		inputc[i] = input[i] = FileRead_getc(StageHandle);
		if (inputc[i] == '/') {
		while (FileRead_getc(StageHandle) != '\n');//���s�܂Ń��[�v
		i = -1; //�J�E���^���ŏ��ɖ߂�
		continue;
		}
		if (input[i] == ',' || input[i] == '\n') {
		inputc[i] = '\0';
		break;
		}
		if (input[i] == EOF) {g
		fileEndFlag = 1;
		break;
		}
		}*/

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
			//case 2: tmpEnemy.v.x = atof(inputc); break;	        //����
			//case 3: tmpEnemy.v.y = atof(inputc); break;	        //����
		case 2: tmpEnemy.r = atoi(inputc); break;
		case 3: tmpEnemy.count = atoi(inputc); break;
		case 4: tmpEnemy.angle = atof(inputc)* M_PI/180; break;
		case 5: tmpEnemy.speed = atoi(inputc); break;
			//case 8: tmpEnemy.moveflag = atoi(inputc); break;   	//����
		case 6: tmpEnemy.maxmove = atoi(inputc); break;
		case 7:tmpEnemy.RLflag = atoi(inputc); break;
		case 8:tmpEnemy.target.x = atof(inputc); break;
		case 9:tmpEnemy.target.y = atof(inputc); break;
		case 10:tmpEnemy.targetr = atoi(inputc); break;
		case 11:tmpEnemy.wave = atoi(inputc); break;	        //�ǉ�
		case 12:tmpEnemy.etype = atoi(inputc); break;           //etype����     
		case 13:tmpEnemy.moveangle[0] = atof(inputc); break;	//����
		case 14:tmpEnemy.countflag[0] = atoi(inputc); break;	//����
		case 15:tmpEnemy.moveangle[1] = atof(inputc); break;	//����
		case 16:tmpEnemy.countflag[1] = atoi(inputc); break;	//����
		case 17:tmpEnemy.moveangle[2] = atof(inputc); break;	//����
		case 18:tmpEnemy.countflag[2] = atoi(inputc); break;	//����
																//case 16:tmpEnemy.onactive = atoi(inputc); break;	    //����
															//case 17:tmpEnemy.item_n[5] = atoi(inputc); break;
		}

		switch (num) {
		case 0: enemy[n].pos.x = atof(inputc); break;
		case 1: enemy[n].pos.y = atof(inputc); break;
			//case 2: enemy[n].v.x = atof(inputc); break;            //����
			//case 3: enemy[n].v.y = atof(inputc); break;            //����
		case 2: enemy[n].r = atoi(inputc); break;
		case 3: enemy[n].count = atoi(inputc); break;
		case 4: enemy[n].angle = atof(inputc) *M_PI / 180; break;
		case 5: enemy[n].speed = atoi(inputc); break;
			//case 8: enemy[n].moveflag = atoi(inputc); break;       //����
		case 6: enemy[n].maxmove = atoi(inputc); break;
		case 7:enemy[n].RLflag = atoi(inputc); break;
		case 8:enemy[n].target.x = atof(inputc); break;
		case 9:enemy[n].target.y = atof(inputc); break;
		case 10:enemy[n].targetr = atoi(inputc); break;
		case 11:enemy[n].wave = atoi(inputc); break;            //�ǉ�
		case 12:enemy[n].etype = atoi(inputc); break;           //etype�ǉ�
		case 13:enemy[n].moveangle[0] = atof(inputc); break;    //����
		case 14:enemy[n].countflag[0] = atoi(inputc); break;    //����
		case 15:enemy[n].moveangle[1] = atof(inputc); break;    //����
		case 16:enemy[n].countflag[1] = atoi(inputc); break;    //����
		case 17:enemy[n].moveangle[2] = atof(inputc); break;    //����
		case 18:enemy[n].countflag[2] = atoi(inputc); break;    //����
																//case 16:enemy[n].onactive = atoi(inputc); break;        //����
																//case 17:enemy[n].item_n[5] = atoi(inputc); break;
		}

		enemy[n].v.x = 0;
		enemy[n].v.y = 0;
		enemy[n].moveflag = 0;
		enemy[n].onactive = false;


		/*switch����type���݂�,���ʂɍ��킹��tmpEnemy�̃f�[�^�����ꂼ���cbaseEnemy�ɂ����
		//enemies[n] = new(*cBaseEnemy)cBlueEnemy(tmpEnemy.pos.x,tmpEnemy.pos.y,etc...);*/
		/*switch (tmpEnemy.etype) {
		case 0:
			enemies[n] = (cBaseEnemy*) new cBlueEnemy(tmpEnemy.pos.x, tmpEnemy.pos.y, tmpEnemy.r, tmpEnemy.count, tmpEnemy.speed, tmpEnemy.angle, tmpEnemy.onactive);

		case 1:
			enemies[n] = (cBaseEnemy*) new cRedEnemy(tmpEnemy.pos.x, tmpEnemy.pos.y, tmpEnemy.r, tmpEnemy.count, tmpEnemy.speed, tmpEnemy.angle, tmpEnemy.onactive);

		case 2:
			enemies[n] = (cBaseEnemy*) new cGreenEnemy(tmpEnemy.pos.x, tmpEnemy.pos.y, tmpEnemy.r, tmpEnemy.count, tmpEnemy.speed, tmpEnemy.angle, tmpEnemy.onactive);


		}*/
		enemy[n].v.x = 0;

		enemy[n].v.y = 0;
		enemy[n].moveflag = 0;
		enemy[n].onactive = 0;

		num++;
		if (num == 19) {
			num = 0;

			switch (tmpEnemy.etype) {
			case 0:
				enemies[n] = (cBaseEnemy*) new cBlueEnemy(tmpEnemy.pos.x, tmpEnemy.pos.y, tmpEnemy.r, tmpEnemy.count, tmpEnemy.speed, tmpEnemy.angle, tmpEnemy.onactive);
				break;
			case 1:
				enemies[n] = (cBaseEnemy*) new cRedEnemy(tmpEnemy.pos.x, tmpEnemy.pos.y, tmpEnemy.r, tmpEnemy.count, tmpEnemy.speed, tmpEnemy.angle, tmpEnemy.onactive);
				break;
			case 2:
				enemies[n] = (cBaseEnemy*) new cGreenEnemy(tmpEnemy.pos.x, tmpEnemy.pos.y, tmpEnemy.r, tmpEnemy.count, tmpEnemy.speed, tmpEnemy.angle, tmpEnemy.onactive);
				break;

			}

			n++;
		}
	}

	//�t�@�C������那
	FileRead_close(StageHandle);

	//waveflag�̏������@���ꂷ���waveflag���ɊY��wave�ŉ��̓G���o�����邩��c���ł���
	for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
		waveflag[enemy[i].wave]++;
	}


	/*
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
	*/
}

//�f�R���X�g���N�^
cEnemyMgr::~cEnemyMgr() {

}


//�v�Z����
void cEnemyMgr::Update() {
	Phaseflag = 0;
	wavecount = 0;

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
				/*else {
				enemy[i].pos.x = enemy[i].target.x;
				enemy[i].pos.y = enemy[i].target.y;
				}*/
			} //��O�����I��
		} //active�ȃG�l�~�[�̓��쏈���I��
		if (enemy[i].moveflag == 11) {
			Phaseflag++;
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
		//���炷�̂��˂݁[�͂����i�Ԗڂɂ��炷����Ȃ��ق��̂��˂݁[(sEnemyMgrData)��������
		enemies[i]->SetEnemyX(enemy[i].pos.x);
		enemies[i]->SetEnemyY(enemy[i].pos.y);
		enemies[i]->SetEnemyAngle(enemy[i].angle);

	}//�z�񐔕��̓G����I��



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
	/*
	DrawFormatString(0, 20, GetColor(255, 255, 255), "[0]:x=%.1lf y=%.1lf", enemy[0].pos.x, enemy[0].pos.y);
	DrawFormatString(0, 40, GetColor(255, 255, 255), "[7]:x=%.1lf y=%.1lf", enemy[7].pos.x, enemy[7].pos.y);
	DrawFormatString(0, 60, GetColor(255, 255, 255), "atan2=%.3lf", atan2(enemy[0].target.y - enemy[0].pos.y, enemy[0].target.x - enemy[0].pos.x));
	*/
	/*for (int i = 0; i < sizeof(enemy) / sizeof(*enemy); i++) {
		//�G�z��̕`��
		if (enemy[i].etype == 0) {
			DrawCircle(enemy[i].pos.x, enemy[i].pos.y, enemy[i].r, GetColor(0, 0, 255), TRUE);
		}
		else if(enemy[i].etype == 1){
			DrawCircle(enemy[i].pos.x, enemy[i].pos.y, enemy[i].r, GetColor(255, 0, 0), TRUE);
		}
		else if (enemy[i].etype == 2) {
			DrawCircle(enemy[i].pos.x, enemy[i].pos.y, enemy[i].r, GetColor(0, 255, 0), TRUE);
		}

	}*/
	
	for (int i = 0; i < sizeof(enemy) / sizeof(*enemy); i++) {
		//enemies[i]->Update2();
		enemies[i]->Draw();
	}

	DrawFormatString(0,100,GetColor(255,255,255),"x:%4.1lf y:%4.1lf",enemies[0]->GetEnemyX(), enemies[0]->GetEnemyY());

}