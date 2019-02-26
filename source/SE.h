#pragma once

#ifndef _SE_INCLUDE_
#define _SE_INCLUDE_

#include "Singleton.h"

#define SENUM 23



typedef enum {
	capture,
	challenging_stage_clear,
	challenging_stage_perfect,
	challenging_stage_start,
	gamestart,
	mistake_12,
	nameentry_1st,
	music_nameentry_2nd_5th,	// - ���g���Ȃ��̂� _ �ɕύX
	rescue

}eMUSIC;


typedef enum {
	alien_flying = 9,
	boss_striken_1,
	boss_striken_2,
	credit,
	extend_sound,
	fighter_shot,
	goei_striken,
	ingame_ambience,
	miss,
	stage_flag,
	tractor_beam,
	tractor_beam_capture,
	triple_formation,
	zako_striken

}eSE;




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
	//����ɒǉ��� by �^�L

	/*************************************************************************
	�ց@��: int GetSeActive()
	���@��:�w�肳�ꂽSE���Đ�����Ă��邩���f����֐�
	���@��: tamplate T (eSe�^��eMUSIC�^�̂ǂ��炩)
	�߂�l: 0�@�Đ����Ă��Ȃ��@1�@�Đ��� -1 �G���[
	���@�l:�Đ�����Ă��邩�m�肽��se�̖��O�������ɓ���Ă�������
	*************************************************************************/
	template <typename Type>
	int GetSeActive(Type musicName) {
		return CheckSoundMem(se[musicName]);
	}

	/*************************************************************************
	�ց@��: void StopSound()
	���@��:�w�肳�ꂽSE���~������֐�
	���@��: tamplate T (eSe�^��eMUSIC�^�̂ǂ��炩)
	�߂�l:�Ȃ�
	���@�l:�~�߂���Se�̖��O�����Ă�������
	*************************************************************************/
	template <typename _Type>
	void StopSound(_Type musicName) {
		StopSoundMem(*(se + musicName));
	}

	//������se���Đ�����
	void selectSE(int);

	//�Đ�����se�̍���
	typedef enum
	{

	}eSe;

};


#endif