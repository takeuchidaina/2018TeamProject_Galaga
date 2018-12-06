#include <DxLib.h>
#include "SE.h"
#include "WinBox.h"

//�R���X�g���N�^
cSE::cSE()
{
	//�z��֓ǂݍ���
	//int LoadSoundMem(char *FileName);
	//se[0] = LoadSoundMem("gal_se_fighter_shot.wav");
	//�ǂݍ��ݏ��΂�΂�Ȃ̂Ő������K�v ���O��
	//se[0] = LoadSoundMem("../resource/Sound/gal_se_fighter_shot.wav");
	//se[1] = LoadSoundMem("../resource/Sound/gal_music_gamestart.wav");

	se[0] = LoadSoundMem("../resource/Sound/gal_music_capture.wav");
	se[1] = LoadSoundMem("../resource/Sound/gal_music_challenging_stage_clear.wav");
	se[2] = LoadSoundMem("../resource/Sound/gal_music_challenging_stage_perfect");
	se[3] = LoadSoundMem("../resource/Sound/gal_music_challenging_stage_start.wav");
	se[4] = LoadSoundMem("../resource/Sound/gal_music_gamestart.wav");
	se[5] = LoadSoundMem("../resource/Sound/gal_music_mistake_12.wav");
	se[6] = LoadSoundMem("../resource/Sound/gal_music_nameentry_1st.wav");
	se[7] = LoadSoundMem("../resource/Sound/gal_music_nameentry_2nd-5th.wav");
	se[8] = LoadSoundMem("../resource/Sound/gal_music_rescue.wav");
	se[9] = LoadSoundMem("../resource/Sound/gal_se_alien_flying.wav");
	se[10] = LoadSoundMem("../resource/Sound/gal_se_boss_striken_1.wav");
	se[11] = LoadSoundMem("../resource/Sound/gal_se_boss_striken_2.wav");
	se[12] = LoadSoundMem("../resource/Sound/gal_se_credit.wav");
	se[13] = LoadSoundMem("../resource/Sound/gal_se_extend_sound.wav");
	se[14] = LoadSoundMem("../resource/Sound/gal_se_fighter_shot.wav");
	se[15] = LoadSoundMem("../resource/Sound/gal_se_goei_striken.wav");
	se[16] = LoadSoundMem("../resource/Sound/gal_se_ingame_ambience.wav");
	se[17] = LoadSoundMem("../resource/Sound/gal_se_miss.wav");
	se[18] = LoadSoundMem("../resource/Sound/gal_se_stage_flag.wav");
	se[19] = LoadSoundMem("../resource/Sound/gal_se_tractor_beam.wav");
	se[20] = LoadSoundMem("../resource/Sound/gal_se_tractor_beam_capture.wav");
	se[21] = LoadSoundMem("../resource/Sound/gal_se_triple_formation.wav");
	se[22] = LoadSoundMem("../resource/Sound/gal_se_zako_striken.wav");



	if (se[0] == -1)ErrBox("SE�ǂݍ��߂܂���ł���");
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
	//enum�Ŏw��ɕύX����
	PlaySoundMem(se[select], DX_PLAYTYPE_BACK);

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