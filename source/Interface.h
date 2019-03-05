#pragma once

#ifndef _INCLUDE_INTERFACE_
#define _INCLUDE_INTERFACE_

#include "Singleton.h"
#include "Keyboard.h"
#include "Joypad.h"
/*
Interfase�̌Ăѕ��i�g�����j
�P�A�g�������\�[�X�̐擪��"Interface.h"���C���N���[�h����
�Q�A������Ă��邩���ׂ����L�[������enum�ꗗ����T��
�R�A���ۂɒ��ׂ鎞��
	if(cInterface::Instance()->Get_Input(InRIGHT) != 0){	//�E�̓��͂�����Ă���ꍇif�̒���
		//�����ɏ���
	}
	�̂悤�ɏ���
	����Ȋ����ŃL�[�̎󂯎��A�f�o�b�O�Ȃǂ����Ă��������B
*/

//Interfase.Get_Input(�R�R)
typedef enum {
	InUP,		//��	����
	InRIGHT,	//�E	�E���
	InDOWN,		//��	�����
	InLEFT,		//��	�����
	InDECISION,	//����	�X�y�[�X�L�[
	InCANCEL,	//�L�����Z��	�o�b�N�X�y�[�X�L�[
	InSTRAT,	//�X�^�[�g�|�[�Y	�o�L�[
	InENTER,	//���U���g�����o���p�@�G���^�[�L�[
	InNONE
}eInput;

//���g�p���Ή�
typedef enum {
	InKeyboard,
	InGamepad
}eInputType;

class cInterface: public cSingleton<cInterface> {
	cInterface();
	friend cSingleton< cInterface >;
private:
	static int buff[InNONE];
	static eInputType inputType;
	cKeyboard tmpKey;
	cJoypad tmpPad;


public:
	void Update();
	int Get_Input(eInput);
	void Set_InputType(eInputType type) { inputType = type; }
};

#endif