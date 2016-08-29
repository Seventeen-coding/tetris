#ifndef WINDOW_H
#define WINDOW_H
#include<stdio.h>
#include<windows.h>
#include<conio.h>                 //ÒýÓÃ
void btdy(char btfh[],char bttitle[]);
void ttdy(char main_t[],char m_title[],int clspa,int clspb,int timep,int ptime);
void sttdy(char stt[],int timep,int ptime);
void skdy(char skt[]);
void gsdy(char gst[],int len);
void errdy(char etext[],char e_title[],char e_class[],int clsup);


void HideTheCursor();
void gotoXY(int x, int y);



#endif // WINDOW_H



