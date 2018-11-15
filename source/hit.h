#pragma once

#define MAXMACHINE 2

#define PLAYER 0
#define ENEMY 1

#ifndef _HITFUNC_INCLUDE_
#define _HITFUNC_INCLUDE_

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

class cHitFunc {
private:

protected:

public:
	cHitFunc();	//�R���X�g���N�^
	~cHitFunc();	//�f�X�g���N�^

	void Update();	//�v�Z����
	void Draw();		//�`�ʏ���
	void Hit();   //�����蔻��
	void BeemHit();    //�g���N�^�[�r�[�������蔻��

};


#endif