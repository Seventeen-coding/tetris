#ifndef W_BLOCK_H
#define W_BLOCK_H


#include "game/game_window.h"
#include "window/basic/w_point.h"
#include "window/block_type.h"

typedef struct{
    //window
    window_t *window;
    w_point_t *point1;
    w_point_t *point2;
    w_point_t *point3;
    w_point_t *point4;
    //data
    w_block_data_t   *data;

    //function
    w_show_handle show;
    w_hide_handle hide;
     w_msg_handle msg;
    w_select_handle select;
    w_destory_handle    destory;

    w_set_position   set_pos;
    w_set_area          set_area;
}w_block_t;

w_block_t *window_create_block(window_t *parent,int x,int y,int w,int h);




#endif // W_BLOCK_H

