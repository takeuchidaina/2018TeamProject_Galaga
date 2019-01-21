#include <DxLib.h>
#include <stdio.h>
#include "SaveLoad.h"

cSaveLoad::cSaveLoad(){
	newScore = 0;
	integerHighScore = 0;
	characterHighScore[256] = { 0 };
}

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
		//値が大きかったらセーブする
		fp = fopen("../resource/SaveLoad/HighScore", "w");
		if (fp == NULL)
		{
			ErrBox("ファイルが開けませんでした(Save)");
		}

		fprintf(fp,"%d",integerHighScore);

		fclose(fp);
	}

}

//ロード
//最初に読みこむ
void cSaveLoad::Load() 
{

	fp = fopen("../resource/SaveLoad/HighScore","r");
	if (fp == NULL)
	{
		ErrBox("ファイルが開けませんでした(Load)");
	}

	//ハイスコアの読み出し
	fgets(characterHighScore,256,fp);
	if (characterHighScore == NULL)
	{
		ErrBox("ファイルから値を読み込みませんでした");
	}

	fclose(fp);

}

//描画
void cSaveLoad::Draw() 
{
	//ハイスコアの表示
	cTextChange::Instance()->DrawTextImage(1000, 80, characterHighScore, eWhite, eMag48);
}