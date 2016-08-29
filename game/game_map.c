#include "game_map.h"
#include "game_goble.h"
#include "game_key.h"   //以后替换为control
#include "game_debug.h"
//外后需要用handle处理更好扩展
int game_map_run(game_map_t *map)
{
    int status = GAME_RUNNING;
    game_status_set(status);
    game_map_begin(map);
    while(status  != GAME_MAP_FINISH && status != GAME_OVER)
    {
        map->_show();
        status = map->_select(game_get_key());   //这里写得不好
        game_status_set(status);
    }
    game_map_end(map);
    return status;
}
int game_map_begin(game_map_t *map)
{
    GAME_BASE_DEBUG("current  map : %0x\r\n",map);


    map->next_map = NULL;
    return 0;// GAME_BEGIN_FINISH;
}

int game_map_end(game_map_t *map)
{
    int status = game_status_get();
    game_status_set(status);

    if(status != GAME_MAP_FINISH)  return status;

    if(map->next_map == NULL)
    {
        GAME_BASE_DEBUG("<map>error : next_map : NULL");
        status = GAME_ERROR;
        return status;
    }
    game_map_set(map->next_map);
    //map->callback_map = NULL;
    return status;
}

