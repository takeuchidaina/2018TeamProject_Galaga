#include "DxLib.h"
#include "interface.h"
#include "Keyboard.h"



cInterface::cInterface() {
	inputType = InKeyboard;
}


//試作 configで対応させる
void cInterface::Update() {
	tmpKey.Keyboard_Update();
	if (inputType == InKeyboard) {
		buff[InUP] = tmpKey.Keyboard_Get(KEY_INPUT_UP);
		buff[InRIGHT] = tmpKey.Keyboard_Get(KEY_INPUT_RIGHT);
		buff[InDOWN] = tmpKey.Keyboard_Get(KEY_INPUT_DOWN);
		buff[InLEFT] = tmpKey.Keyboard_Get(KEY_INPUT_LEFT);
		buff[InDECISION] = tmpKey.Keyboard_Get(KEY_INPUT_SPACE);
		buff[InCANCEL] = tmpKey.Keyboard_Get(KEY_INPUT_BACK);
		buff[InSTRAT] = tmpKey.Keyboard_Get(KEY_INPUT_P);
	}
	else if (inputType == InGamepad) {

	}
}

int cInterface::Get_Input(eInput input) {
	return buff[input];
}