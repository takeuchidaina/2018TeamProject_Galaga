#pragma once
#ifndef _BACKGROUND_INCLUDE_
#define _BACKGROUND_INCLUDE_

#include<time.h>
#include "Singleton.h"
#include "UI.h"
#include "InGameMgr.h"

#define MAXSTAR 200		//���̐�
#define TRUE 1


typedef struct {

	int x, y, r;				//���W�E���a
	int speed;					//�ړ����x
	int blinkFlg;				//�_�ŗp�t���O
	double blinkCnt, blinkNum;	//�_�ŗp�J�E���g
	int color;					//�F

} sStar;

class cBackGround : public cSingleton<cBackGround>
{
	cBackGround();
	friend cSingleton< cBackGround >;
private:
	sStar starArray[MAXSTAR];	//���̔z��

	void Init(int);			//����������

	int sceneFlg;			//scene���
	int eTractor;

public:
	void Update();			//�v�Z����
	void Draw();			//�`�ʏ���

	/************************************************************
	�֐��Fvoid TractingUpdate
	�����F�g���N�^�[���̐��̓���
	�����F�Ȃ�
	�߂�l�F�Ȃ�
	************************************************************/
	void TractingUpdate();

	/************************************************************
	�֐��Fvoid PauseUpdate
	�����F���̓�����~
	�����F�Ȃ�
	�߂�l�F�Ȃ�
	************************************************************/
	void PauseUpdate();

};
#endif