#pragma once

#ifndef _PLAYER_INCLUDE_
#define _PLAYER_INCLUDE_

#include "Interface.h"
#include "Struct.h"

#define SPEED 3     //�v���C���[�̃X�s�[�h
#define IMAGEMAG 48 //�摜�{��

class cPlayer {
private:

	int isLRflg;
	//int isDoubleFlg;
	int image[2];


protected:

public:
	cPlayer();	//�R���X�g���N�^
	~cPlayer();	//�f�X�g���N�^

	int Update();	//�v�Z����
	int Draw();		//�`�ʏ���
	int Double();   //��@�̏���
	int Break(int);    //���S����

	cInterface Interface;
	//sPos player[2];
	sOBJPos OBJPlayer[2];
	//�z��Ȃ͈̂�@����@���ŕς���

};


//���S���g���N�^�[�r�[�������f
typedef enum
{
	eDoubleDeath,
	eDeath,
	eTractorBeam,

}ePlayerBreak;

#endif