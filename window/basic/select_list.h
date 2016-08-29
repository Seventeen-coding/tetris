#ifndef SELECT_LIST_H
#define SELECT_LIST_H

#include "game/game_window.h"
#include "window/basic/w_text.h"


typedef struct{
    window_t *window;
    //item
    w_text_t *index;
    w_text_t *text;
    //
    w_text_data_t   data;
    //function
    // w_text_set_text set_text;

}w_select_list_t;

#endif // SELECT_LIST_H

