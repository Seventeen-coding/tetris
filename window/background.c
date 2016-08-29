
#include "background.h"

static int __w_init__(void **__this);

static int __w_msg ( void *_this,char arg);
static int __w_show( void *__this);
static int __w_hide ( void *__this);
static int __w_select ( void *__this,char arg);
static int __w_destory ( void *__this);
static int  __w_set_pos(void *__this, int x, int y);
static int __w_set_area(void *__this, int w, int h);


static int __w_init__(void **__this)
{
    w_background_t *background = (w_background_t *)__this;
    background->title->function.set_text(background->title,"¶íÂÞË¹·½¿é\n");
    background->top_line->function.set_text(background->top_line,"*****************************************");
    background->left_line->function.set_text(background->left_line,"*******************************************************");
    background->right_line->function.set_text(background->right_line,"*******************************************************");
    background->bottom_line->function.set_text(background->bottom_line,"*****************************************");

    background->show = __w_show;
    background->hide = __w_hide;

}
static int __w_hide ( void *__this)
{


}
static int __w_show( void *__this)
{
    system("cls");//ÇåÆÁ
    system("color 30");
    w_background_t *background =(w_background_t *) __this;
    background->title->function.show(background->title);
    background->top_line->function.show(background->top_line);
    background->left_line->function.show(background->left_line);
        background->right_line->function.show(background->right_line);
    background->bottom_line->function.show(background->bottom_line);
    return 0;
}


w_background_t *window_create_background(window_t *parent,int x,int y,int w,int h)
{
    w_background_t *background =(w_background_t *)malloc(sizeof(w_background_t)) ;
    window_t * window = _w_create_window(parent,x,y,w,h);
    background->window = window;

    background->title = window_create_text(background->window,20,0,40,1);
    background->top_line = window_create_text(background->window,0,1,100,1);
    background->left_line = window_create_text(background->window,0,1,1,28);
    background->right_line = window_create_text(background->window,40,1,1,28);
    background->bottom_line  =  window_create_text(background->window,0,28,100,1);
    __w_init__(background);
    return (w_background_t *)background;
}
