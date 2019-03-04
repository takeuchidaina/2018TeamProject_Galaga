#pragma once

#ifndef _WINBOX_INCLUDE_
#define _WINBOX_INCLUDE_


/*
使い方
１、WinBox.hをインクルードする
２、エラー文を出したい所に
ErrBox("ここにエラー内容");
のように書く。
*/
extern void ErrBox(const char*);
extern void ReportBox(const char*);
extern int InterfaceYesNoBox();
#endif