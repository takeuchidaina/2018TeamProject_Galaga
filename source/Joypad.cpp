#include<DxLib.h>
#include "Joypad.h"


void cJoypad::Joypad_Update() {
	int tmpPad;
	tmpPad = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	for (int i = 0; i<28; i++) {
		if (tmpPad & (1 << i)) {
			Pad[i]++;   // ���Z
		}
		else {              // ������Ă��Ȃ����
			Pad[i] = 0; // 0�ɂ���
		}
	}
}


int cJoypad::Joypad_Get(int Code) {
	return Pad[Code];
}

