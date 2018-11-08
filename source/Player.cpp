#include <DxLib.h>
#include "Player.h"
#include "Interface.h"
#include "InGameMgr.h"



//コンストラクタ
cPlayer::cPlayer()
{

	//左側の機体
	OBJPlayer[0].pos.x = 640.0;
	OBJPlayer[0].pos.y = 850.0;
	OBJPlayer[0].cx = OBJPlayer[0].pos.x + (IMAGEMAG / 2);
	OBJPlayer[0].cy = OBJPlayer[0].pos.y + (IMAGEMAG / 2);
	OBJPlayer[0].onActive = true;
	//右側の機体
	OBJPlayer[1].pos.x = OBJPlayer[0].pos.x + IMAGEMAG;
	OBJPlayer[1].pos.y = 850.0;
	OBJPlayer[1].cx = OBJPlayer[1].pos.x + (IMAGEMAG / 2);
	OBJPlayer[1].cy = OBJPlayer[1].pos.y + (IMAGEMAG / 2);
	OBJPlayer[1].onActive = false;

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
	DeleteGraph(image[0]);
	DeleteGraph(image[1]);
}

/*************************************************************************
  関数: int cPlayer::Update()
  説明: 移動処理
  引数: 無し
戻り値: 無し
*************************************************************************/
int cPlayer::Update()
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

		//フラグの値が1か-1なので向きが変わる
		OBJPlayer[i].pos.x += (SPEED * isLRflg);
		OBJPlayer[i].cx = OBJPlayer[0].pos.x + (IMAGEMAG / 2);

		//壁の設定
		if (OBJPlayer[i].pos.x <= 0)
		{
			OBJPlayer[i].pos.x = 0;
		}
		if (OBJPlayer[i].pos.x + IMAGEMAG >= UIsize)
		{
			//二機ともアクティブ状態なら
			if (OBJPlayer[0].onActive == true && OBJPlayer[1].onActive == true)
			{
				OBJPlayer[0].pos.x = UIsize - IMAGEMAG*2;
				OBJPlayer[1].pos.x = UIsize - IMAGEMAG;
			}
			OBJPlayer[i].pos.x = UIsize - IMAGEMAG;
		}
	}


//DEBUG
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
	if (OBJPlayer[0].onActive == false && OBJPlayer[1].onActive == false)
	{
		cPlayer::Break(eDeath, eDouble);
	}

	

	

	return 0;
}

/*************************************************************************
  関数: int cPlayer::Draw()
  説明: 描画処理
  引数: 無し
戻り値: 無し
*************************************************************************/
int cPlayer::Draw()
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
	DrawFormatString(920, 200, GetColor(255, 0, 0), "一機目x:%4.2lf", OBJPlayer[0].pos.x);
	DrawFormatString(920, 220, GetColor(255, 0, 0), "一機目cx:%4.2lf", OBJPlayer[0].cx);
	DrawFormatString(920, 240, GetColor(255, 0, 0), "一機目onActive:%d", OBJPlayer[0].onActive);
	

	DrawFormatString(920, 260, GetColor(255, 0, 0), "二機目x:%4.2lf", OBJPlayer[1].pos.x);
	DrawFormatString(920, 280, GetColor(255, 0, 0), "二機目cx:%4.2lf", OBJPlayer[1].cx);
	DrawFormatString(920, 300, GetColor(255, 0, 0), "二機目onActive:%d", OBJPlayer[1].onActive);






	return 0;
}

/*************************************************************************
  関数: int cPlayer::Double()
  説明: 二機の処理
  引数: 無し
戻り値: 無し
*************************************************************************/
int cPlayer::Double()
{
	//二機目の座標を更新し状態をアクティブへ
	OBJPlayer[1].pos.x = OBJPlayer[0].pos.x + IMAGEMAG;
	OBJPlayer[1].cx = OBJPlayer[1].pos.x + (IMAGEMAG / 2);
	OBJPlayer[1].cy = OBJPlayer[1].pos.y + (IMAGEMAG / 2);
	OBJPlayer[1].onActive = true;

	//問題点:二回目の二機の時に座標が初期座標になるので配列を増やして三機目の情報を入れないといけないかもしれない。
	//ややこしくなるから他の方法を探す
	//他の関数を作ってプレイヤーの一機目を生成するやつを作ってもいいかも？

	return 0;
}

/*************************************************************************
  関数: int cPlayer::Break()
  説明: 死亡処理 (引数で死亡かトラクタービームかを判断)
  引数: int
戻り値: 無し
*************************************************************************/
int cPlayer::Break(int judgeBreak ,int machineNum)
{
	//二機の状態で片方が死んだら
	if (judgeBreak == eDoubleDeath)
	{
		//撃破された方を非アクティブに
		if (machineNum == eLeftMachine)
		{
			OBJPlayer[0].onActive = false;
		}
		else
		{
			OBJPlayer[1].onActive = false;
		}

	}
	//一機の状態で死んだら
	else if (judgeBreak == eDeath)
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

	return 0;
}

