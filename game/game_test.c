#include "game/game_test.h"



//除了用if和switch选择模块还有什么更好方法判断呢?
void game_test_run()
{
    game_test_base();
    game_test_story();
    game_test_node();
    game_test_map();
    game_test_window();                 //----
}

void game_test_base()
{
    //   game_init();                    //----
    //    game_config();             //----
}

void     game_test_story()
{
        TEST_DEBUG("game_test_story \n\r");

}
void game_test_node()
{
            TEST_DEBUG("game_test_node \n\r");
}
void game_test_map()
{
        TEST_DEBUG("game_test_map \n\r");
}

void game_test_window()
{
            TEST_DEBUG("game_test_window \n\r");
            system("cls");
            w_city_t  *window  = window_create_city(NULL,0,0,40,20);
            window->show(window);
            getch();
            w_world_t  *window2  = window_create_world(NULL,0,0,40,20);
            window2->show(window2);
}//----
