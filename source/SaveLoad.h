#pragma once

#ifndef _SAVELOAD_INCLUDE_
#define _SAVELOAD_INCLUDE_

#include "Singleton.h"
#include "Debug.h"
#include "TextChange.h"
#include "Score.h"

class cSaveLoad : public cSingleton<cSaveLoad>
{
	cSaveLoad();	//コンストラクタ
	~cSaveLoad();	//デストラクタ
	friend cSingleton< cSaveLoad >;

private:
	char characterHighScore[256];
	int highScoreFileHandole;
	int newScore;

	int integerHighScore;

protected:

public:
	void Save();
	void Load();
	void Draw();

};

#endif