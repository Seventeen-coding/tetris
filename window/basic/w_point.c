
#include "w_point.h"

static  int  __w_init( w_point_t  * _this);
static  int __w_msg ( void *__this,char arg);
static  int  __w_show(void *__this);
static  int  __w_hide ( void *__this);
static  int  __w_select ( void *__this,char arg);
static  int  __w_destory ( void *__this);

w_point_t * window_create_point(window_t *parent,int x,int y,int w,int h)
{
    w_point_t  * point =  (w_point_t  *)malloc(sizeof(w_point_t ));
    window_t * window = _w_create_window(parent,x,y,w,h);
    point->window = window;
    __w_init(point);

    return (w_point_t *)point;
}

static  int  __w_init(w_point_t  * _this)
{
    _this->function.destory = __w_destory;
    _this->function.show = __w_show;
    _this->function.hide = __w_hide;
    //    _this->function.select = __w_select;
    _this->function.msg = __w_msg;
    _this->function.set_pos = _this->window->function.set_pos;
    _this->function.set_area = _this->window->function.set_area;
    return 0;
}

static  int  __w_show( void *__this)
{
    w_point_t *point = (w_point_t *)__this;
    system("color 30");         //以后可以用不同的颜色去表示
    int x = point->window->data.__x;
    int y = point->window->data.__y;
    gotoXY(x,y);
    printf("#");
    return 0;
}

int     __w_hide(void*__this)
{
    w_point_t *point = (w_point_t *)__this;
    gotoXY(point->window->data.__x,point->window->data.__y);
    printf(" ");
    return 0;
}

static int __w_msg(void *__this,char msg)
{

    return 0;
}
static int __w_destory(void *__this)
{

    return 0;
}


