#pragma once
#ifndef _FPS_INCLUDE_
#define _FPS_INCLUDE_

#include <math.h>
#include "DxLib.h"
#include "Singleton.h"
/************************************************************************
FPS管理用クラス
FPSの制御と表示を行う
************************************************************************/
class cFps : public cSingleton<cFps>{
	cFps() {
		mStartTime = 0;
		mCount = 0;
		mFps = 0;
	}
	friend cSingleton<cFps>;
	int mStartTime;         //測定開始時刻
	int mCount;             //カウンタ
	float mFps;             //fps
	static const int N = 85;//平均を取るサンプル数
	static const int FPS = 85;	//設定したFPS

public:

	bool Update() {
		if (mCount == 0) { //1フレーム目なら時刻を記憶
			mStartTime = GetNowCount();
		}
		if (mCount == N) { //60フレーム目なら平均を計算する
			int t = GetNowCount();
			mFps = 1000.f / ((t - mStartTime) / (float)N);
			mCount = 0;
			mStartTime = t;
		}
		mCount++;
		return true;
	}

	/*********************************
	関数名：void Draw()
	説明：画面の右上に現在のFPSを表示する
	引数：無し
	戻り値：無し
	**********************************/
	void Draw() {
		DrawFormatString(1220, 0, GetColor(255, 255, 255), "%.1f", mFps);
	}

	/*********************************
	関数名：void Wait()
	説明：FPSをprivate内の static const int FPS の数値と同じにする
	引数：無し
	戻り値：無し
	**********************************/
	void Wait() {
		int tookTime = GetNowCount() - mStartTime;	//かかった時間
		int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
		if (waitTime > 0) {
			Sleep(waitTime);	//待機
		}
	}
};

#endif