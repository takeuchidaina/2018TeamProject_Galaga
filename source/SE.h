#pragma once

#ifndef _SE_INCLUDE_
#define _SE_INCLUDE_

#include "Singleton.h"

#define SENUM 23


class cSE : public cSingleton<cSE>
{
	cSE();	//�R���X�g���N�^
	~cSE();	//�f�X�g���N�^
	friend cSingleton< cSE >;

private:

	//se��ǂݍ��ޔz��
	int se[SENUM];

protected:

public:

	//������se���Đ�����
	void selectSE(int);

	//�Đ�����se�̍���
	typedef enum
	{

	}eSe;

};


#endif