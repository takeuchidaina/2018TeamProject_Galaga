#pragma once
#ifndef _TITLE_INCLUDE_
#define _TITLE_INCLUDE_

#include "Singleton.h"
#include "TextChange.h"

//���W�ƕ\�����镶����̍\����
typedef struct
{
	int x, y;
	char text[30];
	eColor color;
	eMagnification mag;

}sTitleTextPos;

class cTitle : public cSingleton<cTitle>
{
	cTitle();	//�R���X�g���N�^
	~cTitle();	//�f�X�g���N�^
	friend cSingleton< cTitle >;

private:

	const sTitleTextPos TTextPos[5] =
	{
		{ 200,400,"PUSH SPACE BUTTON",eLBlue,eMag48 },
		{ 100,500,"1ST BONUS FOR 20000 PTS",eYellow,eMag48 },
		{ 100,600,"2ND BONUS FOR 70000 PTS",eYellow,eMag48 },
		{ 100,700,"AND FOR EVERY 70000 PTS",eYellow,eMag48 },
		//{ 150,600,"C 1981 1995 NAMCO LTD",eWhite,eMag48},

	};
	int TitleHandle[2];

public:

	int Draw();

};
#endif
