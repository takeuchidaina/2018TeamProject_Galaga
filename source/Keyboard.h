#pragma once

#ifndef _INCLUDE_KEYBOARD_
#define _INCLUDE_KEYBOARD_

class cKeyboard {
private:
	int m_Key[256];  // �L�[�̓��͏�Ԋi�[�p�ϐ�
public:
	cKeyboard() {}
	void Keyboard_Update();
	int Keyboard_Get(int KeyCode);

};


#endif