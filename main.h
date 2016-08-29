#ifndef MAIN_H
#define MAIN_H



#include "game/game.h"


#define cls system("cls") //清屏
#define dis_time 0
#define pause_time 1000

void ttdy(char main_t[],char m_title[],int clspa,int clspb,int timep,int ptime);//打印函数
void sttdy(char stt[],int timep,int ptime);//单一打印：打印字符、播放速度、暂停时间
void errdy(char etext[],char e_title[],char e_class[],int clsup);//错误提示：提示内容、提示标题、严重情况、清屏
void btdy(char btfh[],char bttitle[]);//标题打印函数：美化符号、标题
void gsdy(char gst[],int len);//打印间隔条

void HideCursor();//隐藏光标
void main_dh();
void newgame();
void menuf();
void datdell();void save_dat();void read_dat();
void peoinfo();
void lookwep();
void wupin(); void usewp(int bhao);
void shopc();  void wpinfo(int bhao);  void buywp(int bhao);void pwp(int bhao);//商店、物品信息、买东西、卖东西
void cityc();void cityinfo(int bhao);
void help_menu();
void small_game();
void upcheck();
void end_from_menu();
void skill();  void skillinfo(int bhao);void skdy(char skt[]);
void gwinfo(int bhao);
void god_here();
void god_mod();
void date_check();
void pkload(int bhao);void pkwin(int bhao);void pklost(int bhao);
void test();              //各功能函数





struct wp{char name[30];char pinzhi[20];int zyk;int jhp;int jmp;int jgj;int jfy;int jspeed;int jluck;int mgold;int nbag;int jbaoj;int haved;int mhave;int cbuy;int cshop;}gwp[];
//物品数组：物品名，品质，作用值，加血，加魔，加攻击，加防御，加速度，加幸运，价格，占用包裹，加暴击，拥有量，最大拥有，可买（1可买，0不可），可卖（1可）。

struct ct{char name[30];char info[100];int sgnum;int gnum;int ndj;}gct[];
//地图结构：地图名，简介；怪物起点，怪物数量，限制等级

struct gw{char name[30];char talk[200];int dj;int gj;int fy;int speed;int hp;int hpmax;int mp;int mpmax;int hexp;int hgold;int hyp;int hwp;int hqb;int allow_run;}ggw[];
//怪物结构：名称，交流，等级，攻击，防御，速度，血，最大血，魔，最大魔，携带经验，携带金币，随机奖励药品（1有），随机武器，随机奇宝，允许逃跑（1允许）

struct skill{char name[50];char info[200];int keep;int jhp;int jgj;int jfy;int jspeed;int jluck;int nmp;int ndj;int allow_use;}gskill[];
//技能结构：名称，介绍，持续回合，加血，加攻击(百分比），加防御，加速度，加幸运，释放需要MP，限制等级，，允许释放（1允许），

int c_play,c_gwp;//数组编号统计



#endif // MAIN_H

