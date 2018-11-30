#pragma once
#ifndef _UI_INCLUDE_
#define _UI_INCLUDE_

#include "InGameController.h"
#include "Player.h"
#include "TextChange.h"
#include "Singleton.h"

#define DISP_SIZE ((1280 / 4 * 3) - 50)
#define UI_SIZE (1280 - DISP_SIZE)
#define IMAGEMAG 48		//�摜�{��
#define ICONMAG 32      //�A�C�R���̉摜�{��

//DEBUG
#include "Interface.h"
#define UI_COLOR GetColor(0,255,0)

    //  #include "takeuchi_debug_define.h"


//���W�ƕ\�����镶����̍\����
typedef struct
{
	int x, y;
	char text[20];
	eColor color;

}sTextPos;

class cUI : public cSingleton<cUI>
{
	cUI();	//�R���X�g���N�^
	~cUI();	//�f�X�g���N�^
	friend cSingleton< cUI >;

private:

	int iconX;			//�A�C�R���̍��Wx
	int iconY;			//�A�C�R���̍��Wy
	int textImg[48];	//�e�L�X�g�̉摜
	int iconImg[12];	//�X�e�[�W�A�C�R���̉摜
	int stageNo;		//�X�e�[�W�ԍ�
	int playerHP;		//�c�@
	int blinkCnt;	    //�_�ŏ����̃J�E���g("1UP")
	int blinkFlg;	    //�_�ŏ����̃t���O("1UP")

	//���W�ƕ\�����镶����̍\���̂̏�����
	const sTextPos textPos[4] =
	{
		{ DISP_SIZE + 150, 10,"HIGH",eRed },
		{ DISP_SIZE + 102, 58,"SCORE",eRed },
		{ DISP_SIZE + 198, 152,"1UP",eRed },
		{ DISP_SIZE + 198, 152,"   ",eNone },   //blink
	};

protected:

public:
	/*************************************************************************
	   �֐�: int UI_Draw()
	   ����: �g�g�݁E�c�@�E�X�e�[�W�A�C�R���̕\���ƕ����f�[�^�̑��M
	   ����: ����
	 �߂�l: ����
	 *************************************************************************/
	int UI_Draw();

	/*************************************************************************
	�@�֐�: int UI_SelectIcon()
	�@����: �X�e�[�W���̃A�C�R�����ǂ��\�����邩
	�@����: int �X�e�[�W�ԍ�
	�߂�l: ����
	*************************************************************************/
	int UI_StgSelectIcon(int);

	/*************************************************************************
	�@�֐�: void UI_SetPlayerHP()
	�@����: �v���C���[�̎c�@�̍X�V
	�@����: int �v���C���[��HP
	�߂�l: ����
	*************************************************************************/
	void UI_SetPlayerHP(int);

};

#endif
