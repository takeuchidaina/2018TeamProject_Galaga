#pragma once
#ifndef _UI_INCLUDE_
#define _UI_INCLUDE_

#include "Struct.h"
#include "InGameController.h"
#include "Player.h"

#define DISP_SIZE ((1280 / 4 * 3) - 50)
#define UI_SIZE (1280 - DISP_SIZE)
#define IMAGEMAG 48		//画像倍率
#define ICONMAG 32      //アイコンの画像倍率

//座標と表示する文字列の構造体
typedef struct
{
	int x, y;
	char text[20];

}sTextPos;

extern int UI_Init();
extern int UI_Update();
extern int UI_Draw();
extern int UI_End();

extern int UI_StgSelectIcon(int );
extern void UI_SetPlayerHP(int);

#endif
