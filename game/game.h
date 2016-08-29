#ifndef GAME_H
#define GAME_H

#include "game/game_key.h"
#include "game/game_debug.h"
#include "game/game_test.h"
#include "game/game_goble.h"


#include "list/game_story_list_init.h"


int game_sotry_run(game_story_t  story);

/*由于做游戏 显示 选择 是必不可少的 概念*/
int game_map_show();
int game_map_select(int select);


#endif // GAME_H

