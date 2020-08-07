#include <stdio.h>
#include <windows.h>

LRESULT CALLBACK MainWindowProduction(HWND windowhandle, UINT message, WPARAM wParam, LPARAM lParam);

int WinMain(HINSTANCE instance, HINSTANCE previousInstance, PSTR ComandLine, INT nCmdShow){

    UNREFERENCED_PARAMETER(previousInstance);
    UNREFERENCED_PARAMETER(ComandLine);
    UNREFERENCED_PARAMETER(nCmdShow);

    //initionalize the window
    WNDCLASSEXA windowClass = { 0 };
    HWND windowHandle = 0;

    windowClass.cbSize = sizeof(WNDCLASSEX);
    windowClass.style = 0;
    windowClass.lpfnWndProc = MainWindowProduction;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = instance;
    windowClass.hIcon = LoadIconA(NULL, IDI_APPLICATION);
    windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    windowClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    windowClass.lpszMenuName =  NULL;
    windowClass.lpszClassName = "GameWindowClass";
    windowClass.hIconSm = LoadIconA(NULL, IDI_APPLICATION);

    //make sure the window works
    if(RegisterClassExA(&windowClass) == 0){
        
        MessageBox(NULL, "Window Registration Failed...", "error.", MB_ICONEXCLAMATION | MB_OK);

        return 0;
    }

    //making the window using the handler / class
    windowHandle = CreateWindowEx(
        WS_EX_CLIENTEDGE, windowClass.lpszClassName, "window title",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,
        240, 120, NULL, NULL, instance, NULL
    );

    if(windowHandle == NULL){

        return 0;
    }

    MSG message; 

    while(GetMessage(&message, NULL, 0, 0) > 0){

        TranslateMessage(&message);
        DispatchMessage(&message);
    }

    return 0;
}

LRESULT CALLBACK MainWindowProduction(HWND windowhandle, UINT message, WPARAM wParam, LPARAM lParam){ 

    LRESULT result = 0;
 
    switch (message) 
    { 
        default: 
            result = DefWindowProc(windowhandle, message, wParam, lParam); 
    } 

    return result; 
}