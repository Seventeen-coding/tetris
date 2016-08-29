/*
函数名: randomize     这个比较好
功  能: 初始化随机数发生器
用  法: void randomize(void);
程序例:
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int game_get_random(int range)
{
   srand(time(0));
   return rand()%range;
}
