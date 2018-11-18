#include <DxLib.h>
#include "TextChange.h"
#include "UI.h"

//�R���X�g���N�^
cTextChange::cTextChange()
{
	//�e�L�X�g�̉摜�̓ǂݍ���
	LoadDivGraph("../resource/Image/UI_Text.png", 48, 8, 6, 28, 28, textImg);

	imgEle[40] = { 0 };
	cnt = 0;
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
	char text[] = "HIGHSCORE";
	cnt = 0;

	//�摜�̎Z�o����
	for (int i= 0;i<strlen(text);i++)
	{
		int tmp = text[i];

			//������0�`9�Ȃ�
			if (text[i] >= '0' && text[i] <= '9')
			{
				//DrawGraph(100, 100, textImg[tmp - '0'], TRUE);
				imgEle[cnt] = (tmp - '0');
				cnt++;
			}
			//������A�`Z�Ȃ�
			else if (text[i] >= 'A' && text[i] <= 'Z')
			{
				//DrawGraph(120, 100, textImg[tmp - 'A'+10], TRUE);
				imgEle[cnt] = (tmp - 'A'+10);
				cnt++;
				// +10����̂�0�`9�̔ԍ����܂߂Ȃ��悤�ɂ��邽��
			}
			//�������L���Ȃ�
			else
			{
				//�L��
				//switch case
			}

	}
	//cnt = 1;
	return 0;
}

/*************************************************************************
 �֐�: void cTextChange::_Update()
 ����: �f�o�b�O�p�H�������͕\�������邩��(?)
 ����: 
 �߂�l: ����
 *************************************************************************/
void cTextChange::Draw()
{

	//DEBUG	
	for (int i = 0;i<cnt; i++)
	{
		DrawGraph(DISP_SIZE + 50 +(i*30), 100, textImg[imgEle[i]], TRUE);
		
	}
	DrawFormatString(150, 150, GetColor(0, 255, 122), "cnt:%d", cnt);
	//DrawGraph(100 , 100, textImg[imgEle[0]], TRUE);
	//DrawGraph(120 , 100, textImg[imgEle[1]], TRUE);
}

/*_DEBUG.memo
	�J�E���g��2�Ȃ̂�for����2�񂵂�����Ă��Ȃ��͂��Ȃ̂�
	���ɐL�тĂ���

	i��k�ɂ��Ă��_��
	i��for���̒��Œ�`���Ȃ��Ă��֌W�Ȃ�

	for������Ȃ��Ȃ�񕶎������o�͉\

*/