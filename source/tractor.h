#pragma once
#ifndef TRACTOR_INCLUDE
#define TRACTOR_INCLUDE
#include "Singleton.h"
#include "cBaseEnemy.h"
#include "cBlueEnemy.h"
#include "cRedEnemy.h"
#include "cGreenEnemy.h"
#include "Player.h"


/*�g���N�^�[�r�[���̏������s���܂�
�����蔻��Ȃǂ�������ł��\��ł�*/
class tractor : public cSingleton<tractor>
{
	friend cSingleton<tractor>;
private:
	 tractor();
	double tractorX;
	double tractorWidth;
	double playerX, playerY;
	cPlayerEnemy *TraitPlayer;
	sEnemy enemy;

	int graph[2];

public:
	/************************************
	�g���N�^�[�r�[���̂����蔻��
	���� �G�l�~�[�\����
	�߂�l�@�Ȃ�
	************************************/
	bool TractorHit(cGreenEnemy*);

	cPlayerEnemy* GetAdress(){
		return TraitPlayer;
	}
	void	draw();


};




#endif // !TRACTOR_INCLUDE
