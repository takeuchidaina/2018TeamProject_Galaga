#pragma once

#ifndef _TEXTCONVERSION_INCLUDE_
#define _TEXTCONVERSION_INCLUDE_

#include "Singleton.h"

class cTextChange : public cSingleton<cTextChange>
{
	cTextChange();
	friend cSingleton< cTextChange >;

private:

	int textImg[48];	//画像ハンドル
	int hue;			//色相[0～360]
	int saturation;		//彩度[-255～]
	int bright;			//輝度[-255～255]
	int magX;			//画像倍率用のx
	int magY;			//画像倍率用のy
	int mag;			//画像倍率

public:

	/*************************************************************************
	 関数: int DrawTextImage
	 説明: 引数の座標に指定の色と倍率で文字を表示します、アルファベットの大文字のみです。
	 引数: (int x, int y, char *文字列, int 色, int 倍率)
			色と倍率はenum(下記に記述)
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
	eNone,		//無し(色はあるがプログラムの見た目上)
}eColor;

//文字サイズ(倍率)
typedef enum
{
	eMag16,		//16x16
	eMag32,		//32x32
	eMag48,		//48x48

}eMagnification;

#endif
