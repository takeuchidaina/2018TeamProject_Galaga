#pragma once

#ifndef _SINGLETON_INCLUDE_
#define _SINGLETON_INCLUDE_

template <typename _T>
class cSingleton {

protected:
	cSingleton() {}
	virtual ~cSingleton() {}
	cSingleton(const cSingleton& r) {}
	cSingleton& operator=(const cSingleton& r) {}

public:
	static _T* Instance() {
		static _T inst;
		return &inst;
	};
};

#endif