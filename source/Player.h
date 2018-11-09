#pragma once

#ifndef _PLAYER_INCLUDE_
#define _PLAYER_INCLUDE_

#include "Struct.h"
#include "UI.h"

#define SPEED 3			//�v���C���[�̃X�s�[�h
#define MAXMACHINE 2	//�v���C���[�͓�@�܂�(�O�@�ɂȂ�Ȃ�)

class cPlayer {
private:

	int isLRflg;	  // 0:�ړ��Ȃ� -1:�� 1:�E
	int image[2];	  //�摜

protected:

public:
	cPlayer();	//�R���X�g���N�^
	~cPlayer();	//�f�X�g���N�^

	void Update();	//�v�Z����
	void Draw();		//�`�ʏ���
	void Double();   //��@�̏���
	void Break(int,int);    //���S����
	sOBJPos*  GetStruct() { return OBJPlayer; }	//�\���̂̎󂯓n��

	sOBJPos OBJPlayer[2];
	//�z��Ȃ͈̂�@����@���ŕς���

};

//���S���g���N�^�[�r�[�������f
typedef enum
{
	eDoubleDeath,		//��@�̏�ԂŕЕ������j
	eDeath,				//��@�̏�ԂŌ��j
	eTractorBeam,		//�g���N�^�[�r�[��

}ePlayerBreak;

//���̋@�̂��E�̋@�̂��A�܂��������w�肵�Ă���̂�
typedef enum
{
	eLeftMachine,		//���̋@��
	eRightMachine,		//�E�̋@��
	eDoubleMachine,			//�����̋@��

}eMachineNum;

#endif