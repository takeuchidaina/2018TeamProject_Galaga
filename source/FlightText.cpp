#include "FlightText.h"

//�R���X�g���N�^
cFlightText::cFlightText()
{

}

//�f�X�g���N�^
cFlightText::~cFlightText()
{
}

void cFlightText::ScoreDraw(int x, int y, int score) {

	DrawFormatString(x, y, GetColor(255, 0,0), "%d", score);
	
}
