#include <DxLib.h>
#include <stdio.h>
#include "SaveLoad.h"

cSaveLoad::cSaveLoad(){
	newScore = 0;
	integerHighScore = 0;
	characterHighScore[256] = { 0 };
}

cSaveLoad::~cSaveLoad(){

}

//�Z�[�u
//�Ō�ɓǂ݂���
void cSaveLoad::Save() 
{
	//�ŏI�I�ȃX�R�A�̎擾
	newScore = cScore::Instance()->GetScore();

	//�����񂩂琮���֕ϊ�
	integerHighScore = atoi(characterHighScore);

	//�X�R�A�̑召���r
	if (newScore > integerHighScore)
	{
		//�l���傫��������Z�[�u����
		fp = fopen("../resource/SaveLoad/HighScore", "w");
		if (fp == NULL)
		{
			ErrBox("�t�@�C�����J���܂���ł���(Save)");
		}

		fprintf(fp,"%d",integerHighScore);

		fclose(fp);
	}

}

//���[�h
//�ŏ��ɓǂ݂���
void cSaveLoad::Load() 
{

	fp = fopen("../resource/SaveLoad/HighScore","r");
	if (fp == NULL)
	{
		ErrBox("�t�@�C�����J���܂���ł���(Load)");
	}

	//�n�C�X�R�A�̓ǂݏo��
	fgets(characterHighScore,256,fp);
	if (characterHighScore == NULL)
	{
		ErrBox("�t�@�C������l��ǂݍ��݂܂���ł���");
	}

	fclose(fp);

}

//�`��
void cSaveLoad::Draw() 
{
	//�n�C�X�R�A�̕\��
	cTextChange::Instance()->DrawTextImage(1000, 80, characterHighScore, eWhite, eMag48);
}