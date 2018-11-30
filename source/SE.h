#pragma once

#ifndef _SE_INCLUDE_
#define _SE_INCLUDE_

#include "Singleton.h"

#define SENUM 23


class cSE : public cSingleton<cSE>
{
	cSE();	//コンストラクタ
	~cSE();	//デストラクタ
	friend cSingleton< cSE >;

private:

	//seを読み込む配列
	int se[SENUM];

protected:

public:

	//引数のseを再生する
	void selectSE(int);

	//再生するseの項目
	typedef enum
	{

	}eSe;

};


#endif