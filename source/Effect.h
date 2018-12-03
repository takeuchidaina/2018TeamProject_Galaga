#pragma once

#ifndef _EFFECT_INCLUDE_
#define _EFFECT_INCLUDE_

#include "Singleton.h"


/*
//�e���v���[�g�� �N���X���e���v���[�g���\
template <typename TYPE>
void Swap(TYPE& a, TYPE& b) {
	TYPE tmp;
	tmp = a;
	a = b;
	b = tmp;
}
*/


class cEffect :public cSingleton<cEffect> {
	cEffect();
	friend cSingleton<cEffect>;
private:
	
protected:

public:
	int Update();	//�v�Z����
	int Draw();		//�`�ʏ���
/*
//�錾��
private:
	int mTest;
public:
	void Set_Test(int);	//private�����o�ϐ�mTest�ւ̑��
	int Get_Test();		//private�����o�ϐ�mTest�̊l��
*/
};
#endif