#include <DxLib.h>
#include "SaveLoad.h"

//�R���X�g���N�^
cSaveLoad::cSaveLoad(){
	highScoreFileHandole = 0;
	newScore = 0;
	integerHighScore = 0;
}

//�f�X�g���N�^
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
		//�傫���Ȃ�X�R�A���Z�[�u����
	}
	else 
	{
		//�Z�[�u���Ȃ�
	}
}

//���[�h
//�ŏ��ɓǂ݂���
void cSaveLoad::Load() 
{
	//�t�@�C���̓ǂݍ���
	highScoreFileHandole = FileRead_open("../resource/SaveLoad/HighScore");

	//��s�ǂ�
	FileRead_gets(characterHighScore,256, highScoreFileHandole);

	//�t�@�C�������
	FileRead_close(highScoreFileHandole);
}

//�`��
void cSaveLoad::Draw() 
{
	//�n�C�X�R�A�̕\��
	cTextChange::Instance()->DrawTextImage(1000, 80, characterHighScore, eWhite, eMag48);
}