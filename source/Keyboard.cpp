#include<DxLib.h>
#include "Keyboard.h"


// キーの入力状態更新
void cKeyboard::Keyboard_Update() {
	char tmpKey[256];             // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey);  // 全てのキーの入力状態を得る
	for (int i = 0; i<256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			m_Key[i]++;   // 加算
		}
		else {              // 押されていなければ
			m_Key[i] = 0; // 0にする
		}
	}
}

// KeyCodeのキーの入力状態を取得する
int cKeyboard::Keyboard_Get(int KeyCode) {
	return m_Key[KeyCode]; // KeyCodeの入力状態を返す
}

