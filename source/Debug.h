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



class Debug : public cSingleton <Debug>{
	Debug();
	friend cSingleton<Debug>;
private:
	int tmp[None+1];
	cKeyboard tmpKey;

public:
//	virtual ~Debug();
	void Update();
	int Get_Input(eDebugInput);
};

