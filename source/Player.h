#pragma once

#ifndef _PLAYER_INCLUDE_
#define _PLAYER_INCLUDE_

#include "Interface.h"

class cPlayer {
private:
	int x;
	int y;
	int isLRflg;


protected:

public:
	cPlayer();	//�R���X�g���N�^
	~cPlayer();	//�f�X�g���N�^
	int Update();	//�v�Z����
	int Draw();		//�`�ʏ���
	int Double();   //��@�̏���
	int Break();    //���S����

	cInterface Interface;

};

/*
struct tPlayer
{
int x, y;
int image[9];
int isLRflg;

};
*/
#endif