#pragma once

#ifndef _TEXTCHANGE_INCLUDE_
#define _TEXTCHANGE_INCLUDE_

#include "Singleton.h"

#define IMAGE_NUM 41
#define MAG16 16
#define MAG32 32
#define MAG48 48

class cTextChange : public cSingleton<cTextChange>
{
	cTextChange();
	~cTextChange();
	friend cSingleton< cTextChange >;

private:

	//画像
	int textImgRD[IMAGE_NUM];	//画像ハンドル 赤
	int textImgLB[IMAGE_NUM];	//画像ハンドル 水
	int textImgYL[IMAGE_NUM];	//画像ハンドル 黄
	int textImgWH[IMAGE_NUM];	//画像ハンドル 白
	int imgColor[IMAGE_NUM];	//画像ハンドル代入用  
	//画像は40個だがスペースが欲しいので、41はスペース用

	//倍率関係
	int magX;			//画像倍率用のx
	int magY;			//画像倍率用のy
	int spacing;		//文字間隔

public:

	/*************************************************************************
	 　関数: int DrawTextImage
	 　説明: 引数の座標に指定の色と倍率で文字を表示します、アルファベットの大文字と記号です。
	       　対応記号 : [.] [%] [-] [@]←コピーライト
	 　引数: (int x, int y, char *文字列, eColor, eMag)
			  eColorとeMagは下記記述
	 戻り値: 無し
	 *************************************************************************/
	int DrawTextImage(int, int, const char *,int,int);
};

//色
typedef enum
{
	eRed,		//赤色
	eYellow,	//黄色
	eLBlue,		//水色
	eWhite,		//白色
	eNone,		//点滅等で引数に使用(色は白が指定される)
}eColor;

//文字サイズ(倍率)
typedef enum
{
	eMag16,		//16x16
	eMag32,		//32x32
	eMag48,		//48x48
}eMag;

#endif
