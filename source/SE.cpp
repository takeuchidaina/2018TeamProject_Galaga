#include <DxLib.h>
#include "SE.h"

//�R���X�g���N�^
cSE::cSE()
{
	//�z��֓ǂݍ���
	//int LoadSoundMem(char *FileName);
	se[0] = LoadSoundMem("gal_se_fighter_shot.wav");
}

//�f�X�g���N�^
cSE::~cSE()
{
	//�z��f�[�^�̍폜
	for (int i = 0; i < SENUM; i++)
	{
		DeleteSoundMem(se[i]);
	}
}

//�Đ��E������enum
void cSE::selectSE(int select)
{
	//�Đ�
	//�z��̗v�f����select��


}


/*

�錾	int PlaySoundMem( int SoundHandle , int PlayType , int TopPositionFlag ) ;

�T��	�������ɓǂ݂��񂾉��f�[�^���Đ�����

����	
SoundHanle�@�F �Đ����鉹�̎��ʔԍ��i�T�E���h�n���h���j
PlayType�@�@�F �Đ��`��
DX_PLAYTYPE_NORMAL�@:�@�m�[�}���Đ�
DX_PLAYTYPE_BACK�@�@:�@�o�b�N�O���E���h�Đ�
DX_PLAYTYPE_LOOP�@�@:�@���[�v�Đ�
TopPositionFlag �F �Đ��ʒu�����f�[�^�̐擪�Ɉړ����邩�ǂ���( TRUE�F�ړ�����i�f�t�H���g�j�@FALSE�F�ړ����Ȃ� )

�߂�l	�@�O�F����
�|�P�F�G���[����

���	�@LoadSoundMem�֐� �Ń������ɓǂ݂��񂾉���ǂݍ��ݎ��Ɏ擾���� �T�E���h�n���h���ōĐ����܂��B
PlaySoundFile�֐��Ƃ̈Ⴂ�́A�Đ��ɃT�E���h�n���h�����g�p����Ƃ������ƂƁA��O�̈���
TopPositionFlag �����邱�Ƃł��B

TopPositionFlag �͉��f�[�^���Đ�����O�ɍĐ��J�n�ʒu��擪�ɖ߂����ǂ������w�肵�܂��B
TRUE ��n���Ɛ擪����Đ�����AFALSE ��n���ƍŌ�� StopSoundMem �������ʒu���A
SetSoundCurrentTime �Ŏw�肵���ʒu����Đ�����܂��B
���ATopPositionFlag �͏ȗ��\�ŁA�ȗ������ꍇ�� TRUE ���w�肵�����ƂɂȂ�܂��B

�Đ��ɃT�E���h�n���h�����g�p����ATopPositionFlag ������A�Ƃ������ƈȊO��PlaySoundFile�֐� �ƈႢ�͂���܂���B
(�Đ��`���̏ڂ��������́wPlaySoundFile�x�� �Q�Ƃ��Ă��������B)



*/