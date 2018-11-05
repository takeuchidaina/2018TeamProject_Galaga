#pragma once

#ifndef INGAME_MGR_INCLUDE_
#define INGAME_MGR_INCLUDE_

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
	int targetr;       //�ڕW�ʒu�̔��a(�����蔻��ɗ��p)
	int onactive;         //�\���E��\���̔���
	//int enemytype[3];     //�G�̎��(3�핪)
	}sEnemy;

	sEnemy enemy[16];  //�\���̕ϐ��������̐錾
	int movetype;         //�G�̓���^�C�v
	void Move(sEnemy&);
	void Shifted(sEnemy&,sEnemy&);

public:
	cEnemyMgr();
	~cEnemyMgr();

	void Update();
	void Draw();

};
#endif // !_INGAME_MGR_INCLUDE_
