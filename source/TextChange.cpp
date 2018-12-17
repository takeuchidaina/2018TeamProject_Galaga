#include <DxLib.h>
#include "TextChange.h"

//コンストラクタ
cTextChange::cTextChange()
{
	//テキストの画像の読み込み
	LoadDivGraph("../resource/Image/AC_Classic_Red.png", 40, 8, 5, 16, 16, textImgRD);
	LoadDivGraph("../resource/Image/AC_Classic_LBlue.png", 40, 8, 5, 16, 16, textImgLB);
	LoadDivGraph("../resource/Image/AC_Classic_Yellow.png", 40, 8, 5, 16, 16, textImgYL);
	LoadDivGraph("../resource/Image/AC_Classic_White.png", 40, 8, 5, 16, 16, textImgWH);

	//変数の初期化
	imgColor[41] = { 0 };
	magX = 0;
	magY = 0;
	spacing = 32;
	
}

//デストラクタ
cTextChange::~cTextChange() 
{
	for (int i = 0; i < 41; i++) 
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
		break;
	case eYellow:
		//ImgColorに黄色を代入
		memcpy(imgColor, textImgYL, sizeof(textImgYL));
		break;
	case eLBlue:
		//ImgColorに水色を代入
		memcpy(imgColor, textImgLB, sizeof(textImgLB));
		break;
	case eWhite:
		//ImgColorに白色を代入
		memcpy(imgColor, textImgWH, sizeof(textImgWH));
		break;
	default:	//eNone
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
		spacing = 8;
		break;
	case eMag32:
		magX = x + 32;
		magY = y + 32;
		spacing = 16;
		break;
	case eMag48:
		magX = x + 48;
		magY = y + 48;
		spacing = 32;
		break;
	default:	//eMag48
		magX = x + 48;
		magY = y + 48;
		spacing = 32;
		break;
	}

	//画像の算出・色相変化・描画
	for (int j= 0;j<strlen(text);j++)
	{
			//文字が0～9なら
			if (text[j] >= '0' && text[j] <= '9')
			{
				DrawExtendGraph(x+(j*spacing), y,magX+(j*spacing),magY, imgColor[text[j] - '0'], TRUE);
			}
			//文字がA～Zなら
			else if (text[j] >= 'A' && text[j] <= 'Z')
			{
				//+10するのは0～9の番号を含めないようにするため
				DrawExtendGraph(x+(j*spacing), y, magX + (j * spacing), magY, imgColor[text[j] - 'A'+10], TRUE);
			}
			//記号
			else
			{
				switch (text[j]) 
				{
				case '.':  //ドット
					DrawExtendGraph(x + (j*spacing), y, magX + (j * spacing), magY, imgColor[36], TRUE);
					break;
				case '%':  // % 
					DrawExtendGraph(x + (j*spacing), y, magX + (j * spacing), magY, imgColor[37], TRUE);
					break;
				case '-':  // スペース
					DrawExtendGraph(x + (j*spacing), y, magX + (j * spacing), magY, imgColor[38], TRUE);
					break;
				case '@' :  // コピーライトの代わり
					DrawExtendGraph(x + (j*spacing), y, magX + (j * spacing), magY, imgColor[39], TRUE);
					break;
				default :  //スペース
					DrawExtendGraph(x + (j*spacing), y, magX + (j * spacing), magY, imgColor[40], TRUE);
					break;

				}
			}
	}
	
	return 0;
}