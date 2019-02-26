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
	//勝手に追加分 by タキ

	/*************************************************************************
	関　数: int GetSeActive()
	説　明:指定されたSEが再生されているか判断する関数
	引　数: tamplate T (eSe型かeMUSIC型のどちらか)
	戻り値: 0　再生していない　1　再生中 -1 エラー
	備　考:再生されているか知りたいseの名前を引数に入れてください
	*************************************************************************/
	template <typename Type>
	int GetSeActive(Type musicName) {
		return CheckSoundMem(se[musicName]);
	}

	/*************************************************************************
	関　数: void StopSound()
	説　明:指定されたSEを停止させる関数
	引　数: tamplate T (eSe型かeMUSIC型のどちらか)
	戻り値:なし
	備　考:止めたいSeの名前を入れてください
	*************************************************************************/
	template <typename _Type>
	void StopSound(_Type musicName) {
		StopSoundMem(*(se + musicName));
	}

	//引数のseを再生する
	void selectSE(int);

	//再生するseの項目
	typedef enum
	{

	}eSe;

};


#endif