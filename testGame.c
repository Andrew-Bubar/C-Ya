#include "engine/Main.c"

int main(void){

    SetGameName("testing");

    //error checking
    if(gameIsRunning() == TRUE){

        MessageBox(NULL, 
            "You already have this running... genious", 
            "error.", MB_ICONEXCLAMATION | MB_OK
        );
        goto Exit;
    }

    makeWindow(640, 480);

Exit:
    return 0;
}

void update(){


}