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
	�֐����Fvoid ScoreDraw()
	�����F�w��̍��W�Ɏw��̃X�R�A��\��������
	�����Fint x,int y, int score
	�߂�l�F�Ȃ�
	******************************************************/
	void ScoreDraw(int,int,int);		

};
#endif