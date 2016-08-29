#include "window/window.h"

//移动光标到指定位置
void gotoXY(int x, int y)
{
   //Initialize the coordinates
   COORD coord = {x, y};
   //Set the position
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
//Hides the console cursor
void HideTheCursor()
{
   CONSOLE_CURSOR_INFO cciCursor;
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

   if(GetConsoleCursorInfo(hStdOut, &cciCursor))
   {
      cciCursor.bVisible = FALSE;
      SetConsoleCursorInfo(hStdOut, &cciCursor);
   }
}

///////////////////////////////////////////////////////


void btdy(char btfh[],char bttitle[])//标题打印函数
{
    system("cls");
    int pn;
    printf("\n");
    for(pn=0;pn<25;pn++)
        printf(" ");
    printf("%s",bttitle);
    printf("\n");
    for(pn=0;pn<60;pn++)
        printf("%s",btfh);
    printf("\n");
}



void ttdy(char main_t[],char m_title[],int clspa,int clspb,int timep,int ptime)//动态打印函数，通用！ 打印主体、标题、清屏确认（clspa=1显示前清屏，clspb=1显示后清屏,播放速度，播完暂停时间
{
    if(clspa==1)
    {system("cls");}
    int len,pn;
    len=strlen(main_t);
    for(pn=0;pn<15;pn++)
        printf(" ");
    printf("%s\n",m_title);
    for(pn=0;pn<len;pn++)
    {
        if(pn%40==0)
            printf("\n\n");
        printf("%c",main_t[pn]);
        //Sleep(timep);
    }
    if(clspb==1)
    {system("cls");}
    //Sleep(ptime);
}

void sttdy(char stt[],int timep,int ptime)//单一打印函数
{
    int pn,len;
    len=strlen(stt);
    for(pn=0;pn<len;pn++)
    {
        if(pn%40==0)
            printf(" ");
        printf("%c",stt[pn]);
        //Sleep(timep);

    }
    //Sleep(ptime);
}

void skdy(char skt[])//技能说明无损打印
{
    int pn,len;
    len=strlen(skt);
    printf("   ");
    for(pn=0;pn<len;pn++)
    {
        printf("%c",skt[pn]);
    }

}

void gsdy(char gst[],int len)//打印间隔条
{
    int pn;
    printf("\n");
    for(pn=0;pn<len;pn++)
        printf("%s",gst);
}


void errdy(char etext[],char e_title[],char e_class[],int clsup)//错误反馈
{
    int pn=0,len;
    system("color c0");
    if(clsup==1)
    {system("cls");}
    printf("\n\n\a");
    for(pn=0;pn<20;pn++)
        printf(" ");
    printf("%s\n",e_title);
    for(pn=0;pn<50;pn++)
        printf("*");
    printf("\n\n【错误等级】：%s\n\n",e_class);
    printf("【错误原因】：\n ");
    len=strlen(etext);
    for(pn=0;pn<=len;pn++)
    {
        if(pn%41==0)
            printf("\n");
        printf("%c",etext[pn]);
    }
    getch();
}

#if 0
#include <windows.h>
#include <stdio.h>

void ConPrint(char *CharBuffer, int len);
void ConPrintAt(int x, int y, char *CharBuffer, int len);
void gotoXY(int x, int y);
void ClearConsole(void);
void ClearConsoleToColors(int ForgC, int BackC);
void SetColorAndBackground(int ForgC, int BackC);
void SetColor(int ForgC);
void HideTheCursor(void);
void ShowTheCursor(void);

int main(int argc, char* argv[])
{
   HideTheCursor();
   ClearConsoleToColors(15, 1);
   ClearConsole();
   gotoXY(1, 1);
   SetColor(14);
   printf("This is a test...\n");
   Sleep(5000);
   ShowTheCursor();
   SetColorAndBackground(15, 12);
   ConPrint("This is also a test...\n", 23);
   SetColorAndBackground(1, 7);
   ConPrintAt(22, 15, "This is also a test...\n", 23);
   gotoXY(0, 24);
   SetColorAndBackground(7, 1);
   return 0;
}

//This will clear the console while setting the forground and
//background colors.
void ClearConsoleToColors(int ForgC, int BackC)
{
   WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
   //Get the handle to the current output buffer...
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   //This is used to reset the carat/cursor to the top left.
   COORD coord = {0, 0};
   //A return value... indicating how many chars were written
   //not used but we need to capture this since it will be
   //written anyway (passing NULL causes an access violation).
   DWORD count;

   //This is a structure containing all of the console info
   // it is used here to find the size of the console.
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   //Here we will set the current color
   SetConsoleTextAttribute(hStdOut, wColor);
   if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
   {
      //This fills the buffer with a given character (in this case 32=space).
      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

      FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
      //This will set our cursor position for the next print statement.
      SetConsoleCursorPosition(hStdOut, coord);
   }
}

//This will clear the console.
void ClearConsole()
{
   //Get the handle to the current output buffer...
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   //This is used to reset the carat/cursor to the top left.
   COORD coord = {0, 0};
   //A return value... indicating how many chars were written
   //   not used but we need to capture this since it will be
   //   written anyway (passing NULL causes an access violation).
   DWORD count;
   //This is a structure containing all of the console info
   // it is used here to find the size of the console.
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   //Here we will set the current color
   if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
   {
      //This fills the buffer with a given character (in this case 32=space).
      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
      FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
      //This will set our cursor position for the next print statement.
      SetConsoleCursorPosition(hStdOut, coord);
   }
}

//This will set the forground color for printing in a console window.
void SetColor(int ForgC)
{
   WORD wColor;
   //We will need this handle to get the current background attribute
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO csbi;

   //We use csbi for the wAttributes word.
   if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
   {
      //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
   }
}

//This will set the forground and background color for printing in a console window.
void SetColorAndBackground(int ForgC, int BackC)
{
   WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);;
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

//Direct console output
void ConPrint(char *CharBuffer, int len)
{
   DWORD count;
   WriteConsole(GetStdHandle(STD_OUTPUT_HANDLE), CharBuffer, len, &count, NULL);
}

//Direct Console output at a particular coordinate.
void ConPrintAt(int x, int y, char *CharBuffer, int len)
{
   DWORD count;
   COORD coord = {x, y};
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition(hStdOut, coord);
   WriteConsole(hStdOut, CharBuffer, len, &count, NULL);
}



//Shows the console cursor
void ShowTheCursor()
{
   CONSOLE_CURSOR_INFO cciCursor;
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

   if(GetConsoleCursorInfo(hStdOut, &cciCursor))
   {
      cciCursor.bVisible = TRUE;
      SetConsoleCursorInfo(hStdOut, &cciCursor);
   }
}
#endif
