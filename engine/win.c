#include "win.h"
#include "input.h"

DWORD CreateMainWindow(void){

    DWORD result = ERROR_SUCCESS;

    //initionalize the window
    WNDCLASSEXA windowClass = { 0 };
    HWND windowHandle = 0;

    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.style = 0;
    windowClass.lpfnWndProc = MainWindowProduction;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = GetModuleHandleA(NULL);
    windowClass.hIcon = LoadIconA(NULL, IDI_APPLICATION);
    windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    windowClass.lpszMenuName =  NULL;
    windowClass.lpszClassName = gameName "WindowClass";
    windowClass.hIconSm = LoadIconA(NULL, IDI_APPLICATION);

    //make sure the window works
    if(RegisterClassExA(&windowClass) == 0){

        result = GetLastError();
        
        MessageBox(NULL, "Window Registration Failed...", "error.", MB_ICONEXCLAMATION | MB_OK);

        goto Exit;
    }

    //making the window using the handler / class
    windowHandle = CreateWindowEx(
        WS_EX_CLIENTEDGE, windowClass.lpszClassName, gameName,
        WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,
        240, 120, NULL, NULL, GetModuleHandleA(NULL), NULL
    );

    if(windowHandle == NULL){

        result = GetLastError();
        
        MessageBox(NULL, "Window Registration Failed...", "error.", MB_ICONEXCLAMATION | MB_OK);

        goto Exit;
    }

Exit:

    return result;
}

BOOL gameIsRunning(void){

    HANDLE mutex = NULL;

    mutex = CreateMutexA(NULL, FALSE, gameName "Mutex");

    if(GetLastError() == ERROR_ALREADY_EXISTS){

        return TRUE;
    }
    else{
        return FALSE;
    }
}