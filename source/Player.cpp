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
	//isDoubleFlg = false;  // 0:一機  1:二機
	
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


	//DEBUG
	if (Interface.Get_Input(InDEBUG1) != 0)
	{
		cPlayer::Double();		// I を押したら二機になる
	}

	if (Interface.Get_Input(InDEBUG2) != 0)
	{
		cPlayer::Break(eDoubleDeath);	// O を押したら二機目が死ぬ
	}


	
	//フラグの値が1か-1なので向きが変わる
	//OBJPlayer[0].pos.x += (SPEED * isLRflg);
	
	//二機目がアクティブなら座標更新
	if(OBJPlayer[1].onActive == true)
	{
		OBJPlayer[1].pos.x = OBJPlayer[0].pos.x + IMAGEMAG;
		OBJPlayer[1].cx = OBJPlayer[1].pos.x + (IMAGEMAG / 2);
		OBJPlayer[1].cy = OBJPlayer[1].pos.y + (IMAGEMAG / 2);
	}
	

	for (int i = 0; i < 2; i++)
	{
		if (OBJPlayer[i].onActive == false)
		{
			continue;
		}

		OBJPlayer[i].pos.x += (SPEED * isLRflg);
	}

	//右側が生きてるのに左側が死んだら誰も居なくなってしまうので改良が必要
	//JSみたいにonActiveでコンティニューする感じでできそう(?)
	

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
	/*
	//一機
	if (isDoubleFlg == false)
	{
		DrawExtendGraph(OBJPlayer[0].pos.x, OBJPlayer[0].pos.y, OBJPlayer[0].pos.x + IMAGEMAG, OBJPlayer[0].pos.y +IMAGEMAG, image[0], TRUE);
	}
	//二機
	else
	{
		DrawExtendGraph(OBJPlayer[0].pos.x, OBJPlayer[0].pos.y, OBJPlayer[0].pos.x + IMAGEMAG, OBJPlayer[0].pos.y + IMAGEMAG, image[0], TRUE);
		DrawExtendGraph(OBJPlayer[1].pos.x, OBJPlayer[1].pos.y, OBJPlayer[1].pos.x + IMAGEMAG, OBJPlayer[1].pos.y + IMAGEMAG, image[1], TRUE);
	}
	
	}
	*/

	for (int i = 0; i < 2; i++)
	{

		if (OBJPlayer[i].onActive == false)
		{
			continue;
		}

		//表示
		DrawExtendGraph(OBJPlayer[i].pos.x, OBJPlayer[i].pos.y, OBJPlayer[i].pos.x + IMAGEMAG, OBJPlayer[i].pos.y + IMAGEMAG, image[i], TRUE);

	}

	//UIの枠組みの白線
	int size ;
	size = (1280 / 4 * 3)-50;
	DrawLine(size,0,size,960,GetColor(255,255,255));

#ifndef _DEBUG

	//DrawFormatString(200, 420, GetColor(255, 0, 0), "flg:%d", isLRflg);
	DrawFormatString(200, 440, GetColor(255, 0, 0), "x:%4.2lf", player[0].x);
	DrawFormatString(200, 460, GetColor(255, 0, 0), "y:%4.2lf", player[0].y);

#endif 



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
	//画像の表示が二機になる
	//isDoubleFlg = true;
	OBJPlayer[1].onActive = true;

	//cx,cy等の更新


	return 0;
}

/*************************************************************************
  関数: int cPlayer::Break()
  説明: 死亡処理 (引数で死亡かトラクタービームかを判断)
  引数: int
戻り値: 無し
*************************************************************************/
int cPlayer::Break(int judgeBreak)
{
	if (judgeBreak == eDoubleDeath)
	{
		//画像の表示の変化
		//isDoubleFlg = false;
		//どっちが死んだかの判断とonActive
	}
	else if (judgeBreak == eDeath)
	{
		//死亡処理
		//onActiveの処理
	}
	else if(judgeBreak == eTractorBeam)
	{
		//トラクタービームに攫われる処理
	}

	return 0;
}

