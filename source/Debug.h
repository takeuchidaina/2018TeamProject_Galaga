#pragma once
#include "Singleton.h"
#include "Keyboard.h"

typedef enum {
	Key1,
	Key2,
	Key3,
	Key4,
	Key5,
	Key6,
	Key7,
	Key8,
	Key9,
	Key0,
	KeyF1,
	KeyF2,
	KeyF3,
	KeyF4,
	KeyF5,
	KeyF6,
	KeyF7,
	KeyF8,
	KeyF9,
	KeyF10,
	KeyF11,
	KeyF12,

	None
}eDebugInput;


/************************************************************************
�f�o�b�O�R�}���h�p�N���X
Update�֐����Ăяo���Ȃ���Ύg���Ȃ��̂Ńf�o�b�O����Update()��WinMain�ɏ���
�L�[�́@�O�|�X�@�e�P�|�e�P�Q�@��Ή�
************************************************************************/
class Debug : public cSingleton <Debug>{
	Debug();
	friend cSingleton<Debug>;
private:
	int tmp[None+1];
	cKeyboard tmpKey;

public:
	//�L�[�l����Ԃ̍X�V�p
	void Update();
	/*********************************
	�֐����Fint Get_Input(eDebugInput)
	�����F�f�o�b�O�Ή��L�[��������Ă��邩���l������
	�����FeDebugInput�^ �L�[�R�[�h
	�߂�l�Fint�^ ������Ă���t���[����
	**********************************/
	int Get_Input(eDebugInput);
};

