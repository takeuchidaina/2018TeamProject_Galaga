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
	float hitMissRatio;	  //弾を外した割合
public:
	void Draw();
	void Result();

	void AddScore(int n) { score += n; }
	void ResetScore() { score = 0; }
};


#endif