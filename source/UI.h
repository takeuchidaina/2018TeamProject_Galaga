#pragma once
#ifndef _UI_INCLUDE_
#define _UI_INCLUDE_

#include "Struct.h"

#define DISP_SIZE ((1280 / 4 * 3) - 50)
#define UI_SIZE (1280 - DISP_SIZE)
#define IMAGEMAG 48		//‰æ‘œ”{—¦

//À•W‚Æ•\¦‚·‚é•¶š—ñ‚Ì\‘¢‘Ì
typedef struct
{
	int x, y;
	char text[20];

}sTextPos;

extern int UI_Init();
extern int UI_Update();
extern int UI_Draw();
extern int UI_End();

#endif
