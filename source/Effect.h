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
	double x, y, cx, cy, w, h;
	int OnActive, adjust;
protected:

public:
	cEffect();
	~cEffect();
	void Init();//����������
	int Update();	//�v�Z����
	int Draw(int*);		//�`�ʏ���
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