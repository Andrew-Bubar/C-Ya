#pragma

#include <stdio.h>
#include <windows.h>

BOOL mainGameIsRunning;

LRESULT getInputs(void);

LRESULT CALLBACK MainWindowProduction(
    _In_ HWND windowhandle, _In_ UINT message, 
    _In_ WPARAM wParam, _In_ LPARAM lParam
);