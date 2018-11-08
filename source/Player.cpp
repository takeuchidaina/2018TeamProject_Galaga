#include <DxLib.h>
#include "Player.h"
#include "Interface.h"
#include "InGameMgr.h"



//�R���X�g���N�^
cPlayer::cPlayer()
{

	//�����̋@��
	OBJPlayer[0].pos.x = 640.0;
	OBJPlayer[0].pos.y = 850.0;
	OBJPlayer[0].cx = OBJPlayer[0].pos.x + (IMAGEMAG / 2);
	OBJPlayer[0].cy = OBJPlayer[0].pos.y + (IMAGEMAG / 2);
	OBJPlayer[0].onActive = true;
	//�E���̋@��
	OBJPlayer[1].pos.x = OBJPlayer[0].pos.x + IMAGEMAG;
	OBJPlayer[1].pos.y = 850.0;
	OBJPlayer[1].cx = OBJPlayer[1].pos.x + (IMAGEMAG / 2);
	OBJPlayer[1].cy = OBJPlayer[1].pos.y + (IMAGEMAG / 2);
	OBJPlayer[1].onActive = false;

	//�t���O
	isLRflg = false;      // 0:�ړ��Ȃ�  1:�E  -1:��
	//isDoubleFlg = false;  // 0:��@  1:��@
	
	//�摜�̓ǂݍ��݂ƕ���
	LoadDivGraph("../resource/Image/Galaga_OBJ_dualFighter.png", 2, 2, 1, 16, 16, image);
	if (image == NULL)
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "�摜���ǂݍ��߂܂���ł���");
		WaitKey();
	}

}

//�f�X�g���N�^
cPlayer::~cPlayer()
{
	//�ǂݍ��񂾉摜�̍폜
	DeleteGraph(image[0]);
	DeleteGraph(image[1]);
}

/*************************************************************************
  �֐�: int cPlayer::Update()
  ����: �ړ�����
  ����: ����
�߂�l: ����
*************************************************************************/
int cPlayer::Update()
{

	Interface.Update();

	// �E
	if (Interface.Get_Input(InRIGHT) != 0)
	{
		isLRflg = 1;
	}
	// ��
	else if (Interface.Get_Input(InLEFT) != 0)
	{
		isLRflg = -1;
	}
	// �ړ��Ȃ�
	else
	{
		isLRflg = 0;
	}


	//DEBUG
	if (Interface.Get_Input(InDEBUG1) != 0)
	{
		cPlayer::Double();		// I �����������@�ɂȂ�
	}

	if (Interface.Get_Input(InDEBUG2) != 0)
	{
		cPlayer::Break(eDoubleDeath);	// O �����������@�ڂ�����
	}

	//��@�ڂ��A�N�e�B�u�Ȃ���W�X�V
	if(OBJPlayer[1].onActive == true)
	{
		OBJPlayer[1].pos.x = OBJPlayer[0].pos.x + IMAGEMAG;
		OBJPlayer[1].cx = OBJPlayer[1].pos.x + (IMAGEMAG / 2);
		OBJPlayer[1].cy = OBJPlayer[1].pos.y + (IMAGEMAG / 2);
	}
	
	//�ړ��̌v�Z
	for (int i = 0; i < MAXMACHINE; i++)
	{
		//�A�N�e�B�u��Ԃł͂Ȃ��Ȃ玟��
		if (OBJPlayer[i].onActive == false)
		{
			continue;
		}

		//�t���O�̒l��1��-1�Ȃ̂Ō������ς��
		OBJPlayer[i].pos.x += (SPEED * isLRflg);
	}
	

	return 0;
}

/*************************************************************************
  �֐�: int cPlayer::Draw()
  ����: �`�揈��
  ����: ����
�߂�l: ����
*************************************************************************/
int cPlayer::Draw()
{

	for (int i = 0; i < MAXMACHINE; i++)
	{

		if (OBJPlayer[i].onActive == false)
		{
			continue;
		}

		//�\��
		DrawExtendGraph(OBJPlayer[i].pos.x, OBJPlayer[i].pos.y, OBJPlayer[i].pos.x + IMAGEMAG, OBJPlayer[i].pos.y + IMAGEMAG, image[i], TRUE);

	}

	//UI�̘g�g�݂̔���
	int size ;
	size = (1280 / 4 * 3)-50;
	DrawLine(size,0,size,960,GetColor(255,255,255));

#ifndef _DEBUG

	DrawFormatString(200, 440, GetColor(255, 0, 0), "x:%4.2lf", player[0].x);
	DrawFormatString(200, 460, GetColor(255, 0, 0), "y:%4.2lf", player[0].y);

#endif 



	return 0;
}

/*************************************************************************
  �֐�: int cPlayer::Double()
  ����: ��@�̏���
  ����: ����
�߂�l: ����
*************************************************************************/
int cPlayer::Double()
{
	//�摜�̕\������@�ɂȂ�
	//isDoubleFlg = true;
	OBJPlayer[1].onActive = true;

	//cx,cy���̍X�V


	return 0;
}

/*************************************************************************
  �֐�: int cPlayer::Break()
  ����: ���S���� (�����Ŏ��S���g���N�^�[�r�[�����𔻒f)
  ����: int
�߂�l: ����
*************************************************************************/
int cPlayer::Break(int judgeBreak)
{
	if (judgeBreak == eDoubleDeath)
	{
		//�摜�̕\���̕ω�
		//�ǂ��������񂾂��̔��f��onActive
	}
	else if (judgeBreak == eDeath)
	{
		//���S����
		//onActive�̏���
	}
	else if(judgeBreak == eTractorBeam)
	{
		//�g���N�^�[�r�[���ɝ����鏈��
	}

	return 0;
}

