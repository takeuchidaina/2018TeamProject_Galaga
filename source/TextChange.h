#pragma once

#ifndef _TEXTCONVERSION_INCLUDE_
#define _TEXTCONVERSION_INCLUDE_

class cTextChange 
{
private:

	int textImg[48];

	cTextChange();  //privateなのでnewが使えない

public:
	static cTextChange* Instance()
	{
		static cTextChange inst;
		return &inst;
	}
	

	int Update();
	void Draw();
};
#endif


/* _MEMO

コンストラクタをprivateに指定して、シングルトンクラス以外から
コンストラクタの呼出し（newが使えなくなる）ができないようにします。
そして、（外部よりnewが使えないため）取得するメソッドを用意してあげる必要があります。 
このメソッドは、どこからでも参照できるようにpublic static宣言をする必要があります。


*/
