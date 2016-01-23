// keypp.cpp : Defines the entry point for the console application.
//
#define _WIN32_WINNT 0x0500

#include "keypp_stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>
#include <conio.h>

using namespace std;


int main()
{
	HWND hWnd = GetConsoleWindow();
	int boolshowwindows;
	ShowWindow(hWnd, SW_HIDE);
	boolshowwindows = 0;
	while (1) {
		if (GetAsyncKeyState(VK_LSHIFT) & GetAsyncKeyState(VK_RSHIFT) & GetAsyncKeyState('K') & 0x8000)
		{
			if (boolshowwindows == 0)
			{
				ShowWindow(hWnd, SW_SHOW);
				boolshowwindows = 1;
			}
			else
			{
				ShowWindow(hWnd, SW_HIDE);
				boolshowwindows = 0;
			}
		}
		
	}
    return 0;
}