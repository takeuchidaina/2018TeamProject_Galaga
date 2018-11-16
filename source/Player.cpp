#include <DxLib.h>
#include "Player.h"
#include "Interface.h"
#include "InGameMgr.h"



//コンストラクタ
cPlayer::cPlayer()
{

	//左側の機体
	player[eLeftMachine].pos.x = 640.0;
	player[eLeftMachine].pos.y = 850.0;
	player[eLeftMachine].cx = player[eLeftMachine].pos.x + (IMAGEMAG / 2);
	player[eLeftMachine].cy = player[eLeftMachine].pos.y + (IMAGEMAG / 2);
	player[eLeftMachine].onActive = TRUE;
	//右側の機体
	player[eRightMachine].pos.x = player[eLeftMachine].pos.x + IMAGEMAG;
	player[eRightMachine].pos.y = 850.0;
	player[eRightMachine].cx = player[eRightMachine].pos.x + (IMAGEMAG / 2);
	player[eRightMachine].cy = player[eRightMachine].pos.y + (IMAGEMAG / 2);
	player[eRightMachine].onActive = FALSE;

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
	//移動の計算
	for (int i = 0; i < MAXMACHINE; i++)
	{
		//アクティブ状態ではないなら次へ
		if (player[i].onActive == FALSE)
		{
			continue;
		}

		// 右
		if (cInterface::Instance()->Get_Input(InRIGHT) != 0)
		{
			//フラグの値が1か-1なので向きが変わりcxの更新
			player[i].pos.x += SPEED;
		}

		// 左
		if (cInterface::Instance()->Get_Input(InLEFT) != 0)
		{
			//フラグの値が1か-1なので向きが変わりcxの更新
			player[i].pos.x -= SPEED;
			
		}

		//cxの更新
		player[i].cx = player[eLeftMachine].pos.x + (IMAGEMAG / 2);

			//壁との当たり判定

			for (int j = 0; j < MAXMACHINE; j++)
			{

				//左壁
				if (player[j].pos.x <= 0)
				{
					//二機ともアクティブ状態なら
					if (player[eLeftMachine].onActive == TRUE && player[eRightMachine].onActive == TRUE)
					{
						player[eLeftMachine].pos.x = 0;
						player[eRightMachine].pos.x = 0 + IMAGEMAG;
					}
					//一機のみアクティブ状態なら
					else
					{
						player[i].pos.x = 0;
					}

				}
				//右壁
				if (player[j].pos.x + IMAGEMAG >= DISP_SIZE)
				{
					//二機ともアクティブ状態なら
					if (player[eLeftMachine].onActive == TRUE && player[eRightMachine].onActive == TRUE)
					{
						player[eLeftMachine].pos.x = DISP_SIZE - IMAGEMAG * 2;
						player[eRightMachine].pos.x = DISP_SIZE - IMAGEMAG;
					}
					//一機のみアクティブ状態なら
					else
					{
						player[i].pos.x = DISP_SIZE - IMAGEMAG;
					}

				}

			}
	}

		//DEBUG
			/*
			//キー
			if (cInterface::Instance()->Get_Input(DEBUG1) != 0)
			{
				cPlayer::Double();		// 二機になる
			}
			else if (cInterface::Instance()->Get_Input(DEBUG2) != 0)
			{
				cPlayer::Break(eDoubleDeath,eLeftMachine);	// 一機目が死ぬ
			}
			else if (cInterface::Instance()->Get_Input(DEBUG3) != 0)
			{
				cPlayer::Break(eDoubleDeath,eRightMachine);	// 二機目が死ぬ
			}

			//両方撃破されたら
			if (player[eLeftMachine].onActive == FALSE && player[1].onActive == FALSE)
			{
				cPlayer::Break(eDeath, eDoubleMachine);  //GAMEOVER
			}

			//DEBUGに使用する場合はInterface.hのenumにDEBUG1,2,3と
			//Interface.cppのUpdateにenumを配列の要素数に使用し、三種類のキーボードを対応させてください。
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

		if (player[i].onActive == FALSE)
		{
			continue;
		}

		//表示
		DrawExtendGraph((int)player[i].pos.x, (int)player[i].pos.y, (int)player[i].pos.x + IMAGEMAG, (int)player[i].pos.y + IMAGEMAG, image[i], TRUE);

	}

//DEBUG

	//座標の表示
	DrawFormatString(DISP_SIZE - 300, 500, GetColor(255, 0, 0), "一機目x:%4.2lf", player[eLeftMachine].pos.x);
	DrawFormatString(DISP_SIZE - 300, 520, GetColor(255, 0, 0), "一機目cx:%4.2lf", player[eLeftMachine].cx);
	DrawFormatString(DISP_SIZE - 300, 540, GetColor(255, 0, 0), "一機目onActive:%d", player[eLeftMachine].onActive);
	DrawFormatString(DISP_SIZE - 300, 560, GetColor(255, 0, 0), "二機目x:%4.2lf", player[eRightMachine].pos.x);
	DrawFormatString(DISP_SIZE - 300, 580, GetColor(255, 0, 0), "二機目cx:%4.2lf", player[eRightMachine].cx);
	DrawFormatString(DISP_SIZE - 300, 600, GetColor(255, 0, 0), "二機目onActive:%d", player[eRightMachine].onActive);

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
	player[eRightMachine].pos.x = player[0].pos.x + IMAGEMAG;
	player[eRightMachine].cx = player[eRightMachine].pos.x + (IMAGEMAG / 2);
	player[eRightMachine].onActive = TRUE;

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
						 eNoneMachine   : 機体無し
			
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
			player[eLeftMachine].onActive = FALSE;
		}
		else
		{
			player[eRightMachine].onActive = FALSE;
		}

	}
	//一機の状態で死んだら
	else if (judgeBreak == eDeath && machineNum == eNoneMachine)
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

