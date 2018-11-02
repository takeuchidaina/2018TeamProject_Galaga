#pragma once

#ifndef _SHOT_INCLUDE_
#define _SHOT_INCLUDE_

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


class cShot {
private:
	double x, y, r, w ,h,c,rad;
	int OnActive;
	
protected:

public:
	cShot();	//�R���X�g���N�^
	~cShot();	//�f�X�g���N�^
	int Update();	//�v�Z����
	int Draw();		//�`�ʏ���
	inline int Get_OnActive();
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