#ifndef GAME_TEST_H
#define GAME_TEST_H

#include "game/game_key.h"

#include "game/game_story.h"

#include "game/game_debug.h"

#include "game/game_goble.h"




//想想就知道了 如果模块越来越多  只用一个文件作为测试就会导致文件代
//码越来越多请问你愿意吗？但会使模块文件越来越多 这样就要用文件夹分清楚
#include "game/game_test_module.h"



#define GAME_TEST_DEBUG
#ifdef   GAME_TEST_DEBUG
//#define  TEST_DEBUG(msg...)   do{if(1)GAME_BASE_DEBUG("<node>"msg);}while(0)
#define  TEST_DEBUG(msg...)   GAME_BASE_DEBUG("<test> "msg)
#define  TEST_ERROR(msg...)   GAME_BASE_DEBUG("<test error> "msg)
#else
#define  TEST_DEBUG(...)
#endif

#define GAME_TEST_BASE   1
game_map_t test_map;


//当然这个测试可以用int型选择对应的调试模块
void game_test_run();
void game_test_base();



#endif // GAME_TEST_H

