#include <DxLib.h>
#include "TextChange.h"

//�R���X�g���N�^
cTextChange::cTextChange()
{
	//�e�L�X�g�̉摜�̓ǂݍ���
	LoadDivGraph("../resource/Image/UI_Text.png", 48, 8, 6, 28, 28, textImg);
}

/*************************************************************************
�@�֐�: int cTextChange::_Update()
  ����: �����񂩂�摜�̗v�f���ւ̕ϊ�
  ����: 
�߂�l: 
*************************************************************************/
int cTextChange::Update()
{


	return 0;
}

/*************************************************************************
�@�֐�: int cTextChange::_Update()
 ����: �f�o�b�O�p�H�������͕\�������邩��(?)
 ����: 
 �߂�l: ����
 *************************************************************************/
void cTextChange::Draw()
{

	//DEBUG
	DrawGraph(100, 100, textImg[5], TRUE);
}