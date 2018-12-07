#include <DxLib.h>
#include "Title.h"

//�R���X�g���N�^
cTitle::cTitle()
{
	//�摜�̓ǂݍ��݂ƕ���
	LoadDivGraph("../resource/Image/Galaga_OBJ_dualFighter.png", 2, 2, 1, 16, 16, TitleHandle);
	if (TitleHandle == NULL)   //error
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "�摜���ǂݍ��߂܂���ł���");
		WaitKey();
	}
	TitleIcon = LoadGraph("../resource/Image/Galaga_Title_ult.png");
}

//�f�X�g���N�^
cTitle::~cTitle()
{
	//�ǂݍ��񂾉摜�̍폜
	DeleteGraph(TitleHandle[0]);
	DeleteGraph(TitleHandle[1]);
	DeleteGraph(TitleIcon);
}

int cTitle::Draw()
{
	
	for (int i = 0; i < 4;i++) 
	{
		//���ɂ���v���C���[�̉摜
		if (i != 0) {
			DrawExtendGraph(TTextPos[i].x - 50, TTextPos[i].y, TTextPos[i].x - 50 + IMAGEMAG, TTextPos[i].y + IMAGEMAG, TitleHandle[0], TRUE);
		}
		//����
		cTextChange::Instance()->DrawTextImage(TTextPos[i].x, TTextPos[i].y, TTextPos[i].text,
			TTextPos[i].color, TTextPos[i].mag);
	}

	//DrawGraph(-30, -70, TitleIcon,TRUE);
	DrawExtendGraph(125,50,125+666,50+376,TitleIcon,TRUE);
	
	/*
	cTextChange::Instance()->DrawTextImage(TTextPos[0].x, TTextPos[0].y, TTextPos[0].text,
		TTextPos[0].color, TTextPos[0].mag);
	cTextChange::Instance()->DrawTextImage(TTextPos[1].x, TTextPos[1].y, TTextPos[1].text,
		TTextPos[1].color, TTextPos[1].mag);
	cTextChange::Instance()->DrawTextImage(TTextPos[2].x, TTextPos[2].y, TTextPos[2].text,
		TTextPos[2].color, TTextPos[2].mag);
	cTextChange::Instance()->DrawTextImage(TTextPos[3].x, TTextPos[3].y, TTextPos[3].text,
		TTextPos[3].color, TTextPos[3].mag);
	cTextChange::Instance()->DrawTextImage(TTextPos[4].x, TTextPos[4].y, TTextPos[4].text,
		TTextPos[4].color, TTextPos[4].mag);
		*/
	//cTextChange::Instance()->DrawTextImage(TTextPos[5].x, TTextPos[5].y, TTextPos[5].text,
		//TTextPos[5].color, TTextPos[5].mag);
	
	return 0;
}