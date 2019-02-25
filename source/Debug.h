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
デバッグコマンド用クラス
Update関数を呼び出さなければ使えないのでデバッグ中はUpdate()をWinMainに書く
キーの　０－９　Ｆ１－Ｆ１２　を対応
************************************************************************/
class Debug : public cSingleton <Debug>{
	Debug();
	friend cSingleton<Debug>;
private:
	int tmp[None+1];
	cKeyboard tmpKey;

public:
	//キー獲得状態の更新用
	void Update();
	/*********************************
	関数名：int Get_Input(eDebugInput)
	説明：デバッグ対応キーが押されているかを獲得する
	引数：eDebugInput型 キーコード
	戻り値：int型 押されているフレーム数
	**********************************/
	int Get_Input(eDebugInput);
};

