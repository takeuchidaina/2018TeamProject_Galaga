#pragma once

#ifndef _INCLUDE_INTERFACE_
#define _INCLUDE_INTERFACE_

#include "Keyboard.h"

//Interfase.Get_Input(ココ)
typedef enum {
	InUP,
	InRIGHT,
	InDOWN,
	InLEFT,
	InDECISION,
	InCANCEL,
	InSTRAT,

	InNONE
}eInput;

//未使用未対応
typedef enum {
	InKeyboard,
	InGamepad
}eInputType;

class cInterface {
private:
	static int buff[InNONE];
	static eInputType inputType;
	cKeyboard tmpKey;
public:
	cInterface();
	void Update();
	int Get_Input(eInput);
};

#endif