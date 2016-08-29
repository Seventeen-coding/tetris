#ifndef GAME_STORY_H
#define GAME_STORY_H

#include <stdlib.h>
#include "game/game_list.h"
#include "game/game_node.h"
#include "game/game_debug.h"
typedef struct{
    game_node_t *   game_current_node;
    game_node_list_node_t * node_head;
}game_story_t;

int game_story_begin(game_story_t *story);
int game_story_end(game_story_t *story);
int game_story_run(game_story_t *story);
int game_story_node_has_next(game_story_t *story);

#endif // GAME_STORY_H

