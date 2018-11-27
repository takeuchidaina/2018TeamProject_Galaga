#include <DxLib.h>
#include "TextChange.h"

//コンストラクタ
cTextChange::cTextChange()
{
	//テキストの画像の読み込み
	//LoadDivGraph("../resource/Image/UI_Text_Color.png", 48, 8, 6, 28, 28, textImg);
	LoadDivGraph("../Image/GogoFiveAI.png", 48, 8, 6, 16, 16, textImg);
	hue = 0;			//色相[0～360]
	saturation = 0;		//彩度[-255～]
	bright = 0;			//輝度[-255～255]
	magX = 0;
	magY = 0;
	
}

/*************************************************************************
　関数: int cTextChange::_Update()
  説明: 文字列から画像の要素数への変換
  引数: (int,int,*text)
戻り値: 無し
*************************************************************************/
int cTextChange::DrawTextImage(int x,int y,const char *text,int color,int mag)
{
	
	//色の設定
	switch (color)
	{
	case eRed:
		hue = 360;
		saturation = 0;
		bright = 0;
		break;

	case eYellow:
		hue = 60;
		saturation = 0;
		bright = 0;
		break;

	case eLBlue:
		hue = 187;
		saturation = 0;
		bright = 0;
		break;

	case eWhite:
		hue = 0;
		saturation = 90;
		bright = 10;
		break;

	default:
		//eNone
		break;
	}

	switch (mag)
	{
	case eMag16:
		magX = x + 16;
		magY = y + 16;
		mag = 16;
		break;

	case eMag32:
		magX = x + 32;
		magY = y + 32;
		mag = 32;
		break;

	case eMag48:
		magX = x + 48;
		magY = y + 48;
		mag = 48;
		break;

	default:
		break;
	}

	//画像の算出・色相変化・描画
	for (int j= 0;j<strlen(text);j++)
	{
			//文字が0～9なら
			if (text[j] >= '0' && text[j] <= '9')
			{
				//色相変化
				GraphFilter(textImg[text[j]-'0'], DX_GRAPH_FILTER_HSB, 1, hue, saturation, bright);
				//描画
				DrawExtendGraph(x+(j*mag), y,magX+(j*mag),magY, textImg[text[j] - '0'], TRUE);
			}
			//文字がA～Zなら
			else if (text[j] >= 'A' && text[j] <= 'Z')
			{
				//色相変化
				GraphFilter(textImg[text[j] - 'A'+10], DX_GRAPH_FILTER_HSB, 1, hue, saturation, bright);
				//描画(+10するのは0～9の番号を含めないようにするため)
				DrawExtendGraph(x+(j*mag), y, magX + (j * mag), magY, textImg[text[j] - 'A'+10], TRUE);
			}
			//文字が記号なら
			else
			{
				//記号
				//switch case
			}

	}
	
	return 0;
}