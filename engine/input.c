#include "input.h"

LRESULT getInputs(void){

    MSG message = { 0 }; 
    LRESULT result = 0;

    mainGameIsRunning = TRUE;

    while(mainGameIsRunning == TRUE){

        while(GetMessage(&message, NULL, 0, 0) > 0){

        TranslateMessage(&message);
        result = DispatchMessage(&message);

        return result;
        }
    }
}

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