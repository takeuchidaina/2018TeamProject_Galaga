#include <Windows.h>
#include "WinBox.h"

void ErrBox(const char* tmp) {
	MessageBox(
		NULL,
		TEXT(tmp),
		TEXT("�G���["),
		MB_OK | MB_ICONWARNING);
}