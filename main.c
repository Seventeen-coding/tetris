/*������˵���ְ�  V2016/6/27  By Seventeen  */
/*�ع��� 2016/8/17    By Seventeen                       */

#include "main.h"


int main (int argc, char *argv[])
{
    /*�������е�����Ϸ�ⲿ�޹ص����� �細�ڴ�С ��� ������ɫ�� ˼ά: �ԡ���Ϸ�� Ϊ˼��ȥ�������ӿ� */
    game_env_config();
    int status;
    do{
        status = game_start();
        game_status_set(status);
        if(game_status_get() == GAME_TEST)
        {
            game_test_run();           //ÿ����һ��ģ����testģ��������� �����߿���Ч��
            //continue;
            return 0;
        }
        game_run();
        game_end();
    }while(0);//game_status_get() != GAME_EXIT );
    return 0;
}



