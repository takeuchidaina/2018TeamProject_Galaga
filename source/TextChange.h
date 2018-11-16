#pragma once

#ifndef _TEXTCONVERSION_INCLUDE_
#define _TEXTCONVERSION_INCLUDE_

#include "Singleton.h"

class cTextChange : public cSingleton<cTextChange>
{
private:

	int textImg[48];

	cTextChange();  //private�Ȃ̂�new���g���Ȃ�
	friend cSingleton< cTextChange >;

public:

	int Update();
	void Draw();
};
#endif


/* _MEMO

�R���X�g���N�^��private�Ɏw�肵�āA�V���O���g���N���X�ȊO����
�R���X�g���N�^�̌ďo���inew���g���Ȃ��Ȃ�j���ł��Ȃ��悤�ɂ��܂��B
�����āA�i�O�����new���g���Ȃ����߁j�擾���郁�\�b�h��p�ӂ��Ă�����K�v������܂��B 
���̃��\�b�h�́A�ǂ�����ł��Q�Ƃł���悤��public static�錾������K�v������܂��B


*/
