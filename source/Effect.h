#pragma once

#ifndef _EFFECT_INCLUDE_
#define _EFFECT_INCLUDE_

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


class cEffect {
private:
	
protected:

public:
	cEffect();	//�R���X�g���N�^
	~cEffect();	//�f�X�g���N�^
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