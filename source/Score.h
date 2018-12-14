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
	float oneShotRatio;	  //�e�ꔭ�̊���
	float hitMissRatio;	  //�e���O��������
	int scoreX;			  //�X�R�A������Ă����p

	//snprintf�p
	char snScore[30];
	char snTotalShot[30];
	char snTotalHit[30];
	char snRatio[30];

public:
	void Update();
	void Draw();
	void Result();

	void AddScore(int n) { score += n; }
	void ResetScore() { score = 0; }
};


#endif