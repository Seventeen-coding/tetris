
#include "w_item.h"

//base function
static  int  __w_init( w_item_t* _this);
//static  int __w_msg ( void *__this,char arg);
//static  int  __w_show(void *__this);
//static  int  __w_hide ( void *__this);
//static  int  __w_select ( void *__this,char arg);
//static  int  __w_destory ( void *__this);

//list function
//int    __w_add_item(void *__this, void *item);
//int    __w_add_list(void *__this, void *list);
//int    __w_del_item(void *__this, void *item);
//int    __w_del_list(void *__this, void *list);

w_item_t *window_create_item(window_t *parent, int x, int y, int w, int h)
{
    w_item_t  * item =  (w_item_t  *)malloc(sizeof(w_item_t ));
    window_t * window = _w_create_window(parent,x,y,w,h);
    item->window = window;
    __w_init(item);
    return (w_item_t *)item;
}

static  int  __w_init(w_item_t *_this)
{
    //data
    _this->data.index  = 0;
    //function
    //    _this->function.destory = __w_destory;
    //    _this->function.show = __w_show;
    //    _this->function.hide = __w_hide;
    //    _this->function.msg = __w_msg;

    //    _this->function.add_item = __w_add_item;
    //    _this->function.add_item = __w_add_item;
    return 0;
}

//static  int __w_msg ( void *__this,char arg)
//{
//        w_item_t * item = __this;
//        item->data.window
//}
//static  int  __w_show(void *__this);
//static  int  __w_hide ( void *__this);
//static  int  __w_select ( void *__this,char arg);
//static  int  __w_destory ( void *__this);
