#pragma once

#ifndef _INCLUDE_KEYBOARD_
#define _INCLUDE_KEYBOARD_

class cKeyboard {
private:
	int Key[256];  // キーの入力状態格納用変数
public:
	cKeyboard() {}
	void Keyboard_Update();
	int Keyboard_Get(int KeyCode);

};


#endif