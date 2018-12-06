#include <DxLib.h>
#include "SE.h"
#include "WinBox.h"

//コンストラクタ
cSE::cSE()
{
	//配列へ読み込み
	//int LoadSoundMem(char *FileName);
	//se[0] = LoadSoundMem("gal_se_fighter_shot.wav");
	//読み込み順ばらばらなので整理が必要 名前順
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



	if (se[0] == -1)ErrBox("SE読み込めませんでした");
}

//デストラクタ
cSE::~cSE()
{
	//配列データの削除
	for (int i = 0; i < SENUM; i++)
	{
		DeleteSoundMem(se[i]);
	}
}

//再生・引数にenum
void cSE::selectSE(int select)
{
	//再生
	//配列の要素数をselectに
	//enumで指定に変更する
	PlaySoundMem(se[select], DX_PLAYTYPE_BACK);

}


/*

宣言	int PlaySoundMem( int SoundHandle , int PlayType , int TopPositionFlag ) ;

概略	メモリに読みこんだ音データを再生する

引数	
SoundHanle　： 再生する音の識別番号（サウンドハンドル）
PlayType　　： 再生形式
DX_PLAYTYPE_NORMAL　:　ノーマル再生
DX_PLAYTYPE_BACK　　:　バックグラウンド再生
DX_PLAYTYPE_LOOP　　:　ループ再生
TopPositionFlag ： 再生位置を音データの先頭に移動するかどうか( TRUE：移動する（デフォルト）　FALSE：移動しない )

戻り値	　０：成功
－１：エラー発生

解説	　LoadSoundMem関数 でメモリに読みこんだ音を読み込み時に取得した サウンドハンドルで再生します。
PlaySoundFile関数との違いは、再生にサウンドハンドルを使用するということと、第三の引数
TopPositionFlag があることです。

TopPositionFlag は音データを再生する前に再生開始位置を先頭に戻すかどうかを指定します。
TRUE を渡すと先頭から再生され、FALSE を渡すと最後に StopSoundMem をした位置か、
SetSoundCurrentTime で指定した位置から再生されます。
尚、TopPositionFlag は省略可能で、省略した場合は TRUE を指定したことになります。

再生にサウンドハンドルを使用する、TopPositionFlag がある、ということ以外はPlaySoundFile関数 と違いはありません。
(再生形式の詳しい説明は『PlaySoundFile』を 参照してください。)



*/