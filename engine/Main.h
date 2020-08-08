#pragma

#include <stdio.h>
#include <windows.h>
#define gameName "GameName"

//to create the window
DWORD CreateMainWindow(int width, int height);

//to create a window to show on screen
int makeWindow(int x, int y);

//render the window
void RenderGraphics(int resolutionx, int resolutiony);

//my graphic data 
typedef struct Canvas{

    BITMAPINFO CanvasInfo;

    void* Memory;

} Canvas;

//my graphics varrible
Canvas canvas = { 0 };

//get inputs to the window
void getInputs();

//reset the window
LRESULT CALLBACK MainWindowProduction(
    _In_ HWND windowhandle, _In_ UINT message, 
    _In_ WPARAM wParam, _In_ LPARAM lParam
);

//to see if the game is running
BOOL gameIsRunning();

//global bool
BOOL mainGameIsRunning;

//updates every frame
void update();

//to set the game name
void SetGameName(char name[]);

//to make getting inputs easier in the future
short GetKey(int KeyCode);