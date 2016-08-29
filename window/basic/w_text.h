#ifndef  WINDOW_TEXT_H_
#define WINDOW_TEXT_H_

#include "game/game_window.h"
#include <stdlib.h>
#include <string.h>

typedef enum{
    TEXT_NEXT,
    TEXT_END
}text_control_t;

typedef int (*w_text_set_text)(void *__this,const char *text);

typedef struct {
    char *text;
    int  index;
    int  len;
}w_text_data_t;

typedef struct {
    //game_window_function_t w_function;
    w_msg_handle      msg;
    w_show_handle   show;
    w_select_handle  select;
    w_hide_handle     hide;
    w_destory_handle    destory;

    w_set_position   set_pos;
    w_set_area          set_area;
    w_text_set_text set_text;
}w_text_function_t;

typedef struct{
    window_t *window;
    //data
    w_text_data_t   data;
    //function
    w_text_function_t function;
}w_text_t;

w_text_t *window_create_text(window_t *parent, int x, int y, int w, int h);

#endif //WINDOW_TEXT_H_
