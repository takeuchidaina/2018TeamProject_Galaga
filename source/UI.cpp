#include <DxLib.h>
#include "UI.h"

//DEBUG
#include "Interface.h"
#define COLOR GetColor(0,255,0)

static int textImg[48];	//テキストの画像
static int iconImg[12];	//ステージアイコンの画像

static int iconX;
static int iconY;

//DEBUG
int stageNo;
int playerHP;

sTextPos textPos[] = 
{
	{ DISP_SIZE + 50,100,"HIGH SCORE" },
	{ DISP_SIZE + 50,140,"text02" },
	{ DISP_SIZE + 50,180,"text03" },

};

/*************************************************************************
　関数: int UI_Init()
　説明: 初期化処理
　引数: 無し
戻り値: 無し
*************************************************************************/
int UI_Init()
{
	iconX = DISP_SIZE + 250;
	iconY = 700;

	//DEBUG
	stageNo = cInGameController::Instance()->GetNowStageNum();
	playerHP = 2;

	//画像の読み込み
	//LoadDivGraph("../resource/Image/UI_Text.png",48,8,6,28,28,textImg);
	LoadDivGraph("../resource/Image/Galaga_UI_icon.png", 12, 6, 2, 18, 19, iconImg);
	if (iconImg == NULL)
	{
		DrawFormatString(200, 200, GetColor(255, 0, 0), "画像が読み込めませんでした");
		WaitKey();
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
	//DEBUG
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

	//DEBUG
	for (int i = 0; i < (sizeof(textPos) / sizeof*(textPos)); i++)
	{
		DrawFormatString(textPos[i].x, textPos[i].y, COLOR, "%s", textPos[i].text);
	}


		


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
	1～4を表すアイコンの表示するfor文に使用
	その他アイコンの座標の計算に使用


	【 tmp2 】
	5で割って余りを切り捨てた値
	5のアイコンが必要か必要じゃないかを判断する際に使用

	【 tmp3 】
	10で割って余りを切り捨てた値
	10毎のステージアイコンの要素数に使用


	*/

	fiveFlg = FALSE;

	/*_DEBUG
	if (cInterface::Instance()->Get_Input(DEBUG1) == 1)
	{
	stageNo++;
	}
	if (cInterface::Instance()->Get_Input(DEBUG2) == 1)
	{
	stageNo--;
	}
	*/

	DrawFormatString(iconX - 200, iconY + 110, COLOR, "5flg:%d", fiveFlg);
	DrawFormatString(iconX - 200, iconY + 130, COLOR, "stage:%d", stageNo);
	DrawFormatString(iconX - 200, iconY + 150, COLOR, "tmp1:%d", tmp);
	DrawFormatString(iconX - 200, iconY + 170, COLOR, "tmp2:%d", tmp2);
	DrawFormatString(iconX - 200, iconY + 190, COLOR, "tmp3:%d", tmp3);
	DrawLine(iconX + IMAGEMAG, 0, iconX + IMAGEMAG, 960, GetColor(255, 255, 255));	//アイコンのスタートライン


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
		//1～4のアイコンがあるなら(tmpが1～4)
		if (stageNo % 5 != 0)	
		{
			// X座標からアイコンの数に応じてずれる
			DrawExtendGraph(iconX - (ICONMAG * tmp + 1),
							iconY,
							(iconX + 64) - (ICONMAG * tmp + 1),
							iconY + IMAGEMAG + ICONMAG,
							iconImg[1], TRUE);
		}
		//1～4のアイコンがないなら(tmpが0)
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