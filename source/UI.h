#pragma once
#ifndef _UI_INCLUDE_
#define _UI_INCLUDE_

#include "Struct.h"
#include "InGameController.h"
#include "Player.h"
#include "TextChange.h"
#include "Singleton.h"

#define DISP_SIZE ((1280 / 4 * 3) - 50)
#define UI_SIZE (1280 - DISP_SIZE)
#define IMAGEMAG 48		//画像倍率
#define ICONMAG 32      //アイコンの画像倍率

//DEBUG
#include "Interface.h"
#define UI_COLOR GetColor(0,255,0)

    //  #include "takeuchi_debug_define.h"


//座標と表示する文字列の構造体
typedef struct
{
	int x, y;
	char text[20];

}sTextPos;

class cUI : public cSingleton<cUI>
{
	cUI();	//コンストラクタ
	~cUI();	//デストラクタ
	friend cSingleton< cUI >;

private:

	int iconX;
	int iconY;
	int textImg[48];	//テキストの画像
	int iconImg[12];	//ステージアイコンの画像

	int stageNo;	//ステージ番号
	int playerHP;   //残機

	const sTextPos textPos[3] =
	{
		{ DISP_SIZE + 150, 100,"HIGH" },
		{ DISP_SIZE + 120, 130,"SCORE" },
		{ DISP_SIZE + 180, 200,"1UP" },
	};

protected:

public:

	//int UI_Update();
	int UI_Draw();
	int UI_StgSelectIcon(int);
	void UI_SetPlayerHP(int);

};

#endif
