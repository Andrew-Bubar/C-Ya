#include "Main.h"


HWND windowHandle;

DWORD CreateMainWindow(void){

    DWORD result = ERROR_SUCCESS;

    //initionalize the window
    WNDCLASSEXA windowClass = { 0 };
    windowHandle = 0;

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

//process the game
DWORD getInputs(){

    MSG message = { 0 }; 
    LRESULT result = 0;

    mainGameIsRunning = TRUE;

    while(mainGameIsRunning == TRUE){

        while(PeekMessageA(&message, windowHandle, 0, 0, PM_REMOVE)){
            
            DispatchMessage(&message);
            
            update();
        }
    }
}

//see if the game is running
BOOL gameIsRunning(){

    HANDLE mutex = NULL;

    mutex = CreateMutexA(NULL, FALSE, gameName "Mutex");

    if(GetLastError() == ERROR_ALREADY_EXISTS){

        return TRUE;
    }
    else{
        return FALSE;
    }
}

//handle inputs
LRESULT CALLBACK MainWindowProduction(
    _In_ HWND windowhandle, _In_ UINT message, 
    _In_ WPARAM wParam, _In_ LPARAM lParam
    ){ 

    LRESULT result = 0;
 
    switch (message) 
    { 

        case WM_CLOSE:{

            mainGameIsRunning = FALSE;


            PostQuitMessage(0);

            break;
        }

        default: 
            result = DefWindowProc(windowhandle, message, wParam, lParam); 
    } 

    return result; 
}