#pragma once

#ifndef _EFFECT_INCLUDE_
#define _EFFECT_INCLUDE_
#define PLAYER 0
#define ENEMY 1


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
	int OnActive, type, nowGr, adjust,i;
protected:

public:
	cEffect();
	~cEffect();
	void Init();//����������
	int Update(int*);	//�v�Z����
	int Draw(int*);		//�`�ʏ���

	inline int Get_OnActive() { return OnActive; }
	void Set_OnActive(int tmp) { OnActive = tmp; }
	inline int Get_Type() { return type; }
	void Set_Type(int tmp) { type = tmp; }
	inline int Get_CX() { return (int)cx; }
	void Set_CX(int tmp) { cx = tmp; }
	inline int Get_CY() { return (int)cy; }
	void Set_CY(int tmp) { cy = tmp; }
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