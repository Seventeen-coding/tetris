#ifndef BACKGROUND_H
#define BACKGROUND_H


#include "game/game_window.h"
#include "window/basic/w_text.h"
#include "window/basic/w_list.h"

typedef struct {

}w_background_data_t;

typedef struct{
    //window
    window_t *window;
    w_text_t *title;
    w_text_t *line;
    w_text_t *hero_text;
    w_list_t *menu_list;
    w_text_t * menu_item1;
    w_text_t * menu_item2;
    w_text_t*  menu_item3;
    w_text_t*  menu_item4;
    w_text_t * menu_item5;
    w_text_t * menu_item6;
    w_text_t*  menu_item7;
    w_text_t*  menu_item8;
    w_text_t*  menu_item9;
    //menu_map
    w_text_t *bottom;
    //data
    w_background_data_t   data;

    //function
    w_show_handle show;
    w_hide_handle hide;
    // w_msg_handle msg;
    w_select_handle select;

}w_background_t;

w_background_t *window_create_background(window_t *parent,int x,int y,int w,int h);


#endif // BACKGROUND_H

