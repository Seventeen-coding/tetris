#ifndef TEMPLATE_WINDOW_H
#define TEMPLATE_WINDOW_H

#include "game/game_window.h"


typedef struct {

}w_template_data_t;

//C 语言实验结构体触发函数不好用
#if 0
typedef struct {

}w_template_function_t;
#endif

typedef struct{
    window_t *window;
    //data
    w_template_data_t   data;
    //function
}w_template_t;

w_template_t *window_create_template(window_t *parent);
int     window_show_template(w_template_t * window);
//other function


#endif // TEMPLATE_WINDOW_H

