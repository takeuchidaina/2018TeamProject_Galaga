#include <DxLib.h>
#include "SaveLoad.h"

//コンストラクタ
cSaveLoad::cSaveLoad(){
	highScoreFileHandole = 0;
	newScore = 0;
	integerHighScore = 0;
}

//デストラクタ
cSaveLoad::~cSaveLoad(){

}

//セーブ
//最後に読みこむ
void cSaveLoad::Save() 
{
	//最終的なスコアの取得
	newScore = cScore::Instance()->GetScore();

	//文字列から整数へ変換
	integerHighScore = atoi(characterHighScore);

	//スコアの大小を比較
	if (newScore > integerHighScore) 
	{
		//大きいならスコアをセーブする
	}
	else 
	{
		//セーブしない
	}
}

//ロード
//最初に読みこむ
void cSaveLoad::Load() 
{
	//ファイルの読み込み
	highScoreFileHandole = FileRead_open("../resource/SaveLoad/HighScore");

	//一行読む
	FileRead_gets(characterHighScore,256, highScoreFileHandole);

	//ファイルを閉じる
	FileRead_close(highScoreFileHandole);
}

//描画
void cSaveLoad::Draw() 
{
	//ハイスコアの表示
	cTextChange::Instance()->DrawTextImage(1000, 80, characterHighScore, eWhite, eMag48);
}