#include <DxLib.h>
#include "TextChange.h"

//コンストラクタ
cTextChange::cTextChange()
{
	//テキストの画像の読み込み
	//LoadDivGraph("../resource/Image/AC_Classic.png", 40, 8, 5, 16, 16, textImg);
	LoadDivGraph("../resource/Image/AC_Classic_Red.png", 40, 8, 5, 16, 16, textImgRD);
	LoadDivGraph("../resource/Image/AC_Classic_LBlue.png", 40, 8, 5, 16, 16, textImgLB);
	LoadDivGraph("../resource/Image/AC_Classic_Yellow.png", 40, 8, 5, 16, 16, textImgYL);
	LoadDivGraph("../resource/Image/AC_Classic_White.png", 40, 8, 5, 16, 16, textImgWH);
	imgColor[48] = { 0 };
	//hue = 0;			//色相[0～360]
	//saturation = 0;		//彩度[-255～100]
	//bright = 0;			//輝度[-255～255]
	magX = 0;			//画像を拡大する際のx
	magY = 0;			//画像を拡大する際のy
	
}

//デストラクタ
cTextChange::~cTextChange() 
{
	for (int i = 0; i < 48; i++) 
	{
		DeleteGraph(textImgRD[i]);
		DeleteGraph(textImgLB[i]);
		DeleteGraph(textImgYL[i]);
		DeleteGraph(textImgWH[i]);
		DeleteGraph(imgColor[i]);
	}
}

/*************************************************************************
関数: int DrawTextImage
説明: 引数の座標に指定の色と倍率で文字を表示します
引数: (int x, int y, char *文字列, int 色, int 倍率)
	   色と倍率はenum
戻り値: 無し
*************************************************************************/
int cTextChange::DrawTextImage(int x,int y,const char *text,int color,int mag)
{
	
	//色の設定
	switch (color)
	{
	case eRed:
		//ImgColorに赤色を代入
		memcpy(imgColor, textImgRD, sizeof(textImgRD));

		//hue = 360;
		//saturation = 0;
		//bright = 0;
		break;

	case eYellow:
		//ImgColorに黄色を代入
		memcpy(imgColor, textImgYL, sizeof(textImgYL));

		//hue = 60;
		//saturation = 0;
		//bright = 0;
		break;

	case eLBlue:
		//ImgColorに水色を代入
		memcpy(imgColor, textImgLB, sizeof(textImgLB));

		//hue = 187;
		//saturation = 0;
		//bright = 0;
		break;

	case eWhite:
		//ImgColorに白色を代入
		memcpy(imgColor, textImgWH, sizeof(textImgWH));

		//hue = 0;
		//saturation = 90;
		//bright = 10;
		break;

	default:
		//eNone

		//ImgColorに白色を代入
		memcpy(imgColor, textImgWH, sizeof(textImgWH));

		break;
	}

	//倍率の設定
	switch (mag)
	{
	case eMag16:
		magX = x + 16;
		magY = y + 16;
		mag = 16;  //文字間隔の調整必要
		break;

	case eMag32:
		magX = x + 32;
		magY = y + 32;
		mag = 32;  //文字間隔の調整必要
		break;

	case eMag48:
		magX = x + 48;
		magY = y + 48;
		mag = 32;
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
				//GraphFilter(textImg[text[j]-'0'], DX_GRAPH_FILTER_HSB, 1, hue, saturation, bright);
				//描画
				DrawExtendGraph(x+(j*mag), y,magX+(j*mag),magY, imgColor[text[j] - '0'], TRUE);
			}
			//文字がA～Zなら
			else if (text[j] >= 'A' && text[j] <= 'Z')
			{
				//色相変化
				//GraphFilter(textImg[text[j] - 'A'+10], DX_GRAPH_FILTER_HSB, 1, hue, saturation, bright);
				//描画(+10するのは0～9の番号を含めないようにするため)
				DrawExtendGraph(x+(j*mag), y, magX + (j * mag), magY, imgColor[text[j] - 'A'+10], TRUE);
			}
			//文字がスペースなら
			else if(text[j] == ' ')
			{
				//記号
				DrawExtendGraph(x + (j*mag), y, magX + (j * mag), magY, imgColor[38], TRUE);
			}

	}
	
	return 0;
}