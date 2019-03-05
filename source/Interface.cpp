#include "DxLib.h"
#include "interface.h"
#include "Keyboard.h"


int cInterface::buff[InNONE];
eInputType cInterface::inputType;


cInterface::cInterface() {
	inputType = InKeyboard;
	//inputType = InGamepad;
}

//ééçÏ configÇ≈ëŒâûÇ≥ÇπÇÈ
void cInterface::Update() {
	tmpKey.Keyboard_Update();
	tmpPad.Joypad_Update();
	if (inputType == InKeyboard) {
		buff[InUP] = tmpKey.Keyboard_Get(KEY_INPUT_UP);
		buff[InRIGHT] = tmpKey.Keyboard_Get(KEY_INPUT_RIGHT);
		buff[InDOWN] = tmpKey.Keyboard_Get(KEY_INPUT_DOWN);
		buff[InLEFT] = tmpKey.Keyboard_Get(KEY_INPUT_LEFT);
		buff[InDECISION] = tmpKey.Keyboard_Get(KEY_INPUT_SPACE);
		buff[InCANCEL] = tmpKey.Keyboard_Get(KEY_INPUT_BACK);
		buff[InSTRAT] = tmpKey.Keyboard_Get(KEY_INPUT_P);
		buff[InENTER] = tmpKey.Keyboard_Get(KEY_INPUT_RETURN);
	}
	else if (inputType == InGamepad) {
		buff[InUP] = tmpPad.Joypad_Get(cJoypad::Up);
		buff[InRIGHT] = tmpPad.Joypad_Get(cJoypad::Right);
		buff[InDOWN] = tmpPad.Joypad_Get(cJoypad::Down);
		buff[InLEFT] = tmpPad.Joypad_Get(cJoypad::Left);
		buff[InDECISION] = tmpPad.Joypad_Get(cJoypad::button2);
		buff[InCANCEL] = tmpPad.Joypad_Get(cJoypad::button3);
		buff[InSTRAT] = tmpPad.Joypad_Get(cJoypad::button1);
		buff[InENTER] = tmpPad.Joypad_Get(cJoypad::button4);

	}
}

int cInterface::Get_Input(eInput input) {
	return buff[input];
}