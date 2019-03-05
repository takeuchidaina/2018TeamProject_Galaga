#pragma once

#ifndef _INCLUDE_INTERFACE_
#define _INCLUDE_INTERFACE_

#include "Singleton.h"
#include "Keyboard.h"
#include "Joypad.h"
/*
Interfaseの呼び方（使い方）
１、使いたいソースの先頭で"Interface.h"をインクルードする
２、押されているか調べたいキーを下のenum一覧から探す
３、実際に調べる時は
	if(cInterface::Instance()->Get_Input(InRIGHT) != 0){	//右の入力がされている場合ifの中へ
		//ここに処理
	}
	のように書く
	こんな感じでキーの受け取り、デバッグなどをしてください。
*/

//Interfase.Get_Input(ココ)
typedef enum {
	InUP,		//上	上矢印
	InRIGHT,	//右	右矢印
	InDOWN,		//下	下矢印
	InLEFT,		//左	左矢印
	InDECISION,	//決定	スペースキー
	InCANCEL,	//キャンセル	バックスペースキー
	InSTRAT,	//スタートポーズ	Ｐキー
	InENTER,	//リザルト抜け出す用　エンターキー
	InNONE
}eInput;

//未使用未対応
typedef enum {
	InKeyboard,
	InGamepad
}eInputType;

class cInterface: public cSingleton<cInterface> {
	cInterface();
	friend cSingleton< cInterface >;
private:
	static int buff[InNONE];
	static eInputType inputType;
	cKeyboard tmpKey;
	cJoypad tmpPad;


public:
	void Update();
	int Get_Input(eInput);
	void Set_InputType(eInputType type) { inputType = type; }
};

#endif