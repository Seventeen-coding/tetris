
#include "game_env.h"
#include "window/include/window.h"

void game_env_config()
{
    int x=(GetSystemMetrics(SM_CXSCREEN)-1000),y=GetSystemMetrics(SM_CYSCREEN);
    system("title ¡¾ÃðÁú´«Ëµ¡¿V2.0");
    //system("mode con:cols=62 lines=23");
    //MoveWindow(GetForegroundWindow(),x/2,(y/5),x,y,1);
    system("cls");
    HideTheCursor();
}

