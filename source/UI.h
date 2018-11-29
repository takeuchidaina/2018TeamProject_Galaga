#pragma once
#ifndef _UI_INCLUDE_
#define _UI_INCLUDE_

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
	eColor color;

}sTextPos;

class cUI : public cSingleton<cUI>
{
	cUI();	//コンストラクタ
	~cUI();	//デストラクタ
	friend cSingleton< cUI >;

private:

	int iconX;			//アイコンの座標x
	int iconY;			//アイコンの座標y
	int textImg[48];	//テキストの画像
	int iconImg[12];	//ステージアイコンの画像
	int stageNo;		//ステージ番号
	int playerHP;		//残機
	int blinkCnt;	    //点滅処理のカウント("1UP")
	int blinkFlg;	    //点滅処理のフラグ("1UP")

	//座標と表示する文字列の構造体の初期化
	const sTextPos textPos[4] =
	{
		{ DISP_SIZE + 150, 10,"HIGH",eRed },
		{ DISP_SIZE + 102, 58,"SCORE",eRed },
		{ DISP_SIZE + 198, 152,"1UP",eRed },
		{ DISP_SIZE + 198, 152,"   ",eNone },   //blink
	};

protected:

public:
	/*************************************************************************
	   関数: int UI_Draw()
	   説明: 枠組み・残機・ステージアイコンの表示と文字データの送信
	   引数: 無し
	 戻り値: 無し
	 *************************************************************************/
	int UI_Draw();

	/*************************************************************************
	　関数: int UI_SelectIcon()
	　説明: ステージ情報のアイコンをどれを表示するか
	　引数: int ステージ番号
	戻り値: 無し
	*************************************************************************/
	int UI_StgSelectIcon(int);

	/*************************************************************************
	　関数: void UI_SetPlayerHP()
	　説明: プレイヤーの残機の更新
	　引数: int プレイヤーのHP
	戻り値: 無し
	*************************************************************************/
	void UI_SetPlayerHP(int);

};

#endif
