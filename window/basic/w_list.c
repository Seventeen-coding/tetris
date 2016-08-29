
#include "w_list.h"

//base function
static  int  __w_init( w_list_t* _this);
static  int __w_msg ( void *__this,char arg);
static  int  __w_show(void *__this);
static  int  __w_hide ( void *__this);
static  int  __w_select ( void *__this,char arg);
static  int  __w_destory ( void *__this);

//list function
int    __w_add_item(void *__this, void *item);
int    __w_add_list(void *__this, void *list);
int    __w_del_item(void *__this, void *item);
int    __w_del_list(void *__this, void *list);

w_list_t *window_create_list(window_t *parent, int x, int y, int w, int h)
{
    w_list_t  * list =  (w_list_t  *)malloc(sizeof(w_list_t ));
    window_t * window = _w_create_window(parent,x,y,w,h);
    list->window = window;
    __w_init(list);

    return (w_list_t *)list;
}

static  int  __w_init(w_list_t *_this)
{
    //data
    _this->data.index  = 0;
    _this->data.len  = 0;
    _this->data.item_list  = list_create(NULL);
    //function
    _this->function.destory = __w_destory;
    _this->function.show = __w_show;
    _this->function.hide = __w_hide;
    _this->function.select = __w_select;
    _this->function.msg = __w_msg;

    _this->function.add_item = __w_add_item;
    _this->function.add_list = __w_add_list;
    _this->function.set_area = _this->window->function.set_area;
    _this->function.set_pos = _this->window->function.set_pos;
    return 0;
}


static int __w_select(void *__this,char key)
{

}


static  int  __w_show( void *__this)
{
    w_list_t *window = (w_list_t*)__this;
    item_node_t *item;
    item_node_t *next_item = window->data.item_list->next;   //head item
    w_text_t *show_item ;
    //这种遍历不够通用 需要优化
    while(next_item != NULL)
    {
        item = next_item;
        next_item = item->next;

        show_item =( w_text_t *)item->data;
        show_item->function.show(show_item);
    }
    show_item->function.show(show_item);        //下一个是NULL 因此show完这次就回去

    return 0;
}

int     __w_hide(void*__this)
{

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


int    __w_add_item(void *__this, void *item)
{
    w_list_t *window =(w_list_t *) __this;
    //w_text_t*item = item;                   //以后需要改为 w_item_t *
    list_insert_end(window->data.item_list,item);
    window->data.len++;
}

int    __w_add_list(void *__this, void *list)
{\

}
int    __w_del_item(void *__this, void *item)
{
    w_list_t *window =(w_list_t *) __this;
    if( window->data.len <= 0)   return -1;
    list_remove_by_data(window->data.item_list,item);
    window->data.len--;
    return 0;
}
