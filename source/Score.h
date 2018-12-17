#pragma once
#ifndef _SCORE_INCLUDE_
#define _SCORE_INCLUDE_

#include "Singleton.h"

class cScore : public cSingleton <cScore> {
	cScore();
	friend cSingleton <cScore>;
private:
	int score;			  //スコア
	int totalShot;		  //弾を撃った数
	int totalHit;		  //弾を当てた数
	double oneShotRatio;  //弾一発の割合
	double hitMissRatio;  //弾を外した割合
	int scoreX;			  //スコアがずれていく用

	//snprintf用
	char snScore[30];
	char snTotalShot[30];
	char snTotalHit[30];
	char snRatio[30];

public:
	void Update();
	void Draw();
	void Result();

	void AddScore(int n) { score += n; }
	void ResetScore();
};


#endif