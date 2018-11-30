#include <Windows.h>
#include "WinBox.h"

void ErrBox(const char* tmp) {
	MessageBox(
		NULL,
		TEXT(tmp),
		TEXT("ÉGÉâÅ["),
		MB_OK | MB_ICONWARNING);
}

void ReportBox(const char* tmp) {
	MessageBox(
		NULL,
		TEXT(tmp),
		TEXT("ïÒçê"),
		MB_OK | MB_ICONINFORMATION);
}