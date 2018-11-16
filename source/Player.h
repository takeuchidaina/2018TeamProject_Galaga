#pragma once

#ifndef _PLAYER_INCLUDE_
#define _PLAYER_INCLUDE_

#include "Struct.h"
#include "UI.h"
#include "Singleton.h"

#define SPEED 3			//�v���C���[�̃X�s�[�h
#define MAXMACHINE 2	//�v���C���[�͓�@�܂�(�O�@�ɂȂ�Ȃ�)
#define NULL 0			//�G���[���Ɏg�p

class cPlayer : public cSingleton<cPlayer>
{
	cPlayer();	//�R���X�g���N�^
	~cPlayer();	//�f�X�g���N�^
	friend cSingleton< cPlayer >;

private:

	int image[2];	  //�摜

protected:

public:


	void Update();	//�v�Z����
	void Draw();		//�`�ʏ���
	void Double();   //��@�̏���
	void Break(int,int);    //���S����
	sOBJPos GetPlayer(int num) 	//�\���̂̎󂯓n���@�@num 0:��  1:�E
	{
		sOBJPos *p = NULL;
		return ((num == 0 || num == 1) ? player[num]:*p);
		//�G���[��NULL
		//for���Ŏ󂯎���Ă�������
	}

	sOBJPos player[2];
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