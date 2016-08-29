#ifndef W_LIST_H
#define W_LIST_H

#include "w_text.h"
#include "list/list.h"
typedef  list_node      item_node_t;
typedef int (*w_list_add_list)(void *__this,void *list);
typedef int (*w_list_add_item)(void *__this, void *item);

typedef struct {
    item_node_t  *item_list;
    int  index;
    int  len;
}w_list_data_t;

typedef struct {
    //game_window_function_t w_function;
    w_msg_handle      msg;
    w_show_handle   show;
    w_select_handle  select;
    w_hide_handle     hide;
    w_destory_handle    destory;

    w_set_position   set_pos;
    w_set_area          set_area;

    w_list_add_list add_list;
    w_list_add_list add_item;
}w_list_function_t;

typedef struct{
    window_t *window;
    //data
    w_list_data_t   data;
    //function
    w_list_function_t function;
}w_list_t;

w_list_t *window_create_list(window_t *parent, int x, int y, int w, int h);

#endif // W_LIST_H

