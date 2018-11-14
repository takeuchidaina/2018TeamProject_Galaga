#include <Windows.h>
#include "WinBox.h"

void ErrBox(const char* tmp) {
	MessageBox(
		NULL,
		TEXT(tmp),
		TEXT("ÉGÉâÅ["),
		MB_OK | MB_ICONWARNING);
}