#pragma once

#ifndef _INCLUDE_JOYPAD_
#define _INCLUDE_JOYPAD_


class cJoypad {
private:
	int Pad[28];
public:
	enum {
		Down,
		Left,
		Right,
		Up,
		button1,
		button2,
		button3,
		button4,
		button5,
		button6,
		button7,
		button8,
		button9,
		button10,
		button11,
		button12,
		button13,
		button14,
		button15,
		button16,
		button17,
		button18,
		button19,
		button20,
		button21,
		button22,
		button23,
		button24,
		
		None


	}eJoypad;

	cJoypad() {}
	void Joypad_Update();
	int Joypad_Get(int);

};


#endif