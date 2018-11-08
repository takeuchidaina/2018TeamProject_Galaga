#include <DxLib.h>
#include "Player.h"
#include "Interface.h"
#include "InGameMgr.h"



//コンストラクタ
cPlayer::cPlayer()
{

	//左側の機体
	OBJPlayer[eLeftMachine].pos.x = 640.0;
	OBJPlayer[eLeftMachine].pos.y = 850.0;
	OBJPlayer[eLeftMachine].cx = OBJPlayer[eLeftMachine].pos.x + (IMAGEMAG / 2);
	OBJPlayer[eLeftMachine].cy = OBJPlayer[eLeftMachine].pos.y + (IMAGEMAG / 2);
	OBJPlayer[eLeftMachine].onActive = true;
	//右側の機体
	OBJPlayer[eRightMachine].pos.x = OBJPlayer[eLeftMachine].pos.x + IMAGEMAG;
	OBJPlayer[eRightMachine].pos.y = 850.0;
	OBJPlayer[eRightMachine].cx = OBJPlayer[eRightMachine].pos.x + (IMAGEMAG / 2);
	OBJPlayer[eRightMachine].cy = OBJPlayer[eRightMachine].pos.y + (IMAGEMAG / 2);
	OBJPlayer[eRightMachine].onActive = false;

	//フラグ
	isLRflg = false;      // 0:移動なし  1:右  -1:左

	//UIの白い線
	UIsize = (1280 / 4 * 3) - 50;
	
	//画像の読み込みと分割
	LoadDivGraph("../resource/Image/Galaga_OBJ_dualFighter.png", 2, 2, 1, 16, 16, image);
	if (image == NULL)
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "画像が読み込めませんでした");
		WaitKey();
	}

}

//デストラクタ
cPlayer::~cPlayer()
{
	//読み込んだ画像の削除
	DeleteGraph(image[eLeftMachine]);
	DeleteGraph(image[eRightMachine]);
}

/*************************************************************************
  関数: void cPlayer::Update()
  説明: 移動処理と壁の当たり判定
  引数: 無し
戻り値: 無し
*************************************************************************/
void cPlayer::Update()
{

	Interface.Update();

	// 右
	if (Interface.Get_Input(InRIGHT) != 0)
	{
		isLRflg = 1;
	}
	// 左
	else if (Interface.Get_Input(InLEFT) != 0)
	{
		isLRflg = -1;
	}
	// 移動なし
	else
	{
		isLRflg = 0;
	}

	//移動の計算
	for (int i = 0; i < MAXMACHINE; i++)
	{
		//アクティブ状態ではないなら次へ
		if (OBJPlayer[i].onActive == false)
		{
			continue;
		}

		//フラグの値が1か-1なので向きが変わりcxの更新
		OBJPlayer[i].pos.x += (SPEED * isLRflg);
		OBJPlayer[i].cx = OBJPlayer[eLeftMachine].pos.x + (IMAGEMAG / 2);

	//壁の設定

		for (int j = 0; j < MAXMACHINE; j++)
		{

			//左壁
			if (OBJPlayer[j].pos.x <= 0)
			{
				//二機ともアクティブ状態なら
				if (OBJPlayer[eLeftMachine].onActive == true && OBJPlayer[eRightMachine].onActive == true)
				{
					OBJPlayer[eLeftMachine].pos.x = 0;
					OBJPlayer[eRightMachine].pos.x = 0 + IMAGEMAG;
				}
				//一機のみアクティブ状態なら
				else
				{
					OBJPlayer[i].pos.x = 0;
				}

			}
			//右壁
			if (OBJPlayer[j].pos.x + IMAGEMAG >= UIsize)
			{
				//二機ともアクティブ状態なら
				if (OBJPlayer[eLeftMachine].onActive == true && OBJPlayer[eRightMachine].onActive == true)
				{
					OBJPlayer[eLeftMachine].pos.x = UIsize - IMAGEMAG * 2;
					OBJPlayer[eRightMachine].pos.x = UIsize - IMAGEMAG;
				}
				//一機のみアクティブ状態なら
				else
				{
					OBJPlayer[i].pos.x = UIsize - IMAGEMAG;
				}

			}

		}
	}


//DEBUG
	/*
	//キー
	if (Interface.Get_Input(InDEBUG1) != 0)
	{
		cPlayer::Double();		// I を押したら二機になる
	}
	else if (Interface.Get_Input(InDEBUG2) != 0)
	{
		cPlayer::Break(eDoubleDeath,eLeftMachine);	// O を押したら一機目が死ぬ
	}
	else if (Interface.Get_Input(InDEBUG3) != 0)
	{
		cPlayer::Break(eDoubleDeath,eRightMachine);	// P を押したら二機目が死ぬ
	}

	//両方撃破されたら
	if (OBJPlayer[eLeftMachine].onActive == false && OBJPlayer[1].onActive == false)
	{
		cPlayer::Break(eDeath, eDoubleMachine);
	}

	//DEBUGに使用する場合はInterface.hのenumにInDEBUG1,2,3と
	//Interface.cppのUpdateにenumを配列の要素数に使用し、IとOとPを対応させてください。

	*/

}

/*************************************************************************
  関数: void cPlayer::Draw()
  説明: 描画処理
  引数: 無し
戻り値: 無し
*************************************************************************/
void cPlayer::Draw()
{

	for (int i = 0; i < MAXMACHINE; i++)
	{

		if (OBJPlayer[i].onActive == false)
		{
			continue;
		}

		//表示
		DrawExtendGraph(OBJPlayer[i].pos.x, OBJPlayer[i].pos.y, OBJPlayer[i].pos.x + IMAGEMAG, OBJPlayer[i].pos.y + IMAGEMAG, image[i], TRUE);

	}

//DEBUG
	//UIの枠組みの白線
	DrawLine(UIsize,0,UIsize,960,GetColor(255,255,255));

	//座標の表示
	DrawFormatString(920, 200, GetColor(255, 0, 0), "一機目x:%4.2lf", OBJPlayer[eLeftMachine].pos.x);
	DrawFormatString(920, 220, GetColor(255, 0, 0), "一機目cx:%4.2lf", OBJPlayer[eLeftMachine].cx);
	DrawFormatString(920, 240, GetColor(255, 0, 0), "一機目onActive:%d", OBJPlayer[eLeftMachine].onActive);
	

	DrawFormatString(920, 260, GetColor(255, 0, 0), "二機目x:%4.2lf", OBJPlayer[eRightMachine].pos.x);
	DrawFormatString(920, 280, GetColor(255, 0, 0), "二機目cx:%4.2lf", OBJPlayer[eRightMachine].cx);
	DrawFormatString(920, 300, GetColor(255, 0, 0), "二機目onActive:%d", OBJPlayer[eRightMachine].onActive);

}

/*************************************************************************
  関数: void cPlayer::Double()
  説明: 呼ばれた場合のみ処理される
		二機目の機体のxとcxが更新されアクティブ状態になる
  引数: 無し
戻り値: 無し
*************************************************************************/
void cPlayer::Double()
{
	//二機目の座標を更新し状態をアクティブへ
	OBJPlayer[eRightMachine].pos.x = OBJPlayer[0].pos.x + IMAGEMAG;
	OBJPlayer[eRightMachine].cx = OBJPlayer[eRightMachine].pos.x + (IMAGEMAG / 2);
	OBJPlayer[eRightMachine].onActive = true;

	//問題点:二回目の二機の時に座標が初期座標になるので配列を増やして三機目の情報を入れないといけないかもしれない。
	//ややこしくなるから他の方法を探す
	//他の関数を作ってプレイヤーの一機目を生成するやつを作ってもいいかも？

}

/*************************************************************************
  関数: void cPlayer::Break()
  説明: 死亡処理 (引数で死亡かトラクタービームかを判断)
  引数: int judgeBreak 　eDoubleDeath : 二機居る状態で片方が撃破された時
					　　 eDeath       : 一機しかない状態でで撃破された時
					　 　eTractorBeam : トラクタービームで攫われた時

		int machineNum　 eLeftMachine   : 左の機体
						 eRightMachine  : 右の機体
						 eDoubleMachine : 両方の機体
			
戻り値: 無し
*************************************************************************/
void cPlayer::Break(int judgeBreak ,int machineNum)
{
	//二機の状態で片方が死んだら
	if (judgeBreak == eDoubleDeath)
	{
		//撃破された方を非アクティブに
		if (machineNum == eLeftMachine)
		{
			OBJPlayer[eLeftMachine].onActive = false;
		}
		else
		{
			OBJPlayer[eRightMachine].onActive = false;
		}

	}
	//一機の状態で死んだら
	else if (judgeBreak == eDeath && machineNum == eDoubleMachine)
	{
		//残機によって、マシーンの生成又は終了処理

		//DEBUG
		DrawFormatString(600, 500, GetColor(255, 0, 0), "GAME OVER");
	}
	//トラクタービームに攫われたら
	else if(judgeBreak == eTractorBeam)
	{
		////////////////////////////////
	}

}

