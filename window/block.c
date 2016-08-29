
#include "block.h"
#include "block_type.h"
#include "game/game_random.h"
#include <math.h>
static int __w_init(void *__this);

static int __w_msg ( void *_this,char arg);
static int __w_show( void *__this);
static int __w_hide ( void *__this);
static int __w_select ( void *__this,char arg);
static int __w_destory ( void *__this);
static int  __w_set_pos(void *__this, int x, int y);
static int __w_set_area(void *__this, int w, int h);

block_t *get_random_block(window_t *parent,int x,int y,int w, int h)
{
    window_t *window = _w_create_window(parent,x,y,w,h);
    w_block_t *base_block = window_create_block(window,0,0,w,h);
    block_t *block =(block_t *) malloc(sizeof(block_t));
    block->base_block = base_block;
    block->window = window;
    __w_init(block);
    return block;
}
int get_random_status()      //·­×ª
{
    return game_get_random(4);//BLOCK_TYPE_NUM);
}
int get_random_type()
{
    return game_get_random(BLOCK_TYPE_NUM);
}
static int    block_turn(block_t *block  ,int status)      //·­×ª
{
     w_block_data_t * data = block->data->point_pos_data;

      w_block_data_t temp;


//     block->base_block->point1->function.set_pos(block->base_block->point1->window,data->point1_x,data->point1_y);
//     block->base_block->point2->function.set_pos(block->base_block->point2->window,data->point2_x,data->point2_y);
//     block->base_block->point3->function.set_pos(block->base_block->point3->window,data->point3_x,data->point3_y);
//     block->base_block->point4->function.set_pos(block->base_block->point4->window,data->point4_x,data->point4_y);

    return 0;
}
static int __w_init(void *__this)
{
    block_t *block = __this;
    int type = get_random_type();
    w_block_data_t * data = get_block_data(type);
    block->data->point_pos_data = data; //point_pos_data
    int status = get_random_status();      //·­×ª
    set_block_status(block,status);

    block->show = __w_show;
    block->hide = __w_hide;
    block->destory = __w_destory;
    block->msg = __w_msg;
    block->select = __w_select;
    block->set_pos  = __w_set_pos;
    block->set_pos  = __w_set_area;
    block->turn = block_turn;
}

static int __w_msg ( void *_this,char arg)
{}
static int __w_show( void *__this)
{
    block_t *block = __this;
    block->base_block->show(block->base_block);
    return  0;
}
static int __w_hide ( void *__this)
{


}
static int __w_select ( void *__this,char arg)
{

}
static int __w_destory ( void *__this)
{}
static int  __w_set_pos(void *__this, int x, int y)
{}
static int __w_set_area(void *__this, int w, int h)
{}
