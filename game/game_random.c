/*
������: randomize     ����ȽϺê�
��  ��: ��ʼ�������������
��  ��: void randomize(void);
������:
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int game_get_random(int range)
{
   srand(time(0));
   return rand()%range;
}
