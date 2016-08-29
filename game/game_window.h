#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include "window/window.h"
#include "game/game_list.h"



typedef  int (*w_msg_handle)(void *_this,char arg);
//typedef  int (* w_init_handle)(void *_this);
typedef  int (*w_show_handle)(void *_this);
typedef  int (*w_hide_handle)(void *_this);
typedef  int (*w_select_handle)(void *_this,char arg);
typedef  int (*w_destory_handle)(void *_this);
typedef int (* w_set_position)(void *_this , int x, int y);
typedef int (* w_set_area)(void *_this , int x, int y);


typedef struct{
    //w_init_handle       init;
    w_msg_handle      msg;
    w_show_handle   show;
    w_select_handle  select;
    w_hide_handle     hide;
    w_destory_handle    destory;

    w_set_position   set_pos;
    w_set_area          set_area;

}game_window_function_t;

typedef list_node window_list_node_t;

typedef struct{
    struct game_window_t *parent;
    struct game_window_t *__this;
   window_list_node_t *children_list;
    char * type;
    //Absolute Position
    //    int         __x;
    //    int         __y;
    //Relative Position
    int         __x;
    int         __y;
    int         __w;
    int          __h;

}game_window_data_t;

typedef struct game_window_t{
    game_window_function_t function;
    game_window_data_t    data;
}window_t;


window_t * _w_create_window(window_t *parent, int x, int y, int w, int h);

int game_focus_window(window_t *window);


#endif // GAME_WINDOW_H

