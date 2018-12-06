#pragma once

#ifndef _SE_INCLUDE_
#define _SE_INCLUDE_

#include "Singleton.h"

#define SENUM 23



typedef enum {
	capture,
	challenging_stage_clear,
	challenging_stage_perfect,
	challenging_stage_start,
	gamestart,
	mistake_12,
	nameentry_1st,
	music_nameentry_2nd_5th,	// - が使えないので _ に変更
	rescue

}eMUSIC;


typedef enum {
	alien_flying = 9,
	boss_striken_1,
	boss_striken_2,
	credit,
	extend_sound,
	fighter_shot,
	goei_striken,
	ingame_ambience,
	miss,
	stage_flag,
	tractor_beam,
	tractor_beam_capture,
	triple_formation,
	zako_striken

}eSE;




class cSE : public cSingleton<cSE>
{
	cSE();	//コンストラクタ
	~cSE();	//デストラクタ
	friend cSingleton< cSE >;

private:

	//seを読み込む配列
	int se[SENUM];

protected:

public:

	//引数のseを再生する
	void selectSE(int);

	//再生するseの項目
	typedef enum
	{

	}eSe;

};


#endif