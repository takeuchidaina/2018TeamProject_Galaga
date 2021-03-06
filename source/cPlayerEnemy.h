#pragma once
#ifndef PLAYERENEMY_INCLUDE
#define PLAYERENEMY_INCLUDE

#include "cBaseEnemy.h"

class cPlayerEnemy : public cBaseEnemy {
private:

	sEnemy* tmpEnemy;//自分を今連れているグリーンのアドレスを入れる者
	
	 int graph[4];

	sOBJPos tmpPlayer;

	double rotecnt;//グルグル回るときに使うカウント
	
	int playerGraphNum;//機体の色を変更するときに使う
	
	int reMoveFlg;//リヴァイブ用の移動フラグ
public:
	cPlayerEnemy(/*double, double, double, int, double, double, int, int*/);
	virtual void Move();
	virtual int Update();
	int ReviveUpdate();
	//トラクターされた際の最初の移動をする関数
	 //トラクターされいてる間の移動
	virtual int Draw();
	/*************************************************************************
	  関数: void cEnemyPlayer::SetPenemy()
	  説明: Update関数の中のポインタ変数にtractorを撃った敵のアドレスを代入する
	  引数: sEnemy型ポインタ
	戻り値: 無し
	*************************************************************************/
	void SetPenemy(sEnemy* tmp) {
		tmpEnemy = tmp;
	}
	/*************************************************************************
	  関数: void cEnemyPlayer::GetRemoveFlg()
	  説明: reMoveFlgを取得する
	  引数: int型　reMoveFlg
	戻り値: 無し
	*************************************************************************/
	int GetRemoveFlg() {
		return reMoveFlg;
	}
	/*************************************************************************
	  関数: void cEnemyPlayer::Rolling()
	  説明: 戻る際に回転させるもの
	  引数: 無し
	戻り値: 無し
	*************************************************************************/
	void Rolling() {
		rotecnt += 0.3;
	}
};

#endif // !PLAYERENEMY_INCLUDE
