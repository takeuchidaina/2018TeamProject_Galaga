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

	//DEBUG
	char text[256] = "1H";

	//�摜�̎Z�o����
	for (int i= 0;i<strlen(text);i++)
	{
		int tmp = text[i];

		//������̒��g��0�`9�Ȃ�
		if (text[i] >= '0' && text[i] <= '9')
		{
			DrawGraph(100, 100, textImg[tmp - '0'], TRUE);
		}
		else if (text[i] >= 'A' && text[i] <= 'Z')
		{
			DrawGraph(120, 100, textImg[tmp - 'A'+10], TRUE);
			// +10����̂�0�`9�̔ԍ����܂߂Ȃ��悤�ɂ��邽��
		}
		else
		{
			//�L��
			//switch case
		}
	}

	return 0;
}

/*************************************************************************
 �֐�: int cTextChange::_Update()
 ����: �f�o�b�O�p�H�������͕\�������邩��(?)
 ����: 
 �߂�l: ����
 *************************************************************************/
void cTextChange::Draw()
{

	//DEBUG
	//DrawGraph(100, 100, textImg[5], TRUE);
}