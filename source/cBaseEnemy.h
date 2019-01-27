#pragma once

#ifndef _cBaseEnemy_INCLUDE_
#define _cBaseEnemy_INCLUDE_
#include "Struct.h"
#include <math.h>
#include "DxLib.h"


/*
�S�ẴG�l�~�[�̌p����

*/



typedef struct {
	bool tractorflg;      //�g���N�^�[���s�����̃t���O
	bool tractorHitFlg; //�g���N�^�[�������������̔���
	bool tractingEnemy; //�߂܂��Ă���G�̕ߑ��pflg

	sPos vct;               // �x�N�g���px y
	sOBJPos mainpos;//���C����x y r onActive
	sPos target;          //��ʒu
	int targetr;          //�G�l�~�[�̒�ʒu�̔��a
	double spd;		  //���x
	double ang;	      //�����Ă���p�x
	int* graph;		 //�}�l�[�W���[������炤�摜�̃A�h���X�p
	int dir = 1;         //1�@�E�@-1�@��
	int width;           //��
	int height;         //����
	int count; //�ړ��J�E���g
	int moveflg; //�ړ�����t���O 
	int attackflg;//�U���t���O
	double moveang[15];//�ړ����̕����ω���
	double countflg[15];//�ړ��̃t�F�[�Y�؂�ւ��̃J�E���g
	int hp;
}sEnemy;

class cBaseEnemy {

protected:
	//�A�j���[�V�����̃J�E���g
	int AnimationCnt, AnimationNum;
	int TractorCnt, TractorNum;
	sEnemy enemy;


public:
	cBaseEnemy();//�R���X�g���N�^
	cBaseEnemy(double, double, double, int, double, double, int, int*);//�����t���R���X�g���N�^�[	
	virtual ~cBaseEnemy();//�f�X�g���N�^
	virtual	int Update();//�X�V����
	virtual int Draw();//�`�揈��
	/***********************************
	�ړ�����
	�����Ȃ� : �߂�l�Ȃ�
	****************************************/
	virtual void Move();
	/***********************************
	�g���N�^�[�p�̊֐��@�ΈȊO�ł͂��ł��Ȃɂ��Ȃ�
	�����Ȃ� : �߂�l�Ȃ�
	****************************************/
	virtual int TractorUpdate();
	/***********************************
	�G�l�~�[�̔j��֐��@
	�����Ȃ� : �߂�l�Ȃ�
	****************************************/
	virtual void Break() { enemy.mainpos.onActive = NoActive; };
	/***********************************
	�A�j���[�V�����̕`��֐�
	�����Ȃ� : �߂�l�Ȃ�
	****************************************/
	virtual void AnimationCount() { AnimationCnt++; };

	//OnAcitve�̏��
	enum eActiveType {
		StartMove, //�X�^�[�g��
		NoActive,  // �j��
		YesActive, //�N����
		ReadyStart, //�ړ��\��
		SetPos //�ړ��I����
	};

	//�E�ɂ��邩���ɂ��邩
	enum eRF {
		RIGHT = 1,
		LEFT = -1,
	};
	//�G�l�~�[�}�l�[�W���[�Ŏg���ړ�
	virtual void Update2() {
		enemy.mainpos.cx = enemy.mainpos.pos.x + (enemy.width / 2);
		enemy.mainpos.cy = enemy.mainpos.pos.y + (enemy.height / 2);
	}
	//������ӂ��玩���̏���Ԃ��֐�
	//���������ɑ������֐�

	virtual	sEnemy* GetEnemy() {
		return &enemy;
	}

	// x
	virtual	double GetEnemyX() {
		return enemy.mainpos.pos.x;
	}
	virtual	void SetEnemyX(double x) {
		enemy.mainpos.pos.x = x;
	}
	//y
	virtual	double GetEnemyY() {
		return enemy.mainpos.pos.y;
	}
	//
	virtual	void SetEnemyY(double y) {
		enemy.mainpos.pos.y = y;
	}
	//attackflg
	virtual	int GetEnemyAttackflg() {
		//if (enemy.attackflg == true && enemy.mainpos.onActive == SetPos)return false;

		return enemy.attackflg;
	}

	//�쐅��@�U������G��I������Ƃ��Ɏg������
	virtual int GetEnemyChoiseOrder() {
		if (enemy.attackflg == true && enemy.mainpos.onActive == SetPos)return FALSE;
		return enemy.attackflg;
	}

	virtual	void SetEnemyAttackflg() {
		enemy.attackflg = true;
	}

	//ang
	virtual	double GetEnemyAngle() {
		return enemy.ang;
	}
	virtual	void SetEnemyAngle(double ang) {
		enemy.ang = ang;
	}
	virtual	void SetEnemyAddAngle(double ang) {
		enemy.ang += ang;
	}

	//activeflg
	virtual	int GetEnemyOnActive() {
		return enemy.mainpos.onActive;
	}
	virtual	void SetEnemyOnActive() {
		if (enemy.mainpos.onActive != NoActive)enemy.mainpos.onActive = NoActive;
		else enemy.mainpos.onActive = YesActive;
	}
	//r
	virtual	double GetEnemyR() {
		return enemy.mainpos.r;
	}
	virtual	void SetEnemyR(double r) {
		enemy.mainpos.r = r;
	}
	//cx
	virtual	double GetEnemyCx() {
		return enemy.mainpos.cx;
	}
	virtual	void SetEnemyCx(double cx) {
		enemy.mainpos.cx = cx;
	}
	//cy
	virtual	double GetEnemyCy() {
		return enemy.mainpos.cy;
	}
	virtual	void SetEnemyCy(double cy) {
		enemy.mainpos.cy = cy;
	}

	virtual bool GetTractorfFlg() {
		return enemy.tractorflg;
	}
	virtual void SetTractorfFlg() {
		enemy.tractorflg = true;
	}

	virtual bool GetTractorHitFlg() {
		return enemy.tractorHitFlg;
	}

	virtual void SettractorHitFlg() {
		enemy.tractorHitFlg = true;
	}


	virtual bool GetTractingFlg() {
		return enemy.tractingEnemy;
	}


	virtual	int GetHp() { return enemy.hp; };

	virtual	void DamageHp() { enemy.hp--; };
	virtual	void SetHp() { enemy.hp = 0; };
};

#endif // !_cBaseEnemy_INCLUDE_
