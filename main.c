#include "engine/win.c"
#include "engine/input.c"

int WinMain(HINSTANCE instance, HINSTANCE previousInstance, 
    PSTR ComandLine, INT nCmdShow
){

    UNREFERENCED_PARAMETER(instance);
    UNREFERENCED_PARAMETER(previousInstance);
    UNREFERENCED_PARAMETER(ComandLine);
    UNREFERENCED_PARAMETER(nCmdShow);

    //error checking
    if(gameIsRunning() == TRUE){

        MessageBox(NULL, 
            "You already have this running... genious", 
            "error.", MB_ICONEXCLAMATION | MB_OK
        );
        goto Exit;
    }

    if(CreateMainWindow() != ERROR_SUCCESS){

        goto Exit;
    }

    getInputs();

Exit:
    return 0;
}