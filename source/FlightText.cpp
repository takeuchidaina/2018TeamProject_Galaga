#include "FlightText.h"

//コンストラクタ
cFlightText::cFlightText()
{

}

//デストラクタ
cFlightText::~cFlightText()
{
}

void cFlightText::ScoreDraw(int x, int y, int score) {

	DrawFormatString(x, y, GetColor(255, 0,0), "%d", score);
	
}
