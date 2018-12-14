#pragma once
#ifndef _SCORE_INCLUDE_
#define _SCORE_INCLUDE_

#include "Singleton.h"

class cScore : public cSingleton <cScore> {
	cScore();
	friend cSingleton <cScore>;
private:
	int score;			  //�X�R�A
	int totalShot;		  //�e����������
	int totalHit;		  //�e�𓖂Ă���
	float hitMissRatio;	  //�e���O��������
public:
	void Draw();
	void Result();

	void AddScore(int n) { score += n; }
	void ResetScore() { score = 0; }
};


#endif