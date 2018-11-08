#pragma once

#ifndef _PLAYER_INCLUDE_
#define _PLAYER_INCLUDE_

#include "Interface.h"
#include "Struct.h"

#define SPEED 3			//�v���C���[�̃X�s�[�h
#define IMAGEMAG 48		//�摜�{��
#define MAXMACHINE 2	//�v���C���[�͓�@�܂�(�O�@�ɂȂ�Ȃ�)

class cPlayer {
private:

	int isLRflg;   // 0:�ړ��Ȃ� -1:�� 1:�E
	int image[2];
	int UIsize;

protected:

public:
	cPlayer();	//�R���X�g���N�^
	~cPlayer();	//�f�X�g���N�^

	int Update();	//�v�Z����
	int Draw();		//�`�ʏ���
	int Double();   //��@�̏���
	int Break(int,int);    //���S����

	cInterface Interface;
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
	eDouble,			//�����̋@��

}eMachineNum;

#endif