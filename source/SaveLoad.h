#pragma once

#ifndef _SAVELOAD_INCLUDE_
#define _SAVELOAD_INCLUDE_

#include "Singleton.h"
#include "Debug.h"

class cSaveLoad : public cSingleton<cSaveLoad>
{
	cSaveLoad();	//コンストラクタ
	~cSaveLoad();	//デストラクタ
	friend cSingleton< cSaveLoad >;

private:
	int highScore;


protected:

public:
	void update();
	void draw();

};

#endif