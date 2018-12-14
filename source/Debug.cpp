#include "Debug.h"
#include "DxLib.h"

Debug::Debug() {}




void Debug::Update(){
	tmpKey.Keyboard_Update();
	for (int i = Key1; i <= Key0; i++) {
		tmp[i] = tmpKey.Keyboard_Get(i + KEY_INPUT_1);
	}
	for (int i = KeyF1; i <= KeyF12; i++) {
		tmp[i] = tmpKey.Keyboard_Get(i - KeyF1 + KEY_INPUT_F1);
	}

}
int Debug::Get_Input(eDebugInput num) {
	return tmp[num];
}