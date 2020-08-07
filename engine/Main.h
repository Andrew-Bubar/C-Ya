#pragma

#include <stdio.h>
#include <windows.h>
#define gameName "TestGame"

//to create the window
DWORD CreateMainWindow(void);

DWORD getInputs();

LRESULT CALLBACK MainWindowProduction(
    _In_ HWND windowhandle, _In_ UINT message, 
    _In_ WPARAM wParam, _In_ LPARAM lParam
);

//to see if the game is running
BOOL gameIsRunning();

BOOL mainGameIsRunning;

DWORD update(void);