#include "Main.h"


HWND windowHandle;

DWORD CreateMainWindow(int width, int height){

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
        width, height, NULL, NULL, GetModuleHandleA(NULL), NULL
    );

    //things i need up update
    getInputs();


    if(windowHandle == NULL){

        result = GetLastError();
        
        MessageBox(NULL, "Window Registration Failed...", "error.", MB_ICONEXCLAMATION | MB_OK);

        goto Exit;
    }

Exit:

    return result;
}

//make creating the window easier on the game script
int makeWindow(int x, int y){

    if(CreateMainWindow(x, y) != ERROR_SUCCESS){

        return 0;
    }
}

//rendering the game
void RenderGraphics(int resolutionx, int resolutiony){

    canvas.CanvasInfo.bmiHeader.biSize = sizeof(canvas.CanvasInfo.bmiHeader);

    canvas.CanvasInfo.bmiHeader.biWidth = 256;
    canvas.CanvasInfo.bmiHeader.biHeight = 240;
}

//process the game
void getInputs(){

    MSG message = { 0 }; 
    LRESULT result = 0;

    mainGameIsRunning = TRUE;

    while(mainGameIsRunning == TRUE){

        while(PeekMessageA(&message, windowHandle, 0, 0, PM_REMOVE)){
            
            DispatchMessage(&message);

            update();

            Sleep(1);
        }
    }
}

short GetKey(int KeyCode){

    return GetAsyncKeyState(KeyCode);
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

void SetGameName(char name[]){

    #undef gameName
    #define gameName name
}