#pragma once

#ifndef _PLAYER_INCLUDE_
#define _PLAYER_INCLUDE_

#include "Struct.h"
#include "UI.h"
#include "Singleton.h"

#define SPEED 6			//�v���C���[�̃X�s�[�h
#define MAXMACHINE 2	//�v���C���[�͓�@�܂�(�O�@�ɂȂ�Ȃ�)
#define NULL 0			//�G���[���Ɏg�p

//DEBUG
#define P_COLOR GetColor(255,0,0)

      //    #include "takeuchi_debug_define.h"


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
	int GetPlayerHP();		//HP��n��
	sOBJPos GetPlayer(int num) 	//�\���̂̎󂯓n���@�@num 0:��  1:�E
	{
		sOBJPos *p = NULL;
		return ((num == 0 || num == 1) ? player[num]:*p);
		//�G���[��NULL
		//for���Ŏ󂯎���Ă�������
	}

	sOBJPos player[2];  //�z��Ȃ͈̂�@����@���ŕς���
	int isDoubleFlg;    // 0:��@ 1:��@
	int playerHP;       //HP(��ɏo�Ă���@�̂��܂܂Ȃ�)


};

//���S���g���N�^�[�r�[�������f
typedef enum
{
	eDeath,				//���j
	eTractorBeam,		//�g���N�^�[�r�[��

}ePlayerBreak;

//���̋@�̂��E�̋@�̂��A�܂��������w�肵�Ă���̂�
typedef enum
{
	eLeftMachine,		//���̋@��
	eRightMachine,		//�E�̋@��
	eNoneMachine,		//�@�̖���

}eMachineNum;

#endif