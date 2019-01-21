#pragma once

#ifndef _SAVELOAD_INCLUDE_
#define _SAVELOAD_INCLUDE_

#include "Singleton.h"
#include "Debug.h"
#include "TextChange.h"
#include "Score.h"
#include "WinBox.h"

class cSaveLoad : public cSingleton<cSaveLoad>
{
	cSaveLoad();	//コンストラクタ
	~cSaveLoad();	//デストラクタ
	friend cSingleton< cSaveLoad >;

private:
	FILE * fp;
	char characterHighScore[256];
	int newScore;
	int integerHighScore;

protected:

public:
	void Save();
	void Load();
	void Draw();

};

#endif