#pragma once
#ifndef TRACTOR_INCLUDE
#define TRACTOR_INCLUDE
#include "Singleton.h"
#include "cBaseEnemy.h"
#include "cBlueEnemy.h"
#include "cRedEnemy.h"
#include "cGreenEnemy.h"
#include "Player.h"


/*トラクタービームの処理を行います
当たり判定などもこちらでやる予定です*/
class tractor : public cSingleton<tractor>
{
	friend cSingleton<tractor>;
protected:

	double tractorX;
	double tractorWidth;

public:
	/************************************
	トラクタービームのあたり判定
	引数 エネミー構造体
	戻り値　なし
	************************************/
	bool TractorHit(sEnemy*);

};




#endif // !TRACTOR_INCLUDE
