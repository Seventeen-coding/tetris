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
    w_background_t *background= window_create_background(NULL,10,0,60,10);
    background->show(background);
    //            w_point_t *point = window_create_point(background->window,5,5,1,1);
    //            point->function.show(point);
    block_t *block =  get_random_block(background->window,20,2,4,4);
    block->show(block);
}//----
