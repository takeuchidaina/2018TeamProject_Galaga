#include <DxLib.h>
#include "SE.h"

//コンストラクタ
cSE::cSE()
{
	//配列へ読み込み
	//int LoadSoundMem(char *FileName);
	se[0] = LoadSoundMem("gal_se_fighter_shot.wav");
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