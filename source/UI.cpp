#include <DxLib.h>
#include "UI.h"

static int textImg[48];	//テキストの画像
static int iconImg[12];	//ステージアイコンの画像

static int iconX;
static int iconY;

int stageNo;
int playerHP;

sTextPos textPos[3] = 
{
	{ DISP_SIZE + 150, 100,"HIGH" },
	{ DISP_SIZE +  50, 130,"SCORE" },
	{ DISP_SIZE + 150, 200,"1UP" },

};

/*************************************************************************
　関数: int UI_Init()
　説明: 初期化処理
　引数: 無し
戻り値: -1 画像読み込み時のエラー
*************************************************************************/
int UI_Init()
{
	iconX = DISP_SIZE + 250;
	iconY = 700;

	stageNo = cInGameController::Instance()->GetNowStageNum();
	playerHP = cPlayer::Instance()->GetPlayerHP();

	//画像の読み込み
	//LoadDivGraph("../resource/Image/UI_Text.png",48,8,6,28,28,textImg);
	LoadDivGraph("../resource/Image/Galaga_UI_icon1616.png", 12, 6, 2, 16, 16, iconImg);
	if (iconImg == NULL)
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "画像が読み込めませんでした");
		WaitKey();
		return -1;
	}

	return 0;
}

/*************************************************************************
　関数: int UI_Update()
  説明: 計算処理
  引数: 無し
戻り値: 無し
*************************************************************************/
int UI_Update()
{
	UI_StgSelectIcon(stageNo);

	return 0;
}

/*************************************************************************
　関数: int UI_Draw()
  説明: 描画処理
  引数: 無し
戻り値: 無し
*************************************************************************/
int UI_Draw()
{
	//UIを表示する灰色の部分の描画
	DrawBox(DISP_SIZE,0,DISP_SIZE + UI_SIZE,960,GetColor(125,125,125),TRUE);

	//プレイヤーの残機
	for (int j = 0; j < playerHP; j++)  //3はプレイヤーの残機
	{
		DrawExtendGraph(DISP_SIZE + 50 + (IMAGEMAG*j), 900, DISP_SIZE + 50 + (IMAGEMAG*j + 1) + IMAGEMAG, 900 + IMAGEMAG, iconImg[6], TRUE);
	}

	//ステージアイコンの表示
	UI_StgSelectIcon(stageNo);

#ifdef UI_POS_DEBUG

	for (int i = 0; i < (sizeof(textPos) / sizeof*(textPos)); i++)
	{
		DrawFormatString(textPos[i].x, textPos[i].y, UI_COLOR, "%s", textPos[i].text);
	}

#endif

	return 0;
}

/*************************************************************************
　関数: int UI_End()
  説明: 終了処理
  引数: 無し
戻り値: 無し
*************************************************************************/
int UI_End()
{
	//終了
	return 0;
}

/*************************************************************************
　関数: int UI_SelectIcon()
 説明: ステージ情報のアイコンをどれを表示するか
 引数: ステージ番号
 戻り値: 無し
 *************************************************************************/
int UI_StgSelectIcon(int stageNo)
{
	//ステージアイコン
	int tmp;
	int tmp2;
	int tmp3;
	int fiveFlg;

	tmp = stageNo % 5;
	tmp2 = stageNo / 5;
	tmp3 = stageNo / 10;

	/* tmp毎の解説

	【 tmp 】
	5で割って出た余り
	1〜4を表すアイコンの表示するfor文に使用
	その他アイコンの座標の計算に使用


	【 tmp2 】
	5で割って余りを切り捨てた値
	5のアイコンが必要か必要じゃないかを判断する際に使用

	【 tmp3 】
	10で割って余りを切り捨てた値
	10毎のステージアイコンの要素数に使用


	*/

	fiveFlg = FALSE;

#ifdef UI_ICON_DEBUG

	if (cInterface::Instance()->Get_Input(DEBUG1) == 1)
	{
	stageNo++;
	}
	if (cInterface::Instance()->Get_Input(DEBUG2) == 1)
	{
	stageNo--;
	}
	DrawFormatString(iconX - 200, iconY + 110, UI_COLOR, "5flg:%d", fiveFlg);
	DrawFormatString(iconX - 200, iconY + 130, UI_COLOR, "stage:%d", stageNo);
	DrawFormatString(iconX - 200, iconY + 150, UI_COLOR, "tmp1:%d", tmp);
	DrawFormatString(iconX - 200, iconY + 170, UI_COLOR, "tmp2:%d", tmp2);
	DrawFormatString(iconX - 200, iconY + 190, UI_COLOR, "tmp3:%d", tmp3);

#endif
	




	//ステージが5で割り切れないなら
	if (stageNo % 5 != 0)
	{

		for (int i = 0; i < tmp; i++)
		{
			DrawExtendGraph(iconX - (ICONMAG * i),
							iconY,
							iconX + IMAGEMAG + (ICONMAG / 2) - (ICONMAG * i),
							iconY + IMAGEMAG + ICONMAG,
							iconImg[0], TRUE);
		}
	}
	//ステージ5・15・25・・・
	if (tmp2 % 2 != 0)		//10や20だったらtmp2が偶数なので%2で割ると0になる為処理がされない
	{
		//1〜4のアイコンがあるなら(tmpが1〜4)
		if (stageNo % 5 != 0)	
		{
			// X座標からアイコンの数に応じてずれる
			DrawExtendGraph(iconX - (ICONMAG * tmp + 1),
							iconY,
							(iconX + 64) - (ICONMAG * tmp + 1),
							iconY + IMAGEMAG + ICONMAG,
							iconImg[1], TRUE);
		}
		//1〜4のアイコンがないなら(tmpが0)
		else
		{
			// X座標に表示
			DrawExtendGraph(iconX,
							iconY,
							iconX + IMAGEMAG + (ICONMAG / 2),
							iconY + IMAGEMAG + ICONMAG,
							iconImg[1], TRUE);
		}

		fiveFlg = TRUE;  // 5のアイコンを表示している
	}
	//ステージ10・20・30・・・
	if (stageNo >= 10)
	{
		// 5のアイコンがあるなら
		if (fiveFlg == TRUE)
		{
			DrawExtendGraph(iconX - (ICONMAG * (tmp + 1)),
							iconY,
							iconX + IMAGEMAG + (ICONMAG / 2) - (ICONMAG * (tmp + 1)),
							iconY + IMAGEMAG + ICONMAG,
							iconImg[tmp3 + 1], TRUE);
		}
		// 5のアイコンがないなら
		else
		{
			DrawExtendGraph(iconX - (ICONMAG * tmp),
							iconY,
							iconX + IMAGEMAG + (ICONMAG / 2) - (ICONMAG * tmp),
							iconY + IMAGEMAG + ICONMAG,
							iconImg[tmp3 + 1], TRUE);
		}
	}

	return 0;
}

/*************************************************************************
   関数: void UI_SetPlayerHP()
   説明: プレイヤーの残機の更新
   引数: int (プレイヤーのHP)
 戻り値: 無し
 *************************************************************************/
void UI_SetPlayerHP(int HP)
{
	playerHP = HP;
}
/*************************************************************************
関数: int GetTextPos()
説明: 構造体textPosの受け渡し
引数: 無し
戻り値: textPos
*************************************************************************/
sTextPos GetTextPos()
{
	int i;
	for( i=0;i<sizeof(textPos) / sizeof(textPos[0]);i++);
	{
		return textPos[i];
	}
}
