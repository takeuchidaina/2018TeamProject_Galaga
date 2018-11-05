#pragma once

#ifndef _PLAYER_INCLUDE_
#define _PLAYER_INCLUDE_

#include "Interface.h"
#include "Struct.h"

class cPlayer {
private:

	int isLRflg;
	int image[9];


protected:

public:
	cPlayer();	//�R���X�g���N�^
	~cPlayer();	//�f�X�g���N�^
	int Update();	//�v�Z����
	int Draw();		//�`�ʏ���
	int Double();   //��@�̏���
	int Break(int);    //���S����

	cInterface Interface;
	sPos player[2];
	sOBJPos OBJPlayer[2];

};


//���S���g���N�^�[�r�[�������f
typedef enum
{
	eDeath,
	eTractorBeam,

}ePlayerBreak;

/*
struct tPlayer
{
int x, y;
int image[9];
int isLRflg;

};
*/
#endif