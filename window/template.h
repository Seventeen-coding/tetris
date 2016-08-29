#ifndef TEMPLATE_WINDOW_H
#define TEMPLATE_WINDOW_H

#include "game/game_window.h"

#include "window/basic/w_text.h"

typedef struct {
    int __x;
    int __y;
}w_template_data_t;

typedef struct{
    //window
   window_t *window;
    w_text_t *title;
    w_text_t *text;
    w_text_t *menu1;
    w_text_t *menu2;
    w_text_t *menu3;
    w_text_t *bottom;
    //data
    w_template_data_t   data;
}w_template_t;

w_template_t *window_create_template(window_t *parent);
int     window_show_template(w_template_t*window);




#endif // TEMPLATE_H

