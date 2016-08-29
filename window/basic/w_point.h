#ifndef W_POINT_H
#define W_POINT_H

#include "game/game_window.h"
#include <stdlib.h>
#include <string.h>


typedef int (*w_point_set_text)(void *__this,const char *text);

typedef struct {
}w_point_data_t;

typedef struct {
    //game_window_function_t w_function;
    w_msg_handle      msg;
    w_show_handle   show;
    w_select_handle  select;
    w_hide_handle     hide;
    w_destory_handle    destory;

    w_set_position   set_pos;
    w_set_area          set_area;
}w_point_function_t;

typedef struct{
    window_t *window;
    //data
    w_point_data_t   data;
    //function
    w_point_function_t function;
}w_point_t;

w_point_t *window_create_point(window_t *parent, int x, int y, int w, int h);

#endif // W_POINT_H

