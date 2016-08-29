
#include "game_node.h"
#include "game_goble.h"

int game_node_run(game_node_t *node)
{
    int status = game_status_get();
    game_node_begin(node);
    while(status  != GAME_NODE_FINISH && status != GAME_OVER)
    {
        status =  game_map_run(node->game_current_map);
       //if(status == GAME_OVER) break;
        //status = game_node_map_has_next(node) ;
        game_status_set(status);
    }
    game_node_end(node);
    return status;      //finish or game over
}

int game_node_begin(game_node_t *node)
{
    GAME_BASE_DEBUG("current_node : %0x\r\n",node);
    return GAME_RUNNING;
}

int game_node_end(game_node_t *node)
{
    return GAME_RUNNING;
}

int game_node_map_has_next(game_node_t *node)
{
    game_map_list_node_t   *map_node =  list_find_by_data(node->map_head,node->game_current_map);
    if(map_node->next == NULL) return GAME_NODE_FINISH;
    node->game_current_map = map_node->next->data;
    return GAME_RUNNING;
}
