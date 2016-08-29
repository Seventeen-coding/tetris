#include "game/game_story.h"
#include "game/game_goble.h"

game_story_list_node_t *game_story_list = NULL;

game_story_list_node_t *game_setup_config_story()
{
    game_story_list_node_t   *list_node = game_story_list;
    game_story_list_node_t  *next  = list_node->next;
    /*reload story*/
    while(next != NULL)
    {
        game_remove_story(list_node->data);
        list_node = next;
        next  = list_node->next;
    }
    return game_story_list;
}
#if 0
int game_story_init(game_story_list_node_t *list)
{
    if(list == NULL)    list = (game_story_list_node_t *)malloc(sizeof(game_story_list_node_t));

    /*最理想的做法就是用一个不需要语法的规则去设计每一个故事
            这样日后维护工作可以交给其他人了*/
    game_setup_config_story(list);
    return    0;
}
#endif

int  game_remove_story( game_story_t  * stoty)
{


}
int game_story_begin(game_story_t  * story)
{
    GAME_BASE_DEBUG("begin_story: %0x\r\n",story);

}
int game_story_end(game_story_t * story)
{
    GAME_BASE_DEBUG("end_story: %0x\r\n",story);
    game_node_t *next_node = game_story_node_has_next(story);
    //完成了所有故事 游戏结束
    if(next_node == NULL)  return GAME_STORY_FINISH;
    story->game_current_node = next_node;
    return GAME_RUNNING;
}

int game_story_node_has_next(game_story_t * story)
{
    game_node_list_node_t   *node =  list_find_by_data(story->node_head,story->game_current_node)->next;
    if(node == NULL) return GAME_STORY_FINISH;
    story->game_current_node = node->data;
    return GAME_RUNNING;
}

int game_story_run(game_story_t *story)
{
    int status = game_status_get();
    //game_story_begin(story);
    while(status != GAME_OVER &&  status != GAME_STORY_FINISH)
    {
        status = game_node_run(story->game_current_node);
        // if(status == GAME_OVER) break;
        //status = game_story_node_has_next(story) ;
        game_status_set(status);
    }
    //game_story_end(story);
    return status;
}

