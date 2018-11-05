#pragma once
#pragma once
#ifndef _INGAME_MGR_INCLUDE_
#define _INGAME_MGR_INCLUDE_


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
	double angle;           //�p�x
	double speed;         //���x
	int moveflag;         //����t���O
	int maxmove;          //����t���O�̍ő吔
	double moveangle[3];  //�p�x�ݒ�̔z��
	int countflag[3];     //����̃t���[���������ꂷ��z��
	int RLflag;           //���E�𔻒肷��t���O
	sPos target;          //�ڕW�ʒu�̍��W
	double targetr;       //�ڕW�ʒu�̔��a(�����蔻��ɗ��p)
	int onactive;         //�\���E��\���̔���
	//int enemytype[3];     //�G�̎��(3�핪)
	}sEnemy;

	sEnemy enemy[16];  //�\���̕ϐ��������̐錾
	int movetype;         //�G�̓���^�C�v


public:
	cEnemyMgr();
	~cEnemyMgr();

	void Move(sEnemy&);
	void Shifted(sEnemy&,sEnemy);

	void Update();
	void Draw();

};

#endif