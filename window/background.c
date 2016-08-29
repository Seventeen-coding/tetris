
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
    background->title->function.set_text(background->title,"【灭龙传说】\n");
    background->line->function.set_text(background->line,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\r\n");
    background->menu_item1->function.set_text(background->menu_item1,"[A]--人物信息");
    background->menu_item2->function.set_text(background->menu_item2,"[B]--包裹");
    background->menu_item3->function.set_text(background->menu_item3," [C]--商店");
    background->menu_item4->function.set_text(background->menu_item4,"[D]--【战场】");
    background->menu_item5->function.set_text(background->menu_item5,"[E]--档案");
    background->menu_item6->function.set_text(background->menu_item6,"[F]--返回");
    background->menu_item7->function.set_text(background->menu_item7,"[G]--小游戏");
    background->menu_item8->function.set_text(background->menu_item8,"[S]--休息");
    background->menu_item9->function.set_text(background->menu_item9,"[H]--帮助");


    background->menu_list->function.add_item(background->menu_list,background->menu_item1);
    background->menu_list->function.add_item(background->menu_list,background->menu_item2);
    background->menu_list->function.add_item(background->menu_list,background->menu_item3);
    background->menu_list->function.add_item(background->menu_list,background->menu_item4);
    background->menu_list->function.add_item(background->menu_list,background->menu_item5);
    background->menu_list->function.add_item(background->menu_list,background->menu_item6);
    background->menu_list->function.add_item(background->menu_list,background->menu_item7);
    background->menu_list->function.add_item(background->menu_list,background->menu_item8);
    background->menu_list->function.add_item(background->menu_list,background->menu_item9);


    char str[50];
    sprintf(str,"勇士：%s (%d级)","seventeen",100);   //test
    background->hero_text ->function.set_text(background->hero_text,str);
    background->bottom->function.set_text(background->bottom,"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\r\n");

    background->show = __w_show;
    background->hide = __w_hide;

}
static int __w_hide ( void *__this)
{


}
static int __w_show( void *__this)
{
    system("cls");//清屏
    system("color 30");
    w_background_t *background =(w_background_t *) __this;
    background->title->function.show(background->title);
    background->line->function.show(background->line);
    background->hero_text->function.show(background->hero_text);
    background->menu_list->function.show(background->menu_list);
    background->bottom->function.show(background->bottom);
    return 0;
}


w_background_t *window_create_background(window_t *parent,int x,int y,int w,int h)
{
    w_background_t *background =(w_background_t *)malloc(sizeof(w_background_t)) ;
    window_t * window = _w_create_window(parent,x,y,w,h);
    background->window = window;
    background->title = window_create_text(background->window,20,0,40,1);
    background->line = window_create_text(background->window,0,1,60,1);
    background->hero_text = window_create_text(background->window,0,2,40,1);
    background->menu_list =  window_create_list(background->window,0,4,40,6);
    //item  先用着 有待优化
    background->menu_item1 = window_create_text(background->window,0,4,20,6);
    background->menu_item2 = window_create_text(background->window,0,6,20,6);
    background->menu_item3 = window_create_text(background->window,0,8,20,6);
    background->menu_item4 = window_create_text(background->window,20,4,20,6);
    background->menu_item5 = window_create_text(background->window,20,6,20,6);
    background->menu_item6 = window_create_text(background->window,20,8,20,6);
    background->menu_item7 = window_create_text(background->window,40,4,20,6);
    background->menu_item8 = window_create_text(background->window,40,6,20,6);
    background->menu_item9 = window_create_text(background->window,40,8,20,6);
    background->bottom  =  window_create_text(background->window,0,15,60,1);
    __w_init__(background);
    return (w_background_t *)background;
}
