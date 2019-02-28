#pragma once

#ifndef INGAME_MGR_INCLUDE_
#define INGAME_MGR_INCLUDE_

#include "cBaseEnemy.h"
#include "cPlayerEnemy.h"
#include "TextChange.h"
#include "FlightText.h"

#include "Singleton.h"
#include "WinBox.h"
#include "Score.h"

class cEnemyMgr : public cSingleton <cEnemyMgr> {
	cEnemyMgr();
	friend cSingleton<cEnemyMgr>;

private:
	typedef struct {
		double x, y;
	}sPos;

	typedef struct {
		sPos pos;             //�������W
		sPos v;               //�x�N�g�����W  
		int r;                //���a
		int count;            //�t���[���J�E���g
		double angle;         //�p�x
		double speed;         //���x
		int moveflag;         //����t���O
		int maxmove;          //����t���O�̍ő吔
		int RLflag;           //���E�𔻒肷��t���O
		sPos target;          //�ڕW�ʒu�̍��W
		int targetr;          //�ڕW�ʒu�̔��a(�����蔻��ɗ��p)
		int wave;             //�E�F�[�u�ԍ�  
		int etype;            //�G�̎��(3�핪) 0:�� 1:�� 2:��
		sPos shaft;           //�G�̗�ԍ�
		double moveangle[3];  //�p�x�ݒ�̔z��
		int countflag[3];     //����̃t���[���������ꂷ��z��
		int onactive;         //�\���E��\���̔���
		int attackflag;       //�U���t���O
		int deathflag;        //�G�̎��S�t���O 0:�����Ă� 1:����ł�
	}sEnemy;

	//EnemyMgr���ł݈̂����ϐ����i�[����\����
	typedef struct {
		sPos v;               //�x�N�g�����W  
		int moveflag;         //����t���O
		int maxmove;          //����t���O�̍ő吔
		int RLflag;           //���E�𔻒肷��t���O
		sPos target;          //�ڕW�ʒu�̍��W
		int targetr;          //�ڕW�ʒu�̔��a(�����蔻��ɗ��p)
		int wave;             //�E�F�[�u�ԍ�  
		int etype;            //�G�̎��(3�핪)0:�� 1:�� 2:��
		sPos shaft;           //�G�̗�ԍ�
		double moveangle[3];  //�p�x�ݒ�̔z��
		int countflag[3];     //����̃t���[�������w�肷��z��
		int deathflag;        //�G�̎��S�t���O 0:�����Ă� 1:����ł�
	}sEnemyMgrData;

	/*csv����ǂݍ��ރf�[�^�̔ԍ�
	�@�V�����f�[�^��ǉ������ꍇ�́Amoveangle[0]���O�ɕϐ���ǉ�����
	 */
	typedef enum {
		Posx,            //x���W
		Posy,            //y���W
		Radius,          //���a
		Count,           //�J�E���g
		Angle,           //�p�x
		Speed,           //���x
		Maxmove,         //�ړ��؂�ւ��̍ő吔
		RLflag,          //���E�𔻕ʂ���t���O
		Targetx,         //�ڕW�n�_��x���W
		Targety,         //�ڕW�n�_��y���W
		Targetr,         //�ڕW�n�_�̔��a
		Wave,            //����ԍ�
		Etype,           //�G�̎��
		Shaftx,          //y�̊g�吔
		Shafty,          //x�̊g�吔
		FirstMoveangle,  //�ړ�����p�x�P
		FirstCountflag,  //�ړ�������؂�ւ���J�E���g�P
		SecondMoveangle, //�ړ�����p�x�Q
		SecondCountflag, //�ړ�������؂�ւ���J�E���g�Q
		ThirdMoveangle,  //�ړ�����p�x�R
		ThirdCountflag   //�ړ�������؂�ւ���J�E���g�R
	}eLoadData;

	typedef struct {
		int x, y;
		int onActive;
		int count;
		int score;
	}sScoreText;


	sEnemy enemy[40];         //�\����
	sEnemy tmpEnemy;          //�ꎞ�I�ɓG�f�[�^���i�[����ꏊ
							  //int movetype;           //�G�̓���^�C�v
	int waveflag[10];         //�Y���E�F�[�u�ɓG�����̂��邩���Ǘ�����
	int wave;                 //���݂̃E�F�[�u��
	int wavecount;            //�Y���E�F�[�u�œ���s�����I�����Ă���G�̐�

	int  input[64];           //�t�@�C������ǂݎ����������̈ꎞ�ۊ�(int�p)
	char inputc[64];          //�t�@�C������ǂݎ����������̈ꎞ�ۊ�(char�p)
	int  fileEndFlag;         //�t�@�C���ǂݍ��݂̏I���t���O
	int  StageHandle;         //�t�@�C�����J���n���h��
	char StageFilePath[256];  //�ǂݍ��ރt�@�C���̖��O������z��
	int  n, num;              //n,num
	int  Phaseflag;           //�ړ��i�K�t���O
	int  EnemyGraph[20];      //�G�̉摜 20�̕���݂��� ��enum���\��
	int  Stayflag;            //�G�������ɓ����Ă��Ȃ��� 0:�����Ă��� 1:�����Ă��Ȃ� ��bool���\��

							  //�֐��̃v���g�^�C�v�錾
	void Move(sEnemy&);              //�G�̓�����s���֐�
	void Shifted(sEnemy&, sEnemy&);  //�G����ɕ\��������֐�
	cBaseEnemy* enemies[40];         //cBaseEnemy�̓G�z��

	void Scaling(sEnemy&);    //�H�̐V��֐�
	int  ScalingFlag;         //�G�̎��k�����p�̃t���O true:1 false:-1
	int  ScalingCount;          //���k�J�E���g

	void Sliding(sEnemy&);    //�~�̐V��֐�
	int  SlidingFlag;         //�G�̉��ړ������p�̃t���O true:1 false:-1
	int  SlidingCount;        //���ړ��J�E���g

	int phaseFlagCount;       //���ꂪ�I�����Ă���G�̐�
	int onActiveCount;        //���ꎞ��onActive��true�ɂȂ��Ă���G�̐�

	int ChoiseOrderFlag;      //�O���ő���\�ȍĒ��I�t���O TRUE:���I�\�B���I���s��  FALSE:���I�s�B���I���s��Ȃ� ��bool���\��
	int ReChoiceFlag;         //�Ē��I�t���O 0:���I���s��Ȃ���� 1:���I���s����� ��bool���\��

	int EnemyAttackFlag;      //�U���t���O   0:�U�����s��Ȃ���� 1:�U�����s����� ��bool���\��
	int EnemyDeathCount;      //���S�J�E���g

	void Follow(int);         //�{�X�̒Ǐ]��������֐�

	cPlayerEnemy* pEnemy;      //�G�ɂȂ����v���C���[�̃A�h���X 

	sScoreText scoreText;      //����X�R�A��\��������\����

	int enemyCount;  //�{�X�̎��͂ɂ���ԓG�̐�
	int followEnemy[3];  //���͂ɂ���ԓG�̔ԍ���ۑ�����z��
	sPos followEnemyV[3];
	cBaseEnemy* dummyEnemy;  //�{�X�̓����̕����p

	int attackNum;  //�U������G�̔ԍ�

	int frameCount;  //�ӂ�[�ނ������

	int tractorCount;  //�g���N�^�[�t���O��on�̓G�̐�


public:
	//~cEnemyMgr();

	void Update();
	void Draw();

	void Init();


	/*���̃N���X�Ȃǂɏ����킽���p�̊֐�*/

	double GetTargetX(cBaseEnemy* p) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (p == enemies[i]) {
				return enemy[i].target.x;
			}
		}

		if (p == dummyEnemy) {
			return enemy[attackNum].target.x;
		}

	}

	double GetTargetY(cBaseEnemy* p) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (p == enemies[i]) {
				return enemy[i].target.y;
			}
		}

		if (p == dummyEnemy) {
			return enemy[attackNum].target.y;
		}

	}

	//�G�̍ő吔
	int GetMaxEnemy() {
		return 40;
	}

	//�G��cx
	double GetEnemyPosX(int num) {
		return enemies[num]->GetEnemyCx();
	}

	//�G��cy
	double GetEnemyPosY(int num) {
		return enemies[num]->GetEnemyCy();
	}

	//�G��r
	double GetEnemyPosR(int num) {
		return enemies[num]->GetEnemyR();
	}

	double GetEnemyR(int num) {
		return enemies[num]->GetEnemyR();
	}



	//�G�̍U��������s�����߂̃t���O
	int GetEnemyonActive(int num) {
		//
		return enemies[num]->GetEnemyOnActive() == 1 ? false : true;
	}

	//����ɒǉ��� by��
	int GetEnemyHP(int num) {
		return enemies[num]->GetHp();
	}

	void DamageEnemyHp(int num) {
		enemies[num]->DamageHp();
	}


	//���񂾓G�̐����킽��
	int GetEnemyDeathCount() {
		return EnemyDeathCount;
	}

	int GetTractorCount() {
		return tractorCount;
	}



	/*****************************************************
	�֐����FcPlayerEnemy GetPlayerEnemyAdress()
	�����F�G�z��ɉ������v���C���[�̃A�h���X��^����
	�����F�Ȃ�
	�߂�l�F�G�z��ɉ������v���C���[�̃A�h���X
	******************************************************/
	cPlayerEnemy* GetPlayerEnemyAdress() {
		return pEnemy;
	}



	/*****************************************************
	�֐����FcPlayerEnemy PushPlayerEnemy()
	�����F�g���N�^�[�r�[�������������v���C���[��G�z��ɉ�����
	�����FcPlayerEnemy�^ pEnemy
	�߂�l�F�v�b�V����̃A�h���X
	******************************************************/
	cPlayerEnemy* PushPlayerEnemy() {
		pEnemy = new cPlayerEnemy();
		return pEnemy;
	}

	/*****************************************************
	�֐����Fvoid DeletePlayerEnemy()
	�����F�G�z��ɉ������v���C���[�̃f�[�^���f���[�g����
	�����FcPlayerEnemy�^ pEnemy
	�߂�l�F�v�b�V����̃A�h���X
	******************************************************/
	void DeletePlayerEnemy() {
		delete pEnemy;
		pEnemy = NULL;
	}

	/*****************************************************
	�֐����FcBaseEnemy* GetArrayEnemy()
	�����F
	�����FcBaseEnemy�^ enemies
	�߂�l�F�v�b�V����̃A�h���X
	******************************************************/
	cBaseEnemy* GetArrayEnemy() {
		return *enemies;
	}


	/*****************************************************
	�֐����Fvoid SetEnemyDeath(int num)
	�����F���̊֐����Ă΂ꂽ�Ƃ��A�G�̎��S�������s��
	�����Fint�^ num
	�߂�l�F�Ȃ�
	******************************************************/
	void SetEnemyDeath(int num) {
		//�G�̔j�󏈗����s��
		enemies[num]->Break();

		//�G���\���ɂ���
		enemy[num].onactive = FALSE;

		//�G�̎��S�t���O��TRUE�ɂ���
		enemy[num].deathflag = TRUE;

		//�G�̎��S�����J�E���g����
		EnemyDeathCount++;

		//�������Ƃ̃X�R�A���Z����
		//�U�����̃{�X�M�����K��|�����ꍇ
		if (enemy[num].etype == 2 && enemies[num]->GetEnemyAttackflg() == 1) {
			//�X�R�A��400���Z����
			cScore::Instance()->AddScore(400);
			scoreText.x = GetEnemyPosX(num);
			scoreText.y = GetEnemyPosY(num);
			scoreText.score = 400;
			scoreText.onActive = 1;
			scoreText.count = 0;
		}
		//���ꒆ�̃{�X�M�����K��|�����ꍇ
		else if (enemy[num].etype == 2 && enemy[num].moveflag < 10) {
			//�X�R�A��400���Z����
			cScore::Instance()->AddScore(400);
			scoreText.x = GetEnemyPosX(num);
			scoreText.y = GetEnemyPosY(num);
			scoreText.score = 400;
			scoreText.onActive = 1;
			scoreText.count = 0;
		}
		/*
		//�v���C���[�G�l�~�[��A��Ă���{�X�M�����K��|�����ꍇ
		else if (enemy[num].type==2 && enemies[num]->GetEnemyAttackflg()=1 && �G���v���C���[�G�l�~�[��A��Ă���) {
		//�X�R�A��800���Z����
		cScore::Instance()->AddScore(800);
		scoreText.x = GetEnemyPosX(num);
		scoreText.y = GetEnemyPosY(num);
		scoreText.score = 800;
		scoreText.onActive = 1;
		scoreText.count = 0;
		}*/
		else {  //����ȊO
				//�X�R�A��100���Z����
			cScore::Instance()->AddScore(100);
		}

	}


	/*****************************************************
	�֐����Fvoid EndIt()
	�����F���̊֐����Ă΂ꂽ�Ƃ��A�G�̔z�����������
	�����F�Ȃ�
	�߂�l�F�Ȃ�
	******************************************************/
	void EndIt() {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			delete enemies[i];
		}
	}


	/*
	�����G�����������Ă��Ȃ���Ԃ��l������
	0:�����Ă��� 1:�����Ă��Ȃ�
	*/
	int GetEnemyStay() {
		return Stayflag;
	}

	//InGameController�œG�̍U������𐧌䂷��֐�
	void SetEnemyAttackFlag(int flag) {
		EnemyAttackFlag = flag;
	}

	//InGameController�œG�̒��I���߂𐧌䂷��֐�
	void SetChoiseOrderFlag(int flag) {
		ChoiseOrderFlag = flag;
	}

	bool GetTractingFlg(int num) {
		return enemies[num]->GetTractingFlg();
	}

	//se�p
	int GetEnemyType(int num) {
		return enemies[num]->GetEnemyType();
	}

};
#endif // !_INGAME_MGR_INCLUDE_
