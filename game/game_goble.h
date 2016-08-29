#ifndef GAME_GOBLE_H
#define GAME_GOBLE_H



#include "game/game_story.h"
#include "game/game_node.h"
#include "game/game_map.h"
#include "game/game_window.h"

typedef enum {

    GAME_EXIT = -2,// -2
    GAME_ERROR = -1,//-1
    GAME_OVER = 0,// 0
    GAME_START,   //1
    GAME_STOP,//  2
    GAME_RUNNING,//   3
    GAME_MAP_INIT_ERROR,// 4
    GAME_MAP_INIT_OK,// 5
    GAME_NODE_INIT_ERROR,//6
    GAME_NODE_INIT_OK,//7
    GAME_STORY_INIT_ERROR,//8
    GAME_STORY_INIT_OK,//9
    GAME_INIT_ERROR,//10
    GAME_INIT_FINISH,//11
    GAME_CONFIG_ERROR,//12
    GAME_CONFIG_FINISH,//13
    //由于在这里开始之前配置完毕 在这里以后都要确保是正确没有error
    GAME_MAP_FINISH,//    14
    GAME_NODE_FINISH,//15
    GAME_STORY_FINISH,//16
    GAME_STORY_LIST_FINISH,//17
    GAME_FINISH,//18
    GAME_TEST
}game_status_t;

typedef enum {
    GAME_RET_ERROR = -1,
    GAME_RET_OK
}game_ret_t;
/*动态最好用指针 */

struct {
    game_status_t game_current_status;
    window_t *game_current_window ; //focus
    game_story_list_node_t  *game_story_list;

    /*以下部分只是为了方便调用*/
    game_map_t    *game_current_map;
    game_node_t  *game_current_node;
    game_story_t  *game_current_story;
}gobel_game_config;


int game_init();
int game_config();
int game_run();
int game_start();
int game_stop();
int game_end();

int  game_goble_get();

//status
int game_status_get();
int game_status_set();

//story node map set
int game_story_set(game_story_t *story);

//int game_next_story_set(game_map_t *story,game_map_t *story);

int game_node_set(game_node_t *node);

//int game_next_node_set(game_map_t *node,game_map_t *next_node);

int game_map_set(game_map_t *map);
int game_next_map_set(game_map_t *map, game_map_t *next_map);
int game_callback_map_set(game_map_t *map,game_map_t *callback_map);
#endif // GAME_GOBLE_H

