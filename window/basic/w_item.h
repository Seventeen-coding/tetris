#ifndef W_ITEM_H
#define W_ITEM_H

#include "game/game_window.h"
#include <stdlib.h>
#include <string.h>

typedef int (*w_text_set_text)(void *__this,const char *text);

typedef struct {
    int  index;
    void *window;
}w_item_data_t;

typedef struct {
    //game_window_function_t w_function;
    w_msg_handle      msg;
    w_show_handle   show;
    w_hide_handle     hide;
    w_destory_handle    destory;
}w_item_function_t;

typedef struct{
    window_t *window;
    //data
    w_item_data_t   data;
    //function
    w_item_function_t function;
}w_item_t;

w_item_t *window_create_item(window_t *parent, int x, int y, int w, int h);


#endif // W_ITEM_H

