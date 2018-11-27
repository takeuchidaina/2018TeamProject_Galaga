#pragma once

#ifndef INGAME_MGR_INCLUDE_
#define INGAME_MGR_INCLUDE_

#include "cBaseEnemy.h"
#include "Singleton.h"
#include "WinBox.h"

class cEnemyMgr : public cSingleton <cEnemyMgr>{
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
	}sEnemyMgrData;


	sEnemy enemy[40];          //�\���̕ϐ��������̐錾
	sEnemy tmpEnemy;           //�ꎞ�I�ɓG�f�[�^���i�[����ꏊ
							   //int movetype;            //�G�̓���^�C�v
	int waveflag[10];          //�Y���E�F�[�u�ɓG�����̂��邩���Ǘ�����
	int wave;                  //���݂̃E�F�[�u��
	int wavecount;             //�Y���E�F�[�u�œ���s�����I�����Ă���G�̐�

	int  input[64];           //�t�@�C������ǂݎ����������̈ꎞ�ۊ�(int�p)
	char inputc[64];          //�t�@�C������ǂݎ����������̈ꎞ�ۊ�(char�p)
	int  fileEndFlag;         //�t�@�C���ǂݍ��݂̏I���t���O
	int  StageHandle;         //�t�@�C�����J���n���h��
	char StageFilePath[256];  //�ǂݍ��ރt�@�C���̖��O������z��
	int  n, num;              //n,num
	int  Phaseflag;           //�ړ��i�K�t���O
	int  EnemyGraph[20];          //�G�̉摜 20�̕���݂���

	//�֐��̃v���g�^�C�v�錾
	//void Join(sEnemy&);
	void Move(sEnemy&);
	void Shifted(sEnemy&, sEnemy&);
	cBaseEnemy* enemies[40];

	int phaseFlagCount;  //���ꂪ�I�����Ă���G�̐�
	int onActiveCount;   //���ꎞ��onActive��true�ɂȂ��Ă���G�̐�

	int ReChoiceFlag;  //�Ē��I�t���O 0:���I���s��Ȃ���� 1:���I���s�����

public:
	//~cEnemyMgr();

	void Update();
	void Draw();

	double GetTargetX(cBaseEnemy* p) {
		/*
		char tmp[256];
		snprintf(tmp,255,"p:%d ene:%d size:%d ", p , enemies[0], sizeof(cBaseEnemy*));
		ErrBox(tmp);
		*/

		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (p == enemies[i]) {
				return enemy[i].target.x;
			}
		}
		//return enemy[sizeof(p - enemies[0]) / sizeof(cBaseEnemy*)].target.x;

	}
	double GetTargetY(cBaseEnemy* p) {
		/*return enemy[sizeof(p - enemies[0]) / sizeof(cBaseEnemy*)].target.y; 
		*/
		for (int i = 0; i < sizeof(enemy) / sizeof*(enemy); i++) {
			if (p == enemies[i]) {
				return enemy[i].target.y;
			}
		}

	}

	/*hit��x,y,r,�G���̍ő�l���킽��*/
	int GetMaxEnemy() {
		return 40;
	}

	double GetEnemyPosX(int num){
		return enemies[num]->GetEnemyX();
	};

	double GetEnemyPosY(int num) {
		return enemies[num]->GetEnemyY();
	};

	double GetEnemyPosR(int num) {
		return enemies[num]->GetEnemyR();
	};

};
#endif // !_INGAME_MGR_INCLUDE_
