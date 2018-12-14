#include <DxLib.h>
#include "Player.h"
#include "Interface.h"
#include "InGameMgr.h"
#include "InGameController.h"

//コンストラクタ
cPlayer::cPlayer()
{


	//画像の読み込みと分割
	LoadDivGraph("../resource/Image/Galaga_OBJ_dualFighter.png", 2, 2, 1, 16, 16, image);
	if (image == NULL)   //error
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "画像が読み込めませんでした");
		WaitKey();
	}
	Init();

}

void cPlayer::Init() {
	//左側の機体
	player[eLeftMachine].pos.x = 450.0;
	player[eLeftMachine].pos.y = 850.0;
	player[eLeftMachine].r = IMAGEMAG / 2;
	player[eLeftMachine].cx = player[eLeftMachine].pos.x + (IMAGEMAG / 2);
	player[eLeftMachine].cy = player[eLeftMachine].pos.y + (IMAGEMAG / 2);
	player[eLeftMachine].onActive = TRUE;
	//右側の機体
	player[eRightMachine].pos.x = player[eLeftMachine].pos.x + IMAGEMAG;
	player[eRightMachine].pos.y = player[eLeftMachine].pos.y;
	player[eRightMachine].r = IMAGEMAG / 2;
	player[eRightMachine].cx = player[eRightMachine].pos.x + (IMAGEMAG / 2);
	player[eRightMachine].cy = player[eRightMachine].pos.y + (IMAGEMAG / 2);

	player[eRightMachine].onActive = FALSE;
	//二機時のフラグ  0:一機 1:二機
	isDoubleFlg = FALSE;

	//PlayerのHP
	playerHP = 2;   //(場に出ている機体を含まない)

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
  説明: 各計算処理の呼び出し
  引数: 無し
戻り値: 無し
*************************************************************************/
void cPlayer::Update()
{
	//移動と壁との当たり判定
	cPlayer::Instance()->Move();
			
}

/*************************************************************************
  関数: void cPlayer::Move()
  説明: 移動処理と壁の当たり判定
  引数: 無し
戻り値: 無し
*************************************************************************/
void cPlayer::Move()
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
			player[i].pos.x += SPEED;
		}

		// 左
		if (cInterface::Instance()->Get_Input(InLEFT) != 0)
		{
			player[i].pos.x -= SPEED;
		}

		//cxの更新
		player[i].cx = player[i].pos.x + (IMAGEMAG / 2);

		//壁との当たり判定
		for (int j = 0; j < MAXMACHINE; j++)
		{

			//左壁
			if (player[j].pos.x <= 0)
			{
				//二機ともアクティブ状態なら
				if (isDoubleFlg == TRUE)
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

#ifdef PLAYER_BREAK_DEBUG
	//キー
	if (cInterface::Instance()->Get_Input(DEBUG1) == 1)
	{
		cPlayer::Double();		// 二機になる
	}
	else if (cInterface::Instance()->Get_Input(DEBUG2) == 1)
	{
		cPlayer::Break(eDeath, eLeftMachine);	// 左が破壊
	}
	else if (cInterface::Instance()->Get_Input(DEBUG3) == 1)
	{
		cPlayer::Break(eDeath, eRightMachine);	// 右が破壊
	}
#endif

	//DEBUGに使用する場合はInterface.hのenumにDEBUG1,2,3と
	//Interface.cppのUpdateにenumを配列の要素数に使用し、三種類のキーボードを対応させてください。

}

/*************************************************************************
  関数: void cPlayer::Draw()
  説明: 描画処理
  引数: 無し
戻り値: 無し
*************************************************************************/
void cPlayer::Draw()
{
	//機体の描画
	if(player[0].onActive == TRUE)
	{
		DrawExtendGraph((int)player[0].pos.x, (int)player[0].pos.y, (int)player[0].pos.x + IMAGEMAG, (int)player[0].pos.y + IMAGEMAG, image[0], TRUE);
	}
	if(player[1].onActive == TRUE)
	{
		DrawExtendGraph((int)player[1].pos.x, (int)player[1].pos.y, (int)player[1].pos.x + IMAGEMAG, (int)player[1].pos.y + IMAGEMAG, image[1], TRUE);
	}
#ifdef PLAYER_POS_DEBUG

	//座標の表示
	DrawFormatString(DISP_SIZE - 300, 500, P_COLOR, "一機目x:%4.2lf", player[eLeftMachine].pos.x);
	DrawFormatString(DISP_SIZE - 300, 520, P_COLOR, "一機目cx:%4.2lf", player[eLeftMachine].cx);
	DrawFormatString(DISP_SIZE - 300, 540, P_COLOR, "一機目onActive:%d", player[eLeftMachine].onActive);
	DrawFormatString(DISP_SIZE - 300, 560, P_COLOR, "二機目x:%4.2lf", player[eRightMachine].pos.x);
	DrawFormatString(DISP_SIZE - 300, 580, P_COLOR, "二機目cx:%4.2lf", player[eRightMachine].cx);
	DrawFormatString(DISP_SIZE - 300, 600, P_COLOR, "二機目onActive:%d", player[eRightMachine].onActive);
	DrawFormatString(DISP_SIZE - 300, 620, P_COLOR, "HP:%d", playerHP);

#endif



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
	int activeMachine;	// 場に出ている機体
	int newMachine;		// 新しい機体

	isDoubleFlg = TRUE;
	playerHP--;
	cUI::Instance()->UI_SetPlayerHP(playerHP);

	//どの機体がアクティブ状態か判断
	if (player[eLeftMachine].onActive == TRUE)
	{
		newMachine = eRightMachine;
		activeMachine = eLeftMachine;
	}
	else
	{
		newMachine = eLeftMachine;
		activeMachine = eRightMachine;
	}

	//アクティブな機体の右側に座標を更新しアクティブ状態へ
	player[newMachine].pos.x = player[activeMachine].pos.x + IMAGEMAG;
	player[newMachine].cx = player[activeMachine].pos.x + (IMAGEMAG / 2);
	player[newMachine].onActive = TRUE;

	//一ドットずれる問題の解決(仮)
	//当たり判定で微妙になると考える
	if (newMachine == eLeftMachine)
	{
		player[newMachine].pos.x -= 6;
		player[newMachine].cx -= (6/2);
	}


}

/*************************************************************************
  関数: void cPlayer::Break()
  説明: 死亡処理 (引数で死亡かトラクタービームかを判断)
  引数: int judgeBreak   eDeath       : 一機しかない状態でで撃破された時
					　 　eTractorBeam : トラクタービームで攫われた時

		int machineNum　 eLeftMachine   : 左の機体
						 eRightMachine  : 右の機体
						 eNoneMachine   : 機体無し
			
戻り値: 無し
*************************************************************************/
void cPlayer::Break(int judgeBreak ,int machineNum)
{
	//機体が破壊されたら
	if (judgeBreak == eDeath)
	{
		//プレイヤーのHPを減少
		playerHP--;
		cUI::Instance()->UI_SetPlayerHP(playerHP);

		//撃破された方を非アクティブに
		if (machineNum == eLeftMachine)
		{
			player[eLeftMachine].onActive = FALSE;
		}
		else
		{
			player[eRightMachine].onActive = FALSE;
		}

		isDoubleFlg = FALSE;

		//二機とも撃破されたら
		if (player[eLeftMachine].onActive == FALSE && player[eRightMachine].onActive == FALSE)
		{
			//インゲームコントローラーでHPを管理して復活かゲームオーバー
			//引数として　0 通常死亡 1トラクターとしました by滝
			cInGameController::Instance()->PlayerDeath(0);
		}

	}
	//トラクタービームに攫われたら
	else if(judgeBreak == eTractorBeam)
	{
		//シーンの変更
		//トラクタービーム

		//プレイヤーのHPを減少
		playerHP--;
		cUI::Instance()->UI_SetPlayerHP(playerHP);

		//撃破された方を非アクティブに
		if (machineNum == eLeftMachine)
		{
			player[eLeftMachine].onActive = FALSE;
		}
		else
		{
			player[eRightMachine].onActive = FALSE;
		}

		isDoubleFlg = FALSE;

		//二機とも撃破されたら
		if (player[eLeftMachine].onActive == FALSE && player[eRightMachine].onActive == FALSE)
		{
			//インゲームコントローラーでHPを管理して復活かゲームオーバー
			//引数として　0 通常死亡 1トラクターとしました by滝
			cInGameController::Instance()->PlayerDeath(1);
		}
	

	}

}
/*************************************************************************
関数: int cPlayer::GetPlayerHP()
説明: プレイヤーのHP(場を含める残機)を受け渡す
引数: 無し
戻り値: playerHP
*************************************************************************/
int cPlayer::GetPlayerHP()
{
	return playerHP;
}

/*************************************************************************
　関数: void PlayerRevive();
  説明: プレイヤーの復活
  引数: 無し
戻り値: 無し
*************************************************************************/
void cPlayer::PlayerRevive()
{
	player[eLeftMachine].pos.x = 450.0;
	player[eLeftMachine].pos.y = 850.0;
	player[eLeftMachine].cx = player[eLeftMachine].pos.x + (IMAGEMAG / 2);
	player[eLeftMachine].cy = player[eLeftMachine].pos.y + (IMAGEMAG / 2);
	player[eLeftMachine].onActive = TRUE;
}

