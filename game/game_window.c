

#include "game/game_window.h"
#include "game/game_window_type.h"
#include "list/list.h"  //如果需要更好兼容性 那就自己创建一个 game_list 去代替这个list


static int __w_init__(window_t *parent, window_t * window ,int x, int y,int w,int h);

static int __w_msg ( void *_this,char arg);
static int __w_show( void *__this);
static int __w_hide ( void *__this);
static int __w_select ( void *__this,char arg);
static int __w_destory ( void *__this);
static int  __w_set_pos(void *__this, int x, int y);
static int __w_set_area(void *__this, int w, int h);

//x y 展示没卵用
window_t * _w_create_window(window_t *parent,int x, int y,int w,int h)
{
    window_t * window =  (window_t *)malloc(sizeof(window_t));
    __w_init__(parent,window,x,y,w,h);     //这里想像的是通用的初始化
    return  window;
}

int  __w_init__(window_t *parent, window_t * window ,int x, int y,int w,int h)
{
    do{
        window->data.parent = parent;
        window->data.__this = window;
        window->function.destory = __w_destory;
        //   window->function. init = __w_init__;
        window->function.msg = __w_msg;
        window->function.show = __w_show;
        window->function.select = __w_select;
        window->function.hide = __w_hide;
        window->function.set_pos = __w_set_pos;
        window->function.set_area = __w_set_area;
        window->function.set_pos(window,x,y);
        window->function.set_area(window,w,h);
        window->data.children_list = list_create(NULL);

        //处理parent
        if( parent == NULL) break;      //parent是空的就不往下处理
        list_insert_end(parent->data.children_list,window);
        window->data.type = parent->data.type;

    }while(0);
    return 0;
}

/*destory 的话 没什么好做的 因为我们初始化的东西就不想把他们删除
    除非是大型游戏 ^-^
    一般来说加了 __前缀就不应该修改他们了
*/
int    __w_destory__(void *_this)
{
    window_t * window =(window_t * ) _this;
}
int __w_msg ( void *_this,char arg)
{
    window_t * window =(window_t * ) _this;
}
int __w_init (void *_this)
{
    window_t * window =(window_t * ) _this;
}
int __w_show( void *_this)
{
    window_t * window =(window_t * ) _this;
    //do something children show
    if(window->data.children_list->next == NULL)     return 0;
    window_list_node_t *children_node = window->data.children_list;
    window_list_node_t *next_node = children_node->next;
    window_t *w_child;
    do
    {
        w_child = (window_t *)   children_node->data;
        w_child->function.show(w_child);
        children_node = next_node;
        next_node = children_node->next;
    }while(children_node->next != NULL);
    w_child->function.show(w_child);   //next is null   than show the last

    return 0;
}
int __w_hide (void *__this)
{
    window_t * window =(window_t * )__this;
}
int __w_select (void *__this,char arg)
{
    window_t * window =(window_t * ) __this;

}
int __w_destory (void *__this)
{
    window_t * window =(window_t * ) __this;
}

static int  __w_set_pos(void *__this, int x, int y)
{
    window_t * window =(window_t * )__this;
    if(window->data.parent != NULL)
    {
        x = x+ window->data.parent->data.__x;
        y = y+ window->data.parent->data.__y;
    }
    window->data.__x = x;
    window->data.__y = y;
    return 0;
}

static int __w_set_area(void *__this, int w, int h)
{
    window_t * window =(window_t * )__this;
    window->data.__w= w;
    window->data.__h= h;
    return 0;

}

