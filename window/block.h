#ifndef BLOCK_H
#define BLOCK_H

#include "window/basic/w_block.h"
#include <stdbool.h>


typedef  int   (* block_turn_handle)(struct block_t *block  ,int status);      //·­×ª

typedef struct {
    int block_status;
     w_block_data_t *point_pos_data;
}block_data_t;

typedef struct block_t{
    //window
    window_t  *window;
    w_block_t *base_block;
    block_data_t * data;
    //function
    w_msg_handle      msg;
    w_show_handle   show;
    w_select_handle  select;
    w_hide_handle     hide;
    w_destory_handle    destory;

    w_set_position   set_pos;
    w_set_area          set_area;

    block_turn_handle turn;
}block_t;

block_t *get_random_block(window_t *parent, int x, int y, int w, int h);


#endif // BLOCK_H

