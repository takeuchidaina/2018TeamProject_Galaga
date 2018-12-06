#pragma once

#ifndef INGAME_MGR_INCLUDE_
#define INGAME_MGR_INCLUDE_

#include "cBaseEnemy.h"
#include "Singleton.h"
#include "WinBox.h"

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
		int etype;            //�G�̎��(3�핪)
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
		int etype;            //�G�̎��(3�핪)
		double moveangle[3];  //�p�x�ݒ�̔z��
		int countflag[3];     //����̃t���[���������ꂷ��z��
		int deathflag;        //�G�̎��S�t���O 0:�����Ă� 1:����ł�
	}sEnemyMgrData;


	sEnemy enemy[40];         //�\���̕ϐ��������̐錾
	sEnemy tmpEnemy;          //�ꎞ�I�ɓG�f�[�^���i�[����ꏊ
						      //int movetype;            //�G�̓���^�C�v
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
	int  EnemyGraph[20];      //�G�̉摜 20�̕���݂���
	int  Stayflag;            //�G�������ɓ����Ă��Ȃ��� 0:�����Ă��� 1:�����Ă��Ȃ�

							  //�֐��̃v���g�^�C�v�錾
							  //void Join(sEnemy&);
	void Move(sEnemy&);
	void Shifted(sEnemy&, sEnemy&);
	cBaseEnemy* enemies[40];

	int phaseFlagCount;       //���ꂪ�I�����Ă���G�̐�
	int onActiveCount;        //���ꎞ��onActive��true�ɂȂ��Ă���G�̐�
	   
	int ChoiseOrderFlag;      //�O���ő���\�ȍĒ��I�t���O TRUE:���I�\�B���I���s��  FALSE:���I�s�B���I���s��Ȃ�
	int ReChoiceFlag;         //�Ē��I�t���O 0:���I���s��Ȃ���� 1:���I���s�����

	int EnemyAttackFlag;      //�U���t���O   0:�U�����s��Ȃ���� 1:�U�����s�����
	//int EnemyDeathFlag;       //���S�t���O   0:�����Ă� 1:����ł�@����
	int EnemyDeathCount;       //���S�J�E���g

public:
	//~cEnemyMgr();

	void Update();
	void Draw();

	void Init();

	double GetTargetX(cBaseEnemy* p) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (p == enemies[i]) {
				return enemy[i].target.x;
			}
		}
	}
	double GetTargetY(cBaseEnemy* p) {
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (p == enemies[i]) {
				return enemy[i].target.y;
			}
		}

	}

	/*hit�ɏ����킽���p�֐�*/
	
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
		return enemies[num]->GetEnemyOnActive() == 1 ? false:true;
	}
	

	/***************************************
	�֐����Fvoid SetEnemyDeath(int num)
	�����F���̊֐����Ă΂ꂽ�Ƃ��A�G�̎��S�������s��
	�����Fint�^ num
	�߂�l�F�Ȃ���
	***************************************/
	void SetEnemyDeath(int num) {
		//�G�̔j�󏈗����s��
		enemies[num]->Break();
		enemy[num].onactive = FALSE;
		enemy[num].deathflag =TRUE;
		EnemyDeathCount++;
	}

	/*
	//�G�̎��S����t���O 0:�����Ă� 1:����ł�
	void SetEnemyDeathFlag() {
		EnemyDeathFlag = true;
	}
	*/

	/*
	�����G�����������Ă��Ȃ���Ԃ��l������
	0:�����Ă��� 1:�����Ă��Ȃ�
	*/
	int GetEnemyStay() {
		return Stayflag;
	}
	
	//InGameController�œG�̍U������𐧌䂷��֐�
	void SetEnemyAttackFlag(int flag) {
		EnemyAttackFlag=flag;
	}

	//InGameController�œG�̒��I���߂𐧌䂷��֐�
	void SetChoiseOrderFlag(int flag) {
		ChoiseOrderFlag = flag;
	}

};
#endif // !_INGAME_MGR_INCLUDE_
