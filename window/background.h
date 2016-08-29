#ifndef BACKGROUND_H
#define BACKGROUND_H


#include "game/game_window.h"
#include "window/basic/w_text.h"

typedef struct {

}w_background_data_t;

typedef struct{
    //window
    window_t *window;
    w_text_t *title;
    w_text_t *top_line;
    w_text_t *bottom_line;
    w_text_t *left_line;
    w_text_t *right_line;
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

