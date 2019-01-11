#pragma once

#ifndef _PLAYER_INCLUDE_
#define _PLAYER_INCLUDE_

#include "Struct.h"
#include "UI.h"
#include "Singleton.h"

#define SPEED 6			//プレイヤーのスピード
#define MAXMACHINE 2	//プレイヤーは二機まで(三機にならない)
#define NULL 0			//エラー時に使用

#define WALL 100		//行動制限

//DEBUG
#define P_COLOR GetColor(255,0,0)

      //    #include "takeuchi_debug_define.h"


class cPlayer : public cSingleton<cPlayer>
{
	cPlayer();	//コンストラクタ
	~cPlayer();	//デストラクタ
	friend cSingleton< cPlayer >;

private:

	int image[2];	  //画像
	
protected:

public:

	sOBJPos player[2];  //配列なのは一機か二機かで変わる為
	int isDoubleFlg;
	int playerHP;       //HP(場に出ている機体を含まない)

	void Update();
	void Draw();
	void Init();

	/*************************************************************************
	  関数: void cPlayer::Move()
	  説明: 移動処理と壁の当たり判定
	  引数: 無し
	戻り値: 無し
	*************************************************************************/
	void Move();

	/*************************************************************************
	　関数: void cPlayer::Double()
	　説明: 呼ばれた場合のみ処理される
	　　　　二機目の機体のxとcxが更新されアクティブ状態になる
	　引数: 無し
	戻り値: 無し
	*************************************************************************/
	void Double();

	/*************************************************************************
	  関数: void cPlayer::Break()
	  説明: 死亡処理 (引数で死亡かトラクタービームかを判断)
	  引数: int 破壊orトラクタービー , int 機体番号

	  破壊orトラクタービーム
			eDeath       : 一機しかない状態でで撃破された時
	　 　 　eTractorBeam : トラクタービームで攫われた時
	  機体番号
	   　　 eLeftMachine   : 左の機体
	   　　 eRightMachine  : 右の機体
	   　　 eNoneMachine   : 機体無し(プログラムの見た目上)

	戻り値: 無し
	*************************************************************************/
	void Break(int,int);

	/*************************************************************************
	　関数: int cPlayer::GetPlayerHP()
	　説明: プレイヤーのHP(場を含める残機)を受け渡す
	　引数: 無し
	戻り値: playerHP
	*************************************************************************/
	int GetPlayerHP();

	/*************************************************************************
	　関数: sOBJPos GetPlayer(int num)
	  説明: プレイヤーの構造体の受け渡し
	  引数: 機体番号
	戻り値: 機体番号の構造体か、対応していない機体番号ならNULLを返す
	*************************************************************************/
	sOBJPos GetPlayer(int num) 	//構造体の受け渡し　　num 0:左  1:右
	{
		sOBJPos *p = NULL;
		return ((num == 0 || num == 1) ? player[num]:*p);
	}

	/*************************************************************************
	　関数: int GetDoubleFlg()
	  説明: 二機かどうかの情報の受け渡し
	  引数: 無し
	戻り値: 二機かどうかのフラグを返す(0:一機 1:二機
	*************************************************************************/
	int GetDoubleFlg()
	{
		return isDoubleFlg;
	}

	/*************************************************************************
	　関数: void PlayerRevive();
	  説明: プレイヤーの復活
	  引数: 無し
	戻り値: 無し
	*************************************************************************/
	void PlayerRevive();

	/*************************************************************************
	　関数: void PlayerTractorMove();
	 説明: プレイヤーの位置を中央へ移動させる
	 引数: 無し
	 戻り値: 無し
	 *************************************************************************/
	void PlayerTractorMove();

};

// 死亡かトラクタービームか判断
typedef enum
{
	eDeath,				//撃破
	eTractorBeam,		//トラクタービーム

}ePlayerBreak;

// 左の機体か右の機体か、また両方を指定しているのか
typedef enum
{
	eLeftMachine,		//左の機体
	eRightMachine,		//右の機体
	eNoneMachine,		//機体無し

}eMachineNum;

#endif