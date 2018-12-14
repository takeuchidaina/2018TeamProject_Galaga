#pragma once
#ifndef _TITLE_INCLUDE_
#define _TITLE_INCLUDE_

#include "Singleton.h"
#include "TextChange.h"
#include "UI.h"

//���W�ƕ\�����镶����̍\����(TextChange�Ɏg�p)
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

	//������
	const sTitleTextPos TTextPos[5] =
	{
		{ 160,450,"PUSH SPACE BUTTON",eLBlue,eMag48 },
		{ 100,550,"1ST BONUS FOR 20000 PTS",eYellow,eMag48 },
		{ 100,650,"2ND BONUS FOR 70000 PTS",eYellow,eMag48 },
		{ 100,750,"AND FOR EVERY 70000 PTS",eYellow,eMag48 },
		{ 100,850,"@ 1981 1995 NAMCO LTD",eWhite,eMag48},

	};

	int TitleHandle[2];   //�v���C���[�̋@��
	int TitleIcon;		  //�^�C�g�����S

public:

	int Draw();

};
#endif
