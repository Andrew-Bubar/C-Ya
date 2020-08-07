#include "main.h"

int WinMain(HINSTANCE instance, HINSTANCE previousInstance, 
    PSTR ComandLine, INT nCmdShow
){

    UNREFERENCED_PARAMETER(previousInstance);
    UNREFERENCED_PARAMETER(ComandLine);
    UNREFERENCED_PARAMETER(nCmdShow);

    if(CreateMainWindow() != ERROR_SUCCESS){

        goto Exit;
    }

    MSG message; 

    while(GetMessage(&message, NULL, 0, 0) > 0){

        TranslateMessage(&message);
        DispatchMessage(&message);
    }

Exit:
    return 0;
}

LRESULT CALLBACK MainWindowProduction(
    _In_ HWND windowhandle, _In_ UINT message, 
    _In_ WPARAM wParam, _In_ LPARAM lParam
    ){ 

    LRESULT result = 0;
 
    switch (message) 
    { 

        case WM_CLOSE:{


            PostQuitMessage(0);

            break;
        }

        default: 
            result = DefWindowProc(windowhandle, message, wParam, lParam); 
    } 

    return result; 
}

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
    windowClass.lpszClassName = "GameWindowClass";
    windowClass.hIconSm = LoadIconA(NULL, IDI_APPLICATION);

    //make sure the window works
    if(RegisterClassExA(&windowClass) == 0){

        result = GetLastError();
        
        MessageBox(NULL, "Window Registration Failed...", "error.", MB_ICONEXCLAMATION | MB_OK);

        goto Exit;
    }

    //making the window using the handler / class
    windowHandle = CreateWindowEx(
        WS_EX_CLIENTEDGE, windowClass.lpszClassName, "window title",
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