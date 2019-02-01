#include "EnemyMgr.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <Dxlib.h>
#include "cBaseEnemy.h"
#include "cBlueEnemy.h"
#include "cRedEnemy.h"
#include "cGreenEnemy.h"
#include "Struct.h"
#include "InGameController.h"
#include "Debug.h"

//�R���X�g���N�^
cEnemyMgr::cEnemyMgr() {
	//�摜�̓ǂݍ��ݏ���
	LoadDivGraph("../resource/Image/Galaga_OBJ_enemy1616.png", 20, 5, 4, 16, 16, EnemyGraph);

	Init();
}

void cEnemyMgr::Init() {
	memset(waveflag, 0x00, sizeof(waveflag));
	wave = 1;
	fileEndFlag = 0;
	n = 0;
	num = 0;
	snprintf(StageFilePath, 255, "../resource/MAP/Stage_%d.csv", cInGameController::Instance()->GetNowStageNum());
	//strcpy(StageFilePath, "../resource/MAP/Stage_2.csv");
	Phaseflag = 0;
	onActiveCount = 0;
	Stayflag = 0;
	EnemyAttackFlag = 1;     //�U���t���O 0:�U�����s��Ȃ���� 1:�U�����s�����
	ChoiseOrderFlag = TRUE;
	
	EnemyDeathCount = 0;

	ScalingFlag = -1;
	ScalingCount = 120;

	SlidingFlag = 1;
	SlidingCount = 120;

	//ScoreCount = 0;


	//Stage_1.csv
	StageHandle = FileRead_open(StageFilePath);
	if (StageHandle == 0) {
		//�G���[�����̋L���r��
		StageHandle = FileRead_open("../resource/MAP/Stage_2.csv");
	}
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
		case Posx: tmpEnemy.pos.x = atof(inputc); break;
		case Posy: tmpEnemy.pos.y = atof(inputc); break;
		case Radius: tmpEnemy.r = atoi(inputc); break;
		case Count: tmpEnemy.count = atoi(inputc); break;
		case Angle: tmpEnemy.angle = atof(inputc)* M_PI / 180; break;
		case Speed: tmpEnemy.speed = atoi(inputc); break;
		case Maxmove: tmpEnemy.maxmove = atoi(inputc); break;
		case RLflag:tmpEnemy.RLflag = atoi(inputc); break;
		case Targetx:tmpEnemy.target.x = atof(inputc); break;
		case Targety:tmpEnemy.target.y = atof(inputc); break;
		case Targetr:tmpEnemy.targetr = atoi(inputc); break;
		case Wave:tmpEnemy.wave = atoi(inputc); break;
		case Etype:tmpEnemy.etype = atoi(inputc); break;
		case Shaftx:tmpEnemy.shaft.x = atoi(inputc); break;
		case Shafty:tmpEnemy.shaft.y = atoi(inputc); break;
		case FirstMoveangle:tmpEnemy.moveangle[0] = atof(inputc); break;
		case FirstCountflag:tmpEnemy.countflag[0] = atoi(inputc); break;
		case SecondMoveangle:tmpEnemy.moveangle[1] = atof(inputc); break;
		case SecondCountflag:tmpEnemy.countflag[1] = atoi(inputc); break;
		case ThirdMoveangle:tmpEnemy.moveangle[2] = atof(inputc); break;
		case ThirdCountflag:tmpEnemy.countflag[2] = atoi(inputc); break;
		}

		switch (num) {
		case Posx: enemy[n].pos.x = atof(inputc); break;
		case Posy: enemy[n].pos.y = atof(inputc); break;
		case Radius: enemy[n].r = atoi(inputc); break;
		case Count: enemy[n].count = atoi(inputc); break;
		case Angle: enemy[n].angle = atof(inputc) *M_PI / 180; break;
		case Speed: enemy[n].speed = atoi(inputc); break;
		case Maxmove: enemy[n].maxmove = atoi(inputc); break;
		case RLflag:enemy[n].RLflag = atoi(inputc); break;
		case Targetx:enemy[n].target.x = atof(inputc); break;
		case Targety:enemy[n].target.y = atof(inputc); break;
		case Targetr:enemy[n].targetr = atoi(inputc); break;
		case Wave:enemy[n].wave = atoi(inputc); break;
		case Etype:enemy[n].etype = atoi(inputc); break;
		case Shaftx:enemy[n].shaft.x = atoi(inputc); break;
		case Shafty:enemy[n].shaft.y = atoi(inputc); break;
		case FirstMoveangle:enemy[n].moveangle[0] = atof(inputc); break;
		case FirstCountflag:enemy[n].countflag[0] = atoi(inputc); break;
		case SecondMoveangle:enemy[n].moveangle[1] = atof(inputc); break;
		case SecondCountflag:enemy[n].countflag[1] = atoi(inputc); break;
		case ThirdMoveangle:enemy[n].moveangle[2] = atof(inputc); break;
		case ThirdCountflag:enemy[n].countflag[2] = atoi(inputc); break;
		}

		//�����l�ŏ���������ϐ�
		enemy[n].v.x = 0;
		enemy[n].v.y = 0;
		enemy[n].moveflag = 0;
		enemy[n].onactive = FALSE;
		enemy[n].deathflag = FALSE;

		num++;
		if (num == 21) {
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

	if (pEnemy != NULL) {
		DeletePlayerEnemy();
		pEnemy = NULL;
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
	SlidingCount++;
	ScalingCount++;

	if (Phaseflag == 0) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			//�G�̉��ړ�����
			Sliding(enemy[i]);
			if (enemy[i].wave == wave) {
				//���t���[���J�E���g�𑝂₷
				enemy[i].count++;
				//�J�E���g��0��葽����΁A�G�̕\�������true(1)�ɂ���
				if (enemy[i].count > 0) {
					enemy[i].onactive = TRUE;
				}
				//�G�̔������肪true�łȂ��ꍇ�͈ȍ~�̏����𖳎�(continue)����i�����Z����
				if (enemy[i].onactive != TRUE)continue;

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
						(enemy[i].r /5 + enemy[i].targetr)*(enemy[i].r /5 + enemy[i].targetr)) {
						enemy[i].pos.x = enemy[i].target.x;
						enemy[i].pos.y = enemy[i].target.y;
						enemy[i].moveflag++;
						enemy[i].count = 0;
						enemy[i].angle = -90 * M_PI / 180;
					}
				} //��O�����I��
			} //active�ȃG�l�~�[�̓��쏈���I��

			if (enemy[i].moveflag == 11) {

				enemy[i].pos.x = enemy[i].target.x;
				//enemy[i].pos.y = enemy[i].target.y;

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

		}//�z�񐔕��̓G����I��
		
		 //�G�������Ă��Ȃ��t���O��on�ɂ���
		Stayflag = 1;
	}
	else {

		//Phaseflag��1�̏ꍇ
		if (Phaseflag == 1) {

     		//�ҋ@��Ԃ̃t���Ooff
			Stayflag = 0;

		    //�U���t�F�[�Y�Ɉڍs
		    Phaseflag = 2;

			int randtmp =GetRand(39);
			//int randtmp = 10;

			//1�̖ڂ̓G�������_���ɒ��I���U��������
			if(enemy[randtmp].etype==2){
				/*while (1) {
					red1 = GetRand(20);
					red2 = GetRand(20);
					if (enemy[red1].etype == 1 && enemy[red2].etype == 1)break;
				}
				enemies[red1]->SetEnemyAttackflg();
				enemies[red2]->SetEnemyAttackflg();
				enemies[randtmp]->SetEnemyAttackflg();*/
				Follow(randtmp);
			}
			else {
				enemies[randtmp]->SetEnemyAttackflg();
			}


		}
	}
	if (wave == 10 && Phaseflag == 0) {
		Phaseflag = 1;
	}
	if (Phaseflag == 2) {  //���ꂪ�I�����A�U���t�F�[�Y�ɓ������ꍇ

		//�����̑ҋ@�t���Ooff
		Stayflag = 0;

		//�G�̍Ē��I�t���Oon
		ReChoiceFlag = 1;

		//�G40�̕��������s��
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {

			//�G�̊g�又��
			Scaling(enemy[i]);

			//�G���U�����łȂ��ꍇ�A�G�̍��W��ҋ@�ʒu�ɌŒ肳����
			if (enemies[i]->GetEnemyAttackflg() != 1) {

				enemy[i].pos.x = enemy[i].target.x;
				enemy[i].pos.y = enemy[i].target.y;

				enemies[i]->SetEnemyX(enemy[i].pos.x);
				enemies[i]->SetEnemyY(enemy[i].pos.y);
			}

			//�G����\���������͍U�����ł͂Ȃ��Ƃ��������͓G������ł���Ƃ��͈ȉ��̏������΂�
			if (enemy[i].onactive != TRUE || enemies[i]->GetEnemyAttackflg() != 1 || enemy[i].deathflag == TRUE) {
				continue;
			}

			//Enemy�N���X���Ŋe�G�̓��쏈��
			enemies[i]->Update();
			enemies[i]->Move();

			//�g���N�^�[�t���O��true�̏ꍇ�A�g���N�^�[�r�[�����o��
			if (enemies[i]->GetTractorfFlg() == true) {
				enemies[i]->TractorUpdate();
			}

			//�v���C���[�G�l�~�[�����݂��Ă���ꍇ�A������
			if (pEnemy != NULL) {
				pEnemy->Move();
				pEnemy->Update();
			}
		}

		//�G40�̕��̊m�F�������s��
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			//�G������ł��邩�A�Ē��I�t���O��off�̏ꍇ�͏������΂�
			if (enemy[i].onactive != TRUE || enemies[i]->GetEnemyChoiseOrder() != 1 || enemy[i].deathflag == TRUE)continue;
			
			//�Ē��I�t���Ooff
			ReChoiceFlag = 0;
		
		}

			//�Ē��I
				//�Ē��I�t���O��TRUE�ɂȂ��Ă���������͍U�����̓G���E���ꂽ�ꍇ�A�G�̍Ē��I���s��
			if (ReChoiceFlag == 1 && ChoiseOrderFlag == TRUE) {
				int debug = 0;		
				while (1) {
					//�G���[�{�b�N�X���\�������܂ł̃J�E���g�����Z
					debug++;

					//�G1�̕��̍Ē��I���s��
					int tmp = GetRand(39);
					//int tmp = 8;
			
					//1�̖ڂ̓G�������_���ɒ��I���U��������
					if (enemy[tmp].deathflag != TRUE && enemy[tmp].etype == 2) {
						/*while (1) {
							red1 = GetRand(20);
							red2 = GetRand(20);
							if (enemy[red1].etype == 1 && enemy[red2].etype == 1)break;
						}
						enemies[red1]->SetEnemyAttackflg();
						enemies[red2]->SetEnemyAttackflg();
						enemies[tmp]->SetEnemyAttackflg();
						break;*/
						Follow(tmp);
					}
					else {
						enemies[tmp]->SetEnemyAttackflg();
						break;
					}

					if (enemy[tmp].deathflag != TRUE) {  //���I���ꂽ�G�������Ă���ꍇ�́A�U��������s�������𔲂���
						enemies[tmp]->SetEnemyAttackflg();
						break;
					}
					if (debug == 1000) {  //�f�o�b�O�J�E���g��1000�ɂȂ�����
						ErrBox("���˂݁[�܂ˁ[����[\n�������[�v���Ă��킭��");
						break;
					}

					int tmpcount = 0;  //�G�̎��S���̃J�E���g

					//�G40�̕��̏������s��
					for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
						//�G�����񂾏ꍇ�́A�J�E���g�����Z
						if (enemy[i].deathflag == true)tmpcount++;
					}

					//�G��40�̎��񂾂�A���̃X�e�[�W�Ɉړ�
					if (tmpcount == sizeof(enemy) / sizeof*(enemy)) {
						cInGameController::Instance()->NextStage();
						EndIt();
						Init();
						return;
					}

				}
			}
			else if (ReChoiceFlag == 1 && ChoiseOrderFlag == FALSE) {  //�Ē��I�t���Oon���A�O������Ē��I���~�߂��Ă���ꍇ
				//�ҋ@���t���Oon
				Stayflag = 1;
			}
		
	}

	for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
		enemies[i]->AnimationCount();
	}

	if (EnemyDeathCount == GetMaxEnemy()) {
		//InGameController�̑S�ŕ񍐊֐����Ăяo��
		cInGameController::Instance()->NextStage();
		EndIt();
		Init();
		return;
	}

	//�f�o�b�O�R�}���h6:�ȊO�̓G�����ł���
	if (Debug::Instance()->Get_Input(Key6) == 1) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (enemy[i].etype != 0) {
				SetEnemyDeath(i);
			}
		}
	}

	//�f�o�b�O�R�}���h7:�ԈȊO�̓G�����ł���
	if (Debug::Instance()->Get_Input(Key7) == 1) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (enemy[i].etype != 1) {
				SetEnemyDeath(i);
			}
		}
	}

	//�f�o�b�O�R�}���h8:�{�X�M�����K�ȊO�̓G�����ł���
	if (Debug::Instance()->Get_Input(Key8) == 1) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (enemy[i].etype != 2) {
				SetEnemyDeath(i);
			}
		}
	}

	//�f�o�b�O�R�}���h9:�G���c���̂̏�ԂɂȂ�
	if (Debug::Instance()->Get_Input(Key9) == 1) {
		for (int i = 1; i < sizeof(enemy) / sizeof*(enemy); i++) {
				SetEnemyDeath(i);
				Phaseflag = 2;
		}
	}

	//�t���C�g�e�L�X�g����莞�ԕ\�����ꂽ��A�\��������
	if (scoreText.count >= 60) {
		scoreText.onActive = 0;
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

/*****************************************************
�֐����Fvoid Scalings(sEnemy& enemy)
�����F�G���U���ҋ@���ɑ傫���Ȃ����菬�����Ȃ����肷��
�����FsEnemy�^ enemy
�߂�l�F�Ȃ�
******************************************************/
void cEnemyMgr::Scaling(sEnemy& enemy) {

	if (ScalingCount >=180 ) {
		ScalingFlag *= -1;
		ScalingCount = 0;
	}

	if (ScalingCount % 30 == 0) {
		enemy.target.x += enemy.shaft.x * 2 * ScalingFlag;
		enemy.target.y += enemy.shaft.y * 2 * ScalingFlag;
	}

}

/*****************************************************
�֐����Fvoid Slidings(sEnemy& enemy)
�����F�G������ҋ@���ɉ��ړ�����
�����FsEnemy�^ enemy
�߂�l�F�Ȃ�
******************************************************/
void cEnemyMgr::Sliding(sEnemy& enemy) {

	if (SlidingCount >= 240) {
		SlidingFlag *= -1;
		SlidingCount = 0;
	}

	if (SlidingCount % 60 == 0) {
		enemy.target.x += 10 * SlidingFlag;
	}
}


/*****************************************************
�֐����Fvoid  Follow()
�����F�{�X���U������ꍇ�A�Ԃ̓G���Q�̓����ɍU��������
�����Fint tmp�c�{�X�M�����K�̃A��
�߂�l�F�Ȃ�
******************************************************/
void cEnemyMgr::Follow(int tmp) {

	int enemyCount=0;  //�{�X�̎��͂ɂ���ԓG�̐�
	int followEnemy[3] = { 0 };  //���͂ɂ���ԓG�̔ԍ���ۑ�����z��


	//�{�X�̎��͂ɂ���ԓG��T��
	//�G40�̕��̏���
	for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {

		//�G�̔ԍ��������Ă���ԓG�̎҂ɂȂ�܂ŏ������΂�
		if (enemy[i].etype != 1 || enemy[i].deathflag == TRUE)continue;

		int x1 = enemy[tmp].target.x;  //�{�X�M�����K��x���W
		int y1 = enemy[tmp].target.y;  //�{�X�M�����K��y���W

		int x2 = enemy[i].target.x;  //�ԓG��x���W
		int y2 = enemy[i].target.y;  //�ԓG��y���W

		int r1 = 70;  //�Œ��̔��a
		int r2 = 1;   //�G�̓����蔻��

		//�{�X�M�����K�̎��͂ɓG�������ꍇ
		if ((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2) <= (r1 - r2)*(r1 - r2)) {
			//�G�̔ԍ���ۑ�
			followEnemy[enemyCount] = i;
			enemyCount++;
		}
	}	

	//�{�X�ƒǏ]�G�𓮂�������
	//�{�X���U��������
	enemies[tmp]->SetEnemyAttackflg();

	//�������ꂽ�G�̐��Ɋ�Â��čU�������鏈��
		if (enemyCount ==3) {  //�G�̐���3�̂������ꍇ
			//2�̕��̒��I�������Ȃ�
			for (int i = 0; i < 2; i++) {
				//enemyCount = GetRand(2);
				enemies[followEnemy[enemyCount]]->SetEnemyAttackflg();
			}
		}	
		else {  //�G�̐���3�̖����������ꍇ*/
			for (enemyCount = 0; enemyCount < 2; enemyCount++) {
				//2�̕��̐ԓG���U��������
				enemies[followEnemy[enemyCount]]->SetEnemyAttackflg();
			}
		}
		
	
}


//�`�ʏ���
void cEnemyMgr::Draw() {
	//����ɒǉ����@by��@
	//PlayerEnemy����������Ă����������\��

	if (pEnemy !=NULL) {
		if (pEnemy->GetEnemyOnActive() != 1) {
			pEnemy->Draw();
		}
	}

	for (int i = 0; i < sizeof(enemy) / sizeof(*enemy); i++) {
		if (enemies[i]->GetEnemyOnActive() == 1)continue;
		enemies[i]->Update2();
		enemies[i]->Draw();
	}
	if (Phaseflag == 2) {
		DrawFormatString(100, 100, GetColor(255, 255, 255), "scoreText.count%d", scoreText.count);
	}

	if (scoreText.onActive == 1) {
		cFlightText::Instance()->ScoreDraw(scoreText.x,scoreText.y, scoreText.score);
		scoreText.count++;
	}

	/*
	DrawFormatString(0, 120, GetColor(255, 255, 255), "enemy[0]:%lf", enemy[0].target.x);
	DrawFormatString(0, 140, GetColor(255, 255, 255), "enemy[2]:%lf", enemy[2].target.x);
	*/

}