

#include "w_block.h"

static int __w_init__(void *__this);

static int __w_show( void *__this);
static int __w_hide ( void *__this);
static int __w_destory ( void *__this);
static int __w_msg ( void *_this,char arg);
static int __w_select ( void *__this,char arg);
static int  __w_set_pos(void *__this, int x, int y);
static int __w_set_area(void *__this, int w, int h);

static int __w_init__(void *__this)
{
    w_block_t *block = (w_block_t *)__this;

    //����ֻ��Ϊ�˷������
    block->show = __w_show;
    block->hide = __w_hide;
    block->destory = __w_destory;
    block->msg = __w_msg;
    block->select = __w_select;
    block->set_pos  = __w_set_pos;
    block->set_pos  = __w_set_area;
}
static int __w_hide ( void *__this)
{


}
static int __w_show( void *__this)
{
    system("color 30");
    w_block_t *block =(w_block_t *) __this;
    block->point1->function.show(block->point1);
    block->point2->function.show(block->point2);
    block->point3->function.show(block->point3);
    block->point4->function.show(block->point4);
    return 0;
}

static int __w_msg ( void *_this,char arg)
{

}

static int __w_select ( void *__this,char arg)
{

}
static int __w_destory ( void *__this)
{

}
static int  __w_set_pos(void *__this, int x, int y)
{

}
static int __w_set_area(void *__this, int w, int h)
{

}

w_block_t *window_create_block(window_t *parent,int x,int y,int w,int h)
{
    w_block_t *block =(w_block_t *)malloc(sizeof(w_block_t)) ;
    window_t * window = _w_create_window(parent,x,y,w,h);
    block->point1 = window_create_point(window,0,0,1,1);
    block->point2 = window_create_point(window,1,0,1,1);
    block->point3 = window_create_point(window,0,1,1,1);
    block->point4 = window_create_point(window,1,1,1,1);
    block->window = window;
    //д�Ĳ�����
    __w_init__(block);
    return (w_block_t *)block;
}
