#pragma once
#ifndef PLAYERENEMY_INCLUDE
#define PLAYERENEMY_INCLUDE

#include "cBaseEnemy.h"

class cPlayerEnemy : public cBaseEnemy {
private:

	sEnemy* tmpEnemy;//���������A��Ă���O���[���̃A�h���X�������
	
	 int graph[4];

	sOBJPos tmpPlayer;

	double rotecnt;//�O���O�����Ƃ��Ɏg���J�E���g
	
	int playerGraphNum;//�@�̂̐F��ύX����Ƃ��Ɏg��
	
	int reMoveFlg;//�����@�C�u�p�̈ړ��t���O
public:
	cPlayerEnemy(/*double, double, double, int, double, double, int, int*/);
	virtual ~cPlayerEnemy();
	virtual void Move();
	virtual int Update();
	int ReviveUpdate();
	//�g���N�^�[���ꂽ�ۂ̍ŏ��̈ړ�������֐�
	 //�g���N�^�[���ꂢ�Ă�Ԃ̈ړ�
	virtual int Draw();
	/*************************************************************************
	  �֐�: void cEnemyPlayer::SetPenemy()
	  ����: Update�֐��̒��̃|�C���^�ϐ���tractor���������G�̃A�h���X��������
	  ����: sEnemy�^�|�C���^
	�߂�l: ����
	*************************************************************************/
	void SetPenemy(sEnemy* tmp) {
		tmpEnemy = tmp;
	}

};

#endif // !PLAYERENEMY_INCLUDE
