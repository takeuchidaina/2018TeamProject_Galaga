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
	//�^�C�g�����S
	DrawExtendGraph(125, 50, 125 + 666, 50 + 376, TitleIcon, TRUE);

	for (int i = 0; i < 5;i++) 
	{
		//���ɂ���v���C���[�̉摜 
		if (i > 0 && i < 4) {
			DrawExtendGraph(TTextPos[i].x - 50, TTextPos[i].y, TTextPos[i].x - 50 + IMAGEMAG, TTextPos[i].y + IMAGEMAG, TitleHandle[0], TRUE);
		}
		//����
		cTextChange::Instance()->DrawTextImage(TTextPos[i].x, TTextPos[i].y, TTextPos[i].text,
			TTextPos[i].color, TTextPos[i].mag);
	}


	
	return 0;
}