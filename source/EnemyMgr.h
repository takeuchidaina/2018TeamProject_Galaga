#pragma once

#ifndef INGAME_MGR_INCLUDE_
#define INGAME_MGR_INCLUDE_

#include "cBaseEnemy.h"

class cEnemyMgr {
private:
	typedef struct  {
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
	double moveangle[3];  //�p�x�ݒ�̔z��
	int countflag[3];     //����̃t���[���������ꂷ��z��
	int RLflag;           //���E�𔻒肷��t���O
	int wave;             //�E�F�[�u�ԍ�  
	sPos target;          //�ڕW�ʒu�̍��W
	int targetr;          //�ڕW�ʒu�̔��a(�����蔻��ɗ��p)
	int onactive;         //�\���E��\���̔���
	//int enemytype[3];   //�G�̎��(3�핪)
	}sEnemy;

	sEnemy enemy[32];          //�\���̕ϐ��������̐錾
	//int movetype;            //�G�̓���^�C�v
	int waveflag[10];          //�Y���E�F�[�u�ɓG�����̂��邩���Ǘ�����
	int wave;                  //���݂̃E�F�[�u��
	int wavecount;             //�Y���E�F�[�u�œ���s�����I�����Ă���G�̐�
	
	int input[64];            //�ǂݎ����������̈ꎞ�ۊ�(int�p)
	char inputc[64];          //�ǂݎ����������̈ꎞ�ۊ�(char�p)
	int fileEndFlag;          //�t�@�C���ǂݍ��݂̏I���t���O
	int StageHandle;          //�t�@�C�����J���͂�ǂ�
	char StageFilePath[256];  //�ǂݍ��ރt�@�C���̖��O������z��
	int n,num;                //n,num
	int Phaseflag;            //�ړ��i�K�t���O
 
	//�֐��̃v���g�^�C�v�錾
	void Move(sEnemy&);
	void Shifted(sEnemy&,sEnemy&);
	cBaseEnemy* enemies[40];

public:
	cEnemyMgr();
	~cEnemyMgr();

	void Update();
	void Draw();

};
#endif // !_INGAME_MGR_INCLUDE_
