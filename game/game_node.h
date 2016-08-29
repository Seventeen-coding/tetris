#ifndef GAME_NODE_H
#define GAME_NODE_H

#include "game/game_list.h"
#include "game_map.h"

typedef struct{
    game_map_list_node_t  *map_head;
    game_map_t*  game_current_map;
}game_node_t;

int game_node_begin(game_node_t *node);
int game_node_end(game_node_t *node);
int game_node_run(game_node_t *node);
int game_node_map_has_next(game_node_t *node);


#endif // GAME_NODE_H

