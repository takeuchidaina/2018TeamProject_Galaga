#pragma once
#ifndef _FPS_INCLUDE_
#define _FPS_INCLUDE_

#include <math.h>
#include "DxLib.h"
#include "Singleton.h"
/************************************************************************
FPS�Ǘ��p�N���X
FPS�̐���ƕ\�����s��
************************************************************************/
class cFps : public cSingleton<cFps>{
	cFps() {
		mStartTime = 0;
		mCount = 0;
		mFps = 0;
	}
	friend cSingleton<cFps>;
	int mStartTime;         //����J�n����
	int mCount;             //�J�E���^
	float mFps;             //fps
	static const int N = 85;//���ς����T���v����
	static const int FPS = 85;	//�ݒ肵��FPS

public:

	bool Update() {
		if (mCount == 0) { //1�t���[���ڂȂ玞�����L��
			mStartTime = GetNowCount();
		}
		if (mCount == N) { //60�t���[���ڂȂ畽�ς��v�Z����
			int t = GetNowCount();
			mFps = 1000.f / ((t - mStartTime) / (float)N);
			mCount = 0;
			mStartTime = t;
		}
		mCount++;
		return true;
	}

	/*********************************
	�֐����Fvoid Draw()
	�����F��ʂ̉E��Ɍ��݂�FPS��\������
	�����F����
	�߂�l�F����
	**********************************/
	void Draw() {
		DrawFormatString(1220, 0, GetColor(255, 255, 255), "%.1f", mFps);
	}

	/*********************************
	�֐����Fvoid Wait()
	�����FFPS��private���� static const int FPS �̐��l�Ɠ����ɂ���
	�����F����
	�߂�l�F����
	**********************************/
	void Wait() {
		int tookTime = GetNowCount() - mStartTime;	//������������
		int waitTime = mCount * 1000 / FPS - tookTime;	//�҂ׂ�����
		if (waitTime > 0) {
			Sleep(waitTime);	//�ҋ@
		}
	}
};

#endif