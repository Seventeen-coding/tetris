
#include "game_env.h"
#include "window/window.h"

void game_env_config()
{
    int x=(GetSystemMetrics(SM_CXSCREEN)-1000),y=GetSystemMetrics(SM_CYSCREEN);
    system("title ¡¾¶íÂÞË¹·½¿é¡¿V1.0");
    system("mode con:cols=100 lines=30");
    //MoveWindow(GetForegroundWindow(),x/2,(y/5),x,y,1);
    system("cls");
    HideTheCursor();
}

