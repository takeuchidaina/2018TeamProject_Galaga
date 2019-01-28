#ifndef _FLIGHT_TEXT_INCLUDE_
#define _FLIGHT_TEXT_INCLUDE_
#include <math.h>
#include <Dxlib.h>
#include "Singleton.h"
#include"cBaseEnemy.h"

class cFlightText : public cSingleton<cFlightText>
{
	cFlightText();
	~cFlightText();
	friend cSingleton<cFlightText>;
private:
	int count;

protected:

public:
	

	/*****************************************************
	関数名：void ScoreDraw()
	説明：指定の座標に指定のスコアを表示させる
	引数：int x,int y, int score
	戻り値：なし
	******************************************************/
	void ScoreDraw(int,int,int);		

};
#endif